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
#include <wx/ribbon/toolbar.h>
#include <wx/ribbon/panel.h>
#include <wx/ribbon/page.h>
#include <wx/ribbon/control.h>
#include <wx/ribbon/art.h>
#include <wx/ribbon/bar.h>
#include <wx/simplebook.h>
#include <wx/srchctrl.h>
#include <wx/listbox.h>
#include <wx/aui/auibook.h>
#include <wx/notebook.h>
#include <wx/splitter.h>
#include <wx/treectrl.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
#include <wx/frame.h>

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
		wxSimplebook* m_simplebook3;
		wxPanel* m_tools3D_panel;
		wxPanel* m_panel30;
		wxStaticText* m_staticText7;
		wxAuiToolBar* m_auiToolBar5;
		wxAuiToolBarItem* m_s3d_select_tool;
		wxAuiToolBarItem* m_s3d_boxSelect_tool;
		wxAuiToolBarItem* m_s3d_move_tool;
		wxAuiToolBarItem* m_s3d_rotate_tool;
		wxAuiToolBarItem* m_s3d_scale_tool;
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
		wxAuiToolBarItem* m_scene_effect_tool;
		wxPanel* m_panel306;
		wxStaticText* m_staticText75;
		wxAuiToolBar* m_auiToolBar55;
		wxAuiToolBarItem* m_s3d_select_tool1;
		wxPanel* m_toolsNone_panel;
		wxPanel* m_tools2D_panel;
		wxRibbonBar* m_ribbonBar3;
		wxRibbonPage* m_ribbonPage3;
		wxRibbonPanel* m_ribbonPanel6;
		wxRibbonToolBar* m_ribbonToolBar6;
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
		wxPanel* m_panel16;
		wxNotebook* m_notebook1;
		wxPanel* m_panel32;
		wxPanel* m_panel31;
		wxPanel* m_panel8;
		wxAuiNotebook* m_auinotebook3;
		wxPanel* m_panel25;
		wxSplitterWindow* m_splitter6;
		wxPanel* m_panel305;
		wxTreeCtrl* m_treeCtrl2;
		wxPanel* m_panel311;
		wxPropertyGrid* m_propertyGrid3;
		wxPanel* m_stage_actor_panel;
		wxSplitterWindow* m_splitter4;
		wxPanel* m_panel12;
		wxTreeCtrl* m_treeCtrl1;
		wxPanel* m_panel13;
		wxPropertyGrid* m_propertyGrid1;
		wxPanel* m_panel6;
		wxSplitterWindow* m_splitter51;
		wxPanel* m_panel28;
		wxListBox* m_listBox31;
		wxPanel* m_panel291;
		wxStatusBar* m_statusBar1;
		wxToolBar* m_toolBar1;
		wxToolBarToolBase* m_tool1;
		wxToolBarToolBase* m_tool2;
		wxToolBarToolBase* m_tool3;
		wxToolBarToolBase* m_tool6;
		wxToolBarToolBase* m_tool7;

	public:

		Serenity3D_Frame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Serenity Engine"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1240,812 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Serenity3D_Frame();

		void m_splitter1OnIdle( wxIdleEvent& )
		{
			m_splitter1->SetSashPosition( 204 );
			m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter1OnIdle ), NULL, this );
		}

		void m_splitter3OnIdle( wxIdleEvent& )
		{
			m_splitter3->SetSashPosition( 768 );
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

		void m_splitter4OnIdle( wxIdleEvent& )
		{
			m_splitter4->SetSashPosition( 0 );
			m_splitter4->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter4OnIdle ), NULL, this );
		}

		void m_splitter51OnIdle( wxIdleEvent& )
		{
			m_splitter51->SetSashPosition( 233 );
			m_splitter51->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter51OnIdle ), NULL, this );
		}

};

