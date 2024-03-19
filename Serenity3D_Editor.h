///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

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
#include <wx/stattext.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibar.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/srchctrl.h>
#include <wx/listbox.h>
#include <wx/notebook.h>
#include <wx/simplebook.h>
#include <wx/combobox.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/aui/auibook.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/splitter.h>
#include <wx/treectrl.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/clrpicker.h>
#include <wx/textctrl.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
#include <wx/frame.h>
#include <wx/scrolwin.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Serenity3D_Frame
///////////////////////////////////////////////////////////////////////////////
class Serenity3D_Frame : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_file_menu;
		wxMenu* m_view_menu;
		wxAuiNotebook* m_auinotebook2;
		wxPanel* m_stage_panel;
		wxSplitterWindow* m_splitter1;
		wxPanel* m_panel161;
		wxSimplebook* m_simplebook2;
		wxPanel* m_panel4;
		wxPanel* m_tools3D_panel;
		wxPanel* m_panel30;
		wxStaticText* m_staticText7;
		wxAuiToolBar* m_auiToolBar5;
		wxAuiToolBarItem* m_s3d_select_tool;
		wxAuiToolBarItem* m_s3d_boxSelect_tool;
		wxAuiToolBarItem* m_s3d_move_tool;
		wxAuiToolBarItem* m_s3d_rotate_tool;
		wxAuiToolBarItem* m_s3d_scale_tool;
		wxNotebook* m_notebook2;
		wxPanel* m_panel50;
		wxPanel* m_panel301;
		wxStaticText* m_staticText71;
		wxAuiToolBar* m_auiToolBar51;
		wxAuiToolBarItem* m_prim3d_plane_tool;
		wxAuiToolBarItem* m_prim3d_cube_tool;
		wxAuiToolBarItem* m_prim3d_sphere_tool;
		wxAuiToolBarItem* m_prim3d_cylinder_tool;
		wxPanel* m_panel303;
		wxStaticText* m_staticText73;
		wxAuiToolBar* m_auiToolBar53;
		wxAuiToolBarItem* m_geo_terrain_tool;
		wxAuiToolBarItem* m_geo_water_tool;
		wxAuiToolBarItem* m_geo_grass_tool;
		wxPanel* m_panel304;
		wxStaticText* m_staticText74;
		wxAuiToolBar* m_auiToolBar54;
		wxAuiToolBarItem* m_scene3d_camera_tool;
		wxAuiToolBarItem* m_scene3d_light_tool;
		wxPanel* m_panel306;
		wxStaticText* m_staticText75;
		wxAuiToolBar* m_auiToolBar55;
		wxAuiToolBarItem* m_m3d_path_tool;
		wxAuiToolBarItem* m_m3d_billboard_tool;
		wxAuiToolBarItem* m_scene_effect_tool;
		wxPanel* m_panel302;
		wxStaticText* m_staticText72;
		wxAuiToolBar* m_auiToolBar52;
		wxAuiToolBarItem* m_mesh_dump_tool;
		wxAuiToolBarItem* m_mesh_wiz_tool;
		wxPanel* m_meshList_panel;
		wxSearchCtrl* m_searchCtrl4;
		wxListBox* m_listBox3;
		wxPanel* m_panel5;
		wxSplitterWindow* m_splitter3;
		wxPanel* m_panel71;
		wxSplitterWindow* m_splitter5;
		wxPanel* m_panel15;
		wxAuiNotebook* m_stage_viewport_auinotebook;
		wxPanel* m_panel45;
		wxPanel* m_panel47;
		wxStaticText* m_staticText12;
		wxComboBox* m_comboBox3;
		wxPanel* m_panel48;
		wxStaticText* m_staticText11;
		wxComboBox* m_comboBox2;
		wxBitmapButton* m_bpButton3;
		wxBitmapButton* m_bpButton31;
		wxPanel* m_panel44;
		wxPanel* m_panel16;
		wxNotebook* m_notebook1;
		wxPanel* m_panel31;
		wxRichTextCtrl* m_richText1;
		wxPanel* m_panel8;
		wxAuiNotebook* m_auinotebook3;
		wxPanel* m_project_stages_panel;
		wxSplitterWindow* m_splitter6;
		wxPanel* m_panel305;
		wxTreeCtrl* m_treeCtrl2;
		wxPanel* m_panel311;
		wxPropertyGrid* m_propertyGrid3;
		wxPanel* m_viewport_settings_panel;
		wxPanel* m_panel49;
		wxPanel* m_panel57;
		wxStaticText* m_staticText39;
		wxStaticText* m_staticText40;
		wxStaticText* m_staticText43;
		wxStaticText* m_staticText42;
		wxStaticText* m_staticText44;
		wxPanel* m_panel56;
		wxStaticText* m_staticText36;
		wxCheckBox* m_checkBox1;
		wxStaticText* m_staticText37;
		wxSpinCtrl* m_spinCtrl2;
		wxStaticText* m_staticText38;
		wxSpinCtrl* m_spinCtrl3;
		wxStaticText* m_staticText41;
		wxColourPickerCtrl* m_colourPicker1;
		wxPanel* m_panel6;
		wxSplitterWindow* m_splitter51;
		wxPanel* m_panel28;
		wxListBox* m_listBox31;
		wxPanel* m_panel291;
		wxPanel* m_panel41;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_textCtrl9;
		wxStaticText* m_staticText321;
		wxTextCtrl* m_textCtrl91;
		wxStaticText* m_staticText3211;
		wxComboBox* m_comboBox7;
		wxPanel* m_panel42;
		wxPanel* m_panel43;
		wxStatusBar* m_statusBar1;
		wxToolBar* m_toolBar1;
		wxToolBarToolBase* m_tool1;
		wxToolBarToolBase* m_tool2;
		wxToolBarToolBase* m_tool3;
		wxToolBarToolBase* m_tbar_play_tool;
		wxToolBarToolBase* m_tool7;

		// Virtual event handlers, override them in your derived class
		virtual void OnPlayClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		Serenity3D_Frame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Serenity Engine"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1368,812 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Serenity3D_Frame();

		void m_splitter1OnIdle( wxIdleEvent& )
		{
			m_splitter1->SetSashPosition( 230 );
			m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter1OnIdle ), NULL, this );
		}

		void m_splitter3OnIdle( wxIdleEvent& )
		{
			m_splitter3->SetSashPosition( 850 );
			m_splitter3->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter3OnIdle ), NULL, this );
		}

		void m_splitter5OnIdle( wxIdleEvent& )
		{
			m_splitter5->SetSashPosition( 419 );
			m_splitter5->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter5OnIdle ), NULL, this );
		}

		void m_splitter6OnIdle( wxIdleEvent& )
		{
			m_splitter6->SetSashPosition( 0 );
			m_splitter6->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter6OnIdle ), NULL, this );
		}

		void m_splitter51OnIdle( wxIdleEvent& )
		{
			m_splitter51->SetSashPosition( 233 );
			m_splitter51->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter51OnIdle ), NULL, this );
		}

};

///////////////////////////////////////////////////////////////////////////////
/// Class StageCanvasSettings_Frame
///////////////////////////////////////////////////////////////////////////////
class StageCanvasSettings_Frame : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel33;
		wxScrolledWindow* m_scrolledWindow1;
		wxPanel* m_panel34;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxTextCtrl* m_textCtrl1;
		wxComboBox* m_comboBox4;
		wxButton* m_button3;
		wxButton* m_button2;
		wxPanel* m_panel341;
		wxStaticText* m_staticText91;
		wxStaticText* m_staticText101;
		wxTextCtrl* m_textCtrl11;
		wxComboBox* m_comboBox41;
		wxButton* m_button31;
		wxButton* m_button21;
		wxPanel* m_panel342;
		wxStaticText* m_staticText92;
		wxStaticText* m_staticText102;
		wxTextCtrl* m_textCtrl12;
		wxComboBox* m_comboBox42;
		wxButton* m_button32;
		wxButton* m_button22;
		wxPanel* m_panel343;
		wxStaticText* m_staticText93;
		wxStaticText* m_staticText103;
		wxTextCtrl* m_textCtrl13;
		wxComboBox* m_comboBox43;
		wxButton* m_button33;
		wxButton* m_button23;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;

	public:

		StageCanvasSettings_Frame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Canvas Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 682,420 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~StageCanvasSettings_Frame();

};

