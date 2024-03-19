#include <irrlicht/irrlicht.h>
#include "wxIrrlicht.h"
#include "SerenityEditorSerenity3D_Frame.h"

SerenityEditorSerenity3D_Frame::SerenityEditorSerenity3D_Frame( wxWindow* parent )
:
Serenity3D_Frame( parent )
{
    //m_stage_view_panel
    //wxBoxSizer* bSizer = new wxBoxSizer( wxHORIZONTAL );
	//m_stage_view_panel->SetSizer(bSizer);

	//wxMessageBox(_("Panel Size = ") + wxString::Format(_("%i"), m_panel44->GetClientSize()));

    //wxIrrlicht* irrTst=new wxIrrlicht(m_panel44, wxID_ANY, false, wxPoint(ClientW(2), ClientH(2)), wxSize(ClientW(50), ClientH(50)));
		//irrTst->SetBackgroundColour(wxColour("red"));
		//irrTst->InitIrr();
		//irrTst->StartRendering();
}

void SerenityEditorSerenity3D_Frame::OnPlayClicked( wxCommandEvent& event )
{
    wxMessageBox(_("Panel Size = ") + wxString::Format(_("%i"), m_panel44->GetClientSize().GetWidth()));

    wxIrrlicht* irrTst=new wxIrrlicht(m_panel44, wxID_ANY, false, wxPoint(ClientW(0), ClientH(0)), m_panel44->GetClientSize());
		//irrTst->SetBackgroundColour(wxColour("red"));
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
