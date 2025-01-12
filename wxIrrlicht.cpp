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

	ortho_matrix.buildProjectionMatrixOrthoLH(500.0f,300.0f,1.0f,-500.0f);
	perspective_matrix = camera[0].camera.camera->getProjectionMatrix();

	view2D_texture = NULL;

	m_init = true;

	wxString editor_path = wxStandardPaths::Get().GetExecutablePath();
	wxFileName font_fname(editor_path);
	font_fname.AppendDir(_("font"));
	font_fname.SetFullName(_("FreeMono.ttf"));

	ui_font1 = irr_LoadFont(font_fname.GetAbsolutePath().ToStdString(), 24);
	ui_font2 = irr_LoadFont(font_fname.GetAbsolutePath().ToStdString(), 16);
	//wxMessageBox(_("FNT: ") + wxString::Format(_("%d"), active_font));

	//wxMessageBox(_("GS:") + wxString::Format(_("%d"), (int)grid_size) + _(", ") + wxString::Format(_("%d"), (int)grid_spacing) + _(", ") + wxString::Format(_("%d"), (int)grid_color.color));

	if(init_params && (actual_params->DriverType == EDT_BURNINGSVIDEO || actual_params->DriverType == EDT_SOFTWARE))
	{
		force_refresh();
	}

}//InitIrr()

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
					irr::u32 fit_factor = 1;

					if(texture_size.Height > texture_size.Width)
					{
						fit_factor = camera[i].h / (texture_size.Height < 1 ? 1 : texture_size.Height);
					}
					else
					{
						fit_factor = camera[i].w / (texture_size.Width < 1 ? 1 : texture_size.Width);
					}

					fit_factor = (fit_factor < 1 ? 1 : fit_factor);

					irr::core::rect src( irr::core::position2di(0, 0), texture_size );
					irr::core::rect dst( irr::core::position2di(0, 0), irr::core::dimension2d(texture_size.Width * fit_factor, texture_size.Height * fit_factor) );
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


				switch(camera[i].pov)
				{
					case RC_CAMERA_VIEW_FRONT:
							irr_SetFont(ui_font1);
							irr_DrawText("Front", 10, 10, irr::video::SColor(255,255,255,255), i);
							camera[i].camera.camera->setProjectionMatrix(ortho_matrix);
							break;
					case RC_CAMERA_VIEW_RIGHT:
							irr_SetFont(ui_font1);
							irr_DrawText("Right", 10, 10, irr::video::SColor(255,255,255,255), i);
							camera[i].camera.camera->setProjectionMatrix(ortho_matrix);
							break;
					case RC_CAMERA_VIEW_TOP:
							irr_SetFont(ui_font1);
							irr_DrawText("Top", 10, 10, irr::video::SColor(255,255,255,255), i);
							camera[i].camera.camera->setProjectionMatrix(ortho_matrix);
							break;
					case RC_CAMERA_VIEW_PERSPECTIVE:
							irr_SetFont(ui_font1);
							irr_DrawText("Perspective", 10, 10, irr::video::SColor(255,255,255,255), i);
							camera[i].camera.camera->setProjectionMatrix(perspective_matrix);
							break;
				}

				if(show_camera_info)
				{
					irr_SetFont(ui_font2);
					wxString pos_str = _("POS: ") + wxString::Format(_("%d"), (int)camera[i].camera.x) + _(", ") +
													wxString::Format(_("%d"), (int)camera[i].camera.y) + _(", ") +
													wxString::Format(_("%d"), (int)camera[i].camera.z);

					wxString rot_str = _("ROT: ") + wxString::Format(_("%d"), (int)( ((int)camera[i].camera.rx) % 360)) + _(", ") +
													wxString::Format(_("%d"), (int)( ((int)camera[i].camera.ry) % 360)) + _(", ") +
													wxString::Format(_("%d"), (int)( ((int)camera[i].camera.rz) % 360));
					irr_DrawText(pos_str.ToStdString(), camera[i].w-200, 10, irr::video::SColor(255,255,255,255), i);
					irr_DrawText(rot_str.ToStdString(), camera[i].w-200, 30, irr::video::SColor(255,255,255,255), i);
				}

				m_pDriver->setRenderTarget(camera[i].texture, true, true, irr::video::SColor(255,170,170,170));


				m_pSceneManager->setActiveCamera(camera[i].camera.camera);
				camera[i].camera.update();

				m_pDriver->setViewPort(irr::core::rect<irr::s32>(0,0,camera[i].w, camera[i].h));
				m_pSceneManager->drawAll();

				for(int sn = 0; sn < selected_actors.size(); sn++)
				{
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

				camera[i].gridSceneNode->setVisible(false);
			}
		}

		m_pDriver->setRenderTarget(back_buffer, true, true);

		bool showOutline = (num_views == 4);

		for(int i = 0; i < num_views; i++)
		{
			irr::core::rect src( irr::core::position2di(0, 0), irr::core::dimension2di(camera[i].w, camera[i].h) );
			irr::core::rect dest( irr::core::position2di(camera[i].x, camera[i].y), irr::core::dimension2di(camera[i].w, camera[i].h) );
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

			m_pDriver->draw2DRectangleOutline( irr::core::rect( irr::core::position2di(camera[i].x, camera[i].y), irr::core::dimension2di(camera[i].w, camera[i].h) ), irr::video::SColor(255, 40, 40, 40) );
		}

        m_pDriver->setRenderTarget(0);

        irr::core::rect bb_rect( irr::core::position2di(0, 0), irr::core::dimension2di(this->GetSize().GetWidth(), this->GetSize().GetHeight()) );
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

	m_pDevice->setWindowSize(irr::core::dimension2d((irr::u32)w,(irr::u32)h));
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

void wxIrrlicht::OnTimer(wxTimerEvent& event) {
	if(!m_init)
		return;

    m_pDevice->getTimer()->tick();

    if(window_type != RC_IRR_WINDOW_VIEW2D)
		OnUpdate();

    #ifdef _WIN32
	m_forceWindowActive = true;
	parent->Refresh();
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

	m_pDevice->setWindowSize(irr::core::dimension2d((irr::u32)w,(irr::u32)h));

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

void wxIrrlicht::OnUpdate()
{
	if(window_type == RC_IRR_WINDOW_MATERIAL)
	{
		//ROTATE AROUND (0, 0, 0)
		irr::core::vector3df cam_pos = camera[0].camera.camera->getAbsolutePosition();
		cam_pos.rotateXZBy(material_view_camera_speed, irr::core::vector3df(0,cam_pos.Y,0));
		camera[0].camera.setPosition(cam_pos.X, cam_pos.Y, cam_pos.Z);
		camera[0].camera.setRotation(camera[0].camera.rx, camera[0].camera.ry-material_view_camera_speed, camera[0].camera.rz);
		return;
	}
	else if(window_type == RC_IRR_WINDOW_ANIMATION)
	{
		AnimationPreview_Update();
		return;
	}

	wxMouseState  mouse_state = wxGetMouseState();

	int px = mouse_state.GetPosition().x - this->GetScreenPosition().x;
	int py = mouse_state.GetPosition().y - this->GetScreenPosition().y;

	int pw = this->GetSize().GetWidth();
	int ph = this->GetSize().GetHeight();

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



	if(mouse_state.LeftIsDown())
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
			}
		}
		else if(left_drag_init)
		{
		}



		switch(stage_edit_tool)
		{
			case RC_EDIT_TOOL_SELECT:
			{

				if(init_click)
				{
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
							if(scene_actors[i].node->isVisible())
								selected_actors.push_back(scene_actors[i]);
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


				selected_actors.clear();

				irr::core::vector2di drag_v1( (drag_start.x < px ? drag_start.x : px) , (drag_start.y < py ? drag_start.y : py) );
				irr::core::vector2di drag_v2( (drag_start.x > px ? drag_start.x : px) , (drag_start.y > py ? drag_start.y : py) );

				box_select_shape = irr::core::rect<irr::s32>( drag_v1, drag_v2 );

				for(int i = 0; i < scene_actors.size(); i++)
				{
					irr::core::vector3df pos = scene_actors[i].node->getAbsolutePosition();
					irr::core::vector2d<irr::s32> v1 = collman->getScreenCoordinatesFrom3DPosition(pos, camera[active_camera].camera.camera, true);

					scene_actors[i].v1[active_camera] = irr::core::vector2d<irr::s32>( v1.X + camera[active_camera].x, v1.Y + camera[active_camera].y );


					v1 = scene_actors[i].v1[active_camera];

					if(box_select_shape.isPointInside(v1))
					{
						//irr::f32 d_start = ray.start.getDistanceFrom(pos);
						//irr::f32 d_end = ray.end.getDistanceFrom(pos);
						//if(d_end < d_start)
						if(scene_actors[i].node->isVisible())
							selected_actors.push_back(scene_actors[i]);
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
					for(int i = 0; i < selected_actors.size(); i++)
					{
						selected_actors[i].t_start = selected_actors[i].node->getAbsolutePosition();
					}
				}

				if(!left_drag_init)
					break;


				irr::core::vector3df translate_vector(0.0f, 0.0f, 0.0f);

				double translate_factor_x = 500/((double)camera[box_select_view].w);
				double translate_factor_y = 300/((double)camera[box_select_view].h);

				switch(camera[box_select_view].pov) //box_select_view can be used for every other tool
				{
					case RC_CAMERA_VIEW_FRONT:
						translate_vector.set(((double)px - drag_start.x)*translate_factor_x, ((double)(drag_start.y - py))*translate_factor_y, 0);
					break;
				}

				for(int i = 0; i < selected_actors.size(); i++)
				{
					selected_actors[i].node->setPosition( selected_actors[i].t_start + translate_vector );
				}

			}
			break;

			case RC_EDIT_TOOL_ROTATE:
			break;

			case RC_EDIT_TOOL_SCALE:
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
				}
				break;

				case RC_CAMERA_VIEW_LEFT:
				case RC_CAMERA_VIEW_RIGHT:
				{
					camera[active_camera].camera.translateW(0, delta_y, delta_x);
				}
				break;

				case RC_CAMERA_VIEW_TOP:
				case RC_CAMERA_VIEW_BOTTOM:
				{
					camera[active_camera].camera.translateW(-delta_x, 0, delta_y);
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
		num_views = 4;
		camera[0].pov = view0_pov;
		camera[1].pov = view1_pov;
		camera[2].pov = view2_pov;
		camera[3].pov = view3_pov;
	}
	else
	{
		num_views = 1;
		camera[0].pov = view_flag;
	}

	SetCameraViewParam();
}
