///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Serenity3D_Editor.h"

///////////////////////////////////////////////////////////////////////////

Serenity3D_Frame::Serenity3D_Frame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menubar1 = new wxMenuBar( 0 );
	m_file_menu = new wxMenu();
	m_menubar1->Append( m_file_menu, wxT("File") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_auinotebook2 = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_TAB_FIXED_WIDTH );
	m_stage_panel = new wxPanel( m_auinotebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_splitter1 = new wxSplitterWindow( m_stage_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter1OnIdle ), NULL, this );

	m_panel161 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	m_simplebook2 = new wxSimplebook( m_panel161, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel4 = new wxPanel( m_simplebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	m_ribbonBar1 = new wxRibbonBar( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxRIBBON_BAR_DEFAULT_STYLE|wxRIBBON_BAR_FLOW_VERTICAL );
	m_ribbonBar1->SetArtProvider(new wxRibbonDefaultArtProvider);
	m_ribbonPage1 = new wxRibbonPage( m_ribbonBar1, wxID_ANY, wxT("MyRibbonPage") , wxNullBitmap , 0 );
	m_ribbonPanel1 = new wxRibbonPanel( m_ribbonPage1, wxID_ANY, wxT("Select/Transform Tools") , wxNullBitmap , wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE|wxRIBBON_PANEL_NO_AUTO_MINIMISE );
	m_ribbonToolBar1 = new wxRibbonToolBar( m_ribbonPanel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ribbonToolBar1->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/cursor.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonToolBar1->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/selection-box.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonToolBar1->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/move.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonToolBar1->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/360.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonToolBar1->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/scale.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonPanel2 = new wxRibbonPanel( m_ribbonPage1, wxID_ANY, wxT("Mesh Tools") , wxNullBitmap , wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE|wxRIBBON_PANEL_NO_AUTO_MINIMISE );
	m_ribbonToolBar2 = new wxRibbonToolBar( m_ribbonPanel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ribbonToolBar2->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/mesh.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonToolBar2->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/animated_mesh.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonPanel4 = new wxRibbonPanel( m_ribbonPage1, wxID_ANY, wxT("3D Primitives") , wxNullBitmap , wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE|wxRIBBON_PANEL_NO_AUTO_MINIMISE );
	m_ribbonToolBar3 = new wxRibbonToolBar( m_ribbonPanel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ribbonToolBar3->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/plane.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonToolBar3->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/3d-cube.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonToolBar3->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/sphere.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonToolBar3->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/cylinder.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonPanel5 = new wxRibbonPanel( m_ribbonPage1, wxID_ANY, wxT("MyRibbonPanel") , wxNullBitmap , wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE );
	m_ribbonToolBar4 = new wxRibbonToolBar( m_ribbonPanel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ribbonToolBar4->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/terrain.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonBar1->Realize();

	bSizer13->Add( m_ribbonBar1, 0, wxALL|wxEXPAND, 5 );


	m_panel4->SetSizer( bSizer13 );
	m_panel4->Layout();
	bSizer13->Fit( m_panel4 );
	m_simplebook2->AddPage( m_panel4, wxT("a page"), false );

	bSizer15->Add( m_simplebook2, 1, wxEXPAND | wxALL, 1 );


	m_panel161->SetSizer( bSizer15 );
	m_panel161->Layout();
	bSizer15->Fit( m_panel161 );
	m_panel5 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_splitter3 = new wxSplitterWindow( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter3->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter3OnIdle ), NULL, this );

	m_panel71 = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	m_splitter5 = new wxSplitterWindow( m_panel71, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter5->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter5OnIdle ), NULL, this );

	m_panel15 = new wxPanel( m_splitter5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );


	bSizer11->Add( bSizer12, 0, wxEXPAND, 5 );

	m_stage_viewport_auinotebook = new wxAuiNotebook( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE );

	bSizer11->Add( m_stage_viewport_auinotebook, 1, wxEXPAND | wxALL, 5 );


	m_panel15->SetSizer( bSizer11 );
	m_panel15->Layout();
	bSizer11->Fit( m_panel15 );
	m_panel16 = new wxPanel( m_splitter5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_splitter5->SplitHorizontally( m_panel15, m_panel16, 503 );
	bSizer10->Add( m_splitter5, 1, wxEXPAND, 5 );


	m_panel71->SetSizer( bSizer10 );
	m_panel71->Layout();
	bSizer10->Fit( m_panel71 );
	m_panel8 = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_auinotebook21 = new wxAuiNotebook( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_stage_actor_panel = new wxPanel( m_auinotebook21, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_splitter4 = new wxSplitterWindow( m_stage_actor_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter4->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter4OnIdle ), NULL, this );

	m_panel12 = new wxPanel( m_splitter4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_listBox1 = new wxListBox( m_panel12, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_ALWAYS_SB|wxLB_SORT );
	bSizer8->Add( m_listBox1, 1, wxALL|wxEXPAND, 5 );


	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );


	m_panel12->SetSizer( bSizer7 );
	m_panel12->Layout();
	bSizer7->Fit( m_panel12 );
	m_panel13 = new wxPanel( m_splitter4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_propertyGrid1 = new wxPropertyGrid(m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_DEFAULT_STYLE);
	bSizer9->Add( m_propertyGrid1, 1, wxALL|wxEXPAND, 5 );


	m_panel13->SetSizer( bSizer9 );
	m_panel13->Layout();
	bSizer9->Fit( m_panel13 );
	m_splitter4->SplitHorizontally( m_panel12, m_panel13, 0 );
	bSizer6->Add( m_splitter4, 1, wxEXPAND, 5 );


	m_stage_actor_panel->SetSizer( bSizer6 );
	m_stage_actor_panel->Layout();
	bSizer6->Fit( m_stage_actor_panel );
	m_auinotebook21->AddPage( m_stage_actor_panel, wxT("Actors"), true, wxNullBitmap );
	m_panel19 = new wxPanel( m_auinotebook21, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_auinotebook21->AddPage( m_panel19, wxT("Shapes"), false, wxNullBitmap );
	m_panel20 = new wxPanel( m_auinotebook21, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_auinotebook21->AddPage( m_panel20, wxT("a page"), false, wxNullBitmap );

	bSizer5->Add( m_auinotebook21, 1, wxEXPAND | wxALL, 5 );


	m_panel8->SetSizer( bSizer5 );
	m_panel8->Layout();
	bSizer5->Fit( m_panel8 );
	m_splitter3->SplitVertically( m_panel71, m_panel8, 533 );
	bSizer4->Add( m_splitter3, 1, wxEXPAND, 5 );


	m_panel5->SetSizer( bSizer4 );
	m_panel5->Layout();
	bSizer4->Fit( m_panel5 );
	m_splitter1->SplitVertically( m_panel161, m_panel5, 214 );
	bSizer2->Add( m_splitter1, 1, wxEXPAND, 5 );


	m_stage_panel->SetSizer( bSizer2 );
	m_stage_panel->Layout();
	bSizer2->Fit( m_stage_panel );
	m_auinotebook2->AddPage( m_stage_panel, wxT("Stage"), true, wxNullBitmap );
	m_panel6 = new wxPanel( m_auinotebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_auinotebook2->AddPage( m_panel6, wxT("a page"), false, wxNullBitmap );
	m_panel7 = new wxPanel( m_auinotebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_auinotebook2->AddPage( m_panel7, wxT("a page"), false, wxNullBitmap );

	bSizer1->Add( m_auinotebook2, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

Serenity3D_Frame::~Serenity3D_Frame()
{
}
