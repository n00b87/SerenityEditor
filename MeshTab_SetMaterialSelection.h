#ifndef MESHTAB_SETMATERIALSELECTION_H_INCLUDED
#define MESHTAB_SETMATERIALSELECTION_H_INCLUDED

#pragma once

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
#include "engine_base.h"

class MT_SetMaterialPanel : public wxPanel
{
	private:

	protected:
		wxPanel* m_materialLabel_panel;
		wxStaticText* m_materialNumber_staticText;
		wxPanel* m_materialID_panel;
		wxComboBox* m_materialID_comboBox;
		serenity_project* project;

		int mesh_index; //The mesh index in project
		int material_num; //The material number on the mesh that this panel represents

	public:

		MT_SetMaterialPanel(wxWindow* parent, serenity_project* p);

		~MT_SetMaterialPanel();

		void initMeshMaterialLink(int m_mesh_index, int m_material_number);
		void setMaterial();
		void updateMaterialOptions();

};

#endif // MESHTAB_SETMATERIALSELECTION_H_INCLUDED
