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
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/ribbon/toolbar.h>
#include <wx/ribbon/panel.h>
#include <wx/ribbon/page.h>
#include <wx/ribbon/control.h>
#include <wx/ribbon/art.h>
#include <wx/ribbon/bar.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/simplebook.h>
#include <wx/aui/auibook.h>
#include <wx/splitter.h>
#include <wx/listbox.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
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
		wxAuiNotebook* m_auinotebook2;
		wxPanel* m_stage_panel;
		wxSplitterWindow* m_splitter1;
		wxPanel* m_panel161;
		wxSimplebook* m_simplebook2;
		wxPanel* m_panel4;
		wxRibbonBar* m_ribbonBar1;
		wxRibbonPage* m_ribbonPage1;
		wxRibbonPanel* m_ribbonPanel1;
		wxRibbonToolBar* m_ribbonToolBar1;
		wxRibbonPanel* m_ribbonPanel2;
		wxRibbonToolBar* m_ribbonToolBar2;
		wxRibbonPanel* m_ribbonPanel4;
		wxRibbonToolBar* m_ribbonToolBar3;
		wxRibbonPanel* m_ribbonPanel5;
		wxRibbonToolBar* m_ribbonToolBar4;
		wxPanel* m_panel5;
		wxSplitterWindow* m_splitter3;
		wxPanel* m_panel71;
		wxSplitterWindow* m_splitter5;
		wxPanel* m_panel15;
		wxAuiNotebook* m_stage_viewport_auinotebook;
		wxPanel* m_panel16;
		wxPanel* m_panel8;
		wxAuiNotebook* m_auinotebook21;
		wxPanel* m_stage_actor_panel;
		wxSplitterWindow* m_splitter4;
		wxPanel* m_panel12;
		wxListBox* m_listBox1;
		wxPanel* m_panel13;
		wxPropertyGrid* m_propertyGrid1;
		wxPanel* m_panel19;
		wxPanel* m_panel20;
		wxPanel* m_panel6;
		wxPanel* m_panel7;

	public:

		Serenity3D_Frame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Serenity Engine"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1045,742 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Serenity3D_Frame();

		void m_splitter1OnIdle( wxIdleEvent& )
		{
			m_splitter1->SetSashPosition( 214 );
			m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter1OnIdle ), NULL, this );
		}

		void m_splitter3OnIdle( wxIdleEvent& )
		{
			m_splitter3->SetSashPosition( 533 );
			m_splitter3->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter3OnIdle ), NULL, this );
		}

		void m_splitter5OnIdle( wxIdleEvent& )
		{
			m_splitter5->SetSashPosition( 503 );
			m_splitter5->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter5OnIdle ), NULL, this );
		}

		void m_splitter4OnIdle( wxIdleEvent& )
		{
			m_splitter4->SetSashPosition( 0 );
			m_splitter4->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter4OnIdle ), NULL, this );
		}

};

