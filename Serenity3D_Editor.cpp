///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6-dirty)
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
	m_splitter1->SetSashGravity( 0 );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter1OnIdle ), NULL, this );
	m_splitter1->SetMinimumPaneSize( 1 );

	m_panel161 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	m_simplebook2 = new wxSimplebook( m_panel161, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel4 = new wxPanel( m_simplebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	m_tools3D_panel = new wxPanel( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
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
	bSizer25->Add( m_panel30, 0, wxEXPAND | wxALL, 5 );

	m_panel50 = new wxPanel( m_tools3D_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel50->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_CAPTIONTEXT ) );
	m_panel50->SetBackgroundColour( wxColour( 224, 224, 224 ) );

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxVERTICAL );

	m_panel301 = new wxPanel( m_panel50, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer301;
	bSizer301 = new wxBoxSizer( wxVERTICAL );

	m_staticText71 = new wxStaticText( m_panel301, wxID_ANY, wxT("Primitives"), wxDefaultPosition, wxDefaultSize, 0 );
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
	bSizer91->Add( m_panel301, 0, wxEXPAND | wxALL, 5 );

	m_panel421 = new wxPanel( m_panel50, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_RAISED|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer711;
	bSizer711 = new wxBoxSizer( wxVERTICAL );

	m_staticText72 = new wxStaticText( m_panel421, wxID_ANY, wxT("Objects"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText72->Wrap( -1 );
	bSizer711->Add( m_staticText72, 0, wxALL, 5 );

	m_auiToolBar52 = new wxAuiToolBar( m_panel421, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT );
	m_mesh_dump_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/mesh.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_mesh_wiz_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/animated_mesh.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_m3d_billboard_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Billboard"), wxBitmap( wxT("icons/billboard.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Add a billboard to the stage"), wxEmptyString, NULL );

	m_scene3d_light_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Light"), wxBitmap( wxT("icons/light-bulb.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Add a light to the stage"), wxEmptyString, NULL );

	m_auiToolBar52->Realize();

	bSizer711->Add( m_auiToolBar52, 0, wxALL, 5 );


	m_panel421->SetSizer( bSizer711 );
	m_panel421->Layout();
	bSizer711->Fit( m_panel421 );
	bSizer91->Add( m_panel421, 0, wxEXPAND | wxALL, 5 );

	m_panel303 = new wxPanel( m_panel50, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer303;
	bSizer303 = new wxBoxSizer( wxVERTICAL );

	m_staticText73 = new wxStaticText( m_panel303, wxID_ANY, wxT("Geography"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText73->Wrap( -1 );
	bSizer303->Add( m_staticText73, 0, wxALL, 5 );

	m_auiToolBar53 = new wxAuiToolBar( m_panel303, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT );
	m_geo_terrain_tool = m_auiToolBar53->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/terrain.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_geo_water_tool = m_auiToolBar53->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/sea.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_geo_grass_tool = m_auiToolBar53->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/grass.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar53->Realize();

	bSizer303->Add( m_auiToolBar53, 0, wxALL, 5 );


	m_panel303->SetSizer( bSizer303 );
	m_panel303->Layout();
	bSizer303->Fit( m_panel303 );
	bSizer91->Add( m_panel303, 0, wxEXPAND | wxALL, 5 );

	m_panel304 = new wxPanel( m_panel50, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer304;
	bSizer304 = new wxBoxSizer( wxVERTICAL );

	m_staticText74 = new wxStaticText( m_panel304, wxID_ANY, wxT("Misc"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText74->Wrap( -1 );
	bSizer304->Add( m_staticText74, 0, wxALL, 5 );

	m_auiToolBar54 = new wxAuiToolBar( m_panel304, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT );
	m_m3d_path_tool = m_auiToolBar54->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/anchor.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_scene_effect_tool = m_auiToolBar54->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/effect.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar54->Realize();

	bSizer304->Add( m_auiToolBar54, 0, wxALL, 5 );


	m_panel304->SetSizer( bSizer304 );
	m_panel304->Layout();
	bSizer304->Fit( m_panel304 );
	bSizer91->Add( m_panel304, 0, wxEXPAND | wxALL, 5 );


	m_panel50->SetSizer( bSizer91 );
	m_panel50->Layout();
	bSizer91->Fit( m_panel50 );
	bSizer25->Add( m_panel50, 1, wxEXPAND | wxALL, 5 );


	m_tools3D_panel->SetSizer( bSizer25 );
	m_tools3D_panel->Layout();
	bSizer25->Fit( m_tools3D_panel );
	bSizer13->Add( m_tools3D_panel, 1, wxEXPAND | wxALL, 5 );


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
	m_splitter3->SetSashGravity( 1 );
	m_splitter3->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter3OnIdle ), NULL, this );
	m_splitter3->SetMinimumPaneSize( 1 );

	m_panel71 = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	m_panel15 = new wxPanel( m_panel71, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	m_panel45 = new wxPanel( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );

	m_panel47 = new wxPanel( m_panel45, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText12 = new wxStaticText( m_panel47, wxID_ANY, wxT("POV"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer46->Add( m_staticText12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_stagePOV_comboBox = new wxComboBox( m_panel47, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer46->Add( m_stagePOV_comboBox, 0, wxALL, 5 );


	m_panel47->SetSizer( bSizer46 );
	m_panel47->Layout();
	bSizer46->Fit( m_panel47 );
	bSizer43->Add( m_panel47, 1, wxEXPAND | wxALL, 5 );

	m_panel441 = new wxPanel( m_panel45, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer74;
	bSizer74 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText331 = new wxStaticText( m_panel441, wxID_ANY, wxT("MODE"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText331->Wrap( -1 );
	bSizer74->Add( m_staticText331, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_auiToolBar6 = new wxAuiToolBar( m_panel441, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT );
	m_editMode_tool = m_auiToolBar6->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/edit_pencil_icon.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_cameraMode_tool = m_auiToolBar6->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/camera.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar6->Realize();

	bSizer74->Add( m_auiToolBar6, 1, wxALL, 5 );


	m_panel441->SetSizer( bSizer74 );
	m_panel441->Layout();
	bSizer74->Fit( m_panel441 );
	bSizer43->Add( m_panel441, 0, wxALL|wxEXPAND, 5 );


	bSizer42->Add( bSizer43, 0, wxEXPAND, 5 );

	m_stageViewport_panel = new wxPanel( m_panel45, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	bSizer42->Add( m_stageViewport_panel, 1, wxEXPAND | wxALL, 5 );


	m_panel45->SetSizer( bSizer42 );
	m_panel45->Layout();
	bSizer42->Fit( m_panel45 );
	bSizer11->Add( m_panel45, 1, wxEXPAND | wxALL, 5 );


	m_panel15->SetSizer( bSizer11 );
	m_panel15->Layout();
	bSizer11->Fit( m_panel15 );
	bSizer10->Add( m_panel15, 1, wxEXPAND | wxALL, 5 );

	m_panel39 = new wxPanel( m_panel71, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer611;
	bSizer611 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText23 = new wxStaticText( m_panel39, wxID_ANY, wxT("Position:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer611->Add( m_staticText23, 0, wxALL, 5 );

	m_viewPosition_staticText = new wxStaticText( m_panel39, wxID_ANY, wxT("0, 0, 0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_viewPosition_staticText->Wrap( -1 );
	bSizer611->Add( m_viewPosition_staticText, 0, wxALL, 5 );


	bSizer611->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText25 = new wxStaticText( m_panel39, wxID_ANY, wxT("Rotation:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer611->Add( m_staticText25, 0, wxALL, 5 );

	m_viewRotation_staticText = new wxStaticText( m_panel39, wxID_ANY, wxT("0, 0, 0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_viewRotation_staticText->Wrap( -1 );
	bSizer611->Add( m_viewRotation_staticText, 0, wxALL, 5 );


	bSizer611->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer62->Add( bSizer611, 0, wxEXPAND, 5 );


	m_panel39->SetSizer( bSizer62 );
	m_panel39->Layout();
	bSizer62->Fit( m_panel39 );
	bSizer10->Add( m_panel39, 0, wxEXPAND | wxALL, 5 );

	m_panel40 = new wxPanel( m_panel71, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer10->Add( m_panel40, 0, wxEXPAND | wxALL, 5 );


	m_panel71->SetSizer( bSizer10 );
	m_panel71->Layout();
	bSizer10->Fit( m_panel71 );
	m_panel8 = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_auinotebook3 = new wxAuiNotebook( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_MIDDLE_CLICK_CLOSE );
	m_project_stages_panel = new wxPanel( m_auinotebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );

	m_splitter6 = new wxSplitterWindow( m_project_stages_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter6->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter6OnIdle ), NULL, this );

	m_panel305 = new wxPanel( m_splitter6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer305;
	bSizer305 = new wxBoxSizer( wxVERTICAL );

	m_project_treeCtrl = new wxTreeCtrl( m_panel305, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	m_project_treeCtrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer305->Add( m_project_treeCtrl, 1, wxALL|wxEXPAND, 5 );


	m_panel305->SetSizer( bSizer305 );
	m_panel305->Layout();
	bSizer305->Fit( m_panel305 );
	m_panel311 = new wxPanel( m_splitter6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );

	m_project_propertyGrid = new wxPropertyGrid(m_panel311, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_DEFAULT_STYLE);
	bSizer31->Add( m_project_propertyGrid, 1, wxALL|wxEXPAND, 5 );


	m_panel311->SetSizer( bSizer31 );
	m_panel311->Layout();
	bSizer31->Fit( m_panel311 );
	m_splitter6->SplitHorizontally( m_panel305, m_panel311, 0 );
	bSizer29->Add( m_splitter6, 1, wxEXPAND, 5 );


	m_project_stages_panel->SetSizer( bSizer29 );
	m_project_stages_panel->Layout();
	bSizer29->Fit( m_project_stages_panel );
	m_auinotebook3->AddPage( m_project_stages_panel, wxT("Project"), true, wxNullBitmap );
	m_scrolledWindow2 = new wxScrolledWindow( m_auinotebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow2->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer671;
	bSizer671 = new wxBoxSizer( wxVERTICAL );

	m_panel422 = new wxPanel( m_scrolledWindow2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_RAISED|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer691;
	bSizer691 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText28 = new wxStaticText( m_panel422, wxID_ANY, wxT("Grid Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	bSizer691->Add( m_staticText28, 0, wxALL, 5 );


	bSizer68->Add( bSizer691, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer702;
	bSizer702 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBox1 = new wxCheckBox( m_panel422, wxID_ANY, wxT("Show Grid"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_checkBox1->SetValue(true);
	bSizer702->Add( m_checkBox1, 0, wxALL, 5 );


	bSizer68->Add( bSizer702, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer712;
	bSizer712 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText30 = new wxStaticText( m_panel422, wxID_ANY, wxT("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	bSizer712->Add( m_staticText30, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_spinCtrl1 = new wxSpinCtrl( m_panel422, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	bSizer712->Add( m_spinCtrl1, 2, wxALL, 5 );


	bSizer68->Add( bSizer712, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer72;
	bSizer72 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( m_panel422, wxID_ANY, wxT("Spacing"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer72->Add( m_staticText31, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_spinCtrl2 = new wxSpinCtrl( m_panel422, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	bSizer72->Add( m_spinCtrl2, 2, wxALL, 5 );


	bSizer68->Add( bSizer72, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText322 = new wxStaticText( m_panel422, wxID_ANY, wxT("Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText322->Wrap( -1 );
	bSizer73->Add( m_staticText322, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_colourPicker1 = new wxColourPickerCtrl( m_panel422, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer73->Add( m_colourPicker1, 2, wxALL, 5 );


	bSizer68->Add( bSizer73, 0, wxEXPAND, 5 );


	m_panel422->SetSizer( bSizer68 );
	m_panel422->Layout();
	bSizer68->Fit( m_panel422 );
	bSizer671->Add( m_panel422, 0, wxEXPAND | wxALL, 5 );


	m_scrolledWindow2->SetSizer( bSizer671 );
	m_scrolledWindow2->Layout();
	bSizer671->Fit( m_scrolledWindow2 );
	m_auinotebook3->AddPage( m_scrolledWindow2, wxT("Settings"), false, wxNullBitmap );

	bSizer5->Add( m_auinotebook3, 1, wxEXPAND | wxALL, 5 );


	m_panel8->SetSizer( bSizer5 );
	m_panel8->Layout();
	bSizer5->Fit( m_panel8 );
	m_splitter3->SplitVertically( m_panel71, m_panel8, 850 );
	bSizer4->Add( m_splitter3, 1, wxEXPAND, 5 );


	m_panel5->SetSizer( bSizer4 );
	m_panel5->Layout();
	bSizer4->Fit( m_panel5 );
	m_splitter1->SplitVertically( m_panel161, m_panel5, 238 );
	bSizer2->Add( m_splitter1, 1, wxEXPAND, 5 );


	m_stage_panel->SetSizer( bSizer2 );
	m_stage_panel->Layout();
	bSizer2->Fit( m_stage_panel );
	m_auinotebook2->AddPage( m_stage_panel, wxT("Stage"), false, wxNullBitmap );
	m_panel6 = new wxPanel( m_auinotebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	m_splitter51 = new wxSplitterWindow( m_panel6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter51->SetSashGravity( 0 );
	m_splitter51->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter51OnIdle ), NULL, this );
	m_splitter51->SetMinimumPaneSize( 1 );

	m_panel28 = new wxPanel( m_splitter51, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer251;
	bSizer251 = new wxBoxSizer( wxHORIZONTAL );


	bSizer23->Add( bSizer251, 0, wxEXPAND, 5 );

	m_mesh_listBox = new wxListBox( m_panel28, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer23->Add( m_mesh_listBox, 1, wxALL|wxEXPAND, 5 );


	m_panel28->SetSizer( bSizer23 );
	m_panel28->Layout();
	bSizer23->Fit( m_panel28 );
	m_panel291 = new wxPanel( m_splitter51, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxVERTICAL );

	m_panel41 = new wxPanel( m_panel291, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer70;
	bSizer70 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32 = new wxStaticText( m_panel41, wxID_ANY, wxT("File\t\t"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer70->Add( m_staticText32, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_meshFile_textCtrl = new wxTextCtrl( m_panel41, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer70->Add( m_meshFile_textCtrl, 1, wxALL, 5 );


	bSizer69->Add( bSizer70, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer701;
	bSizer701 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText321 = new wxStaticText( m_panel41, wxID_ANY, wxT("ID\t\t\t"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText321->Wrap( -1 );
	bSizer701->Add( m_staticText321, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_meshID_textCtrl = new wxTextCtrl( m_panel41, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer701->Add( m_meshID_textCtrl, 1, wxALL, 5 );


	bSizer69->Add( bSizer701, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer7011;
	bSizer7011 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3211 = new wxStaticText( m_panel41, wxID_ANY, wxT("Texture\t"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3211->Wrap( -1 );
	bSizer7011->Add( m_staticText3211, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_meshTexture_comboBox = new wxComboBox( m_panel41, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer7011->Add( m_meshTexture_comboBox, 1, wxALL, 5 );


	bSizer69->Add( bSizer7011, 0, wxEXPAND, 5 );


	m_panel41->SetSizer( bSizer69 );
	m_panel41->Layout();
	bSizer69->Fit( m_panel41 );
	bSizer67->Add( m_panel41, 1, wxEXPAND | wxALL, 5 );


	bSizer61->Add( bSizer67, 4, wxEXPAND, 5 );

	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );

	m_modelView_panel = new wxPanel( m_panel291, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	bSizer71->Add( m_modelView_panel, 1, wxEXPAND | wxALL, 5 );

	m_toolBar2 = new wxToolBar( m_panel291, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL );
	m_meshAnimation_play_tool = m_toolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/play.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_meshAnimation_stop_tool = m_toolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/stop.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar2->Realize();

	bSizer71->Add( m_toolBar2, 0, wxEXPAND, 5 );


	bSizer61->Add( bSizer71, 4, wxEXPAND, 5 );


	bSizer78->Add( bSizer61, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxVERTICAL );

	m_panel43 = new wxPanel( m_panel291, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );

	m_panel46 = new wxPanel( m_panel43, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	m_staticText33 = new wxStaticText( m_panel46, wxID_ANY, wxT("Animations"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer77->Add( m_staticText33, 0, wxALL, 5 );

	wxBoxSizer* bSizer781;
	bSizer781 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxVERTICAL );

	m_meshAnimation_new_button = new wxButton( m_panel46, wxID_ANY, wxT("New"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_meshAnimation_new_button, 0, wxALL, 5 );

	m_meshAnimation_delete_button = new wxButton( m_panel46, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_meshAnimation_delete_button, 0, wxALL, 5 );

	m_meshAnimation_save_button = new wxButton( m_panel46, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_meshAnimation_save_button, 0, wxALL, 5 );


	bSizer781->Add( bSizer82, 1, wxEXPAND, 5 );

	m_meshAnimation_listBox = new wxListBox( m_panel46, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer781->Add( m_meshAnimation_listBox, 4, wxALL|wxEXPAND, 5 );


	bSizer77->Add( bSizer781, 1, wxEXPAND, 5 );


	m_panel46->SetSizer( bSizer77 );
	m_panel46->Layout();
	bSizer77->Fit( m_panel46 );
	bSizer76->Add( m_panel46, 1, wxEXPAND | wxALL, 5 );

	m_panel451 = new wxPanel( m_panel43, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer713;
	bSizer713 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer721;
	bSizer721 = new wxBoxSizer( wxVERTICAL );


	bSizer721->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer731;
	bSizer731 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText27 = new wxStaticText( m_panel451, wxID_ANY, wxT("Animation ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	bSizer731->Add( m_staticText27, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_animationID_textCtrl = new wxTextCtrl( m_panel451, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer731->Add( m_animationID_textCtrl, 2, wxALL, 5 );


	bSizer731->Add( 0, 0, 3, wxEXPAND, 5 );


	bSizer721->Add( bSizer731, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7311;
	bSizer7311 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText271 = new wxStaticText( m_panel451, wxID_ANY, wxT("Start Frame"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText271->Wrap( -1 );
	bSizer7311->Add( m_staticText271, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_animationStartFrame_textCtrl = new wxTextCtrl( m_panel451, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7311->Add( m_animationStartFrame_textCtrl, 2, wxALL, 5 );


	bSizer7311->Add( 0, 0, 3, wxEXPAND, 5 );


	bSizer721->Add( bSizer7311, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer73111;
	bSizer73111 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2711 = new wxStaticText( m_panel451, wxID_ANY, wxT("End Frame"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2711->Wrap( -1 );
	bSizer73111->Add( m_staticText2711, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_animationEndFrame_textCtrl = new wxTextCtrl( m_panel451, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer73111->Add( m_animationEndFrame_textCtrl, 2, wxALL, 5 );


	bSizer73111->Add( 0, 0, 3, wxEXPAND, 5 );


	bSizer721->Add( bSizer73111, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer73112;
	bSizer73112 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2712 = new wxStaticText( m_panel451, wxID_ANY, wxT("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2712->Wrap( -1 );
	bSizer73112->Add( m_staticText2712, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_animationSpeed_textCtrl = new wxTextCtrl( m_panel451, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer73112->Add( m_animationSpeed_textCtrl, 2, wxALL, 5 );


	bSizer73112->Add( 0, 0, 3, wxEXPAND, 5 );


	bSizer721->Add( bSizer73112, 0, wxEXPAND, 5 );


	bSizer713->Add( bSizer721, 0, wxEXPAND, 5 );


	m_panel451->SetSizer( bSizer713 );
	m_panel451->Layout();
	bSizer713->Fit( m_panel451 );
	bSizer76->Add( m_panel451, 1, wxEXPAND | wxALL, 5 );


	bSizer75->Add( bSizer76, 1, wxEXPAND, 5 );


	m_panel43->SetSizer( bSizer75 );
	m_panel43->Layout();
	bSizer75->Fit( m_panel43 );
	bSizer81->Add( m_panel43, 1, wxEXPAND | wxALL, 5 );


	bSizer78->Add( bSizer81, 1, wxEXPAND, 5 );


	m_panel291->SetSizer( bSizer78 );
	m_panel291->Layout();
	bSizer78->Fit( m_panel291 );
	m_splitter51->SplitVertically( m_panel28, m_panel291, 233 );
	bSizer22->Add( m_splitter51, 1, wxEXPAND, 5 );


	bSizer21->Add( bSizer22, 1, wxEXPAND, 5 );


	m_panel6->SetSizer( bSizer21 );
	m_panel6->Layout();
	bSizer21->Fit( m_panel6 );
	m_auinotebook2->AddPage( m_panel6, wxT("Mesh"), true, wxNullBitmap );

	bSizer1->Add( m_auinotebook2, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	m_toolBar1 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	m_tool1 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxArtProvider::GetBitmap( wxASCII_STR(wxART_NEW), wxASCII_STR(wxART_TOOLBAR) ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool2 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxArtProvider::GetBitmap( wxASCII_STR(wxART_FOLDER_OPEN), wxASCII_STR(wxART_TOOLBAR) ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool3 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_SAVE), wxASCII_STR(wxART_TOOLBAR) ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar1->AddSeparator();

	m_tbar_play_tool = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/play.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool7 = m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/stop.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar1->Realize();


	this->Centre( wxBOTH );

	// Connect Events
	m_modelView_panel->Connect( wxEVT_SIZE, wxSizeEventHandler( Serenity3D_Frame::OnAnimationPreviewSize ), NULL, this );
	this->Connect( m_meshAnimation_stop_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnAnimationStopClicked ) );
	this->Connect( m_tbar_play_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnPlayClicked ) );
	this->Connect( m_tool7->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnStopClicked ) );
}

Serenity3D_Frame::~Serenity3D_Frame()
{
	// Disconnect Events
	m_modelView_panel->Disconnect( wxEVT_SIZE, wxSizeEventHandler( Serenity3D_Frame::OnAnimationPreviewSize ), NULL, this );
	this->Disconnect( m_meshAnimation_stop_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnAnimationStopClicked ) );
	this->Disconnect( m_tbar_play_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnPlayClicked ) );
	this->Disconnect( m_tool7->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnStopClicked ) );

}

StageCanvasSettings_Frame::StageCanvasSettings_Frame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxVERTICAL );

	m_panel33 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );

	m_scrolledWindow1 = new wxScrolledWindow( m_panel33, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxALWAYS_SHOW_SB|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );

	m_panel34 = new wxPanel( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText9 = new wxStaticText( m_panel34, wxID_ANY, wxT("Layer 0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	m_staticText9->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer37->Add( m_staticText9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer36->Add( bSizer37, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText10 = new wxStaticText( m_panel34, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer38->Add( m_staticText10, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_textCtrl1 = new wxTextCtrl( m_panel34, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer38->Add( m_textCtrl1, 2, wxALL, 5 );

	m_comboBox4 = new wxComboBox( m_panel34, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer38->Add( m_comboBox4, 1, wxALL, 5 );

	m_button3 = new wxButton( m_panel34, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer38->Add( m_button3, 0, wxALL, 5 );

	m_button2 = new wxButton( m_panel34, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer38->Add( m_button2, 0, wxALL, 5 );


	bSizer36->Add( bSizer38, 0, wxEXPAND, 5 );


	m_panel34->SetSizer( bSizer36 );
	m_panel34->Layout();
	bSizer36->Fit( m_panel34 );
	bSizer51->Add( m_panel34, 1, wxEXPAND | wxALL, 5 );


	bSizer35->Add( bSizer51, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer511;
	bSizer511 = new wxBoxSizer( wxVERTICAL );

	m_panel341 = new wxPanel( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer361;
	bSizer361 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer371;
	bSizer371 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText91 = new wxStaticText( m_panel341, wxID_ANY, wxT("Layer 0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	m_staticText91->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer371->Add( m_staticText91, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer361->Add( bSizer371, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer381;
	bSizer381 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText101 = new wxStaticText( m_panel341, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	bSizer381->Add( m_staticText101, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_textCtrl11 = new wxTextCtrl( m_panel341, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer381->Add( m_textCtrl11, 2, wxALL, 5 );

	m_comboBox41 = new wxComboBox( m_panel341, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer381->Add( m_comboBox41, 1, wxALL, 5 );

	m_button31 = new wxButton( m_panel341, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer381->Add( m_button31, 0, wxALL, 5 );

	m_button21 = new wxButton( m_panel341, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer381->Add( m_button21, 0, wxALL, 5 );


	bSizer361->Add( bSizer381, 0, wxEXPAND, 5 );


	m_panel341->SetSizer( bSizer361 );
	m_panel341->Layout();
	bSizer361->Fit( m_panel341 );
	bSizer511->Add( m_panel341, 1, wxEXPAND | wxALL, 5 );


	bSizer35->Add( bSizer511, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer512;
	bSizer512 = new wxBoxSizer( wxVERTICAL );

	m_panel342 = new wxPanel( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer362;
	bSizer362 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer372;
	bSizer372 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText92 = new wxStaticText( m_panel342, wxID_ANY, wxT("Layer 0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText92->Wrap( -1 );
	m_staticText92->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer372->Add( m_staticText92, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer362->Add( bSizer372, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer382;
	bSizer382 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText102 = new wxStaticText( m_panel342, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText102->Wrap( -1 );
	bSizer382->Add( m_staticText102, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_textCtrl12 = new wxTextCtrl( m_panel342, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer382->Add( m_textCtrl12, 2, wxALL, 5 );

	m_comboBox42 = new wxComboBox( m_panel342, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer382->Add( m_comboBox42, 1, wxALL, 5 );

	m_button32 = new wxButton( m_panel342, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer382->Add( m_button32, 0, wxALL, 5 );

	m_button22 = new wxButton( m_panel342, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer382->Add( m_button22, 0, wxALL, 5 );


	bSizer362->Add( bSizer382, 0, wxEXPAND, 5 );


	m_panel342->SetSizer( bSizer362 );
	m_panel342->Layout();
	bSizer362->Fit( m_panel342 );
	bSizer512->Add( m_panel342, 1, wxEXPAND | wxALL, 5 );


	bSizer35->Add( bSizer512, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer513;
	bSizer513 = new wxBoxSizer( wxVERTICAL );

	m_panel343 = new wxPanel( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer363;
	bSizer363 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer373;
	bSizer373 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText93 = new wxStaticText( m_panel343, wxID_ANY, wxT("Layer 0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText93->Wrap( -1 );
	m_staticText93->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer373->Add( m_staticText93, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer363->Add( bSizer373, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer383;
	bSizer383 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText103 = new wxStaticText( m_panel343, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText103->Wrap( -1 );
	bSizer383->Add( m_staticText103, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_textCtrl13 = new wxTextCtrl( m_panel343, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer383->Add( m_textCtrl13, 2, wxALL, 5 );

	m_comboBox43 = new wxComboBox( m_panel343, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer383->Add( m_comboBox43, 1, wxALL, 5 );

	m_button33 = new wxButton( m_panel343, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer383->Add( m_button33, 0, wxALL, 5 );

	m_button23 = new wxButton( m_panel343, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer383->Add( m_button23, 0, wxALL, 5 );


	bSizer363->Add( bSizer383, 0, wxEXPAND, 5 );


	m_panel343->SetSizer( bSizer363 );
	m_panel343->Layout();
	bSizer363->Fit( m_panel343 );
	bSizer513->Add( m_panel343, 1, wxEXPAND | wxALL, 5 );


	bSizer35->Add( bSizer513, 0, wxEXPAND, 5 );


	m_scrolledWindow1->SetSizer( bSizer35 );
	m_scrolledWindow1->Layout();
	bSizer35->Fit( m_scrolledWindow1 );
	bSizer34->Add( m_scrolledWindow1, 1, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer90;
	bSizer90 = new wxBoxSizer( wxHORIZONTAL );

	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( m_panel33, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( m_panel33, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();

	bSizer90->Add( m_sdbSizer1, 1, wxEXPAND, 5 );


	bSizer34->Add( bSizer90, 1, wxEXPAND, 5 );


	m_panel33->SetSizer( bSizer34 );
	m_panel33->Layout();
	bSizer34->Fit( m_panel33 );
	bSizer48->Add( m_panel33, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer48 );
	this->Layout();

	this->Centre( wxBOTH );
}

StageCanvasSettings_Frame::~StageCanvasSettings_Frame()
{
}
