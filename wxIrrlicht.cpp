#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>

#ifdef _WIN32
#include <windows.h>
#endif // WINDOWS

#ifdef __linux__
#include <gdk/gdk.h>
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#include <X11/Xlib.h>
#endif // __linux__

#include <irrlicht.h>
#include "wxIrrlicht.h"

#include "rc_defines.h"
#include "camera.h"
#include "rc_utf8.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

//BEGIN_EVENT_TABLE(wxIrrlicht, wxControl)
//    EVT_TIMER(ID_IRR_TIMER, wxIrrlicht::OnTimer)
//    EVT_SIZE(wxIrrlicht::OnSize)
//    EVT_PAINT(wxIrrlicht::OnPaint)
//    EVT_ERASE_BACKGROUND(wxIrrlicht::OnEraseBackground)
//    EVT_MOUSE_EVENTS(wxIrrlicht::OnMouse)
//    EVT_KEY_DOWN(wxIrrlicht::OnKey)
//    EVT_KEY_UP(wxIrrlicht::OnKey)
//END_EVENT_TABLE()

wxIrrlicht::wxIrrlicht(wxWindow* parent, wxWindowID id, bool bs, const wxPoint& pos, const wxSize& size, long style, const wxString& name)
	: wxControl(parent, id, pos, size, style, wxDefaultValidator, name),
	m_pDevice(0),
    m_pDriver(0),
    m_pSceneManager(0),
    m_pGuiEnvironment(0),
    m_pCameraNode(0),
    m_Timer(this, ID_IRR_TIMER),
    m_pFPSText(0),
	m_showFPS(bs) {
		//this->SetFocus();
		//this->SetClientSize(size);
		//this->CaptureMouse();
	    SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	    parent_window = parent;
	    grid_color = irr::video::SColor(255, 100, 100, 100);
	    grid_size = 2500;
	    grid_spacing = 50;
	    hud_color = irr::video::SColor(255,255,255,255);
}//ctor

wxIrrlicht::~wxIrrlicht() {
	m_pDevice->drop();
}//dtor


void wxIrrlicht::InitIrr(irr::SIrrlichtCreationParameters* init_params) {
    SIrrlichtCreationParameters params;
    params.DriverType = EDT_OPENGL;

    SIrrlichtCreationParameters* actual_params = init_params ? init_params : &params;
    dimension2d<u32> irrSize(parent_window->GetClientSize().GetX(), parent_window->GetClientSize().GetY());
    actual_params->WindowSize = irrSize;

#ifdef __linux__
    wxWindow* renderPanel = parent_window;
    GtkWidget* widget = renderPanel->GetHandle();

    if(!widget)
    {
        wxMessageBox(_("Could not get window handle"));
        return;
    }

    if (!gtk_widget_get_realized(widget)) {
            gtk_widget_realize(widget);
    }


    GdkWindow* gdkWindow = gtk_widget_get_window(widget);

    Window xid;

    if (gdkWindow)
    {
        xid = GDK_WINDOW_XID(gdkWindow);
    }
    else
    {
        wxMessageBox(_("Could not get window ID"));
        return;
    }

    actual_params->WindowId = reinterpret_cast<void*>(xid);

#endif

#ifdef _WIN32
actual_params->WindowId = (HWND)this->GetHandle();
#endif // _WIN32


    m_pDevice = createDeviceEx(*actual_params);

    //SIrrlichtCreationParameters wx_params;
    //wx_params.WindowId = parent_window;
    //wx_params.DeviceType = EIDT_WX;
    //wx_params.DriverType = EDT_OPENGL;

    //dimension2d<u32> irrSize(GetClientSize().GetX(), GetClientSize().GetY());
    //wx_params.WindowSize = irrSize;
    //wxMessageBox(_("testing"));
    //m_pDevice = createDeviceEx(wx_params);
    //wxMessageBox(_("no dice"));


    if (!m_pDevice) {
        throw "Can't create Irrlicht device!";
	}//if

	m_pDriver = m_pDevice->getVideoDriver();
	m_pSceneManager = m_pDevice->getSceneManager();
	m_pGuiEnvironment = m_pDevice->getGUIEnvironment();
    m_pDriver->OnResize(irrSize);

    parent_window->Connect( wxEVT_SIZE, wxSizeEventHandler( wxIrrlicht::OnParentSize ), NULL, this );

    Bind(wxEVT_TIMER, &wxIrrlicht::OnTimer, this);

    Bind(wxEVT_SIZE, &wxIrrlicht::OnSize, this);

    Bind(wxEVT_PAINT, &wxIrrlicht::OnPaint, this);

    Bind(wxEVT_ERASE_BACKGROUND, &wxIrrlicht::OnEraseBackground, this);


    //Bind(wxEVT_MOUSEWHEEL, &wxIrrlicht::OnMouse, this);

    Bind(wxEVT_KEY_DOWN, &wxIrrlicht::OnKey, this);
    Bind(wxEVT_KEY_UP, &wxIrrlicht::OnKey, this);

    m_forceWindowActive = true;
    rendering = false;
    Refresh();

    select_group_flag = false;

	back_buffer = m_pDriver->addRenderTargetTexture(irr::core::dimension2d<irr::u32>((irr::u32)2048, (irr::u32)2048), "rt", ECF_A8R8G8B8);

	camera[0].camera.init(m_pSceneManager, 0, 0, 0);
	camera[0].texture = m_pDriver->addRenderTargetTexture(irr::core::dimension2d<irr::u32>((irr::u32)2048, (irr::u32)2048), "rt", ECF_A8R8G8B8);
	camera[0].ui_layer = m_pDriver->addRenderTargetTexture(irr::core::dimension2d<irr::u32>((irr::u32)2048, (irr::u32)2048), "rt", ECF_A8R8G8B8);
	camera[0].pov = RC_CAMERA_VIEW_FRONT;
	m_pDriver->makeColorKeyTexture(camera[0].ui_layer, irr::video::SColor(0,0,0,0));

	camera[0].gridSceneNode = NULL;
	camera[0].gridSceneNode = new CGridSceneNode(m_pSceneManager->getRootSceneNode(), m_pSceneManager, -1, 1);
	if(camera[0].gridSceneNode)
	{
		camera[0].gridSceneNode->setGridsSize( irr::core::dimension2df(grid_size, grid_size));
		camera[0].gridSceneNode->getGrid(0).setSpacing( grid_spacing );
		camera[0].gridSceneNode->getGrid(0).setGridColor(grid_color);
	}
	else
		wxMessageBox(_("Error: Scene Camera could not be created"));

	camera[1].camera.init(m_pSceneManager, 0, 0, 0);
	camera[1].texture = m_pDriver->addRenderTargetTexture(irr::core::dimension2d<irr::u32>((irr::u32)2048, (irr::u32)2048), "rt", ECF_A8R8G8B8);
	camera[1].ui_layer = m_pDriver->addRenderTargetTexture(irr::core::dimension2d<irr::u32>((irr::u32)2048, (irr::u32)2048), "rt", ECF_A8R8G8B8);
	camera[1].pov = RC_CAMERA_VIEW_RIGHT;
	m_pDriver->makeColorKeyTexture(camera[1].ui_layer, irr::video::SColor(0,0,0,0));

	camera[1].gridSceneNode = NULL;
	camera[1].gridSceneNode = new CGridSceneNode(m_pSceneManager->getRootSceneNode(), m_pSceneManager, -1, 1);
	if(camera[0].gridSceneNode)
	{
		camera[1].gridSceneNode->setGridsSize( irr::core::dimension2df(grid_size, grid_size));
		camera[1].gridSceneNode->getGrid(0).setSpacing( grid_spacing );
		camera[1].gridSceneNode->getGrid(0).setGridColor(grid_color);
	}
	else
		wxMessageBox(_("Error: Scene Camera could not be created"));

	camera[2].camera.init(m_pSceneManager, 0, 0, 0);
	camera[2].texture = m_pDriver->addRenderTargetTexture(irr::core::dimension2d<irr::u32>((irr::u32)2048, (irr::u32)2048), "rt", ECF_A8R8G8B8);
	camera[2].ui_layer = m_pDriver->addRenderTargetTexture(irr::core::dimension2d<irr::u32>((irr::u32)2048, (irr::u32)2048), "rt", ECF_A8R8G8B8);
	camera[2].pov = RC_CAMERA_VIEW_TOP;
	m_pDriver->makeColorKeyTexture(camera[2].ui_layer, irr::video::SColor(0,0,0,0));

	camera[2].gridSceneNode = NULL;
	camera[2].gridSceneNode = new CGridSceneNode(m_pSceneManager->getRootSceneNode(), m_pSceneManager, -1, 1);
	if(camera[2].gridSceneNode)
	{
		camera[2].gridSceneNode->setGridsSize( irr::core::dimension2df(grid_size, grid_size));
		camera[2].gridSceneNode->getGrid(0).setSpacing( grid_spacing );
		camera[2].gridSceneNode->getGrid(0).setGridColor(grid_color);
	}
	else
		wxMessageBox(_("Error: Scene Camera could not be created"));

	camera[3].camera.init(m_pSceneManager, 0, 0, 0);
	camera[3].texture = m_pDriver->addRenderTargetTexture(irr::core::dimension2d<irr::u32>((irr::u32)2048, (irr::u32)2048), "rt", ECF_A8R8G8B8);
	camera[3].ui_layer = m_pDriver->addRenderTargetTexture(irr::core::dimension2d<irr::u32>((irr::u32)2048, (irr::u32)2048), "rt", ECF_A8R8G8B8);
	camera[3].pov = RC_CAMERA_VIEW_PERSPECTIVE;
	m_pDriver->makeColorKeyTexture(camera[3].ui_layer, irr::video::SColor(0,0,0,0));

	camera[3].gridSceneNode = NULL;
	camera[3].gridSceneNode = new CGridSceneNode(m_pSceneManager->getRootSceneNode(), m_pSceneManager, -1, 1);
	if(camera[3].gridSceneNode)
	{
		camera[3].gridSceneNode->setGridsSize( irr::core::dimension2df(grid_size, grid_size));
		camera[3].gridSceneNode->getGrid(0).setSpacing( grid_spacing );
		camera[3].gridSceneNode->getGrid(0).setGridColor(grid_color);
	}
	else
		wxMessageBox(_("Error: Scene Camera could not be created"));

	num_views = 4;
	SetCameraViewParam();

	ortho_near = 1.0f;
	ortho_far = 5000.0f;
	ortho_width = 2000.0f;
	ortho_height = 1200.0f;
	ortho_matrix.buildProjectionMatrixOrthoLH(ortho_width,ortho_height,ortho_near,ortho_far);

	perspective_near = 1.0000000;
	perspective_far = 5000.0000;
	perspective_fov_radians = 1.2566371;
	perspective_aspect = 1.3333334;
	perspective_matrix = camera[0].camera.camera->getProjectionMatrix();
	perspective_matrix.buildProjectionMatrixPerspectiveFovLH(perspective_fov_radians, perspective_aspect, perspective_near, perspective_far);

	view2D_texture = NULL;

	m_init = true;

	wxString editor_path = wxStandardPaths::Get().GetExecutablePath();
	wxFileName font_fname(editor_path);
	font_fname.AppendDir(_("font"));
	font_fname.SetFullName(_("FreeMono.ttf"));

	ui_font1 = irr_LoadFont(font_fname.GetAbsolutePath().ToStdString(), 24);
	ui_font2 = irr_LoadFont(font_fname.GetAbsolutePath().ToStdString(), 16);


	wxFileName icon_fname(editor_path);
	icon_fname.AppendDir(_("icons"));

	icon_fname.SetFullName(_("x_transform_tool.png"));
	transform_tool_widget.x_texture = m_pDriver->getTexture(icon_fname.GetAbsolutePath().ToStdString().c_str());

	icon_fname.SetFullName(_("y_transform_tool.png"));
	transform_tool_widget.y_texture = m_pDriver->getTexture(icon_fname.GetAbsolutePath().ToStdString().c_str());

	icon_fname.SetFullName(_("z_transform_tool.png"));
	transform_tool_widget.z_texture = m_pDriver->getTexture(icon_fname.GetAbsolutePath().ToStdString().c_str());

	transform_tool_widget.widget_size = 32;
	transform_tool_widget.image_size = 64;


	// Arrow
    terrain_arrow = m_pSceneManager->addAnimatedMeshSceneNode(m_pSceneManager->addArrowMesh("arrow",
                                                        SColor(255, 255, 0, 0), SColor(255, 0, 255, 0)), NULL);
    terrain_arrow->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    terrain_arrow->setScale(vector3df(20,20,20));
    terrain_arrow->setRotation(vector3df(0,0,180));

    if(terrain_arrow)
        terrain_arrow->setVisible(false);

    terrainTimer_then = 0;
    terrainTimer_then30 = 0;
    terrainSelector = NULL;
    terrain_actor_index = -1;
    terrain_size = -1;
    terrain_scale.set(1,1,1);

	//wxMessageBox(_("FNT: ") + wxString::Format(_("%d"), active_font));

	//wxMessageBox(_("GS:") + wxString::Format(_("%d"), (int)grid_size) + _(", ") + wxString::Format(_("%d"), (int)grid_spacing) + _(", ") + wxString::Format(_("%d"), (int)grid_color.color));

	if(init_params && (actual_params->DriverType == EDT_BURNINGSVIDEO || actual_params->DriverType == EDT_SOFTWARE))
	{
		force_refresh();
	}

}//InitIrr()

void wxIrrlicht::setDefaultMaterial(irr::scene::ISceneNode* node, irr::video::ITexture* texture)
{
	node->getMaterial(0).MaterialType = irr::video::EMT_ONETEXTURE_BLEND;
	node->getMaterial(0).Lighting = false;
	node->getMaterial(0).ZWriteEnable = irr::video::EZW_OFF;
	node->getMaterial(0).ZBuffer = false;
	node->getMaterial(0).BackfaceCulling = false;
	node->getMaterial(0).TextureLayer[0].Texture = texture;
	node->getMaterial(0).BlendOperation = irr::video::EBO_ADD;
	node->getMaterial(0).MaterialTypeParam = irr::video::pack_textureBlendFunc(irr::video::EBF_SRC_ALPHA, irr::video::EBF_ONE_MINUS_SRC_ALPHA, irr::video::EMFN_MODULATE_1X, irr::video::EAS_TEXTURE | irr::video::EAS_VERTEX_COLOR);
}

void wxIrrlicht::init_stage_camera()
{
	float ax = 0;
	float ay = 0;
	float az = 0;
	camera[3].camera.getPosition(ax, ay, az);

	for(int i = 0; i < 4; i++)
	{
		if(camera[i].pov == RC_CAMERA_VIEW_FRONT)
		{
			float ax_front = 0;
			float ay_front = ay;
			float az_front = az + (perspective_far/4);

			irr::core::vector3df cam_pos(ax, ay, az);
			irr::core::vector3df cam_tgt = cam_pos;
			cam_tgt += irr::core::vector3df(0, 0, (perspective_far/4));
			cam_tgt.rotateXZBy(-camera[3].camera.ry, cam_pos);

			ax_front = cam_tgt.X;
			az_front = az - (perspective_far/2);

			camera[i].camera.setPosition(ax_front, ay, az_front);
		}
		else if(camera[i].pov == RC_CAMERA_VIEW_RIGHT)
		{
			float ax_right = ax - (perspective_far/2);
			float az_right = az + (perspective_far/4);

			irr::core::vector3df cam_pos(ax, ay, az);
			irr::core::vector3df cam_tgt = cam_pos;
			cam_tgt += irr::core::vector3df(0, 0, (perspective_far/4));
			cam_tgt.rotateXZBy(camera[3].camera.ry, cam_pos);

			ax_right = cam_tgt.X - (perspective_far/4);
			az_right = cam_tgt.Z;

			camera[i].camera.setPosition(ax_right, ay, az_right);
		}
		else if(camera[i].pov == RC_CAMERA_VIEW_TOP)
		{
			float ax_top = 0;
			float ay_top = ay + (perspective_far/2);
			float az_top = az + (perspective_far/4);

			irr::core::vector3df cam_pos(ax, ay, az);
			irr::core::vector3df cam_tgt = cam_pos;
			cam_tgt += irr::core::vector3df(0, 0, (perspective_far/4));
			cam_tgt.rotateXZBy(-camera[3].camera.ry, cam_pos);

			ax_top = cam_tgt.X;
			az_top = cam_tgt.Z;

			camera[i].camera.setPosition(ax_top, ay_top, az_top);
		}
	}
}

void wxIrrlicht::setGridSize(irr::f32 g_size)
{
	grid_size = g_size;

	for(int i = 0; i < 4; i++)
	{
		camera[i].gridSceneNode->setGridsSize( irr::core::dimension2df(g_size, g_size));
	}
}

void wxIrrlicht::setGridSpacing(irr::f32 g_spacing)
{
	grid_spacing = g_spacing;

	for(int i = 0; i < 4; i++)
	{
		camera[i].gridSceneNode->getGrid(0).setSpacing( g_spacing );
	}
}

void wxIrrlicht::setGridColor(irr::u32 g_color)
{
	grid_color = irr::video::SColor(g_color);

	for(int i = 0; i < 4; i++)
	{
		camera[i].gridSceneNode->getGrid(0).setGridColor(irr::video::SColor(g_color));
	}
}

//void wxIrrlicht::InitIrr(irr::IrrlichtDevice* device) {
//
//    m_pDevice = device;
//
//	m_pDriver = m_pDevice->getVideoDriver();
//	m_pSceneManager = m_pDevice->getSceneManager();
//	m_pGuiEnvironment = m_pDevice->getGUIEnvironment();
//
//	dimension2d<u32> irrSize(GetClientSize().GetX(), GetClientSize().GetY());
//    m_pDriver->OnResize(irrSize);
//
//    parent_window->Connect( wxEVT_SIZE, wxSizeEventHandler( wxIrrlicht::OnParentSize ), NULL, this );
//    m_forceWindowActive = true;
//    rendering = false;
//	Refresh();
//
//	m_init = true;
//
//}//InitIrr()

void wxIrrlicht::SetCameraViewParam()
{
	switch(num_views)
	{
		case 1:
			camera[0].x = 0;
			camera[0].y = 0;
			camera[0].w = parent_window->GetSize().GetWidth();
			camera[0].h = parent_window->GetSize().GetHeight();
			break;

		case 4:
			camera[0].x = 0;
			camera[0].y = 0;
			camera[0].w = parent_window->GetSize().GetWidth()/2;
			camera[0].h = parent_window->GetSize().GetHeight()/2;

			camera[1].x = camera[0].w;
			camera[1].y = 0;
			camera[1].w = parent_window->GetSize().GetWidth()/2;
			camera[1].h = parent_window->GetSize().GetHeight()/2;

			camera[2].x = 0;
			camera[2].y = camera[0].h;
			camera[2].w = parent_window->GetSize().GetWidth()/2;
			camera[2].h = parent_window->GetSize().GetHeight()/2;

			camera[3].x = camera[0].w;
			camera[3].y = camera[0].h;
			camera[3].w = parent_window->GetSize().GetWidth()/2;
			camera[3].h = parent_window->GetSize().GetHeight()/2;
			break;
	}

	for(int i = 0; i < 4; i++)
	{
		switch(camera[i].pov)
		{
			case RC_CAMERA_VIEW_BACK:
			case RC_CAMERA_VIEW_FRONT:
				camera[i].gridSceneNode->setRotation(irr::core::vector3df(90, 0, 0));
				break;

			case RC_CAMERA_VIEW_LEFT:
			case RC_CAMERA_VIEW_RIGHT:
				camera[i].gridSceneNode->setRotation(irr::core::vector3df(0, 0, 90));
				break;

			case RC_CAMERA_VIEW_TOP:
			case RC_CAMERA_VIEW_BOTTOM:
			case RC_CAMERA_VIEW_PERSPECTIVE:
				camera[i].gridSceneNode->setRotation(irr::core::vector3df(0, 0, 0));
				break;
		}
	}
}


void wxIrrlicht::StartRendering(int milliseconds) {
    m_Timer.Start(milliseconds);
}//StartRendering()

void wxIrrlicht::StopRendering(){
    m_Timer.Stop();
}//StopRendering()

void wxIrrlicht::Render() {

    if (rendering) {
        return;
	}//if

	if(!enable_events)
		return;


    if(this->GetScreenRect().Contains( wxGetMousePosition() ))
        m_windowIsActive = true;
    else
        m_windowIsActive = false;

    if(m_forceWindowInActive)
        m_windowIsActive = false;

    if(m_forceWindowActive)
        m_windowIsActive = true;

    m_forceWindowInActive = false;
    m_forceWindowActive = false;

    rendering = true;
    //OnPreRender();
    OnRender();
    //OnPostRender();
    rendering = false;
}//Render()

void wxIrrlicht::OnCreateScene() {
	if (m_showFPS) {
		m_pFPSText = m_pGuiEnvironment->addStaticText(L"FPS: 0", rect<s32>(1, 1, 50, 10), false);
		m_pFPSText->setOverrideColor(SColor(255,255,255,255));
	}//if
}//OnCreateScene()

void wxIrrlicht::OnRender() {
        // draw everything here
        if(!m_init)
			return;

		m_pDriver->beginScene(true, true, SColor(255,170,170,170));

		camera[0].gridSceneNode->setVisible(false);
		camera[1].gridSceneNode->setVisible(false);
		camera[2].gridSceneNode->setVisible(false);
		camera[3].gridSceneNode->setVisible(false);

		if(window_type == RC_IRR_WINDOW_VIEW2D)
			num_views = 1; //Just to be safe

		irr::scene::ISceneCollisionManager* collman = m_pSceneManager->getSceneCollisionManager();

		bool draw_axis_widget = false;
		if( selected_actors.size() > 0)
		{
			switch(stage_edit_tool)
			{
				case RC_EDIT_TOOL_MOVE:
				case RC_EDIT_TOOL_ROTATE:
				case RC_EDIT_TOOL_SCALE:
					draw_axis_widget = true;

					if(selected_actors[0].node)
						transform_tool_widget.pos = selected_actors[0].node->getAbsolutePosition();

					setTransformToolBox();
				break;
			}
		}

		//std::cout << "NUM_VIEWS = " << num_views << std::endl;

		for(int i = 0; i < num_views; i++)
		{
			if(window_type == RC_IRR_WINDOW_VIEW2D)
			{
				m_pDriver->setRenderTarget(camera[i].texture, true, true, irr::video::SColor(255,0,0,0));

				m_pSceneManager->setActiveCamera(camera[i].camera.camera);
				camera[i].camera.update();

				//draw texture
				if(view2D_texture)
				{
					irr::core::dimension2d<irr::u32> texture_size = view2D_texture->getSize();
					float fit_factor = 1;

					if(camera[i].h < camera[i].w)
					{
						fit_factor = (float)camera[i].h / (float)(texture_size.Height < 1 ? 1 : texture_size.Height);
					}
					else
					{
					    fit_factor = (float)camera[i].w / (float)(texture_size.Width < 1 ? 1 : texture_size.Width);
					}

					fit_factor = (fit_factor <= 0 ? 1 : fit_factor);

					irr::core::rect<irr::s32> src( irr::core::position2di(0, 0), texture_size );
					irr::core::rect<irr::s32> dst( irr::core::position2di(0, 0), irr::core::dimension2d<irr::s32>((irr::s32)((float)texture_size.Width * fit_factor), (irr::s32)((float)texture_size.Height * fit_factor)) );
					m_pDriver->draw2DImage(view2D_texture, dst, src);
				}

				m_pDriver->setViewPort(irr::core::rect<irr::s32>(0,0,camera[i].w, camera[i].h));
				m_pSceneManager->drawAll();

			}
			else
			{
				if(window_type != RC_IRR_WINDOW_ANIMATION)
					camera[i].gridSceneNode->setVisible(grid_visible);

				m_pDriver->setRenderTarget(camera[i].ui_layer, true, true, irr::video::SColor(0));


				if(window_type == RC_IRR_WINDOW_NAV3D)
				{
					ortho_matrix.buildProjectionMatrixOrthoLH(ortho_width,ortho_height,ortho_near,ortho_far);
					perspective_matrix.buildProjectionMatrixPerspectiveFovLH(perspective_fov_radians, perspective_aspect, perspective_near, perspective_far);

					switch(camera[i].pov)
					{
						case RC_CAMERA_VIEW_FRONT:
						{
							irr_SetFont(ui_font1);
							irr_DrawText("Front", 10, 10, hud_color, i);
							camera[i].camera.camera->setProjectionMatrix(ortho_matrix);

							camera[i].gridSceneNode->setGridsSize(irr::core::dimension2df((float)(ortho_width*2), (float)(ortho_height*2)));

							float gcx = (float)((int)(camera[i].camera.x / grid_spacing)*grid_spacing);
							float gcy = (float)((int)(camera[i].camera.y / grid_spacing)*grid_spacing);
							float gcz = (float)camera[i].camera.z;
							//std::cout << "Camera: " << camera[i].camera.x << ", " << camera[i].camera.y << " -> " << gcx << ", " << gcy << "  ortho: " << ortho_width << ", " << ortho_height << "  g_spacing: " << grid_spacing << std::endl;
							camera[i].gridSceneNode->setPosition(irr::core::vector3df(gcx, gcy, gcz));

							if(draw_axis_widget)
							{
								irr::u32 image_size = transform_tool_widget.image_size;
								m_pDriver->draw2DImage(transform_tool_widget.x_texture, transform_tool_widget.view_box_x[i], irr::core::recti(irr::core::vector2di(0,0), irr::core::dimension2du(image_size, image_size)));
								m_pDriver->draw2DImage(transform_tool_widget.y_texture, transform_tool_widget.view_box_y[i], irr::core::recti(irr::core::vector2di(0,0), irr::core::dimension2du(image_size, image_size)));
							}
						}
						break;

						case RC_CAMERA_VIEW_RIGHT:
						{
							irr_SetFont(ui_font1);
							irr_DrawText("Right", 10, 10, hud_color, i);
							camera[i].camera.camera->setProjectionMatrix(ortho_matrix);

							camera[i].gridSceneNode->setGridsSize(irr::core::dimension2df((float)(ortho_width*2), (float)(ortho_height*2)));

							float gcx = (float)camera[i].camera.x;
							float gcy = (float)((int)(camera[i].camera.y / grid_spacing)*grid_spacing);
							float gcz = (float)((int)(camera[i].camera.z / grid_spacing)*grid_spacing);
							//std::cout << "Camera: " << camera[i].camera.x << ", " << camera[i].camera.y << " -> " << gcx << ", " << gcy << "  ortho: " << ortho_width << ", " << ortho_height << "  g_spacing: " << grid_spacing << std::endl;
							camera[i].gridSceneNode->setPosition(irr::core::vector3df(gcx, gcy, gcz));

							if(draw_axis_widget)
							{
								irr::u32 image_size = transform_tool_widget.image_size;
								m_pDriver->draw2DImage(transform_tool_widget.z_texture, transform_tool_widget.view_box_z[i], irr::core::recti(irr::core::vector2di(0,0), irr::core::dimension2du(image_size, image_size)));
								m_pDriver->draw2DImage(transform_tool_widget.y_texture, transform_tool_widget.view_box_y[i], irr::core::recti(irr::core::vector2di(0,0), irr::core::dimension2du(image_size, image_size)));
							}
						}
						break;

						case RC_CAMERA_VIEW_TOP:
						{
							irr_SetFont(ui_font1);
							irr_DrawText("Top", 10, 10, hud_color, i);
							camera[i].camera.camera->setProjectionMatrix(ortho_matrix);

							float gcx = (float)((int)(camera[i].camera.x / grid_spacing)*grid_spacing);
							float gcy = (float)camera[i].camera.y;
							float gcz = (float)((int)(camera[i].camera.z / grid_spacing)*grid_spacing);

							camera[i].gridSceneNode->setPosition(irr::core::vector3df(gcx, gcy, gcz));

							if(draw_axis_widget)
							{
								irr::u32 image_size = transform_tool_widget.image_size;
								m_pDriver->draw2DImage(transform_tool_widget.x_texture, transform_tool_widget.view_box_x[i], irr::core::recti(irr::core::vector2di(0,0), irr::core::dimension2du(image_size, image_size)));
								m_pDriver->draw2DImage(transform_tool_widget.z_texture, transform_tool_widget.view_box_z[i], irr::core::recti(irr::core::vector2di(0,0), irr::core::dimension2du(image_size, image_size)));
							}
						}
						break;

						case RC_CAMERA_VIEW_PERSPECTIVE:
						{
							irr_SetFont(ui_font1);
							irr_DrawText("Perspective", 10, 10, hud_color, i);
							camera[i].camera.camera->setProjectionMatrix(perspective_matrix);

							if(draw_axis_widget)
							{
								irr::u32 image_size = transform_tool_widget.image_size;

								m_pDriver->draw2DImage(transform_tool_widget.x_texture, transform_tool_widget.view_box_x[i], irr::core::recti(irr::core::vector2di(0,0), irr::core::dimension2du(image_size, image_size)));
								m_pDriver->draw2DImage(transform_tool_widget.y_texture, transform_tool_widget.view_box_y[i], irr::core::recti(irr::core::vector2di(0,0), irr::core::dimension2du(image_size, image_size)));
								m_pDriver->draw2DImage(transform_tool_widget.z_texture, transform_tool_widget.view_box_z[i], irr::core::recti(irr::core::vector2di(0,0), irr::core::dimension2du(image_size, image_size)));
							}
						}
						break;
					}
				}

				if((show_camera_pos || show_camera_rot) && window_type == RC_IRR_WINDOW_NAV3D)
				{
					irr_SetFont(ui_font2);
					wxString pos_str = _("POS: ") + wxString::Format(_("%d"), (int)camera[i].camera.x) + _(", ") +
													wxString::Format(_("%d"), (int)camera[i].camera.y) + _(", ") +
													wxString::Format(_("%d"), (int)camera[i].camera.z);

					wxString rot_str = _("ROT: ") + wxString::Format(_("%d"), (int)( ((int)camera[i].camera.rx) % 360)) + _(", ") +
													wxString::Format(_("%d"), (int)( ((int)camera[i].camera.ry) % 360)) + _(", ") +
													wxString::Format(_("%d"), (int)( ((int)camera[i].camera.rz) % 360));
					int c_info_y = 10;

					if(show_camera_pos)
					{
						irr_DrawText(pos_str.ToStdString(), camera[i].w-200, c_info_y, hud_color, i);
						c_info_y+= 20;
					}

					if(show_camera_rot)
						irr_DrawText(rot_str.ToStdString(), camera[i].w-200, c_info_y, hud_color, i);
				}

				m_pDriver->setRenderTarget(camera[i].texture, true, true, irr::video::SColor(255,170,170,170));


				m_pSceneManager->setActiveCamera(camera[i].camera.camera);
				camera[i].camera.update();

				m_pDriver->setViewPort(irr::core::rect<irr::s32>(0,0,camera[i].w, camera[i].h));

				m_pSceneManager->drawAll();

				for(int sn = 0; sn < selected_actors.size(); sn++)
				{
					if(!selected_actors[sn].node)
						continue;

					irr::core::aabbox3df abox = selected_actors[sn].node->getBoundingBox();

					if(selected_actors[sn].use_override_size)
						abox = selected_actors[sn].override_box;

						irr::core::vector3df pos = selected_actors[sn].node->getAbsolutePosition();
						irr::core::vector3df scale = selected_actors[sn].node->getScale();
						irr::core::vector3df min_v(pos - ( (abox.getExtent()*scale) / 2));
						irr::core::vector3df max_v(pos + ( (abox.getExtent()*scale) / 2));
						irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(min_v, camera[i].camera.camera);
						irr::core::vector2d<irr::s32> v2 = collman->getScreenCoordinatesFrom3DPosition(max_v, camera[i].camera.camera);

						selected_actors[sn].v1[i] = irr::core::vector2d<irr::s32>( (v1.X < v2.X ? v1.X : v2.X),
																						   (v1.Y < v2.Y ? v1.Y : v2.Y) );

						selected_actors[sn].v2[i] = irr::core::vector2d<irr::s32>( (v1.X > v2.X ? v1.X : v2.X),
																						   (v1.Y > v2.Y ? v1.Y : v2.Y) );

						v1 = selected_actors[sn].v1[i];
						v2 = selected_actors[sn].v2[i];

						irr::core::rect<irr::s32> actor_highlight(selected_actors[sn].v1[i], selected_actors[sn].v2[i]);
					m_pDriver->draw2DRectangleOutline(actor_highlight, irr::video::SColor(255, 220, 0, 0));

					//m_pDriver->draw2DLine(irr::core::vector2di(0, 0), irr::core::vector2di(200, 200));
				}

				if(stage_edit_tool == RC_EDIT_TOOL_BOXSELECT && i == box_select_view)
				{
					//irr::core::recti r( irr::core::vector2di(670, 370), irr::core::vector2di(690, 390) );
					//m_pDriver->draw2DRectangleOutline(r);
					irr::core::vector2di v1 = box_select_shape.UpperLeftCorner;
					irr::core::vector2di v2 = box_select_shape.LowerRightCorner;

					v1.set( v1.X* (camera[i].texture->getSize().Width/ camera[i].w), v1.Y * (camera[i].texture->getSize().Height / camera[i].h) );
					v2.set( v2.X* (camera[i].texture->getSize().Width/ camera[i].w), v2.Y * (camera[i].texture->getSize().Height / camera[i].h) );

					//box_select_shape = irr::core::recti(v1, v2);

					//m_pDriver->draw2DRectangleOutline(box_select_shape);
				}
				else if(stage_edit_tool == RC_EDIT_TOOL_MOVE && selected_actors.size() > 0 && show_axis_lines)
				{
					irr::core::vector3df vx(1000, 0, 0);
					irr::core::vector3df vy(0, 1000, 0);
					irr::core::vector3df vz(0, 0, 1000);
					drawLine(transform_tool_widget.pos-vx, transform_tool_widget.pos+vx, irr::video::SColor(255, 255, 0, 0));
					drawLine(transform_tool_widget.pos-vy, transform_tool_widget.pos+vy, irr::video::SColor(255, 0, 255, 0));
					drawLine(transform_tool_widget.pos-vz, transform_tool_widget.pos+vz, irr::video::SColor(255, 0, 0, 255));
				}
				else if(stage_edit_tool == RC_EDIT_TOOL_ROTATE && selected_actors.size() > 0 && show_axis_rings)
				{
					if(selected_actors[0].node)
					{
						//irr::core::vector3df direction = getDirectionVector(transform_tool_widget.pos, selected_actors[0].node->getRotation());
						drawCircle(transform_tool_widget.pos, 50, selected_actors[0].node->getRotation(), irr::core::vector3df(1,0,0), irr::video::SColor(255, 255, 0, 0));
						drawCircle(transform_tool_widget.pos, 50, irr::core::vector3df(0, 0, 1), irr::core::vector3df(0,1,0), irr::video::SColor(255, 0, 255, 0));
						drawCircle(transform_tool_widget.pos, 50, selected_actors[0].node->getRotation(), irr::core::vector3df(0,0,1), irr::video::SColor(255, 0, 0, 255));
					}
				}

				drawAllLightInfluences();

				camera[i].gridSceneNode->setVisible(false);
			}
		}

		m_pDriver->setRenderTarget(back_buffer, true, true);

		bool showOutline = (num_views == 4);

		for(int i = 0; i < num_views; i++)
		{
			irr::core::rect<irr::s32> src( irr::core::position2di(0, 0), irr::core::dimension2d<irr::s32>(camera[i].w, camera[i].h) );
			irr::core::rect<irr::s32> dest( irr::core::position2di(camera[i].x, camera[i].y), irr::core::dimension2d<irr::s32>(camera[i].w, camera[i].h) );
			m_pDriver->draw2DImage(camera[i].texture, dest, src);
			m_pDriver->draw2DImage(camera[i].ui_layer, dest, src, 0, 0, true);

			if(stage_edit_tool == RC_EDIT_TOOL_BOXSELECT && i == box_select_view && box_select_draw_flag)
			{
				//irr::core::recti r( irr::core::vector2di(670, 370), irr::core::vector2di(690, 390) );
				//m_pDriver->draw2DRectangleOutline(r);
				irr::core::vector2di v1 = box_select_shape.UpperLeftCorner;
				irr::core::vector2di v2 = box_select_shape.LowerRightCorner;

				if(v1.X < camera[i].x)
					v1.X = camera[i].x;

				if(v1.Y < camera[i].y)
					v1.Y = camera[i].y;

				if(v1.X >= (camera[i].x + camera[i].w))
					v1.X = (camera[i].x + camera[i].w);

				if(v1.Y >= (camera[i].y + camera[i].h))
					v1.Y = (camera[i].y + camera[i].h);

				box_select_shape = irr::core::recti(v1, v2);

				m_pDriver->draw2DRectangleOutline(box_select_shape);
			}

			m_pDriver->draw2DRectangleOutline( irr::core::recti( irr::core::position2di(camera[i].x, camera[i].y), irr::core::dimension2du(camera[i].w, camera[i].h) ), irr::video::SColor(255, 40, 40, 40) );
		}

        m_pDriver->setRenderTarget(0);

        irr::core::recti bb_rect( irr::core::position2di(0, 0), irr::core::dimension2du(this->GetSize().GetWidth(), this->GetSize().GetHeight()) );
        m_pDriver->draw2DImage(back_buffer, bb_rect, bb_rect );


        //m_pDriver->beginScene(true, true, SColor(255,170,170,170));
        //m_pSceneManager->drawAll();
        //m_pGuiEnvironment->drawAll();
        m_pDriver->endScene();

        Refresh();

}//OnRender()

void wxIrrlicht::OnPostRender() {

    if (m_pFPSText && m_showFPS) {
        int fps = m_pDriver->getFPS();

        static int lastFPS = 0;
        if (lastFPS != fps) {
            core::stringw str = L"FPS: ";
            str += fps;

            m_pFPSText->setText(str.c_str());
            lastFPS = fps;
        }//if
    }//if
}//OnPostRender()

void wxIrrlicht::OnPaint(wxPaintEvent& event){
    Render();
    wxPaintDC paint_dc(this);

}//OnPaint()

void wxIrrlicht::OnParentSize(wxSizeEvent& event)
{
	if(!m_init)
		return;

    if (!m_pDriver) {
        return;
	}//if

    s32 w;
    s32 h;

    wxWindow* parent = (wxWindow*)event.GetEventObject();

    parent->GetClientSize(&w, &h);
    this->SetClientSize(w, h);

    dimension2d<u32> size(w, h);
    m_pDriver->OnResize(size);

    if (m_pCameraNode) {
        m_pCameraNode->setAspectRatio((float)w / (float)h);
	}//if

	m_pDevice->setWindowSize(irr::core::dimension2d<irr::u32>((irr::u32)w,(irr::u32)h));
	SetCameraViewParam();

	m_forceWindowActive = true;
	parent->Refresh();
	Refresh();

	//wxMessageBox(_("REFRESH"));
}

void wxIrrlicht::OnSize(wxSizeEvent& event) {
    if (!m_pDriver) {
        return;
	}//if

    return;
}//OnSize

void wxIrrlicht::drawAllLightInfluences()
{
	for(int i = 0; i < selected_actors.size(); i++)
	{
		if(!selected_actors[i].node)
			continue;

		if(selected_actors[i].isLight && selected_actors[i].node->isVisible())
		{
			irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)selected_actors[i].node;

			switch((int)node->getLightType())
			{
				case (int)(irr::video::ELT_SPOT):
				{
					//position, direction, and cone
					irr::core::vector3df pos_v = node->getAbsolutePosition();
					irr::core::vector3df dir_v = node->getLightData().Direction;
					irr::f32 outer_cone = node->getLightData().OuterCone;
					irr::f32 inner_cone = node->getLightData().InnerCone;

					irr::core::matrix4 tmat;
					tmat.setTranslation(irr::core::vector3df(0,0,0));
					tmat.setRotationDegrees(dir_v.getHorizontalAngle());

					irr::f32 line_length = 1000;

					irr::core::vector3df target = pos_v + (dir_v.normalize() * line_length);

					irr::core::vector3df inner_limit1 = irr::core::vector3df(0, 0, line_length);
					inner_limit1.rotateXZBy(inner_cone, irr::core::vector3df(0, 0, 0));
					tmat.transformVect(inner_limit1);
					inner_limit1 += pos_v;

					irr::core::vector3df inner_limit2 = irr::core::vector3df(0, 0, line_length);
					inner_limit2.rotateXZBy(-1*(inner_cone), irr::core::vector3df(0, 0, 0));
					tmat.transformVect(inner_limit2);
					inner_limit2 += pos_v;

					irr::core::vector3df inner_limit3 = irr::core::vector3df(0, 0, line_length);
					inner_limit3.rotateYZBy(inner_cone, irr::core::vector3df(0, 0, 0));
					tmat.transformVect(inner_limit3);
					inner_limit3 += pos_v;

					irr::core::vector3df inner_limit4 = irr::core::vector3df(0, 0, line_length);
					inner_limit4.rotateYZBy(-1*(inner_cone), irr::core::vector3df(0, 0, 0));
					tmat.transformVect(inner_limit4);
					inner_limit4 += pos_v;

					irr::core::vector3df outer_limit1 = irr::core::vector3df(0, 0, line_length);
					outer_limit1.rotateXZBy(outer_cone, irr::core::vector3df(0, 0, 0));
					tmat.transformVect(outer_limit1);
					outer_limit1 += pos_v;

					irr::core::vector3df outer_limit2 = irr::core::vector3df(0, 0, line_length);
					outer_limit2.rotateXZBy(-1*(outer_cone), irr::core::vector3df(0, 0, 0));
					tmat.transformVect(outer_limit2);
					outer_limit2 += pos_v;

					irr::core::vector3df outer_limit3 = irr::core::vector3df(0, 0, line_length);
					outer_limit3.rotateYZBy(outer_cone, irr::core::vector3df(0, 0, 0));
					tmat.transformVect(outer_limit3);
					outer_limit3 += pos_v;

					irr::core::vector3df outer_limit4 = irr::core::vector3df(0, 0, line_length);
					outer_limit4.rotateYZBy(-1*(outer_cone), irr::core::vector3df(0, 0, 0));
					tmat.transformVect(outer_limit4);
					outer_limit4 += pos_v;

					//irr::scene::IGeometryCreator* gc = m_pSceneManager->getGeometryCreator();

					drawLine(pos_v, target, irr::video::SColor(255, 255, 255, 255));

					drawLine(pos_v, inner_limit1, irr::video::SColor(255, 255, 255, 0));
					drawLine(pos_v, inner_limit2, irr::video::SColor(255, 255, 255, 0));
					drawLine(pos_v, inner_limit3, irr::video::SColor(255, 255, 255, 0));
					drawLine(pos_v, inner_limit4, irr::video::SColor(255, 255, 255, 0));

					drawLine(pos_v, outer_limit1, irr::video::SColor(255, 255, 181, 0));
					drawLine(pos_v, outer_limit2, irr::video::SColor(255, 255, 181, 0));
					drawLine(pos_v, outer_limit3, irr::video::SColor(255, 255, 181, 0));
					drawLine(pos_v, outer_limit4, irr::video::SColor(255, 255, 181, 0));
				}
				break;

				case (int)(irr::video::ELT_POINT):
				{
					//position, radius
					irr::core::vector3df pos_v = node->getAbsolutePosition();
					irr::f32 radius = node->getLightData().Radius;

					drawCircle(pos_v, radius, irr::core::vector3df(0,0,0), irr::core::vector3df(1,0,0), irr::video::SColor(255,255,255,0));
					drawCircle(pos_v, radius, irr::core::vector3df(0,0,0), irr::core::vector3df(0,1,0), irr::video::SColor(255,255,255,0));
					drawCircle(pos_v, radius, irr::core::vector3df(0,0,0), irr::core::vector3df(0,0,1), irr::video::SColor(255,255,255,0));
				}
				break;

				case (int)(irr::video::ELT_DIRECTIONAL):
				{
					//position, direction, and cone
					irr::core::vector3df pos_v = node->getAbsolutePosition();
					irr::core::vector3df dir_v = node->getLightData().Direction;

					irr::core::matrix4 tmat;
					tmat.setTranslation(irr::core::vector3df(0,0,0));
					tmat.setRotationDegrees(dir_v.getHorizontalAngle());

					irr::f32 line_length = 1000;

					irr::core::vector3df target = pos_v + (dir_v.normalize() * line_length);

					drawLine(pos_v, target, irr::video::SColor(255, 255, 255, 255));
				}
				break;
			}
		}
	}
}

void wxIrrlicht::OnTimer(wxTimerEvent& event) {
	if(!m_init)
		return;

	if(!enable_events)
		return;

    m_pDevice->getTimer()->tick();

    if(window_type != RC_IRR_WINDOW_VIEW2D)
	{
		OnUpdate();
	}

    #ifdef _WIN32
	m_forceWindowActive = true;
	//parent->Refresh();
	Refresh();
	#endif // _WIN32
}

void wxIrrlicht::OnMouse(wxMouseEvent& event) {
	return;
	if(!m_init)
		return;
    irr::SEvent sevt;

    wxMessageBox(_("CALL") + wxString::Format(_("%d"), event.GetEventType()));

    sevt.EventType = irr::EET_MOUSE_INPUT_EVENT;

    if (event.IsButton()) {
        if (event.LeftDown())
		{
			sevt.MouseInput.Event = irr::EMIE_LMOUSE_PRESSED_DOWN;
			wxMessageBox(_("YOLO"));
		}
        else if (event.LeftUp())
            sevt.MouseInput.Event = irr::EMIE_LMOUSE_LEFT_UP;
        else if (event.MiddleDown())
            sevt.MouseInput.Event = irr::EMIE_MMOUSE_PRESSED_DOWN;
        else if (event.MiddleUp())
            sevt.MouseInput.Event = irr::EMIE_MMOUSE_LEFT_UP;
        else if (event.RightDown())
            sevt.MouseInput.Event = irr::EMIE_RMOUSE_PRESSED_DOWN;
        else if (event.RightUp())
            sevt.MouseInput.Event = irr::EMIE_RMOUSE_LEFT_UP;
    }//if

    else if (event.GetWheelRotation() != 0) {
        sevt.MouseInput.Wheel = (float)event.GetWheelRotation();
        sevt.MouseInput.Event = irr::EMIE_MOUSE_WHEEL;
    }//else if

    else if (event.Moving() || event.Dragging()) {
		sevt.MouseInput.Event = irr::EMIE_MOUSE_MOVED;
	}//else if

    sevt.MouseInput.X = event.GetX();
    sevt.MouseInput.Y = event.GetY();

    m_pDevice->postEventFromUser(sevt);

    event.Skip();
}//OnMouse()

void wxIrrlicht::OnKey(wxKeyEvent& event) {
	if(!m_init)
		return;

    irr::SEvent sevt;

    //wxMessageBox(_("KEY EVENT: ") + wxString::Format(_("%d"), event.GetKeyCode()));

    sevt.EventType = irr::EET_KEY_INPUT_EVENT;

    sevt.KeyInput.Key = (irr::EKEY_CODE)event.GetRawKeyCode();
    sevt.KeyInput.PressedDown = event.GetEventType() == wxEVT_KEY_DOWN;

    sevt.KeyInput.Shift = event.ShiftDown();
    sevt.KeyInput.Control = event.CmdDown();
#if wxUSE_UNICODE
    sevt.KeyInput.Char = event.GetUnicodeKey();
#else
    sevt.KeyInput.Char = event.GetKeyCode();
#endif

    m_pDevice->postEventFromUser(sevt);

    if(event.GetKeyCode() == irr::KEY_KEY_W)
	{
		VIEW_KEY_W = sevt.KeyInput.PressedDown;
		//wxMessageBox(_("KEY EVENT2: ") + wxString::Format(_("%d"), VIEW_KEY_W));
	}
	else if(event.GetKeyCode() == irr::KEY_KEY_A)
	{
		VIEW_KEY_A = sevt.KeyInput.PressedDown;
		//wxMessageBox(_("KEY EVENT2: ") + wxString::Format(_("%d"), VIEW_KEY_W));
	}
	else if(event.GetKeyCode() == irr::KEY_KEY_S)
	{
		VIEW_KEY_S = sevt.KeyInput.PressedDown;
		//wxMessageBox(_("KEY EVENT2: ") + wxString::Format(_("%d"), VIEW_KEY_W));
	}
	else if(event.GetKeyCode() == irr::KEY_KEY_D)
	{
		VIEW_KEY_D = sevt.KeyInput.PressedDown;
		//wxMessageBox(_("KEY EVENT2: ") + wxString::Format(_("%d"), VIEW_KEY_W));
	}
	else if(event.GetKeyCode() == irr::KEY_KEY_R)
	{
		VIEW_KEY_R = sevt.KeyInput.PressedDown;
		//wxMessageBox(_("KEY EVENT2: ") + wxString::Format(_("%d"), VIEW_KEY_W));
	}
	else if(event.GetKeyCode() == irr::KEY_KEY_F)
	{
		VIEW_KEY_F = sevt.KeyInput.PressedDown;
		//wxMessageBox(_("KEY EVENT2: ") + wxString::Format(_("%d"), VIEW_KEY_W));
	}

    event.Skip();
}//OnKey()


void wxIrrlicht::force_refresh()
{
    if (!m_pDriver) {
        return;
	}//if

    s32 w;
    s32 h;

    wxWindow* parent = parent_window;

    parent->GetClientSize(&w, &h);
    this->SetClientSize(w, h);

    dimension2d<u32> size(w, h);
    m_pDriver->OnResize(size);

    if (m_pCameraNode) {
        m_pCameraNode->setAspectRatio((float)w / (float)h);
	}//if

	m_pDevice->setWindowSize(irr::core::dimension2du((irr::u32)w,(irr::u32)h));

	m_forceWindowActive = true;
	parent->Refresh();
	Refresh();
}

void wxIrrlicht::AnimationPreview_Update()
{
	wxMouseState  mouse_state = wxGetMouseState();

	int px = mouse_state.GetPosition().x - this->GetScreenPosition().x;
	int py = mouse_state.GetPosition().y - this->GetScreenPosition().y;

	int pw = this->GetSize().GetWidth();
	int ph = this->GetSize().GetHeight();


	if(mouse_state.MiddleIsDown())
	{
		if(!(middle_drag_init||left_drag_init||right_drag_init))
		{

			if( px >= 0 && px < pw && py >= 0 && py < ph )
			{
				middle_drag_init = true;
				//this->CaptureMouse();
				this->SetFocusFromKbd();
				//HIDE_CURSOR;
				//this->WarpPointer(px + (pw/2), py + (ph/2));
				drag_start.x = px;// + (pw/2);
				drag_start.y = py;// + (ph/2);
			}
		}
		else if(middle_drag_init)
		{

			int drag_w = pw/2;
			int drag_h = ph/2;

			int delta_x = px - drag_start.x;
			int delta_y = py - drag_start.y;

			irr::core::vector3df cam_pos = camera[0].camera.camera->getAbsolutePosition();
			cam_pos.rotateXZBy(-delta_x, irr::core::vector3df(0,cam_pos.Y,0));
			camera[0].camera.setPosition(cam_pos.X, cam_pos.Y, cam_pos.Z);
			camera[0].camera.setRotation(camera[0].camera.rx, camera[0].camera.ry+delta_x, camera[0].camera.rz);

			irr::f32 cam_angle = camera[0].camera.ry;
			irr::core::vector3df base_pos(camera[0].camera.x, camera[0].camera.y, camera[0].camera.z);
			base_pos.rotateXZBy(cam_angle, irr::core::vector3df(0, camera[0].camera.y, 0));

			irr::core::vector3df obj_pos(0,0,0);
			if(test_material_object)
				obj_pos = test_material_object->getBoundingBox().getCenter();

			irr::f32 heading = getHeading(irr::core::vector2df(base_pos.Z, base_pos.Y), irr::core::vector2df(obj_pos.Z, obj_pos.Y));

			//std::cout << "Heading Info: ca=" << cam_angle << ",  bp=(" << base_pos.X << ", " << base_pos.Y << ", " << base_pos.Z << ")  op=(" << obj_pos.X << ", " << obj_pos.Y << ", " << obj_pos.Z << ")  heading=" << heading << std::endl;

			camera[0].camera.setRotation(-heading, camera[0].camera.ry, camera[0].camera.rz);

			drag_start.x = px;
			drag_start.y = py;
		}
	}
	else if( (!mouse_state.MiddleIsDown()) && middle_drag_init )
	{
		//SHOW_CURSOR;
		//this->ReleaseMouse();
		middle_drag_init = false;
		//wxMessageBox(_("RELEASE"));
	}
}

irr::core::vector3df wxIrrlicht::getNewActorPosition()
{
	irr::core::vector3df pos = camera[active_camera].camera.camera->getAbsolutePosition();

	core::line3d<f32> ray;
	ray.start = pos;
	ray.end = ray.start + (camera[active_camera].camera.camera->getTarget() - ray.start).normalize() * transform_tool_widget.cursor3d_distance;

	return ray.end;
}

void wxIrrlicht::rc_setDriverMaterial()
{
	if(!m_pDriver)
		return;

	irr::video::SMaterial material;
    material.Lighting = false;
    material.ZWriteEnable = irr::video::EZW_OFF;
    material.ZBuffer = false;
    material.BackfaceCulling = false;
    material.TextureLayer[0].Texture = 0;
    //material.TextureLayer[0].BilinearFilter = true;
    material.MaterialTypeParam = irr::video::pack_textureBlendFunc(irr::video::EBF_SRC_ALPHA, irr::video::EBF_ONE_MINUS_SRC_ALPHA, irr::video::EMFN_MODULATE_1X, irr::video::EAS_TEXTURE | irr::video::EAS_VERTEX_COLOR);
    material.BlendOperation = irr::video::EBO_ADD;
    //material.AntiAliasing = rc_anti_alias;

    material.MaterialType = irr::video::EMT_ONETEXTURE_BLEND;

    m_pDriver->setMaterial(material);
}

void wxIrrlicht::drawLine(irr::core::vector3df line_v1, irr::core::vector3df line_v2, irr::video::SColor color)
{
	irr::video::SMaterial m;
	m.Lighting=false;
	m.Thickness = 2;
	m_pDriver->setMaterial(m);
	m_pDriver->setTransform(video::ETS_WORLD, core::matrix4());

    m_pDriver->draw3DLine(line_v1, line_v2, color);

    rc_setDriverMaterial();
}

irr::core::vector3df wxIrrlicht::getDirectionVector(irr::core::vector3df pos, irr::core::vector3df rot)
{
	irr::core::vector3df target = pos + irr::core::vector3df(0, 0, 10);
	target.rotateXZBy(rot.Y, pos);
	target.rotateYZBy(rot.X, pos);
	target.rotateXYBy(rot.Z, pos);

	irr::core::vector3df direction = target - pos;

	return direction;
}

void wxIrrlicht::drawCircle(irr::core::vector3df center, double radius, irr::core::vector3df rotation, irr::core::vector3df c_axis, irr::video::SColor color)
{
    std::vector<vector3df> points;

    int segments = 36;

    double interval = 360/segments;

    irr::core::matrix4 t_mat;
    t_mat.setRotationDegrees(rotation);

    if(c_axis.X != 0)
    {
    	for (int i = 0; i <= segments; i++)
		{
			irr::core::vector3df p = irr::core::vector3df(0, 0, radius);
			p.rotateYZBy(interval*i, irr::core::vector3df(0,0,0));
			t_mat.transformVect(p);

			p += center;
			points.push_back(p);
		}

		irr::core::vector3df p = irr::core::vector3df(0, 0, radius);
		t_mat.transformVect(p);

		p += center;
		points.push_back(p);
    }
    else if(c_axis.Y != 0)
    {
    	for (int i = 0; i <= segments; i++)
		{
			irr::core::vector3df p = irr::core::vector3df(0, 0, radius);
			p.rotateXZBy(interval*i, irr::core::vector3df(0,0,0));
			t_mat.transformVect(p);

			p += center;
			points.push_back(p);
		}

		irr::core::vector3df p = irr::core::vector3df(0, 0, radius);
		t_mat.transformVect(p);

		p += center;
		points.push_back(p);
    }
    else if(c_axis.Z != 0)
	{
		for (int i = 0; i <= segments; i++)
		{
			irr::core::vector3df p = irr::core::vector3df(0, radius, 0);
			p.rotateXYBy(interval*i, irr::core::vector3df(0,0,0));
			t_mat.transformVect(p);

			p += center;
			points.push_back(p);
		}

		irr::core::vector3df p = irr::core::vector3df(0, 0, radius);
		t_mat.transformVect(p);

		p += center;
		points.push_back(p);
	}

	irr::video::SMaterial m;
	m.Lighting=false;
	m.Thickness = 2;
	m_pDriver->setMaterial(m);
	m_pDriver->setTransform(video::ETS_WORLD, core::matrix4());

    for (size_t i = 0; i < points.size() - 2; ++i)
	{
        m_pDriver->draw3DLine(points[i], points[i + 1], color);
    }

    rc_setDriverMaterial();
}

void wxIrrlicht::setTransformToolBox()
{
	irr::scene::ISceneCollisionManager* collman = m_pSceneManager->getSceneCollisionManager();
	int widget_half = transform_tool_widget.widget_size/2;
	irr::core::dimension2du widget_dim(transform_tool_widget.widget_size, transform_tool_widget.widget_size);
	int axis_tool_space = 50;

	for(int i = 0; i < 4; i++)
	{
		switch(camera[i].pov) //box_select_view can be used for every other tool
		{
			case RC_CAMERA_VIEW_FRONT:
			{
				if(stage_edit_tool == RC_EDIT_TOOL_MOVE || stage_edit_tool == RC_EDIT_TOOL_SCALE)
				{
					irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
					transform_tool_widget.view_box_x[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
					transform_tool_widget.view_box_y[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
				}
				else if(stage_edit_tool == RC_EDIT_TOOL_ROTATE)
				{
					irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
					transform_tool_widget.view_box_y[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
					transform_tool_widget.view_box_x[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
				}
			}
			break;

			case RC_CAMERA_VIEW_TOP:
			{
				if(stage_edit_tool == RC_EDIT_TOOL_MOVE || stage_edit_tool == RC_EDIT_TOOL_SCALE)
				{
					irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
					transform_tool_widget.view_box_x[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
					transform_tool_widget.view_box_z[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
				}
				else if(stage_edit_tool == RC_EDIT_TOOL_ROTATE)
				{
					irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
					transform_tool_widget.view_box_z[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
					transform_tool_widget.view_box_x[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
				}
			}
			break;

			case RC_CAMERA_VIEW_RIGHT:
			{
				if(stage_edit_tool == RC_EDIT_TOOL_MOVE || stage_edit_tool == RC_EDIT_TOOL_SCALE)
				{
					irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
					transform_tool_widget.view_box_z[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
					transform_tool_widget.view_box_y[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
				}
				else if(stage_edit_tool == RC_EDIT_TOOL_ROTATE)
				{
					irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
					transform_tool_widget.view_box_y[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
					transform_tool_widget.view_box_z[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
				}
			}
			break;

			case RC_CAMERA_VIEW_PERSPECTIVE:
			{
				if(stage_edit_tool == RC_EDIT_TOOL_MOVE || stage_edit_tool == RC_EDIT_TOOL_SCALE)
				{
					irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
					transform_tool_widget.view_box_x[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
					transform_tool_widget.view_box_y[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
					transform_tool_widget.view_box_z[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -axis_tool_space-widget_half), widget_dim);
				}
				else if(stage_edit_tool == RC_EDIT_TOOL_ROTATE)
				{
					irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
					transform_tool_widget.view_box_y[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
					transform_tool_widget.view_box_x[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
					transform_tool_widget.view_box_z[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -axis_tool_space-widget_half), widget_dim);
				}
			}
			break;
		}
	}
}

irr::core::vector2df wxIrrlicht::GetLineIntersect(double p0_x, double p0_y, double p1_x, double p1_y, double p2_x, double p2_y, double p3_x, double p3_y, bool* has_intersection)
{
	double s1_x = p1_x - p0_x;
	double s1_y = p1_y - p0_y;
    double s2_x = p3_x - p2_x;
	double s2_y = p3_y - p2_y;

	double n = ( (-1 * s2_x) * s1_y + s1_x * s2_y);

	if(n == 0)
		return irr::core::vector2df(0,0);

    double s = ( (-1 * s1_y) * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / n;
    double t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / n;

    double i_x = p0_x + (t * s1_x);
    double i_y = p0_y + (t * s1_y);

    irr::core::vector2df ivec(i_x, i_y);

    if(s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
    	if(has_intersection)
			*has_intersection = true;
        //' Collision detected
        return ivec;
    }

	//' No collision
	if(has_intersection)
		*has_intersection = false;

    return irr::core::vector2df(0,0);
}

float wxIrrlicht::getHeading(irr::core::vector2df a, irr::core::vector2df b)
{
    float PI = 3.1415926535;
    float x = b.X - a.X;
    float y = b.Y - a.Y;
    return std::atan2(y, x) * (180.0 / PI);
}

irr::core::vector2df wxIrrlicht::getRotatedPoint2D(irr::core::vector2df pt, irr::core::vector2df center, irr::f32 angleDeg)
{
	irr::f32 angleRad = irr::core::degToRad(-angleDeg);
	irr::f32 cosAngle = std::cos(angleRad);
	irr::f32 sinAngle = std::sin(angleRad);
	irr::f32 dx = (pt.X-center.X);
	irr::f32 dy = (pt.Y-center.Y);

	irr::core::vector2df v;
	v.X = center.X + (dx*cosAngle-dy*sinAngle);
	v.Y = center.Y + (dx*sinAngle+dy*cosAngle);
	return v;
}


/*==============================================================================
  Raise or lower terrain (selected vertice)
==============================================================================*/
void wxIrrlicht::RaiseTerrainVertex(ITerrainSceneNode* terrain, s32 index, f32 step, bool up)
{
   IMesh* pMesh = terrain->getMesh();

   s32 b;

   for (b=0; b<pMesh->getMeshBufferCount(); ++b)
   {
      IMeshBuffer* pMeshBuffer = pMesh->getMeshBuffer(b);
      // skip mesh buffers that are not the right type
      if (pMeshBuffer->getVertexType() != video::EVT_2TCOORDS) continue;

      video::S3DVertex2TCoords* pVertices = (video::S3DVertex2TCoords*)pMeshBuffer->getVertices();

      pVertices[index].Pos.Y += (up) ? step : -step;

      if(pVertices[index].Pos.Y < 0)
        pVertices[index].Pos.Y = 0;
   }

   // force terrain render buffer to reload
   terrain->setPosition(terrain->getPosition());
}


/*==============================================================================
  Raise or lower terrain (selected vertice)
==============================================================================*/
//-------------
// Function to calculate a point on a cubic Bezier curve
vector3df wxIrrlicht::bezierPoint(const vector3df& p0, const vector3df& p1, const vector3df& p2, const vector3df& p3, float t) {
    float u = 1.0f - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    vector3df p = uuu * p0; // (1-t)^3 * p0
    p += 3 * uu * t * p1;   // 3 * (1-t)^2 * t * p1
    p += 3 * u * tt * p2;   // 3 * (1-t) * t^2 * p2
    p += ttt * p3;          // t^3 * p3

    return p;
}

// Function to draw a Bezier curve
std::vector<irr::core::vector3df> wxIrrlicht::drawBezierCurve(const vector3df& p0, const vector3df& p1, const vector3df& p2, const vector3df& p3, int segments) {
    std::vector<vector3df> points;

    for (int i = 0; i <= segments; ++i) {
        float t = static_cast<float>(i) / segments;
        points.push_back(bezierPoint(p0, p1, p2, p3, t));
    }

    return points;

    //for (size_t i = 0; i < points.size() - 1; ++i) {
    //    driver->draw3DLine(points[i], points[i + 1], color);
    //}
}

void wxIrrlicht::RaiseTerrainVertex_C(ITerrainSceneNode* terrain, irr::f32 x, irr::f32 z, irr::s32 hm_size, irr::f32 scale, bool up)
{
   IMesh* pMesh = terrain->getMesh();

   s32 b;

   irr::s32 brush_size = terrain_brush_size;
   irr::s32 step = terrain_brush_step;

   //---------
   //static const s32 scale = 32; // terrain is scaled 32X
   //static const s32 size = 256; // heightmap is 256X256 pixels
   //s32 tx = (s32)((x-(brush_size/2)) / scale);
   //s32 tz = (s32)((z-(brush_size/2)) / scale);

   int segments = 180;

   std::vector<irr::core::vector3df> curve_points = drawBezierCurve(irr::core::vector3df(-1*brush_size, 0, 0),
                                                       irr::core::vector3df(-1*brush_size, step, 0),
                                                       irr::core::vector3df(brush_size, step, 0),
                                                       irr::core::vector3df(brush_size, 0, 0),
                                                       segments);


    float t = (((float)brush_size)/2) / scale;
    //std::cout << "TOTAL = " << t << " --> " << curve_points[0].Y << ", " << curve_points[89].Y << ", " << curve_points[179].Y << std::endl;

    bool check_flag = true;

    int ti = 0;

    for(int tz = ((z-(brush_size/2)) / scale); tz < ((z+(brush_size/2)) / scale); tz++ )
    {
        //if(tz == ((int)(z/scale)))
        //    check_flag = true;
        //else
        //    check_flag = false;

        for(int tx = ((x-(brush_size/2)) / scale); tx < ((x+(brush_size/2)) / scale); tx++ )
        {
           s32 index = tx * hm_size + tz;

           float curve_fraction = (irr::core::vector2df(tx, tz).getDistanceFrom(irr::core::vector2df(x/scale, z/scale)))/t;
           //curve_fraction = curve_fraction / (brush_size / scale);
           int curve_index = (0.5 + (curve_fraction/2)) * segments;

           //if(check_flag)
            //std::cout << ti << ": CF = (" << tx << ", " << tz << ") (" << (x/scale) << ", " << (z/scale) << ") --> " << curve_fraction << " [" << curve_index << "]" << std::endl;

            ti++;

            if(curve_index < 0 || curve_index >= curve_points.size())
                continue;

           for (b=0; b<pMesh->getMeshBufferCount(); ++b)
           {
              irr::scene::IMeshBuffer* pMeshBuffer = pMesh->getMeshBuffer(b);
              // skip mesh buffers that are not the right type
              if (pMeshBuffer->getVertexType() != video::EVT_2TCOORDS) continue;

              video::S3DVertex2TCoords* pVertices = (video::S3DVertex2TCoords*)pMeshBuffer->getVertices();

              if(index < 0 || index >= pMeshBuffer->getVertexCount())
                continue;

              step = curve_points[curve_index].Y;
              pVertices[index].Pos.Y += (up) ? step : -step;

              if(pVertices[index].Pos.Y < 0)
                pVertices[index].Pos.Y = 0;
           }
        }

        check_flag = false;
    }

   // force terrain render buffer to reload
   terrain->setPosition(terrain->getPosition());
}


void wxIrrlicht::RaiseTerrainVertex_B(ITerrainSceneNode* terrain, irr::f32 x, irr::f32 z, irr::s32 hm_size, bool up)
{
   IMesh* pMesh = terrain->getMesh();

   s32 b;

   irr::s32 brush_size = terrain_brush_size;
   irr::s32 step = terrain_brush_step;

   //---------
   //static const s32 scale = 32; // terrain is scaled 32X
   //static const s32 size = 256; // heightmap is 256X256 pixels
   //s32 tx = (s32)((x-(brush_size/2)) / scale);
   //s32 tz = (s32)((z-(brush_size/2)) / scale);


   for(int tz = ((z-(brush_size/2)) / terrain_scale.Z); tz < ((z+(brush_size/2)) / terrain_scale.Z); tz++ )
   for(int tx = ((x-(brush_size/2)) / terrain_scale.X); tx < ((x+(brush_size/2)) / terrain_scale.X); tx++ )
   {
       s32 index = tx * hm_size + tz;

       for (b=0; b<pMesh->getMeshBufferCount(); ++b)
       {
          irr::scene::IMeshBuffer* pMeshBuffer = pMesh->getMeshBuffer(b);
          // skip mesh buffers that are not the right type
          if (pMeshBuffer->getVertexType() != video::EVT_2TCOORDS) continue;

          video::S3DVertex2TCoords* pVertices = (video::S3DVertex2TCoords*)pMeshBuffer->getVertices();

          if(index < 0 || index >= pMeshBuffer->getVertexCount())
            continue;

          pVertices[index].Pos.Y += (up) ? step : -step;

          if(pVertices[index].Pos.Y < 0)
            pVertices[index].Pos.Y = 0;
       }
   }

   // force terrain render buffer to reload
   terrain->setPosition(terrain->getPosition());
}


void wxIrrlicht::terrain_brush_control(irr::scene::ITerrainSceneNode* terrain, irr::scene::ICameraSceneNode* cam, int click_x, int click_y, bool IsLMBDown, bool IsRMBDown)
{
    irr::scene::ISceneManager* smgr = m_pDevice->getSceneManager();
    u32 terrainTimer_now = m_pDevice->getTimer()->getTime();

    if(!terrain)
        return;

    if(!terrainSelector)
        return;

    if (terrainTimer_then30 < terrainTimer_now)
    {
        // move the arrow to the nearest vertex ...
        //const position2di clickPosition = m_pDevice->getCursorControl()->getPosition();
        irr::core::position2di clickPosition(click_x, click_y);
        const line3df ray = smgr->getSceneCollisionManager()->getRayFromScreenCoordinates(clickPosition, cam);
        vector3df pos;
        triangle3df Tri;
        irr::scene::ISceneNode* tmp;
        if (smgr->getSceneCollisionManager()->getCollisionPoint(ray, terrainSelector, pos, Tri, tmp))
        {
          //arrow->setPosition(pos);
          static const s32 scale = terrain->getScale().X; // terrain is scaled 32X
          static const s32 t_size = terrain_size; // heightmap is 256X256 pixels
          //std::cout << "T_SIZE: " << terrain_scale.X << ", " << terrain_scale.Z << std::endl;
          pos = pos - selected_actors[0].t_pos;
          s32 x = (s32)(pos.X / terrain_scale.X);
          s32 z = (s32)(pos.Z / terrain_scale.Z);
          s32 index = x * t_size + z;

          // ... Move it if clicked
          if( (IsLMBDown || IsRMBDown) && terrainTimer_then < terrainTimer_now)
          {
            switch(terrain_brush_shape)
            {
                case RC_TERRAIN_BRUSH_SHAPE_DOME:
                {
                    RaiseTerrainVertex_C(terrain, pos.X, pos.Z, t_size, terrain_scale.X, IsLMBDown);
                }
                break;

                case RC_TERRAIN_BRUSH_SHAPE_BOX:
                {
                    RaiseTerrainVertex_B(terrain, pos.X, pos.Z, t_size, IsLMBDown);
                }
                break;

                case RC_TERRAIN_BRUSH_SHAPE_POINT:
                {
                    RaiseTerrainVertex(terrain, index, terrain_brush_step, IsLMBDown);
                }
                break;
            }
            //RaiseTerrainVertex(terrain, index, step, receiver.IsLMBDown());
            //RaiseTerrainVertex_B(terrain, pos.X, pos.Z, t_size, receiver.IsLMBDown());
            //RaiseTerrainVertex_C(terrain, pos.X, pos.Z, t_size, terrain_scale.X, IsLMBDown);
            terrainTimer_then = terrainTimer_now + 100;
          }

          x *= terrain_scale.X;
          z *= terrain_scale.Z;

          terrain_arrow->setPosition(vector3df(x, terrain->getHeight(x, z) + 20, z));
        }

        terrainTimer_then30 = terrainTimer_now + 30;
    }

    terrain->setPosition(terrain->getPosition());
    terrain->updateAbsolutePosition();
}


/*==============================================================================
  Save file
==============================================================================*/
void wxIrrlicht::saveTerrainHMap (ITerrainSceneNode* terrain, int hmap_size, wxFileName out_file)
{
    core::dimension2d<u32> dim (hmap_size,hmap_size);
    video::IImage *img = m_pDriver->createImage(ECF_R8G8B8, dim);

    u32 VertexCount = terrain->getMesh()->getMeshBuffer(0)->getVertexCount();
    S3DVertex2TCoords* verts = (S3DVertex2TCoords*)terrain->getMesh()->getMeshBuffer(0)->getVertices();

    for (u32 i=0; i<VertexCount; i++)
    {
     S3DVertex2TCoords* vertex = verts + i;
     u8 y = (u8)vertex->Pos.Y;
     img->setPixel((u32)((hmap_size-1) - vertex->Pos.X), (u32)vertex->Pos.Z, video::SColor(0, y,y,y));
    }

    m_pDriver->writeImageToFile(img, out_file.GetAbsolutePath().ToStdString().c_str(), 0);
    img->drop();
}


void wxIrrlicht::OnUpdate()
{
	if(window_type == RC_IRR_WINDOW_MATERIAL && (!manual_control))
	{
		//ROTATE AROUND (0, 0, 0)
		irr::core::vector3df cam_pos = camera[0].camera.camera->getAbsolutePosition();
		cam_pos.rotateXZBy(material_view_camera_speed, irr::core::vector3df(0,cam_pos.Y,0));
		camera[0].camera.setPosition(cam_pos.X, cam_pos.Y, cam_pos.Z);
		camera[0].camera.setRotation(camera[0].camera.rx, camera[0].camera.ry-material_view_camera_speed, camera[0].camera.rz);
		return;
	}
	else if(window_type == RC_IRR_WINDOW_ANIMATION || (window_type == RC_IRR_WINDOW_MATERIAL && manual_control))
	{
		AnimationPreview_Update();
		return;
	}

	wxMouseState  mouse_state = wxGetMouseState();

	int px = mouse_state.GetPosition().x - this->GetScreenPosition().x;
	int py = mouse_state.GetPosition().y - this->GetScreenPosition().y;

	int pw = this->GetSize().GetWidth();
	int ph = this->GetSize().GetHeight();

	if( px < 0 || px >= pw || py < 0 || py >= ph)
		stage_window_isActive = false;
	else
		stage_window_isActive = true;

	if(num_views == 4)
	{
		if(!middle_drag_init)
		{
			active_camera = 0;
			int row = (int) (py / (ph/2));
			if(row >= 0 && row < 2)
			{
				int col = (int) (px / (pw/2));
				if( col >= 0 && col < 2)
				{
					active_camera = (row * 2) + col;
				}
			}
		}
	}

//	if(mouse_state.RightIsDown())
//	{
//		wxMessageBox(_("POS: ") + wxString::Format(_("%d"), (int)camera[0].camera.x) + _(", ") +
//								  wxString::Format(_("%d"), (int)camera[0].camera.y) + _(", ") +
//								  wxString::Format(_("%d"), (int)camera[0].camera.z));
//
//		wxMessageBox(_("ROT: ") + wxString::Format(_("%d"), (int)camera[0].camera.rx) + _(", ") +
//								  wxString::Format(_("%d"), (int)camera[0].camera.ry) + _(", ") +
//								  wxString::Format(_("%d"), (int)camera[0].camera.rz));
//	}

    if(stage_edit_tool != RC_EDIT_TOOL_TERRAINBRUSH)
    {
        if(terrain_arrow)
            terrain_arrow->setVisible(false);
    }
    else
    {
        if(!(mouse_state.LeftIsDown() || mouse_state.RightIsDown()))
        {
            if(terrain_arrow)
                terrain_arrow->setVisible(false);
        }
    }



	if(mouse_state.LeftIsDown() || (stage_edit_tool==RC_EDIT_TOOL_TERRAINBRUSH && mouse_state.RightIsDown()))
	{
		//irr::scene::ITriangleSelector* selector = 0;
		irr::scene::ISceneCollisionManager* collman = m_pSceneManager->getSceneCollisionManager();

		core::line3d<f32> ray;
        ray.start = camera[active_camera].camera.camera->getAbsolutePosition();
        ray.end = ray.start + (camera[active_camera].camera.camera->getTarget() - ray.start).normalize() * 10.0f;

        // Tracks the current intersection point with the level or a mesh
        core::vector3df intersection;
        // Used to show with triangle has been hit
        core::triangle3df hitTriangle;

        bool init_click = false;

		if(!(middle_drag_init||left_drag_init||right_drag_init))
		{

			if( px >= 0 && px < pw && py >= 0 && py < ph )
			{
				left_drag_init = true;
				//this->CaptureMouse();
				this->SetFocusFromKbd();
				HIDE_CURSOR;
				//this->WarpPointer(px + (pw/2), py + (ph/2));
				drag_start.x = px;// + (pw/2);
				drag_start.y = py;// + (ph/2);
				init_click = true;

				box_select_view = active_camera;
				box_select_draw_flag = true;

				transform_tool_widget.lock_x = false;
				transform_tool_widget.lock_y = false;
				transform_tool_widget.lock_z = false;

				terrain_actor_index = -1;
			}
		}



		switch(stage_edit_tool)
		{
			case RC_EDIT_TOOL_SELECT:
			{

				if(init_click)
				{
				    select_group_flag = false;
					//wxMessageBox(_("Click"));
					//irr::scene::ISceneNode * selectedSceneNode =
					/*collman->getSceneNodeAndCollisionPointFromRay(
							ray,
							intersection, // This will be the position of the collision
							hitTriangle, // This will be the triangle hit in the collision
							0, // This ensures that only nodes that we have
									// set up to be pickable are considered
							0); // Check the entire scene (this is actually the implicit default)
					*/

					selected_actors.clear();
					for(int i = 0; i < scene_actors.size(); i++)
					{
						if(!scene_actors[i].node)
							continue;

						irr::core::aabbox3df abox = scene_actors[i].node->getBoundingBox();

						if(scene_actors[i].use_override_size)
							abox = scene_actors[i].override_box;

						irr::core::vector3df pos = scene_actors[i].node->getAbsolutePosition();
						irr::core::vector3df scale = scene_actors[i].node->getScale();
						irr::core::vector3df min_v(pos - ( (abox.getExtent()*scale) / 2));
						irr::core::vector3df max_v(pos + ( (abox.getExtent()*scale) / 2));
						irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(min_v, camera[active_camera].camera.camera, true);
						irr::core::vector2d<irr::s32> v2 = collman->getScreenCoordinatesFrom3DPosition(max_v, camera[active_camera].camera.camera, true);

						scene_actors[i].v1[active_camera] = irr::core::vector2d<irr::s32>( (v1.X < v2.X ? v1.X : v2.X) + camera[active_camera].x,
																						   (v1.Y < v2.Y ? v1.Y : v2.Y) + camera[active_camera].y );

						scene_actors[i].v2[active_camera] = irr::core::vector2d<irr::s32>( (v1.X > v2.X ? v1.X : v2.X) + camera[active_camera].x,
																						   (v1.Y > v2.Y ? v1.Y : v2.Y) + camera[active_camera].y );

						v1 = scene_actors[i].v1[active_camera];
						v2 = scene_actors[i].v2[active_camera];

						irr::core::rect<irr::s32> actor_highlight(scene_actors[i].v1[active_camera], scene_actors[i].v2[active_camera]);

						if(actor_highlight.isPointInside(irr::core::vector2di(px, py)))
						{
							//irr::f32 d_start = ray.start.getDistanceFrom(pos);
							//irr::f32 d_end = ray.end.getDistanceFrom(pos);
							//if(d_end < d_start)
							scene_actors[i].t_start = scene_actors[i].node->getAbsolutePosition();

							if(scene_actors[i].node->isVisible())
							{
								selected_actors.push_back(scene_actors[i]);
								transform_tool_widget.pos = selected_actors[0].node->getAbsolutePosition();
							}
							//setTransformToolBox();

							break;

							//wxMessageBox(_("Selected"));
						}
					}
				}
			}
			break;

			case RC_EDIT_TOOL_BOXSELECT:
			{
				if(!left_drag_init)
					break;

                select_group_flag = false;


				selected_actors.clear();

				irr::core::vector2di drag_v1( (drag_start.x < px ? drag_start.x : px) , (drag_start.y < py ? drag_start.y : py) );
				irr::core::vector2di drag_v2( (drag_start.x > px ? drag_start.x : px) , (drag_start.y > py ? drag_start.y : py) );

				box_select_shape = irr::core::rect<irr::s32>( drag_v1, drag_v2 );

				for(int i = 0; i < scene_actors.size(); i++)
				{
					if(!scene_actors[i].node)
						continue;

					irr::core::vector3df pos = scene_actors[i].node->getAbsolutePosition();
					irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(pos, camera[active_camera].camera.camera, true);

					scene_actors[i].v1[active_camera] = irr::core::vector2d<irr::s32>( v1.X + camera[active_camera].x, v1.Y + camera[active_camera].y );


					v1 = scene_actors[i].v1[active_camera];

					if(box_select_shape.isPointInside(v1))
					{
						if(!scene_actors[i].node)
							continue;

						//irr::f32 d_start = ray.start.getDistanceFrom(pos);
						//irr::f32 d_end = ray.end.getDistanceFrom(pos);
						//if(d_end < d_start)
						scene_actors[i].t_start = scene_actors[i].node->getAbsolutePosition();

						if(scene_actors[i].node->isVisible())
						{
							selected_actors.push_back(scene_actors[i]);
							transform_tool_widget.pos = selected_actors[0].node->getAbsolutePosition();
						}
						//setTransformToolBox();

						//break;
						//wxMessageBox(_("Selected: ") + wxString::Format(_("%d"), drag_v1.X) + _(", ") + wxString::Format(_("%d"), drag_v1.Y) + _("\n") +
						//							   wxString::Format(_("%d"), drag_v2.X) + _(", ") + wxString::Format(_("%d"), drag_v2.Y) + _("\n"));
						//break;
					}
				}


				//drag_v1.X += camera[active_camera].x;
				//drag_v1.Y += camera[active_camera].y;
				//drag_v2.X += camera[active_camera].x;
				//drag_v2.Y += camera[active_camera].y;

			}
			break;

			case RC_EDIT_TOOL_MOVE:
			{
				if(init_click)
				{
					move_tool_average_x = 0;
					move_tool_average_y = 0;
					move_tool_average_z = 0;

					terrain_actor_index = -1;

					int num_actors = 0;
					for(int i = 0; i < selected_actors.size(); i++)
					{
						if(!selected_actors[i].node)
							continue;

						if(selected_actors[i].isTerrain)
						{
							selected_actors[i].t_start = selected_actors[i].t_pos;
						}
						else
						{
							selected_actors[i].t_start = selected_actors[i].node->getAbsolutePosition();
						}

						move_tool_average_x += selected_actors[i].t_start.X;
						move_tool_average_y += selected_actors[i].t_start.Y;
						move_tool_average_z += selected_actors[i].t_start.Z;
						num_actors++;
					}

					move_tool_average_x = move_tool_average_x / num_actors;
					move_tool_average_y = move_tool_average_y / num_actors;
					move_tool_average_z = move_tool_average_z / num_actors;
				}

				if(!left_drag_init)
					break;


				irr::core::vector3df translate_vector(0.0f, 0.0f, 0.0f);

				double translate_factor_x = ortho_width/((double)camera[box_select_view].w);
				double translate_factor_y = ortho_height/((double)camera[box_select_view].h);

				double axis_lock_factor_x = ( (transform_tool_widget.lock_y || transform_tool_widget.lock_z) ? 0 : 1);
				double axis_lock_factor_y = ( (transform_tool_widget.lock_x || transform_tool_widget.lock_z) ? 0 : 1);
				double axis_lock_factor_z = ( (transform_tool_widget.lock_x || transform_tool_widget.lock_y) ? 0 : 1);

				irr::core::vector3df axis_lock_vector(axis_lock_factor_x, axis_lock_factor_y, axis_lock_factor_z);

				switch(camera[box_select_view].pov) //box_select_view can be used for every other tool
				{
					case RC_CAMERA_VIEW_FRONT:
						translate_vector.set(((double)px - drag_start.x)*translate_factor_x, ((double)(drag_start.y - py))*translate_factor_y, 0);
					break;

					case RC_CAMERA_VIEW_TOP:
						translate_vector.set(((double)px - drag_start.x)*translate_factor_x, 0, ((double)(drag_start.y - py))*translate_factor_y);
					break;

					case RC_CAMERA_VIEW_RIGHT:
						translate_vector.set(0, ((double)(drag_start.y - py))*translate_factor_y, ((double)drag_start.x - px)*translate_factor_x);
					break;

					case RC_CAMERA_VIEW_PERSPECTIVE:
						//translate_vector.set(((double)px - drag_start.x)*translate_factor_x, ((double)(drag_start.y - py))*translate_factor_y, 0);
						//irr::core::matrix4 tmat = camera[box_select_view].camera.camera->getAbsoluteTransformation();
						//irr::core::vector3df dvec = camera[box_select_view].camera.camera->getTarget();

						//double zy = (((double)(drag_start.y - py))*translate_factor_y) * ( ( 180 - ((int)(camera[box_select_view].camera.ry-90)%180) )/180);
						//double zx = (((double)(px - drag_start.x))*translate_factor_x) * ( ( 180 - ((int)(camera[box_select_view].camera.rx-90)%180) )/180);

						irr::core::vector3df pos(camera[box_select_view].camera.x, camera[box_select_view].camera.y, camera[box_select_view].camera.z);
						irr::core::vector3df rot(camera[box_select_view].camera.rx, camera[box_select_view].camera.ry, camera[box_select_view].camera.rz);
						irr::core::vector3df obj_pos(move_tool_average_x, move_tool_average_y, move_tool_average_z);

						irr::f32 angle_to_obj = getHeading( irr::core::vector2df(pos.Z, pos.X), irr::core::vector2df(obj_pos.Z, obj_pos.X) );

						//std::cout << "Info[X]: angle_to_obj = " << angle_to_obj << std::endl;

						irr::core::vector2df rotate_pos = getRotatedPoint2D(irr::core::vector2df(obj_pos.X, obj_pos.Z), irr::core::vector2df(pos.X, pos.Z), -angle_to_obj);

						//std::cout << "Rotated: " << obj_pos.X << ", " << obj_pos.Y << ", " << obj_pos.Z << "\n" << angle_to_obj << " degrees Around "
						//						 << pos.X << ", " << pos.Y << ", " << pos.Z << "\nTo "
						//						 << rotate_pos.X << ", " << obj_pos.Y << ", " << rotate_pos.Y << std::endl << std::endl;

						irr::f32 axis_dist = irr::core::abs_(rotate_pos.Y - pos.Z);

						//std::cout << "axis_info: " << axis_dist << " (" << (int)(pw/2) << ", " << (int)(ph/2) << ") " << " t_factor: (" << translate_factor_x << ", " << translate_factor_y << ") " << std::endl;

						int vp_w = pw/2;
						int vp_h = ph/2;

						if(num_views > 1)
						{
							vp_w = pw/4;
							vp_h = ph/4;
						}

						//This probably isn't right but its a lot better than it was
						translate_factor_x = axis_dist / vp_w;
						translate_factor_y = axis_dist / vp_h;

						translate_factor_x = (translate_factor_x < 1.0f) ? 1.0f : translate_factor_x;
						translate_factor_y = (translate_factor_y < 1.0f) ? 1.0f : translate_factor_y;

						//std::cout << "New t_factor: (" << translate_factor_x << ", " << translate_factor_y << ") " << std::endl << std::endl;

						translate_vector.set(((double)px - drag_start.x)*translate_factor_x, ((double)(drag_start.y - py))*translate_factor_y, 0);
						translate_vector.rotateXZBy(-camera[box_select_view].camera.ry);
						translate_vector.rotateYZBy(camera[box_select_view].camera.rx);
					break;
				}

				translate_vector *= axis_lock_vector;

				for(int i = 0; i < selected_actors.size(); i++)
				{
					if(!selected_actors[i].node)
						continue;

					selected_actors[i].node->setPosition( selected_actors[i].t_start + translate_vector );
					selected_actors[i].t_pos = selected_actors[i].t_start + translate_vector;

					if(selected_actors[i].icon_node)
					{
						selected_actors[i].icon_node->setPosition(irr::core::vector3df(0,0,0));
					}
				}

				if(selected_actors.size() > 0)
				{
					if(!selected_actors[0].node)
						break;

					transform_tool_widget.pos = selected_actors[0].node->getAbsolutePosition();
					int widget_half = transform_tool_widget.widget_size/2;
					irr::core::dimension2du widget_dim(transform_tool_widget.widget_size, transform_tool_widget.widget_size);

					int axis_tool_space = 50;

					for(int i = 0; i < num_views; i++)
					{
						switch(camera[i].pov) //box_select_view can be used for every other tool
						{
							case RC_CAMERA_VIEW_FRONT:
							{
								irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
								transform_tool_widget.view_box_x[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
								transform_tool_widget.view_box_y[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
							}
							break;

							case RC_CAMERA_VIEW_TOP:
							{
								irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
								transform_tool_widget.view_box_x[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
								transform_tool_widget.view_box_z[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
							}
							break;

							case RC_CAMERA_VIEW_RIGHT:
							{
								irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
								transform_tool_widget.view_box_z[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
								transform_tool_widget.view_box_y[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
							}
							break;

							case RC_CAMERA_VIEW_PERSPECTIVE:
							{
								irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
								transform_tool_widget.view_box_x[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
								transform_tool_widget.view_box_y[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
								transform_tool_widget.view_box_z[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -axis_tool_space-widget_half), widget_dim);
							}
							break;
						}
					}
				}

				if(init_click)
				{
					int mouse_to_view_x = px - (camera[active_camera].w * (active_camera % 2) );
					int mouse_to_view_y = py - (camera[active_camera].h * (active_camera / 2) );
					if(transform_tool_widget.view_box_x[active_camera].isPointInside( irr::core::vector2di(mouse_to_view_x, mouse_to_view_y) ))
					{
						transform_tool_widget.lock_x = true;
					}
					else if(transform_tool_widget.view_box_y[active_camera].isPointInside( irr::core::vector2di(mouse_to_view_x, mouse_to_view_y) ))
					{
						transform_tool_widget.lock_y = true;
					}
					else if(transform_tool_widget.view_box_z[active_camera].isPointInside( irr::core::vector2di(mouse_to_view_x, mouse_to_view_y) ))
					{
						transform_tool_widget.lock_z = true;
					}

					//wxMessageBox(_("mouse: ") + wxString::Format(_("%d"), active_camera) + _(" :: ") + wxString::Format(_("%d"), mouse_to_view_x) + _(", ") + wxString::Format(_("%d"), mouse_to_view_y));
				}

			}
			break;

			case RC_EDIT_TOOL_ROTATE:
			{
				if(init_click)
				{
					for(int i = 0; i < selected_actors.size(); i++)
					{
						if(selected_actors[i].rotation)
							selected_actors[i].t_start = *selected_actors[i].rotation;
						else
							selected_actors[i].t_start = irr::core::vector3df(0,0,0);
					}
				}

				if(!left_drag_init)
					break;


				irr::core::vector3df rotate_vector(0.0f, 0.0f, 0.0f);

				double rotate_factor_x = 500/((double)camera[box_select_view].w);
				double rotate_factor_y = 300/((double)camera[box_select_view].h);

				double axis_lock_factor_x = ( (transform_tool_widget.lock_y || transform_tool_widget.lock_z) ? 0 : 1);
				double axis_lock_factor_y = ( (transform_tool_widget.lock_x || transform_tool_widget.lock_z) ? 0 : 1);
				double axis_lock_factor_z = ( (transform_tool_widget.lock_x || transform_tool_widget.lock_y) ? 0 : 1);

				irr::core::vector3df axis_lock_vector(axis_lock_factor_x, axis_lock_factor_y, axis_lock_factor_z);

				switch(camera[box_select_view].pov) //box_select_view can be used for every other tool
				{
					case RC_CAMERA_VIEW_FRONT:
						rotate_vector.set(((double)(drag_start.y - py))*rotate_factor_y, ((double)drag_start.x - px)*rotate_factor_x, 0);
					break;

					case RC_CAMERA_VIEW_TOP:
						rotate_vector.set(((double)(drag_start.y - py))*rotate_factor_y, 0, ((double)drag_start.x - px)*rotate_factor_x);
					break;

					case RC_CAMERA_VIEW_RIGHT:
						rotate_vector.set(0, ((double)drag_start.x - px)*rotate_factor_x, ((double)(py - drag_start.y))*rotate_factor_y);
					break;

					case RC_CAMERA_VIEW_PERSPECTIVE:
						//rotate_vector.set(((double)px - drag_start.x)*rotate_factor_x, ((double)(drag_start.y - py))*rotate_factor_y, 0);
						//irr::core::matrix4 tmat = camera[box_select_view].camera.camera->getAbsoluteTransformation();
						//irr::core::vector3df dvec = camera[box_select_view].camera.camera->getTarget();

						double zy = (((double)(py - drag_start.y))*rotate_factor_y) * ( ( 180 - ((int)(camera[box_select_view].camera.ry-90)%180) )/180);
						double zx = (((double)(px - drag_start.x))*rotate_factor_x) * ( ( 180 - ((int)(camera[box_select_view].camera.rx-90)%180) )/180);
						rotate_vector.set(((double)(drag_start.y - py))*rotate_factor_y, ((double)drag_start.x - px)*rotate_factor_x, -1*(zx+zy));
						//rotate_vector.rotateXZBy(-camera[box_select_view].camera.ry);
						//rotate_vector.rotateYZBy(camera[box_select_view].camera.rx);
					break;
				}

				rotate_vector *= axis_lock_vector;

				for(int i = 0; i < selected_actors.size(); i++)
				{
				    if(selected_actors[i].isTerrain)
                        continue;

					//Apply Rotation in Y,X,Z order
					irr::scene::ISceneNode* node = selected_actors[i].node;
					if(!node)
						continue;

					if(!selected_actors[i].rotation)
						continue;

					selected_actors[i].rotation->set(selected_actors[i].t_start + rotate_vector);

					node->setRotation( irr::core::vector3df(0, 0, 0) );

					irr::core::vector3df rot;
					irr::core::matrix4 m;
					irr::core::matrix4 n;

					//Rotate on Y
					m.setRotationDegrees(node->getRotation());

					rot.set(0, selected_actors[i].rotation->Y, 0);

					n.setRotationDegrees(rot);

					m *= n;

					node->setRotation( m.getRotationDegrees() );
					node->updateAbsolutePosition();

					//Rotate on X
					m.setRotationDegrees(node->getRotation());

					rot.set(selected_actors[i].rotation->X, 0, 0);

					n.setRotationDegrees(rot);

					m *= n;

					node->setRotation( m.getRotationDegrees() );
					node->updateAbsolutePosition();

					//Rotate on Z
					m.setRotationDegrees(node->getRotation());

					rot.set(0, 0, selected_actors[i].rotation->Z);

					n.setRotationDegrees(rot);

					m *= n;

					node->setRotation( m.getRotationDegrees() );
					node->updateAbsolutePosition();

				}

				if(selected_actors.size() > 0)
				{
					if(!selected_actors[0].node)
						break;

					transform_tool_widget.pos = selected_actors[0].node->getAbsolutePosition();
					setTransformToolBox();
				}

				if(init_click)
				{
					int mouse_to_view_x = px - (camera[active_camera].w * (active_camera % 2) );
					int mouse_to_view_y = py - (camera[active_camera].h * (active_camera / 2) );
					if(transform_tool_widget.view_box_x[active_camera].isPointInside( irr::core::vector2di(mouse_to_view_x, mouse_to_view_y) ))
					{
						transform_tool_widget.lock_x = true;
					}
					else if(transform_tool_widget.view_box_y[active_camera].isPointInside( irr::core::vector2di(mouse_to_view_x, mouse_to_view_y) ))
					{
						transform_tool_widget.lock_y = true;
					}
					else if(transform_tool_widget.view_box_z[active_camera].isPointInside( irr::core::vector2di(mouse_to_view_x, mouse_to_view_y) ))
					{
						transform_tool_widget.lock_z = true;
					}

					//wxMessageBox(_("mouse: ") + wxString::Format(_("%d"), active_camera) + _(" :: ") + wxString::Format(_("%d"), mouse_to_view_x) + _(", ") + wxString::Format(_("%d"), mouse_to_view_y));
				}

			}
			break;

			case RC_EDIT_TOOL_SCALE:
			{
				if(init_click)
				{
					for(int i = 0; i < selected_actors.size(); i++)
					{
						if(!selected_actors[i].node)
							continue;

						selected_actors[i].t_start = selected_actors[i].node->getScale();
					}
				}

				if(!left_drag_init)
					break;


				irr::core::vector3df scale_vector(0.0f, 0.0f, 0.0f);

				double scale_factor_x = 500/((double)camera[box_select_view].w);
				double scale_factor_y = 300/((double)camera[box_select_view].h);

				double axis_lock_factor_x = ( (transform_tool_widget.lock_y || transform_tool_widget.lock_z) ? 0 : 1);
				double axis_lock_factor_y = ( (transform_tool_widget.lock_x || transform_tool_widget.lock_z) ? 0 : 1);
				double axis_lock_factor_z = ( (transform_tool_widget.lock_x || transform_tool_widget.lock_y) ? 0 : 1);

				irr::core::vector3df axis_lock_vector(axis_lock_factor_x, axis_lock_factor_y, axis_lock_factor_z);

				irr::core::vector2di t_pos = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[box_select_view].camera.camera, true);
				double start_distance = irr::core::vector2di(drag_start.x, drag_start.y).getDistanceFrom(t_pos);
				double current_distance = irr::core::vector2di(px, py).getDistanceFrom(t_pos);
				double scale_distance = current_distance - start_distance;

				if(!(transform_tool_widget.lock_x || transform_tool_widget.lock_y || transform_tool_widget.lock_z))
				{
					double sx = ((double)px - drag_start.x)*scale_factor_x;
					double sy = ((double)(drag_start.y - py))*scale_factor_y;
					double scale_n = scale_distance;
					scale_vector.set(scale_n, scale_n, scale_n);
				}
				else
				{
					switch(camera[box_select_view].pov) //box_select_view can be used for every other tool
					{
						case RC_CAMERA_VIEW_FRONT:
							scale_vector.set(scale_distance, scale_distance, 0);
						break;

						case RC_CAMERA_VIEW_TOP:
							scale_vector.set(scale_distance, 0, -scale_distance);
						break;

						case RC_CAMERA_VIEW_RIGHT:
							scale_vector.set(0, scale_distance, scale_distance);
						break;

						case RC_CAMERA_VIEW_PERSPECTIVE:
							//scale_vector.set(((double)px - drag_start.x)*translate_factor_x, ((double)(drag_start.y - py))*translate_factor_y, 0);
							//irr::core::matrix4 tmat = camera[box_select_view].camera.camera->getAbsoluteTransformation();
							//irr::core::vector3df dvec = camera[box_select_view].camera.camera->getTarget();

							//double zy = (((double)(drag_start.y - py))*translate_factor_y) * ( ( 180 - ((int)(camera[box_select_view].camera.ry-90)%180) )/180);
							//double zx = (((double)(px - drag_start.x))*translate_factor_x) * ( ( 180 - ((int)(camera[box_select_view].camera.rx-90)%180) )/180);

							scale_vector.set(scale_distance, -scale_distance, scale_distance);
							scale_vector.rotateXZBy(-camera[box_select_view].camera.ry);
							scale_vector.rotateYZBy(camera[box_select_view].camera.rx);
						break;
					}
				}

				scale_vector *= axis_lock_vector;

				scale_vector *= irr::core::vector3df(.5, .5, .5);

				for(int i = 0; i < selected_actors.size(); i++)
				{
					if(!selected_actors[i].node)
						continue;

					if(selected_actors[i].isTerrain)
                    {
                        irr::core::vector3df t_scale_vector = selected_actors[i].t_start + scale_vector;
                        bool use_x = ((t_scale_vector.X >= t_scale_vector.Y) && (t_scale_vector.X >= t_scale_vector.Z));
                        bool use_y = ((t_scale_vector.Y >= t_scale_vector.X) && (t_scale_vector.Y >= t_scale_vector.Z));
                        bool use_z = ((t_scale_vector.Z >= t_scale_vector.Y) && (t_scale_vector.Z >= t_scale_vector.X));
                        if(use_x)
                            t_scale_vector.set(t_scale_vector.X, t_scale_vector.X, t_scale_vector.X);
                        else if(use_y)
                            t_scale_vector.set(t_scale_vector.Y, t_scale_vector.Y, t_scale_vector.Y);
                        if(use_z)
                            t_scale_vector.set(t_scale_vector.Z, t_scale_vector.Z, t_scale_vector.Z);

                        selected_actors[i].node->setScale( t_scale_vector );
                    }
                    else
					{
					    selected_actors[i].node->setScale( selected_actors[i].t_start + scale_vector );
					}
				}

				if(selected_actors.size() > 0)
				{
					if(!selected_actors[0].node)
						break;

					transform_tool_widget.pos = selected_actors[0].node->getAbsolutePosition();
					int widget_half = transform_tool_widget.widget_size/2;
					irr::core::dimension2du widget_dim(transform_tool_widget.widget_size, transform_tool_widget.widget_size);

					int axis_tool_space = 50;

					for(int i = 0; i < num_views; i++)
					{
						switch(camera[i].pov) //box_select_view can be used for every other tool
						{
							case RC_CAMERA_VIEW_FRONT:
							{
								irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
								transform_tool_widget.view_box_x[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
								transform_tool_widget.view_box_y[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
							}
							break;

							case RC_CAMERA_VIEW_TOP:
							{
								irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
								transform_tool_widget.view_box_x[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
								transform_tool_widget.view_box_z[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
							}
							break;

							case RC_CAMERA_VIEW_RIGHT:
							{
								irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
								transform_tool_widget.view_box_z[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
								transform_tool_widget.view_box_y[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
							}
							break;

							case RC_CAMERA_VIEW_PERSPECTIVE:
							{
								irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(transform_tool_widget.pos, camera[i].camera.camera, true);
								transform_tool_widget.view_box_x[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -widget_half), widget_dim);
								transform_tool_widget.view_box_y[i] = irr::core::recti(v1 + irr::core::vector2di(-widget_half, -axis_tool_space-widget_half), widget_dim);
								transform_tool_widget.view_box_z[i] = irr::core::recti(v1 + irr::core::vector2di(axis_tool_space-widget_half, -axis_tool_space-widget_half), widget_dim);
							}
							break;
						}
					}
				}

				if(init_click)
				{
					int mouse_to_view_x = px - (camera[active_camera].w * (active_camera % 2) );
					int mouse_to_view_y = py - (camera[active_camera].h * (active_camera / 2) );
					if(transform_tool_widget.view_box_x[active_camera].isPointInside( irr::core::vector2di(mouse_to_view_x, mouse_to_view_y) ))
					{
						transform_tool_widget.lock_x = true;
					}
					else if(transform_tool_widget.view_box_y[active_camera].isPointInside( irr::core::vector2di(mouse_to_view_x, mouse_to_view_y) ))
					{
						transform_tool_widget.lock_y = true;
					}
					else if(transform_tool_widget.view_box_z[active_camera].isPointInside( irr::core::vector2di(mouse_to_view_x, mouse_to_view_y) ))
					{
						transform_tool_widget.lock_z = true;
					}

					//wxMessageBox(_("mouse: ") + wxString::Format(_("%d"), active_camera) + _(" :: ") + wxString::Format(_("%d"), mouse_to_view_x) + _(", ") + wxString::Format(_("%d"), mouse_to_view_y));
				}

			}
			break;


			case RC_EDIT_TOOL_TERRAINBRUSH:
			{
			    if(selected_actors.size() != 1)
                    break;

                int actor_index = -1;

			    if(init_click)
                {

                    actor_index = selected_actors[0].actor_index;

                    if(!selected_actors[0].isTerrain)
                        break;

                    if(!selected_actors[0].node)
                        break;

                    if(terrainSelector)
                        terrainSelector->drop();

                    terrainSelector = m_pSceneManager->createTerrainTriangleSelector((irr::scene::ITerrainSceneNode*)selected_actors[0].node, 0);
                    terrain_actor_index = actor_index;

                    if(terrain_arrow)
                        terrain_arrow->setVisible(true);
                }

				if(terrain_actor_index >= 0) //(init_click)
				{

                    irr::core::vector3df tmp_scale = selected_actors[0].node->getScale();
                    //selected_actors[0].node->setScale(irr::core::vector3df(1.f, 1.f, 1.f));

                    terrain_brush_control((irr::scene::ITerrainSceneNode*) selected_actors[0].node,
                                          camera[active_camera].camera.camera,
                                          px - camera[active_camera].x,
                                          py - camera[active_camera].y,
                                          mouse_state.LeftIsDown(),
                                          mouse_state.RightIsDown());
                    //selected_actors[0].node->setScale(tmp_scale);
                    OnRender();
				}
			}
			break;
		}
	}
	else if( (!mouse_state.LeftIsDown()) && left_drag_init )
	{
		SHOW_CURSOR;
		//this->ReleaseMouse();
		left_drag_init = false;
		box_select_draw_flag = false;
		//wxMessageBox(_("RELEASE"));
		return;
	}



	if(mouse_state.MiddleIsDown())
	{
		if(!(middle_drag_init||left_drag_init||right_drag_init))
		{

			if( px >= 0 && px < pw && py >= 0 && py < ph )
			{
				middle_drag_init = true;
				//this->CaptureMouse();
				this->SetFocusFromKbd();
				HIDE_CURSOR;
				//this->WarpPointer(px + (pw/2), py + (ph/2));
				drag_start.x = px;// + (pw/2);
				drag_start.y = py;// + (ph/2);
			}
		}
		else if(middle_drag_init)
		{

			int drag_w = pw/2;
			int drag_h = ph/2;

			int delta_x = px - drag_start.x;
			int delta_y = py - drag_start.y;

			float cam_far = ortho_far;

			if(camera[active_camera].pov != RC_CAMERA_VIEW_PERSPECTIVE)
			{
				if(num_views == 1)
				{
					delta_x *= 2; //(int)((double)(ortho_width/pw)*1.3);
					delta_y *= 2; //(int)((double)(ortho_height/ph)*1.3);
				}
				else
				{
					delta_x *= 4; //(int)((double)(ortho_width/((double)pw/2.0f))*1.3);
					delta_y *= 4; //(int)((double)(ortho_height/((double)ph/2.0f))*1.3);

					//std::cout << "New delta: " << delta_x << ", " << delta_y << std::endl;
				}
			}

			switch(camera[active_camera].pov)
			{
				case RC_CAMERA_VIEW_PERSPECTIVE:
				{
					float cx, cy, cz;
					cx = camera[active_camera].camera.rx;
					cy = camera[active_camera].camera.ry;
					cz = camera[active_camera].camera.rz;
					camera[active_camera].camera.setRotation(cx, cy+delta_x, cz);
					camera[active_camera].camera.rotate(delta_y, 0, 0);
				}
				break;

				case RC_CAMERA_VIEW_BACK:
				case RC_CAMERA_VIEW_FRONT:
				{

					camera[active_camera].camera.translateW(-delta_x, delta_y, 0);

					float ax = 0;
					float ay = 0;
					float az = 0;
					camera[active_camera].camera.getPosition(ax, ay, az);

					for(int i = 0; i < num_views; i++)
					{
						if(i != active_camera)
						{
							float pos_x = 0;
							float pos_y = 0;
							float pos_z = 0;
							camera[i].camera.getPosition(pos_x, pos_y, pos_z);
							camera[i].camera.setPosition(ax, ay, pos_z);
						}
					}
				}
				break;

				case RC_CAMERA_VIEW_LEFT:
				case RC_CAMERA_VIEW_RIGHT:
				{
				    int adj_delta_x = (num_views == 1) ? 1: -1;

					//This fixes the scrolling being in different directions when in single view or multiview
					camera[active_camera].camera.translateW(0, delta_y, delta_x * adj_delta_x);

					float ax = 0;
					float ay = 0;
					float az = 0;
					camera[active_camera].camera.getPosition(ax, ay, az);

					for(int i = 0; i < num_views; i++)
					{
						if(i != active_camera)
						{
							float pos_x = 0;
							float pos_y = 0;
							float pos_z = 0;
							camera[i].camera.getPosition(pos_x, pos_y, pos_z);
							camera[i].camera.setPosition(pos_x, ay, az);
						}
					}
				}
				break;

				case RC_CAMERA_VIEW_TOP:
				case RC_CAMERA_VIEW_BOTTOM:
				{
					camera[active_camera].camera.translateW(-delta_x, 0, delta_y);

					float ax = 0;
					float ay = 0;
					float az = 0;
					camera[active_camera].camera.getPosition(ax, ay, az);

					for(int i = 0; i < num_views; i++)
					{
						if(i != active_camera)
						{
							float pos_x = 0;
							float pos_y = 0;
							float pos_z = 0;
							camera[i].camera.getPosition(pos_x, pos_y, pos_z);
							camera[i].camera.setPosition(ax, pos_y, az);
						}
					}
				}
				break;
			}
			drag_start.x = px;
			drag_start.y = py;


			if(camera[active_camera].pov == RC_CAMERA_VIEW_PERSPECTIVE)
			{
				if(VIEW_KEY_W)
				{
					VIEW_KEY_W = false;

					camera[active_camera].camera.translate(0, 0, cam_move_speed);
				}

				if(VIEW_KEY_S)
				{
					VIEW_KEY_S = false;

					camera[active_camera].camera.translate(0, 0, -cam_move_speed);
				}

				if(VIEW_KEY_A)
				{
					VIEW_KEY_A = false;

					camera[active_camera].camera.translate(-cam_move_speed, 0, 0);
				}

				if(VIEW_KEY_D)
				{
					VIEW_KEY_D = false;

					camera[active_camera].camera.translate(cam_move_speed, 0, 0);
				}

				if(VIEW_KEY_R)
				{
					VIEW_KEY_R = false;

					camera[active_camera].camera.translateW(0, cam_move_speed, 0);
				}

				if(VIEW_KEY_F)
				{
					VIEW_KEY_F = false;

					camera[active_camera].camera.translateW(0, -cam_move_speed, 0);
				}

				float ax = 0;
				float ay = 0;
				float az = 0;
				camera[active_camera].camera.getPosition(ax, ay, az);

				for(int i = 0; i < num_views; i++)
				{
					if(camera[i].pov == RC_CAMERA_VIEW_FRONT)
					{
						float ax_front = 0;
						float ay_front = ay;
						float az_front = az + (cam_far/4);

						irr::core::vector3df cam_pos(ax, ay, az);
						irr::core::vector3df cam_tgt = cam_pos;
						cam_tgt += irr::core::vector3df(0, 0, (cam_far/4));
						cam_tgt.rotateXZBy(-camera[active_camera].camera.ry, cam_pos);

						ax_front = cam_tgt.X;
						az_front = az - (cam_far/2);

						//std::cout << "AX~ " << ax << ", " << ax_front << std::endl;
						//std::cout << "AZ~ " << az << ", " << az_front << std::endl << std::endl;

						//camera[i].camera.setPosition(ax, ay, az-300);
						camera[i].camera.setPosition(ax_front, ay, az_front);
						camera[i].gridSceneNode->setPosition(irr::core::vector3df(0, 0, az+100));
					}
					else if(camera[i].pov == RC_CAMERA_VIEW_RIGHT)
					{
						float ax_right = ax - (cam_far/2);
						float az_right = az + (cam_far/4);

						irr::core::vector3df cam_pos(ax, ay, az);
						irr::core::vector3df cam_tgt = cam_pos;
						cam_tgt += irr::core::vector3df(0, 0, (cam_far/4));
						cam_tgt.rotateXZBy(camera[active_camera].camera.ry, cam_pos);

						ax_right = cam_tgt.X - (cam_far/4);
						az_right = cam_tgt.Z;

						//std::cout << "AX~ " << ax << ", " << ax_right << std::endl;
						//std::cout << "AZ~ " << az << ", " << az_right << std::endl << std::endl;

						camera[i].camera.setPosition(ax_right, ay, az_right);
						//camera[i].camera.setPosition(ax-300, ay, az);
						camera[i].gridSceneNode->setPosition(irr::core::vector3df(ax+100, 0, 0));
					}
					else if(camera[i].pov == RC_CAMERA_VIEW_TOP)
					{
						float ax_top = 0;
						float ay_top = ay - (cam_far/2);
						float az_top = az + (cam_far/4);

						irr::core::vector3df cam_pos(ax, ay, az);
						irr::core::vector3df cam_tgt = cam_pos;
						cam_tgt += irr::core::vector3df(0, 0, (cam_far/4));
						cam_tgt.rotateXZBy(-camera[active_camera].camera.ry, cam_pos);

						ax_top = cam_tgt.X;
						az_top = cam_tgt.Z;

						//std::cout << "AX~ " << ax << ", " << ax_top << std::endl;
						//std::cout << "AZ~ " << az << ", " << az_top << std::endl << std::endl;

						camera[i].camera.setPosition(ax_top, ay_top, az_top);
						//camera[i].camera.setPosition(ax, ay+300, az);
						camera[i].gridSceneNode->setPosition(irr::core::vector3df(0, ay-100, 0));
					}
				}
			}
			else if(num_views == 4)
			{
				float ax = 0;
				float ay = 0;
				float az = 0;
				camera[active_camera].camera.getPosition(ax, ay, az);

				if(camera[active_camera].pov == RC_CAMERA_VIEW_FRONT)
				{
					float ax_front = 0;
					float ay_front = ay;
					float az_front = az - (cam_far/4);

					irr::core::vector3df cam_pos(ax, ay, az);
					irr::core::vector3df cam_tgt = cam_pos;
					cam_tgt += irr::core::vector3df(0, 0, -(cam_far/4));
					cam_tgt.rotateXZBy(-camera[3].camera.ry, cam_pos);

					ax_front = cam_tgt.X;
					az_front = az + (cam_far/2);

					camera[3].camera.setPosition(ax_front, ay, az_front);
				}
				else if(camera[active_camera].pov == RC_CAMERA_VIEW_RIGHT)
				{
					float ax_right = ax - (cam_far/2);
					float az_right = az + (cam_far/4);

					irr::core::vector3df cam_pos(ax, ay, az);
					irr::core::vector3df cam_tgt = cam_pos;
					cam_tgt += irr::core::vector3df(0, 0, -(cam_far/4));
					cam_tgt.rotateXZBy(camera[3].camera.ry, cam_pos);

					ax_right = cam_tgt.X + (cam_far/4);
					az_right = cam_tgt.Z;

					//std::cout << "AX~ " << ax << ", " << ax_right << std::endl;
					//std::cout << "AZ~ " << az << ", " << az_right << std::endl << std::endl;

					camera[3].camera.setPosition(ax_right, ay, az_right);
				}
				else if(camera[active_camera].pov == RC_CAMERA_VIEW_TOP)
				{
					float ax_top = 0;
					float ay_top = ay - irr::core::abs_(cam_far/2);
					float az_top = az + (cam_far/4);

					irr::core::vector3df cam_pos(ax, ay, az);
					irr::core::vector3df cam_tgt = cam_pos;
					cam_tgt += irr::core::vector3df(0, 0, -(cam_far/4));
					cam_tgt.rotateXZBy(-camera[3].camera.ry, cam_pos);

					ax_top = cam_tgt.X;
					az_top = cam_tgt.Z;

					//std::cout << "AX~ " << ax << ", " << ax_top << std::endl;
					//std::cout << "AZ~ " << az << ", " << az_top << std::endl << std::endl;

					camera[3].camera.setPosition(ax_top, camera[3].camera.y, az_top);
				}

				camera[3].camera.update();
				camera[3].camera.getPosition(ax, ay, az);

				for(int i = 0; i < num_views; i++)
				{
					if(i == active_camera)
						continue;

					if(camera[i].pov == RC_CAMERA_VIEW_FRONT)
					{
						float ax_front = 0;
						float ay_front = ay;
						float az_front = az + (cam_far/4);

						irr::core::vector3df cam_pos(ax, ay, az);
						irr::core::vector3df cam_tgt = cam_pos;
						cam_tgt += irr::core::vector3df(0, 0, (cam_far/4));
						cam_tgt.rotateXZBy(-camera[3].camera.ry, cam_pos);

						ax_front = cam_tgt.X;
						az_front = az - (cam_far/2);

						//std::cout << "AX~ " << ax << ", " << ax_front << std::endl;
						//std::cout << "AZ~ " << az << ", " << az_front << std::endl << std::endl;

						//camera[i].camera.setPosition(ax, ay, az-300);
						camera[i].camera.setPosition(ax_front, ay, az_front);
						camera[i].gridSceneNode->setPosition(irr::core::vector3df(0, 0, az+100));
					}
					else if(camera[i].pov == RC_CAMERA_VIEW_RIGHT)
					{
						float ax_right = ax - (cam_far/2);
						float az_right = az + (cam_far/4);

						irr::core::vector3df cam_pos(ax, ay, az);
						irr::core::vector3df cam_tgt = cam_pos;
						cam_tgt += irr::core::vector3df(0, 0, (cam_far/4));
						cam_tgt.rotateXZBy(camera[3].camera.ry, cam_pos);

						ax_right = cam_tgt.X - (cam_far/4);
						az_right = cam_tgt.Z;

						camera[i].camera.setPosition(ax_right, ay, az_right);
					}
					else if(camera[i].pov == RC_CAMERA_VIEW_TOP)
					{
						float ax_top = 0;
						float ay_top = ay + (cam_far/2);
						float az_top = az + (cam_far/4);

						irr::core::vector3df cam_pos(ax, ay, az);
						irr::core::vector3df cam_tgt = cam_pos;
						cam_tgt += irr::core::vector3df(0, 0, (cam_far/4));
						cam_tgt.rotateXZBy(-camera[3].camera.ry, cam_pos);

						ax_top = cam_tgt.X;
						az_top = cam_tgt.Z;

						camera[i].camera.setPosition(ax_top, ay_top, az_top);
					}
				}
			}
		}
	}
	else if( (!mouse_state.MiddleIsDown()) && middle_drag_init )
	{
		SHOW_CURSOR;
		//this->ReleaseMouse();
		middle_drag_init = false;
		//wxMessageBox(_("RELEASE"));
	}
}

int wxIrrlicht::irr_LoadFont(std::string fnt_file, int font_size)
{
	irr::io::path file_path = fnt_file.c_str();
    int font_id = -1;
    for(int i = 0; i < MAX_FONTS; i++)
    {
        if(!font[i].active)
        {
            font_id = i;
            break;
        }
    }

    if(font_id < 0)
		return -1;

    CGUITTFace* Face;
    CGUIFreetypeFont* dfont;

    Face = new CGUITTFace();
    Face->load(file_path);

    dfont = new CGUIFreetypeFont(m_pDriver);
    dfont->attach(Face, font_size);

    if(!dfont)
	{
		if(Face)
		{
			delete Face;
			return -1;
		}
	}

	font[font_id].face = Face;
	font[font_id].font = dfont;
	font[font_id].font_size = font_size;
	font[font_id].active = true;

	if(active_font < 0)
		active_font = font_id;

    return font_id;
}


void wxIrrlicht::irr_DeleteFont(int font_id)
{
	if(font_id < 0 || font_id >= MAX_FONTS)
		return;

    if(font[font_id].active)
    {
        delete font[font_id].font;
        delete font[font_id].face;
        font[font_id].font = NULL;
        font[font_id].face = NULL;
        font[font_id].font_size = 0;
        font[font_id].active = false;
    }
}

void wxIrrlicht::irr_SetFont(int font_id)
{
	if(font_id < 0 || font_id >= MAX_FONTS)
		return;

    if(font[font_id].active)
        active_font = font_id;
}

void wxIrrlicht::irr_DrawText(std::string txt, int x, int y, irr::video::SColor color, int camera_index)
{
	if(active_font < 0 || active_font >= MAX_FONTS)
		return;

    if(!font[active_font].active)
        return;

	m_pDriver->setRenderTarget(camera[camera_index].ui_layer, false, false);

    std::wstring text = utf8_to_wstring(txt);
	irr::core::dimension2d<irr::u32> text_dim = font[active_font].font->getDimension(text.c_str());
	irr::core::rect<s32> tpos(x, y, text_dim.Width, font[active_font].font_size);
    font[active_font].font->draw(text.c_str(), tpos, color);

        //std::cout << "------------------" << std::endl;

}


void wxIrrlicht::SetViews(int view_flag, int view0_pov, int view1_pov, int view2_pov, int view3_pov)
{
	if(view_flag == RC_CAMERA_VIEW_ALL)
	{
		bool viewport_switch = true; //(num_views == 1);

		num_views = 4;
		camera[0].pov = view0_pov;
		camera[1].pov = view1_pov;
		camera[2].pov = view2_pov;
		camera[3].pov = view3_pov;

		if(viewport_switch)
		{
			float ax = 0;
			float ay = 0;
			float az = 0;
			camera[active_camera].camera.getPosition(ax, ay, az);

			float rx = camera[active_camera].camera.rx;
			float ry = camera[active_camera].camera.ry;
			float rz = camera[active_camera].camera.rz;

			for(int i = 0; i < num_views; i++)
			{
				if(camera[i].pov == RC_CAMERA_VIEW_FRONT)
				{
					camera[i].camera.setPosition(ax, ay, az-300);
					camera[i].gridSceneNode->setPosition(irr::core::vector3df(0, 0, az+100));
					//camera[i].camera.setRotation(0, 0, 0);
				}
				else if(camera[i].pov == RC_CAMERA_VIEW_RIGHT)
				{
					camera[i].camera.setPosition(ax-300, ay, az);
					camera[i].gridSceneNode->setPosition(irr::core::vector3df(ax+100, 0, 0));
					//camera[i].camera.setRotation(0, 90, 0);
				}
				else if(camera[i].pov == RC_CAMERA_VIEW_TOP)
				{
					camera[i].camera.setPosition(ax, ay+300, az);
					camera[i].gridSceneNode->setPosition(irr::core::vector3df(0, ay-100, 0));
					//camera[i].camera.setRotation(90, 0, 0);
				}
				else
				{
					camera[i].camera.setPosition(ax, ay, az);
					camera[i].gridSceneNode->setPosition(irr::core::vector3df(0, 0, 0));
					camera[i].camera.setRotation(rx, ry, rz);
				}
			}
		}
	}
	else
	{
		bool viewport_switch = true; //(num_views == 4);

		num_views = 1;
		camera[0].pov = view_flag;

		if(viewport_switch)
		{
			//wxMessageBox(_("BALLS"));
			float ax = 0;
			float ay = 0;
			float az = 0;
			camera[3].camera.getPosition(ax, ay, az);

			float rx = camera[3].camera.rx;
			float ry = camera[3].camera.ry;
			float rz = camera[3].camera.rz;

			for(int i = 0; i < num_views; i++)
			{
				if(camera[i].pov == RC_CAMERA_VIEW_FRONT)
				{
					camera[i].camera.setPosition(ax, ay, az-300);
					camera[i].gridSceneNode->setPosition(irr::core::vector3df(0, 0, az+100));
					//camera[i].camera.setRotation(0, 0, 0);
				}
				else if(camera[i].pov == RC_CAMERA_VIEW_RIGHT)
				{
					camera[i].camera.setPosition(ax-300, ay, az);
					camera[i].gridSceneNode->setPosition(irr::core::vector3df(ax+100, 0, 0));
					//camera[i].camera.setRotation(0, 90, 0);
				}
				else if(camera[i].pov == RC_CAMERA_VIEW_TOP)
				{
					camera[i].camera.setPosition(ax, ay+300, az);
					camera[i].gridSceneNode->setPosition(irr::core::vector3df(0, ay-100, 0));
					//camera[i].camera.setRotation(90, 0, 0);
				}
				else
				{
					camera[i].camera.setPosition(ax, ay, az);
					camera[i].gridSceneNode->setPosition(irr::core::vector3df(0, 0, 0));
					camera[i].camera.setRotation(rx, ry, rz);
				}
			}
		}
	}

	SetCameraViewParam();
}
