#include <wx/stdpaths.h>
#include <irrlicht.h>
#include "wxIrrlicht.h"
#include "SerenityEditorSerenity3D_Frame.h"
#include "CGridSceneNode.h"
#include "engine_base.h"
#include "rc_stage.h"
#include "rc_defines.h"
#include "MeshTab_SetMaterialSelection.h"

SerenityEditorSerenity3D_Frame::SerenityEditorSerenity3D_Frame( wxWindow* parent )
:
Serenity3D_Frame( parent )
{
	m_stagePOV_comboBox->Insert(_("Front"),0);
	m_stagePOV_comboBox->Insert(_("Right"),1);
	m_stagePOV_comboBox->Insert(_("Top"),2);
	m_stagePOV_comboBox->Insert(_("Perspective"),3);
	m_stagePOV_comboBox->Insert(_("All"),4);
	m_stagePOV_comboBox->SetSelection(0);

	stage_tools.push_back(m_s3d_select_tool);
	stage_tools.push_back(m_s3d_boxSelect_tool);
	stage_tools.push_back(m_s3d_move_tool);
	stage_tools.push_back(m_s3d_rotate_tool);
	stage_tools.push_back(m_s3d_scale_tool);

	stage_tools.push_back(m_s3d_plane_tool);
	stage_tools.push_back(m_s3d_cube_tool);
	stage_tools.push_back(m_s3d_sphere_tool);
	//stage_tools.push_back(m_prim3d_cylinder_tool);

	stage_tools.push_back(m_s3d_octreeActor_tool);
	stage_tools.push_back(m_s3d_animatedActor_tool);
	stage_tools.push_back(m_s3d_billboardActor_tool);
	stage_tools.push_back(m_s3d_lightActor_tool);

	stage_tools.push_back(m_s3d_terrainActor_tool);
	stage_tools.push_back(m_s3d_waterActor_tool);
	//stage_tools.push_back(m_geo_grass_tool);

	stage_tools.push_back(m_s3d_path_tool);
	stage_tools.push_back(m_s3d_particleActor_tool);

	asset_dir = wxStandardPaths::Get().GetExecutablePath();
	asset_dir.AppendDir(_("assets"));



	stage_window=new wxIrrlicht(m_stageViewport_panel, wxID_ANY, false, wxPoint(ClientW(0), ClientH(0)), m_stageViewport_panel->GetClientSize());
	//irrTst->SetBackgroundColour(wxColour("red"));

	stage_window->InitIrr();
	stage_window->StartRendering();

	irr::IrrlichtDevice* device = stage_window->GetDevice();
	irr::video::IVideoDriver* driver = device->getVideoDriver();
	irr::scene::ISceneManager* smgr = device->getSceneManager();
	irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();


	//gridSceneNode->drop();  // added to scene already, that still has a reference

	irr::scene::IAnimatedMesh* mesh = smgr->getMesh("media/sydney.md2");
	if (!mesh)
	{
		wxMessageBox(_("No dice"));
		//device->drop();
		return;
	}
	irr::scene::IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh );

	if (node)
	{
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		node->setMD2Animation(irr::scene::EMAT_STAND);
		node->setMaterialTexture( 0, driver->getTexture("media/sydney.bmp") );
	}

	stage_window->camera[0].camera.setPosition(0, 0, -100);
	stage_window->camera[0].camera.setRotation(0, 0, 0);

	stage_window->camera[1].camera.setPosition(-100, 0, 0);
	stage_window->camera[1].camera.setRotation(0, 90, 0);

	stage_window->camera[2].camera.setPosition(0, 100, 0);
	stage_window->camera[2].camera.setRotation(90, 0, 0);

	stage_window->camera[3].camera.setPosition(0, 30, -40);
	stage_window->camera[3].camera.setRotation(0, 5, 0);


	//b_setMaterial_Sizer = new wxBoxSizer( wxVERTICAL );
	//m_setMaterial_scrolledWindow->SetSizer(b_setMaterial_Sizer);
	//m_setMaterial_scrolledWindow->Layout();
	//m_setMaterial_scrolledWindow->Fit();

	//m_mesh_material_propertyGrid->SetSplitterPosition(90);
}

void SerenityEditorSerenity3D_Frame::OnPlayClicked( wxCommandEvent& event )
{
}

void SerenityEditorSerenity3D_Frame::OnStopClicked( wxCommandEvent& event )
{
    //wxMessageBox(_("Panel Size = ") + wxString::Format(_("%i"), m_panel44->GetClientSize().GetWidth()));

    //wxMessageBox(_("Start Constructor"));
    animation_window=new wxIrrlicht(m_mesh_animationPreview_panel, wxID_ANY, false, wxPoint(ClientW(0), ClientH(0)), wxGetDisplaySize());
		//irrTst->SetBackgroundColour(wxColour("red"));
		wxMessageBox(_("Start Frame"));
		irr::SIrrlichtCreationParameters params;
		params.WindowSize.set(m_mesh_animationPreview_panel->GetClientSize().GetWidth(), m_mesh_animationPreview_panel->GetClientSize().GetHeight());
		params.DriverType = irr::video::EDT_BURNINGSVIDEO;
		animation_window->InitIrr(&params);
		animation_window->StartRendering();

		irr::IrrlichtDevice* device = animation_window->GetDevice();
		irr::video::IVideoDriver* driver = device->getVideoDriver();
        irr::scene::ISceneManager* smgr = device->getSceneManager();
        irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

        irr::scene::IAnimatedMesh* mesh = smgr->getMesh("media/sydney.md2");
        if (!mesh)
        {
            wxMessageBox(_("No dice"));
            //device->drop();
            return;
        }
        irr::scene::IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh );

        if (node)
        {
            node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            node->setMD2Animation(irr::scene::EMAT_STAND);
            node->setMaterialTexture( 0, driver->getTexture("media/sydney.bmp") );
        }

		smgr->addCameraSceneNode(0, irr::core::vector3df(0,30,-40), irr::core::vector3df(0,5,0));


    //wxMessageBox(_("IrrTst Size = ") + wxString::Format(_("%i"), irrTst->GetClientSize().GetWidth()));
}

void SerenityEditorSerenity3D_Frame::OnAnimationStopClicked( wxCommandEvent& event )
{

}

void SerenityEditorSerenity3D_Frame::OnAnimationPreviewSize( wxSizeEvent& event )
{

}


void SerenityEditorSerenity3D_Frame::updateToolSelection()
{
	for(int i = 0; i < stage_tools.size(); i++)
	{
		if(stage_tools[i]->GetKind() == wxITEM_CHECK)
		{
			stage_tools[i]->SetState(wxAUI_BUTTON_STATE_NORMAL);
		}
	}

	//This should always be true but better safe than sorry
	if(stage_tools_selection >= 0 && stage_tools_selection < stage_tools.size())
	{
		if(stage_tools[stage_tools_selection]->GetKind() == wxITEM_CHECK)
			stage_tools[stage_tools_selection]->SetState(wxAUI_BUTTON_STATE_CHECKED);
	}

	Refresh();
	Update();
}






int SerenityEditorSerenity3D_Frame::getStageToolIndex(wxAuiToolBarItem* toolbar_item)
{
	for(int i = 0; i < stage_tools.size(); i++)
	{
		if(stage_tools[i] == toolbar_item)
			return i;
	}
	return 0;
}

void SerenityEditorSerenity3D_Frame::OnS3DSelectClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_select_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DBoxClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_boxSelect_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DMoveClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_move_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DRotateClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_rotate_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DScaleClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_scale_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DPlaneClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_plane_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DCubeClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_cube_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DSphereClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_sphere_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DCylinderClicked( wxCommandEvent& event )
{
	//stage_tools_selection = getStageToolIndex(m_prim3d_cylinder_tool);
	//updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DDumpClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_octreeActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DWizClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_animatedActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DBillboardClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_billboardActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DLightClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_lightActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DTerrainClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_terrainActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DWaterClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_waterActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DGrassClicked( wxCommandEvent& event )
{
	//stage_tools_selection = getStageToolIndex(m_geo_grass_tool);
	//updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DPathClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_path_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DEffectClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_particleActor_tool);
	updateToolSelection();
}


//Stage Modes
void SerenityEditorSerenity3D_Frame::OnS3DModeEditClicked( wxCommandEvent& event )
{
	viewport_mode = RC_VIEWPORT_MODE_EDIT;
}

void SerenityEditorSerenity3D_Frame::OnS3DModeCameraClicked( wxCommandEvent& event )
{
	viewport_mode = RC_VIEWPORT_MODE_CAMERA;
}

void SerenityEditorSerenity3D_Frame::OnNewProjectMenuSelection( wxCommandEvent& event )
{
	project = serenity_project("/home/n00b/test/stp/test.snprj");
}


void SerenityEditorSerenity3D_Frame::OnStageViewportMouse( wxMouseEvent& event )
{
	//if(wxString::Format(_("%d"), event.GetEventType()).compare("10227")!=0 && wxString::Format(_("%d"), event.GetEventType()).compare("10226")!=0
	  // && wxString::Format(_("%d"), event.GetEventType()).compare("10228")!=0)
		//wxMessageBox(_("EVT DEBUG: ") + wxString::Format(_("%d"), event.GetEventType()));

	if(wxString::Format(_("%d"), event.GetEventType()).compare("10220")==0)
		wxMessageBox(_("LEFT"));

	if(event.GetEventType() == wxEVT_MOTION)
	{
		wxPoint pt = wxGetMousePosition();
		mouse_x = pt.x - m_stageViewport_panel->GetScreenPosition().x;
		mouse_y = pt.y - m_stageViewport_panel->GetScreenPosition().y;
	}
	else if(event.GetEventType() == wxEVT_LEFT_DOWN || event.GetEventType() == wxEVT_LEFT_UP)
	{
		mouse_button = ( event.GetEventType() == wxEVT_LEFT_DOWN ? RC_MOUSEBUTTON_LEFT : RC_MOUSEBUTTON_NONE);
		//wxMessageBox(_("Pos: ") + wxString::Format(_("%d"), mouse_x) + _(", ") + wxString::Format(_("%d"), mouse_y));
	}
	else if(event.GetEventType() == wxEVT_RIGHT_DOWN || event.GetEventType() == wxEVT_RIGHT_UP)
	{
		mouse_button = ( event.GetEventType() == wxEVT_RIGHT_DOWN ? RC_MOUSEBUTTON_RIGHT : RC_MOUSEBUTTON_NONE);
		//wxMessageBox(_("Pos: ") + wxString::Format(_("%d"), mouse_x) + _(", ") + wxString::Format(_("%d"), mouse_y));
	}
	else if(event.GetEventType() == wxEVT_MIDDLE_DOWN || event.GetEventType() == wxEVT_MIDDLE_UP)
	{
		return;
		mouse_button = ( event.GetEventType() == wxEVT_MIDDLE_DOWN ? RC_MOUSEBUTTON_MIDDLE : RC_MOUSEBUTTON_NONE);
		wxSize panel_size = m_stageViewport_panel->GetSize();
		viewport_camera_mouse_x = panel_size.GetWidth()/2;
		viewport_camera_mouse_y = panel_size.GetHeight()/2;

		if(mouse_button == RC_MOUSEBUTTON_MIDDLE && (!viewport_camera_active))
		{
			m_stageViewport_panel->CaptureMouse();
			HIDE_CURSOR;
			m_stageViewport_panel->WarpPointer(viewport_camera_mouse_x, viewport_camera_mouse_y);
			viewport_camera_active = true;
			wxMessageBox(_("HIDE"));
		}
		else if(viewport_camera_active)
		{
			m_stageViewport_panel->ReleaseMouse();
			SHOW_CURSOR;
			viewport_camera_active = false;
		}
		//wxMessageBox(_("Pos: ") + wxString::Format(_("%d"), mouse_x) + _(", ") + wxString::Format(_("%d"), mouse_y));
	}
}

void SerenityEditorSerenity3D_Frame::OnStageContainerMouse( wxMouseEvent& event )
{
	if(wxString::Format(_("%d"), event.GetEventType()).compare("10220")==0)
		wxMessageBox(_("LEFT"));

	int px = m_stageViewport_panel->GetPosition().x;
	int py = m_stageViewport_panel->GetPosition().y;

	int pw = m_stageViewport_panel->GetSize().GetWidth();
	int ph = m_stageViewport_panel->GetSize().GetHeight();

	if(event.LeftDown())
		wxMessageBox(_("inside"));
}

void SerenityEditorSerenity3D_Frame::OnStageViewportSetFocus( wxFocusEvent& event )
{
	wxMessageBox(_("SET"));
}

void SerenityEditorSerenity3D_Frame::OnStageViewportKillFocus( wxFocusEvent& event )
{
	wxMessageBox(_("KILL"));
}


void SerenityEditorSerenity3D_Frame::OnViewComboSelect( wxCommandEvent& event )
{
	wxString pov_selection = m_stagePOV_comboBox->GetStringSelection();
	//wxMessageBox(_("SELECT: ") + pov_selection);

	if(!stage_window)
	{
		return;
	}

	if(pov_selection.compare(_("Front"))==0)
	{
		stage_window->SetViews(RC_CAMERA_VIEW_FRONT);

		stage_window->camera[0].camera.setPosition(0, 0, -100);
		stage_window->camera[0].camera.setRotation(0, 0, 0);
	}
	else if(pov_selection.compare(_("Right"))==0)
	{
		stage_window->SetViews(RC_CAMERA_VIEW_RIGHT);

		stage_window->camera[0].camera.setPosition(-100, 0, 0);
        stage_window->camera[0].camera.setRotation(0, 90, 0);
	}
	else if(pov_selection.compare(_("Top"))==0)
	{
		stage_window->SetViews(RC_CAMERA_VIEW_TOP);

		stage_window->camera[0].camera.setPosition(0, 100, 0);
        stage_window->camera[0].camera.setRotation(90, 0, 0);
	}
	else if(pov_selection.compare(_("Perspective"))==0)
	{
		stage_window->SetViews(RC_CAMERA_VIEW_PERSPECTIVE);

		stage_window->camera[0].camera.setPosition(0, 30, -40);
        stage_window->camera[0].camera.setRotation(0, 5, 0);
	}
	else
	{
		stage_window->SetViews(RC_CAMERA_VIEW_ALL, RC_CAMERA_VIEW_FRONT, RC_CAMERA_VIEW_RIGHT, RC_CAMERA_VIEW_TOP, RC_CAMERA_VIEW_PERSPECTIVE);

		stage_window->camera[0].camera.setPosition(0, 0, -100);
        stage_window->camera[0].camera.setRotation(0, 0, 0);

        stage_window->camera[1].camera.setPosition(-100, 0, 0);
        stage_window->camera[1].camera.setRotation(0, 90, 0);

        stage_window->camera[2].camera.setPosition(0, 100, 0);
        stage_window->camera[2].camera.setRotation(90, 0, 0);

        stage_window->camera[3].camera.setPosition(0, 30, -40);
        stage_window->camera[3].camera.setRotation(0, 5, 0);
	}
}


void SerenityEditorSerenity3D_Frame::clearMeshMaterialList()
{
	b_setMaterial_Sizer->Clear(true);
}

void SerenityEditorSerenity3D_Frame::appendMeshMaterialList(int material_index)
{
	MT_SetMaterialPanel* mpanel = new MT_SetMaterialPanel(m_setMaterial_scrolledWindow, &project);
	mpanel->updateMaterialOptions();

	if(material_index >= 0 && material_index < project.materials.size())
	{
	}

	b_setMaterial_Sizer->Add( mpanel, 0, wxALL, 0 );

	mesh_material_items.push_back(mpanel);

	m_setMaterial_scrolledWindow->Layout();
	m_setMaterial_scrolledWindow->Fit();
}

void SerenityEditorSerenity3D_Frame::OnMeshImportButtonClick( wxCommandEvent& event )
{

}
