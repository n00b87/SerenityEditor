#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibar.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/panel.h>
#include <wx/treectrl.h>
#include <wx/notebook.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/splitter.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/clrpicker.h>
#include <wx/scrolwin.h>
#include <wx/aui/auibook.h>
#include <wx/button.h>
#include <wx/listbox.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>
#include <wx/statbmp.h>
#include <wx/filepicker.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include "MeshTab_SetMaterialSelection.h"



MT_SetMaterialPanel::MT_SetMaterialPanel(wxWindow* parent, serenity_project* p) : wxPanel( parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL )
{
	wxBoxSizer* b_setMaterial_Sizer;
	b_setMaterial_Sizer = new wxBoxSizer( wxHORIZONTAL );

	m_materialLabel_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b_materialLabel_Sizer;
	b_materialLabel_Sizer = new wxBoxSizer( wxHORIZONTAL );

	m_materialNumber_staticText = new wxStaticText( m_materialLabel_panel, wxID_ANY, wxT("Material [0]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_materialNumber_staticText->Wrap( -1 );
	b_materialLabel_Sizer->Add( m_materialNumber_staticText, 0, wxALIGN_CENTER_VERTICAL, 5 );


	m_materialLabel_panel->SetSizer( b_materialLabel_Sizer );
	m_materialLabel_panel->Layout();
	b_materialLabel_Sizer->Fit( m_materialLabel_panel );
	b_setMaterial_Sizer->Add( m_materialLabel_panel, 1, wxALIGN_CENTER_VERTICAL, 5 );

	m_materialID_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b_materialID_Sizer;
	b_materialID_Sizer = new wxBoxSizer( wxHORIZONTAL );

	m_materialID_comboBox = new wxComboBox( m_materialID_panel, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	b_materialID_Sizer->Add( m_materialID_comboBox, 1, wxALIGN_CENTER_VERTICAL, 5 );


	m_materialID_panel->SetSizer( b_materialID_Sizer );
	m_materialID_panel->Layout();
	b_materialID_Sizer->Fit( m_materialID_panel );
	b_setMaterial_Sizer->Add( m_materialID_panel, 4, wxALL, 5 );


	this->SetSizer( b_setMaterial_Sizer );
	this->Layout();
	//this->Fit( m_setMaterial_panel );
	//this->Centre( wxBOTH );
}

MT_SetMaterialPanel::~MT_SetMaterialPanel()
{
}

void MT_SetMaterialPanel::initMeshMaterialLink(int m_mesh_index, int m_material_number)
{
	mesh_index = m_mesh_index;
	material_num = m_material_number;

	m_materialNumber_staticText->SetLabel(_("Material ") + wxString::Format(_("%d"), m_material_number) + _(":"));
	m_materialNumber_staticText->Refresh();
}

void MT_SetMaterialPanel::setMaterial()
{
	wxString material_name = m_materialID_comboBox->GetStringSelection();

	for(int i = 0; i < project->materials.size(); i++)
	{
		if(material_name.compare(project->materials[i].id_name)==0)
		{
			project->meshes[mesh_index].material_index[material_num] = i;
			break;
		}
	}
}

void MT_SetMaterialPanel::updateMaterialOptions()
{
	wxString material_name = m_materialID_comboBox->GetStringSelection();
	int m_index = -1;
	m_materialID_comboBox->Clear();

	for(int i = 0; i < project->materials.size(); i++)
	{
		m_materialID_comboBox->Insert(project->materials[i].id_name, i);

		if(project->materials[i].id_name.compare(material_name)==0)
			m_index = i;
	}

	if(m_index >= 0)
		m_materialID_comboBox->SetSelection(m_index);
}
