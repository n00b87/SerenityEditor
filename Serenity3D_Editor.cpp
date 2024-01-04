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
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_file_menu, wxID_ANY, wxString( wxT("New Project") ) , wxEmptyString, wxITEM_NORMAL );
	m_file_menu->Append( m_menuItem1 );

	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( m_file_menu, wxID_ANY, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
	m_file_menu->Append( m_menuItem2 );

	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( m_file_menu, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_file_menu->Append( m_menuItem3 );

	wxMenuItem* m_menuItem4;
	m_menuItem4 = new wxMenuItem( m_file_menu, wxID_ANY, wxString( wxT("Save As") ) , wxEmptyString, wxITEM_NORMAL );
	m_file_menu->Append( m_menuItem4 );

	m_file_menu->AppendSeparator();

	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( m_file_menu, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_file_menu->Append( m_menuItem5 );

	m_menubar1->Append( m_file_menu, wxT("File") );

	m_view_menu = new wxMenu();
	wxMenuItem* m_showStageTools_menuItem;
	m_showStageTools_menuItem = new wxMenuItem( m_view_menu, wxID_ANY, wxString( wxT("Show Stage Tools") ) , wxEmptyString, wxITEM_NORMAL );
	m_view_menu->Append( m_showStageTools_menuItem );

	wxMenuItem* m_showStageTree_menuItem;
	m_showStageTree_menuItem = new wxMenuItem( m_view_menu, wxID_ANY, wxString( wxT("Show Stage Tree") ) , wxEmptyString, wxITEM_NORMAL );
	m_view_menu->Append( m_showStageTree_menuItem );

	wxMenuItem* m_showStageInfo_menuItem;
	m_showStageInfo_menuItem = new wxMenuItem( m_view_menu, wxID_ANY, wxString( wxT("Show Stage/Build Info") ) , wxEmptyString, wxITEM_NORMAL );
	m_view_menu->Append( m_showStageInfo_menuItem );

	m_menubar1->Append( m_view_menu, wxT("View") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	m_auinotebook2 = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_TAB_FIXED_WIDTH );
	m_stage_panel = new wxPanel( m_auinotebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_splitter1 = new wxSplitterWindow( m_stage_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter1->SetSashGravity( 1 );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter1OnIdle ), NULL, this );
	m_splitter1->SetMinimumPaneSize( 1 );

	m_panel161 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	m_simplebook2 = new wxSimplebook( m_panel161, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel4 = new wxPanel( m_simplebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	m_simplebook3 = new wxSimplebook( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_tools3D_panel = new wxPanel( m_simplebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );

	m_panel30 = new wxPanel( m_tools3D_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );

	m_staticText7 = new wxStaticText( m_panel30, wxID_ANY, wxT("Select/Transform"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer30->Add( m_staticText7, 0, wxALL, 5 );

	m_auiToolBar5 = new wxAuiToolBar( m_panel30, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT );
	m_s3d_select_tool = m_auiToolBar5->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/cursor.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_s3d_boxSelect_tool = m_auiToolBar5->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/selection-box.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_s3d_move_tool = m_auiToolBar5->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/move.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_s3d_rotate_tool = m_auiToolBar5->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/360.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_s3d_scale_tool = m_auiToolBar5->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/scale.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar5->Realize();

	bSizer30->Add( m_auiToolBar5, 0, wxALL, 5 );


	m_panel30->SetSizer( bSizer30 );
	m_panel30->Layout();
	bSizer30->Fit( m_panel30 );
	bSizer25->Add( m_panel30, 1, wxEXPAND | wxALL, 5 );

	m_panel301 = new wxPanel( m_tools3D_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer301;
	bSizer301 = new wxBoxSizer( wxVERTICAL );

	m_staticText71 = new wxStaticText( m_panel301, wxID_ANY, wxT("3D Primitives"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	m_staticText71->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer301->Add( m_staticText71, 0, wxALL, 5 );

	m_auiToolBar51 = new wxAuiToolBar( m_panel301, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT );
	m_prim3d_plane_tool = m_auiToolBar51->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/plane.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_prim3d_cube_tool = m_auiToolBar51->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/3d-cube.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_prim3d_sphere_tool = m_auiToolBar51->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/sphere.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_prim3d_cylinder_tool = m_auiToolBar51->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/cylinder.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar51->Realize();

	bSizer301->Add( m_auiToolBar51, 0, wxALL, 5 );


	m_panel301->SetSizer( bSizer301 );
	m_panel301->Layout();
	bSizer301->Fit( m_panel301 );
	bSizer25->Add( m_panel301, 1, wxEXPAND | wxALL, 5 );

	m_panel303 = new wxPanel( m_tools3D_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer303;
	bSizer303 = new wxBoxSizer( wxVERTICAL );

	m_staticText73 = new wxStaticText( m_panel303, wxID_ANY, wxT("Geography"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText73->Wrap( -1 );
	bSizer303->Add( m_staticText73, 0, wxALL, 5 );

	m_auiToolBar53 = new wxAuiToolBar( m_panel303, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT );
	m_geo_terrain_tool = m_auiToolBar53->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/terrain.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_geo_water_tool = m_auiToolBar53->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/sea.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_geo_grass_tool = m_auiToolBar53->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/grass.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar53->Realize();

	bSizer303->Add( m_auiToolBar53, 0, wxALL, 5 );


	m_panel303->SetSizer( bSizer303 );
	m_panel303->Layout();
	bSizer303->Fit( m_panel303 );
	bSizer25->Add( m_panel303, 1, wxEXPAND | wxALL, 5 );

	m_panel304 = new wxPanel( m_tools3D_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer304;
	bSizer304 = new wxBoxSizer( wxVERTICAL );

	m_staticText74 = new wxStaticText( m_panel304, wxID_ANY, wxT("Scene"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText74->Wrap( -1 );
	bSizer304->Add( m_staticText74, 0, wxALL, 5 );

	m_auiToolBar54 = new wxAuiToolBar( m_panel304, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT );
	m_scene3d_camera_tool = m_auiToolBar54->AddTool( wxID_ANY, wxT("Add Camera"), wxBitmap( wxT("icons/camera.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxT("Add a camera to the stage"), wxEmptyString, NULL );

	m_scene3d_light_tool = m_auiToolBar54->AddTool( wxID_ANY, wxT("Add Light"), wxBitmap( wxT("icons/light-bulb.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxT("Add a light to the stage"), wxEmptyString, NULL );

	m_scene_effect_tool = m_auiToolBar54->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/effect.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar54->Realize();

	bSizer304->Add( m_auiToolBar54, 0, wxALL, 5 );


	m_panel304->SetSizer( bSizer304 );
	m_panel304->Layout();
	bSizer304->Fit( m_panel304 );
	bSizer25->Add( m_panel304, 1, wxEXPAND | wxALL, 5 );

	m_panel306 = new wxPanel( m_tools3D_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer306;
	bSizer306 = new wxBoxSizer( wxVERTICAL );

	m_staticText75 = new wxStaticText( m_panel306, wxID_ANY, wxT("Misc."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText75->Wrap( -1 );
	bSizer306->Add( m_staticText75, 0, wxALL, 5 );

	m_auiToolBar55 = new wxAuiToolBar( m_panel306, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT );
	m_s3d_select_tool1 = m_auiToolBar55->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/anchor.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar55->Realize();

	bSizer306->Add( m_auiToolBar55, 0, wxALL, 5 );


	m_panel306->SetSizer( bSizer306 );
	m_panel306->Layout();
	bSizer306->Fit( m_panel306 );
	bSizer25->Add( m_panel306, 1, wxEXPAND | wxALL, 5 );


	m_tools3D_panel->SetSizer( bSizer25 );
	m_tools3D_panel->Layout();
	bSizer25->Fit( m_tools3D_panel );
	m_simplebook3->AddPage( m_tools3D_panel, wxT("3D Tools"), false );
	m_toolsNone_panel = new wxPanel( m_simplebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_simplebook3->AddPage( m_toolsNone_panel, wxT("a page"), false );
	m_tools2D_panel = new wxPanel( m_simplebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxVERTICAL );

	m_ribbonBar3 = new wxRibbonBar( m_tools2D_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxRIBBON_BAR_DEFAULT_STYLE );
	m_ribbonBar3->SetArtProvider(new wxRibbonDefaultArtProvider);
	m_ribbonPage3 = new wxRibbonPage( m_ribbonBar3, wxID_ANY, wxT("MyRibbonPage") , wxNullBitmap , 0 );
	m_ribbonPanel6 = new wxRibbonPanel( m_ribbonPage3, wxID_ANY, wxT("Select/Transform Tools") , wxNullBitmap , wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE|wxRIBBON_PANEL_NO_AUTO_MINIMISE|wxRIBBON_PANEL_STRETCH );
	m_ribbonToolBar6 = new wxRibbonToolBar( m_ribbonPanel6, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ribbonToolBar6->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/cursor.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonToolBar6->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/selection-box.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonToolBar6->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/move.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonToolBar6->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/rotate2D.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonToolBar6->AddToggleTool( wxID_ANY, wxBitmap( wxT("icons/scale.png"), wxBITMAP_TYPE_ANY ), wxEmptyString);
	m_ribbonBar3->Realize();

	bSizer28->Add( m_ribbonBar3, 0, wxALL|wxEXPAND, 5 );


	m_tools2D_panel->SetSizer( bSizer28 );
	m_tools2D_panel->Layout();
	bSizer28->Fit( m_tools2D_panel );
	m_simplebook3->AddPage( m_tools2D_panel, wxT("2D Tools"), false );

	bSizer13->Add( m_simplebook3, 0, wxEXPAND | wxALL, 0 );


	m_panel4->SetSizer( bSizer13 );
	m_panel4->Layout();
	bSizer13->Fit( m_panel4 );
	m_simplebook2->AddPage( m_panel4, wxT("a page"), false );

	bSizer15->Add( m_simplebook2, 1, wxEXPAND | wxALL, 1 );

	m_panel302 = new wxPanel( m_panel161, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer302;
	bSizer302 = new wxBoxSizer( wxVERTICAL );

	m_staticText72 = new wxStaticText( m_panel302, wxID_ANY, wxT("Meshes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText72->Wrap( -1 );
	bSizer302->Add( m_staticText72, 0, wxALL, 5 );

	m_auiToolBar52 = new wxAuiToolBar( m_panel302, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT );
	m_mesh_dump_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/mesh.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_mesh_wiz_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/animated_mesh.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar52->Realize();

	bSizer302->Add( m_auiToolBar52, 0, wxALL, 5 );

	m_meshList_panel = new wxPanel( m_panel302, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	m_searchCtrl4 = new wxSearchCtrl( m_meshList_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_searchCtrl4->ShowSearchButton( true );
	#endif
	m_searchCtrl4->ShowCancelButton( false );
	bSizer14->Add( m_searchCtrl4, 0, wxALL|wxEXPAND, 5 );

	m_listBox3 = new wxListBox( m_meshList_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer14->Add( m_listBox3, 7, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );


	bSizer14->Add( bSizer16, 1, wxEXPAND, 5 );


	m_meshList_panel->SetSizer( bSizer14 );
	m_meshList_panel->Layout();
	bSizer14->Fit( m_meshList_panel );
	bSizer302->Add( m_meshList_panel, 1, wxEXPAND | wxALL, 5 );


	m_panel302->SetSizer( bSizer302 );
	m_panel302->Layout();
	bSizer302->Fit( m_panel302 );
	bSizer15->Add( m_panel302, 1, wxEXPAND | wxALL, 5 );


	m_panel161->SetSizer( bSizer15 );
	m_panel161->Layout();
	bSizer15->Fit( m_panel161 );
	m_panel5 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_splitter3 = new wxSplitterWindow( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter3->SetSashGravity( 1 );
	m_splitter3->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter3OnIdle ), NULL, this );
	m_splitter3->SetMinimumPaneSize( 1 );

	m_panel71 = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	m_splitter5 = new wxSplitterWindow( m_panel71, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter5->SetSashGravity( 1 );
	m_splitter5->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter5OnIdle ), NULL, this );
	m_splitter5->SetMinimumPaneSize( 1 );

	m_panel15 = new wxPanel( m_splitter5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	m_stage_viewport_auinotebook = new wxAuiNotebook( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE );

	bSizer11->Add( m_stage_viewport_auinotebook, 1, wxEXPAND | wxALL, 5 );


	m_panel15->SetSizer( bSizer11 );
	m_panel15->Layout();
	bSizer11->Fit( m_panel15 );
	m_panel16 = new wxPanel( m_splitter5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );

	m_notebook1 = new wxNotebook( m_panel16, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel32 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook1->AddPage( m_panel32, wxT("View"), false );
	m_panel31 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook1->AddPage( m_panel31, wxT("Build Log"), true );

	bSizer17->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );


	m_panel16->SetSizer( bSizer17 );
	m_panel16->Layout();
	bSizer17->Fit( m_panel16 );
	m_splitter5->SplitHorizontally( m_panel15, m_panel16, 419 );
	bSizer10->Add( m_splitter5, 1, wxEXPAND, 5 );


	m_panel71->SetSizer( bSizer10 );
	m_panel71->Layout();
	bSizer10->Fit( m_panel71 );
	m_panel8 = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_auinotebook3 = new wxAuiNotebook( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_MIDDLE_CLICK_CLOSE );
	m_panel25 = new wxPanel( m_auinotebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );

	m_splitter6 = new wxSplitterWindow( m_panel25, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter6->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter6OnIdle ), NULL, this );

	m_panel305 = new wxPanel( m_splitter6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer305;
	bSizer305 = new wxBoxSizer( wxVERTICAL );

	m_treeCtrl2 = new wxTreeCtrl( m_panel305, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	bSizer305->Add( m_treeCtrl2, 1, wxALL|wxEXPAND, 5 );


	m_panel305->SetSizer( bSizer305 );
	m_panel305->Layout();
	bSizer305->Fit( m_panel305 );
	m_panel311 = new wxPanel( m_splitter6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );

	m_propertyGrid3 = new wxPropertyGrid(m_panel311, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_DEFAULT_STYLE);
	bSizer31->Add( m_propertyGrid3, 1, wxALL|wxEXPAND, 5 );


	m_panel311->SetSizer( bSizer31 );
	m_panel311->Layout();
	bSizer31->Fit( m_panel311 );
	m_splitter6->SplitHorizontally( m_panel305, m_panel311, 0 );
	bSizer29->Add( m_splitter6, 1, wxEXPAND, 5 );


	m_panel25->SetSizer( bSizer29 );
	m_panel25->Layout();
	bSizer29->Fit( m_panel25 );
	m_auinotebook3->AddPage( m_panel25, wxT("Project"), true, wxNullBitmap );
	m_stage_actor_panel = new wxPanel( m_auinotebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_splitter4 = new wxSplitterWindow( m_stage_actor_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter4->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter4OnIdle ), NULL, this );

	m_panel12 = new wxPanel( m_splitter4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_treeCtrl1 = new wxTreeCtrl( m_panel12, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	bSizer8->Add( m_treeCtrl1, 1, wxALL|wxEXPAND, 5 );


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
	m_auinotebook3->AddPage( m_stage_actor_panel, wxT("Stage"), false, wxNullBitmap );

	bSizer5->Add( m_auinotebook3, 1, wxEXPAND | wxALL, 5 );


	m_panel8->SetSizer( bSizer5 );
	m_panel8->Layout();
	bSizer5->Fit( m_panel8 );
	m_splitter3->SplitVertically( m_panel71, m_panel8, 768 );
	bSizer4->Add( m_splitter3, 1, wxEXPAND, 5 );


	m_panel5->SetSizer( bSizer4 );
	m_panel5->Layout();
	bSizer4->Fit( m_panel5 );
	m_splitter1->SplitVertically( m_panel161, m_panel5, 204 );
	bSizer2->Add( m_splitter1, 1, wxEXPAND, 5 );


	m_stage_panel->SetSizer( bSizer2 );
	m_stage_panel->Layout();
	bSizer2->Fit( m_stage_panel );
	m_auinotebook2->AddPage( m_stage_panel, wxT("Stage"), true, wxNullBitmap );
	m_panel6 = new wxPanel( m_auinotebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	m_splitter51 = new wxSplitterWindow( m_panel6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter51->SetSashGravity( 1 );
	m_splitter51->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter51OnIdle ), NULL, this );
	m_splitter51->SetMinimumPaneSize( 1 );

	m_panel28 = new wxPanel( m_splitter51, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer251;
	bSizer251 = new wxBoxSizer( wxHORIZONTAL );


	bSizer23->Add( bSizer251, 0, wxEXPAND, 5 );

	m_listBox31 = new wxListBox( m_panel28, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer23->Add( m_listBox31, 1, wxALL|wxEXPAND, 5 );


	m_panel28->SetSizer( bSizer23 );
	m_panel28->Layout();
	bSizer23->Fit( m_panel28 );
	m_panel291 = new wxPanel( m_splitter51, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );


	m_panel291->SetSizer( bSizer24 );
	m_panel291->Layout();
	bSizer24->Fit( m_panel291 );
	m_splitter51->SplitVertically( m_panel28, m_panel291, 233 );
	bSizer22->Add( m_splitter51, 1, wxEXPAND, 5 );


	bSizer21->Add( bSizer22, 1, wxEXPAND, 5 );


	m_panel6->SetSizer( bSizer21 );
	m_panel6->Layout();
	bSizer21->Fit( m_panel6 );
	m_auinotebook2->AddPage( m_panel6, wxT("Assets"), false, wxNullBitmap );

	bSizer1->Add( m_auinotebook2, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	m_toolBar1 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	m_tool1 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxArtProvider::GetBitmap( wxART_NEW, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool2 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxArtProvider::GetBitmap( wxART_FOLDER_OPEN, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool3 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxArtProvider::GetBitmap( wxART_FILE_SAVE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar1->AddSeparator();

	m_tool6 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/play.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool7 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/stop.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar1->Realize();


	this->Centre( wxBOTH );
}

Serenity3D_Frame::~Serenity3D_Frame()
{
}
