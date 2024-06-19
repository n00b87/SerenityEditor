#include <irrlicht.h>
#include "wxIrrlicht.h"
#include "SerenityEditorSerenity3D_Frame.h"

SerenityEditorSerenity3D_Frame::SerenityEditorSerenity3D_Frame( wxWindow* parent )
:
Serenity3D_Frame( parent )
{
	m_stagePOV_comboBox->Insert(_("Front"),0);
	m_stagePOV_comboBox->Insert(_("Left"),1);
	m_stagePOV_comboBox->Insert(_("Top"),2);
	m_stagePOV_comboBox->Insert(_("Perspective"),3);
	m_stagePOV_comboBox->Insert(_("All"),4);
	m_stagePOV_comboBox->SetSelection(0);
}

void SerenityEditorSerenity3D_Frame::OnPlayClicked( wxCommandEvent& event )
{
    //wxMessageBox(_("Panel Size = ") + wxString::Format(_("%i"), m_panel44->GetClientSize().GetWidth()));

    wxMessageBox(_("Start Constructor"));
    wxIrrlicht* irrTst=new wxIrrlicht(m_stageViewport_panel, wxID_ANY, false, wxPoint(ClientW(0), ClientH(0)), m_stageViewport_panel->GetClientSize());
		//irrTst->SetBackgroundColour(wxColour("red"));
		wxMessageBox(_("Start Init"));
		irrTst->InitIrr();
		irrTst->StartRendering();


		irr::IrrlichtDevice* device = irrTst->GetDevice();
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


    wxMessageBox(_("IrrTst Size = ") + wxString::Format(_("%i"), irrTst->GetClientSize().GetWidth()));
}

void SerenityEditorSerenity3D_Frame::OnStopClicked( wxCommandEvent& event )
{
    //wxMessageBox(_("Panel Size = ") + wxString::Format(_("%i"), m_panel44->GetClientSize().GetWidth()));

    //wxMessageBox(_("Start Constructor"));
    animation_window=new wxIrrlicht(m_modelView_panel, wxID_ANY, false, wxPoint(ClientW(0), ClientH(0)), wxGetDisplaySize());
		//irrTst->SetBackgroundColour(wxColour("red"));
		wxMessageBox(_("Start Frame"));
		irr::SIrrlichtCreationParameters params;
		params.WindowSize.set(m_modelView_panel->GetClientSize().GetWidth(), m_modelView_panel->GetClientSize().GetHeight());
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
