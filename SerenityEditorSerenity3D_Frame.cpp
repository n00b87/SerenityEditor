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
		irrTst->SetBackgroundColour(wxColour("red"));
		irrTst->InitIrr();
		irrTst->StartRendering();

    wxMessageBox(_("IrrTst Size = ") + wxString::Format(_("%i"), irrTst->GetClientSize().GetWidth()));
}
