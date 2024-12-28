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
	m_project_menu = new wxMenu();
	wxMenuItem* m_newProject_menuItem;
	m_newProject_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("New Project") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_newProject_menuItem );

	wxMenuItem* m_loadProject_menuItem;
	m_loadProject_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("Load Project") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_loadProject_menuItem );

	wxMenuItem* m_saveProject_menuItem;
	m_saveProject_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("Save Project") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_saveProject_menuItem );

	wxMenuItem* m_saveProjectAs_menuItem;
	m_saveProjectAs_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("Save Project As") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_saveProjectAs_menuItem );

	m_project_menu->AppendSeparator();

	wxMenuItem* m_exit_menuItem;
	m_exit_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_exit_menuItem );

	m_menubar1->Append( m_project_menu, wxT("Project") );

	m_menu3 = new wxMenu();
	wxMenuItem* m_newStage_menuItem;
	m_newStage_menuItem = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("New Stage") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_newStage_menuItem );

	wxMenuItem* m_importStage_menuItem;
	m_importStage_menuItem = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("Import Stage") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_importStage_menuItem );

	m_menubar1->Append( m_menu3, wxT("Stage") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	m_auinotebook2 = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_TAB_FIXED_WIDTH );
	m_stage_panel = new wxPanel( m_auinotebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer99;
	bSizer99 = new wxBoxSizer( wxVERTICAL );


	bSizer99->Add( 0, 0, 1, wxEXPAND, 5 );

	m_auiToolBar52 = new wxAuiToolBar( m_stage_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_VERTICAL );
	m_s3d_select_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/cursor.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_s3d_boxSelect_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/selection-box.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_s3d_move_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/move.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_s3d_rotate_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/360.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_s3d_scale_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/scale.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_s3d_octreeActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Octree Actor"), wxBitmap( wxT("icons/mesh.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_s3d_animatedActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Animated Actor"), wxBitmap( wxT("icons/animated_mesh.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_s3d_billboardActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Billboard"), wxBitmap( wxT("icons/billboard.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Add a billboard to the stage"), wxEmptyString, NULL );

	m_s3d_lightActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Light"), wxBitmap( wxT("icons/light-bulb.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Add a light to the stage"), wxEmptyString, NULL );

	m_s3d_terrainActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add/Edit Terrain"), wxBitmap( wxT("icons/terrain.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_s3d_waterActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Water"), wxBitmap( wxT("icons/sea.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_s3d_particleActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Particle Effect"), wxBitmap( wxT("icons/effect.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_s3d_plane_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add plane"), wxBitmap( wxT("icons/plane.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_s3d_cube_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Cube"), wxBitmap( wxT("icons/3d-cube.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_s3d_sphere_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Sphere"), wxBitmap( wxT("icons/sphere.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_s3d_path_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Path"), wxBitmap( wxT("icons/anchor.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar52->Realize();

	bSizer99->Add( m_auiToolBar52, 0, wxALL, 5 );


	bSizer99->Add( 0, 0, 3, wxEXPAND, 5 );


	bSizer2->Add( bSizer99, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_splitter3 = new wxSplitterWindow( m_stage_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter3->SetSashGravity( 1 );
	m_splitter3->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter3OnIdle ), NULL, this );
	m_splitter3->SetMinimumPaneSize( 300 );

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

	m_staticText12 = new wxStaticText( m_panel47, wxID_ANY, wxT("VIEW"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer46->Add( m_staticText12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_stagePOV_comboBox = new wxComboBox( m_panel47, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer46->Add( m_stagePOV_comboBox, 0, wxALL, 5 );


	bSizer46->Add( 0, 0, 1, wxEXPAND, 5 );


	m_panel47->SetSizer( bSizer46 );
	m_panel47->Layout();
	bSizer46->Fit( m_panel47 );
	bSizer43->Add( m_panel47, 1, wxEXPAND | wxALL, 5 );


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
	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxVERTICAL );

	m_notebook1 = new wxNotebook( m_panel305, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel44 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer305;
	bSizer305 = new wxBoxSizer( wxVERTICAL );

	m_project_treeCtrl = new wxTreeCtrl( m_panel44, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	m_project_treeCtrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer305->Add( m_project_treeCtrl, 1, wxALL|wxEXPAND, 5 );


	m_panel44->SetSizer( bSizer305 );
	m_panel44->Layout();
	bSizer305->Fit( m_panel44 );
	m_notebook1->AddPage( m_panel44, wxT("Stages"), true );
	m_panel452 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer102;
	bSizer102 = new wxBoxSizer( wxVERTICAL );

	m_treeCtrl2 = new wxTreeCtrl( m_panel452, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	bSizer102->Add( m_treeCtrl2, 1, wxALL|wxEXPAND, 5 );


	m_panel452->SetSizer( bSizer102 );
	m_panel452->Layout();
	bSizer102->Fit( m_panel452 );
	m_notebook1->AddPage( m_panel452, wxT("Objects"), false );

	bSizer101->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );


	m_panel305->SetSizer( bSizer101 );
	m_panel305->Layout();
	bSizer101->Fit( m_panel305 );
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
	m_splitter3->SplitVertically( m_panel71, m_panel8, 1400 );
	bSizer4->Add( m_splitter3, 1, wxEXPAND, 5 );


	bSizer2->Add( bSizer4, 1, wxEXPAND, 5 );


	m_stage_panel->SetSizer( bSizer2 );
	m_stage_panel->Layout();
	bSizer2->Fit( m_stage_panel );
	m_auinotebook2->AddPage( m_stage_panel, wxT("Stage"), true, wxNullBitmap );
	m_meshDB_panel = new wxPanel( m_auinotebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	m_splitter51 = new wxSplitterWindow( m_meshDB_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter51->SetSashGravity( 0 );
	m_splitter51->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter51OnIdle ), NULL, this );
	m_splitter51->SetMinimumPaneSize( 1 );

	m_panel28 = new wxPanel( m_splitter51, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer251;
	bSizer251 = new wxBoxSizer( wxHORIZONTAL );

	m_mesh_importMesh_button = new wxButton( m_panel28, wxID_ANY, wxT("Import"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer251->Add( m_mesh_importMesh_button, 1, wxALL, 5 );

	m_mesh_removeMesh_button = new wxButton( m_panel28, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer251->Add( m_mesh_removeMesh_button, 1, wxALL, 5 );


	bSizer23->Add( bSizer251, 0, wxEXPAND, 5 );

	m_mesh_mesh_listBox = new wxListBox( m_panel28, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer23->Add( m_mesh_mesh_listBox, 1, wxALL|wxEXPAND, 5 );


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

	m_panel41 = new wxPanel( m_panel291, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxVERTICAL );

	m_panel33 = new wxPanel( m_panel41, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer881;
	bSizer881 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer701;
	bSizer701 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText321 = new wxStaticText( m_panel33, wxID_ANY, wxT("ID\t\t\t"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText321->Wrap( -1 );
	bSizer701->Add( m_staticText321, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_mesh_meshID_textCtrl = new wxTextCtrl( m_panel33, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer701->Add( m_mesh_meshID_textCtrl, 1, wxALL, 5 );


	bSizer881->Add( bSizer701, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer70;
	bSizer70 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32 = new wxStaticText( m_panel33, wxID_ANY, wxT("File\t\t"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer70->Add( m_staticText32, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_mesh_meshFile_textCtrl = new wxTextCtrl( m_panel33, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer70->Add( m_mesh_meshFile_textCtrl, 1, wxALL, 5 );


	bSizer881->Add( bSizer70, 0, wxEXPAND, 5 );


	m_panel33->SetSizer( bSizer881 );
	m_panel33->Layout();
	bSizer881->Fit( m_panel33 );
	bSizer69->Add( m_panel33, 0, wxEXPAND | wxALL, 5 );

	m_panel34 = new wxPanel( m_panel41, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_RAISED|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer89;
	bSizer89 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText323 = new wxStaticText( m_panel34, wxID_ANY, wxT("Materials"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323->Wrap( -1 );
	bSizer89->Add( m_staticText323, 0, wxALL, 5 );


	bSizer83->Add( bSizer89, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer( wxHORIZONTAL );

	m_panel35 = new wxPanel( m_panel34, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer88;
	bSizer88 = new wxBoxSizer( wxHORIZONTAL );


	m_panel35->SetSizer( bSizer88 );
	m_panel35->Layout();
	bSizer88->Fit( m_panel35 );
	bSizer87->Add( m_panel35, 1, wxEXPAND | wxALL, 5 );


	bSizer83->Add( bSizer87, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );

	m_setMaterial_scrolledWindow = new wxScrolledWindow( m_panel34, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL );
	m_setMaterial_scrolledWindow->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer158;
	bSizer158 = new wxBoxSizer( wxVERTICAL );

	m_mesh_material_propertyGrid = new wxPropertyGrid(m_setMaterial_scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_DEFAULT_STYLE|wxPG_HIDE_MARGIN);
	m_propertyGridItem25 = m_mesh_material_propertyGrid->Append( new wxEnumProperty( wxT("0") ) );
	m_propertyGridItem26 = m_mesh_material_propertyGrid->Append( new wxStringProperty( wxT("1") ) );
	bSizer158->Add( m_mesh_material_propertyGrid, 1, wxALL|wxEXPAND, 5 );


	m_setMaterial_scrolledWindow->SetSizer( bSizer158 );
	m_setMaterial_scrolledWindow->Layout();
	bSizer158->Fit( m_setMaterial_scrolledWindow );
	bSizer84->Add( m_setMaterial_scrolledWindow, 1, wxEXPAND | wxALL, 5 );


	bSizer83->Add( bSizer84, 1, wxEXPAND, 5 );


	m_panel34->SetSizer( bSizer83 );
	m_panel34->Layout();
	bSizer83->Fit( m_panel34 );
	bSizer69->Add( m_panel34, 1, wxEXPAND | wxALL, 5 );


	m_panel41->SetSizer( bSizer69 );
	m_panel41->Layout();
	bSizer69->Fit( m_panel41 );
	bSizer67->Add( m_panel41, 1, wxEXPAND | wxALL, 5 );


	bSizer61->Add( bSizer67, 4, wxEXPAND, 5 );

	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );

	m_mesh_animationPreview_panel = new wxPanel( m_panel291, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	bSizer71->Add( m_mesh_animationPreview_panel, 1, wxEXPAND | wxALL, 5 );

	m_toolBar2 = new wxToolBar( m_panel291, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL );
	m_mesh_meshAnimation_play_tool = m_toolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/play.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_mesh_meshAnimation_stop_tool = m_toolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/stop.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

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

	m_mesh_newAnimation_button = new wxButton( m_panel46, wxID_ANY, wxT("New"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_mesh_newAnimation_button, 0, wxALL, 5 );

	m_mesh_deleteAnimation_button = new wxButton( m_panel46, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_mesh_deleteAnimation_button, 0, wxALL, 5 );


	bSizer781->Add( bSizer82, 1, wxEXPAND, 5 );

	m_mesh_meshAnimation_listBox = new wxListBox( m_panel46, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer781->Add( m_mesh_meshAnimation_listBox, 4, wxALL|wxEXPAND, 5 );


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

	m_mesh_animationID_textCtrl = new wxTextCtrl( m_panel451, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer731->Add( m_mesh_animationID_textCtrl, 2, wxALL, 5 );


	bSizer731->Add( 0, 0, 3, wxEXPAND, 5 );


	bSizer721->Add( bSizer731, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7311;
	bSizer7311 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText271 = new wxStaticText( m_panel451, wxID_ANY, wxT("Start Frame"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText271->Wrap( -1 );
	bSizer7311->Add( m_staticText271, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_mesh_animationStartFrame_textCtrl = new wxTextCtrl( m_panel451, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7311->Add( m_mesh_animationStartFrame_textCtrl, 2, wxALL, 5 );


	bSizer7311->Add( 0, 0, 3, wxEXPAND, 5 );


	bSizer721->Add( bSizer7311, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer73111;
	bSizer73111 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2711 = new wxStaticText( m_panel451, wxID_ANY, wxT("End Frame"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2711->Wrap( -1 );
	bSizer73111->Add( m_staticText2711, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_mesh_animationEndFrame_textCtrl = new wxTextCtrl( m_panel451, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer73111->Add( m_mesh_animationEndFrame_textCtrl, 2, wxALL, 5 );


	bSizer73111->Add( 0, 0, 3, wxEXPAND, 5 );


	bSizer721->Add( bSizer73111, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer73112;
	bSizer73112 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2712 = new wxStaticText( m_panel451, wxID_ANY, wxT("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2712->Wrap( -1 );
	bSizer73112->Add( m_staticText2712, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_mesh_animationSpeed_textCtrl = new wxTextCtrl( m_panel451, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer73112->Add( m_mesh_animationSpeed_textCtrl, 2, wxALL, 5 );


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
	m_splitter51->SplitVertically( m_panel28, m_panel291, 300 );
	bSizer22->Add( m_splitter51, 1, wxEXPAND, 5 );


	bSizer21->Add( bSizer22, 1, wxEXPAND, 5 );


	m_meshDB_panel->SetSizer( bSizer21 );
	m_meshDB_panel->Layout();
	bSizer21->Fit( m_meshDB_panel );
	m_auinotebook2->AddPage( m_meshDB_panel, wxT("Mesh"), false, wxNullBitmap );
	m_panel36 = new wxPanel( m_auinotebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer93;
	bSizer93 = new wxBoxSizer( wxHORIZONTAL );

	m_splitter4 = new wxSplitterWindow( m_panel36, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter4->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter4OnIdle ), NULL, this );
	m_splitter4->SetMinimumPaneSize( 1 );

	m_panel37 = new wxPanel( m_splitter4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer94;
	bSizer94 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer95;
	bSizer95 = new wxBoxSizer( wxHORIZONTAL );

	m_material_newMaterial_button = new wxButton( m_panel37, wxID_ANY, wxT("New"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer95->Add( m_material_newMaterial_button, 0, wxALL, 5 );

	m_button231 = new wxButton( m_panel37, wxID_ANY, wxT("Import"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer95->Add( m_button231, 0, wxALL, 5 );


	bSizer94->Add( bSizer95, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer96;
	bSizer96 = new wxBoxSizer( wxHORIZONTAL );

	m_material_saveMaterial_button = new wxButton( m_panel37, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer96->Add( m_material_saveMaterial_button, 0, wxALL, 5 );

	m_button24 = new wxButton( m_panel37, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer96->Add( m_button24, 0, wxALL, 5 );


	bSizer94->Add( bSizer96, 0, wxEXPAND, 5 );

	m_material_material_listBox = new wxListBox( m_panel37, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer94->Add( m_material_material_listBox, 1, wxALL|wxEXPAND, 5 );


	m_panel37->SetSizer( bSizer94 );
	m_panel37->Layout();
	bSizer94->Fit( m_panel37 );
	m_panel38 = new wxPanel( m_splitter4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer97;
	bSizer97 = new wxBoxSizer( wxHORIZONTAL );

	m_panel391 = new wxPanel( m_panel38, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer98;
	bSizer98 = new wxBoxSizer( wxVERTICAL );

	m_scrolledWindow3 = new wxScrolledWindow( m_panel391, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer100;
	bSizer100 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer1011;
	bSizer1011 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Material ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer1011->Add( m_staticText34, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_id_textCtrl = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1011->Add( m_material_id_textCtrl, 4, wxALL, 5 );


	bSizer100->Add( bSizer1011, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1021;
	bSizer1021 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText35 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	bSizer1021->Add( m_staticText35, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_type_comboBox = new wxComboBox( m_scrolledWindow3, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer1021->Add( m_material_type_comboBox, 4, wxALL, 5 );


	bSizer100->Add( bSizer1021, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer103;
	bSizer103 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText36 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Ambient Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	bSizer103->Add( m_staticText36, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_ambient_colourPicker = new wxColourPickerCtrl( m_scrolledWindow3, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer103->Add( m_material_ambient_colourPicker, 4, wxALL, 5 );


	bSizer100->Add( bSizer103, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1031;
	bSizer1031 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText361 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Diffuse Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText361->Wrap( -1 );
	bSizer1031->Add( m_staticText361, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_diffuse_colourPicker = new wxColourPickerCtrl( m_scrolledWindow3, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer1031->Add( m_material_diffuse_colourPicker, 4, wxALL, 5 );


	bSizer100->Add( bSizer1031, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1032;
	bSizer1032 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText362 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Emissive Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText362->Wrap( -1 );
	bSizer1032->Add( m_staticText362, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_emissive_colourPicker = new wxColourPickerCtrl( m_scrolledWindow3, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer1032->Add( m_material_emissive_colourPicker, 4, wxALL, 5 );


	bSizer100->Add( bSizer1032, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1033;
	bSizer1033 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText363 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Specular Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText363->Wrap( -1 );
	bSizer1033->Add( m_staticText363, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_specular_colourPicker = new wxColourPickerCtrl( m_scrolledWindow3, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer1033->Add( m_material_specular_colourPicker, 4, wxALL, 5 );


	bSizer100->Add( bSizer1033, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer10211;
	bSizer10211 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText351 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Anti-Alias"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText351->Wrap( -1 );
	bSizer10211->Add( m_staticText351, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_antiAlias_comboBox = new wxComboBox( m_scrolledWindow3, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer10211->Add( m_material_antiAlias_comboBox, 4, wxALL, 5 );


	bSizer100->Add( bSizer10211, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer114;
	bSizer114 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText43 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Backface Culling  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	bSizer114->Add( m_staticText43, 1, wxALL, 5 );

	m_material_backFaceCulling_checkBox = new wxCheckBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer114->Add( m_material_backFaceCulling_checkBox, 4, wxALL, 5 );


	bSizer100->Add( bSizer114, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1141;
	bSizer1141 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText431 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Frontface Culling"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431->Wrap( -1 );
	bSizer1141->Add( m_staticText431, 1, wxALL, 5 );

	m_material_frontFaceCulling_checkBox = new wxCheckBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1141->Add( m_material_frontFaceCulling_checkBox, 4, wxALL, 5 );


	bSizer100->Add( bSizer1141, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer118;
	bSizer118 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText46 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Blend Factor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText46->Wrap( -1 );
	bSizer118->Add( m_staticText46, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_blendFactor_spinCtrlDouble = new wxSpinCtrlDouble( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0.000000, 0.1 );
	m_material_blendFactor_spinCtrlDouble->SetDigits( 3 );
	bSizer118->Add( m_material_blendFactor_spinCtrlDouble, 4, wxALL, 5 );


	bSizer100->Add( bSizer118, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer119;
	bSizer119 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText47 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Blend Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText47->Wrap( -1 );
	bSizer119->Add( m_staticText47, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_blendMode_comboBox = new wxComboBox( m_scrolledWindow3, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer119->Add( m_material_blendMode_comboBox, 4, wxALL, 5 );


	bSizer100->Add( bSizer119, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer120;
	bSizer120 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText48 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Color Mask"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText48->Wrap( -1 );
	bSizer120->Add( m_staticText48, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_colorMask_comboBox = new wxComboBox( m_scrolledWindow3, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer120->Add( m_material_colorMask_comboBox, 4, wxALL, 5 );


	bSizer100->Add( bSizer120, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText49 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Color Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText49->Wrap( -1 );
	bSizer121->Add( m_staticText49, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_colorMode_comboBox = new wxComboBox( m_scrolledWindow3, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer121->Add( m_material_colorMode_comboBox, 4, wxALL, 5 );


	bSizer100->Add( bSizer121, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer122;
	bSizer122 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText50 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Fog"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText50->Wrap( -1 );
	bSizer122->Add( m_staticText50, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_fog_checkBox = new wxCheckBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer122->Add( m_material_fog_checkBox, 4, wxALL, 5 );


	bSizer100->Add( bSizer122, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer123;
	bSizer123 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText51 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Gourad Shading"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	bSizer123->Add( m_staticText51, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_gouradShading_checkBox = new wxCheckBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer123->Add( m_material_gouradShading_checkBox, 4, wxALL, 5 );


	bSizer100->Add( bSizer123, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer124;
	bSizer124 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText52 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Lighting"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	bSizer124->Add( m_staticText52, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_lighting_checkBox = new wxCheckBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer124->Add( m_material_lighting_checkBox, 4, wxALL, 5 );


	bSizer100->Add( bSizer124, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1241;
	bSizer1241 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText521 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Normalize"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText521->Wrap( -1 );
	bSizer1241->Add( m_staticText521, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_normalize_checkBox = new wxCheckBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1241->Add( m_material_normalize_checkBox, 4, wxALL, 5 );


	bSizer100->Add( bSizer1241, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1242;
	bSizer1242 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText522 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Point Cloud"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText522->Wrap( -1 );
	bSizer1242->Add( m_staticText522, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_pointCloud_checkBox = new wxCheckBox( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1242->Add( m_material_pointCloud_checkBox, 4, wxALL, 5 );


	bSizer100->Add( bSizer1242, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer130;
	bSizer130 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText56 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("Shineness"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText56->Wrap( -1 );
	bSizer130->Add( m_staticText56, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_shineness_spinCtrl = new wxSpinCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 128, 0 );
	bSizer130->Add( m_material_shineness_spinCtrl, 4, wxALL, 5 );


	bSizer100->Add( bSizer130, 0, wxEXPAND, 5 );


	m_scrolledWindow3->SetSizer( bSizer100 );
	m_scrolledWindow3->Layout();
	bSizer100->Fit( m_scrolledWindow3 );
	bSizer98->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 5 );


	m_panel391->SetSizer( bSizer98 );
	m_panel391->Layout();
	bSizer98->Fit( m_panel391 );
	bSizer97->Add( m_panel391, 1, wxEXPAND | wxALL, 5 );

	m_panel401 = new wxPanel( m_panel38, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer131;
	bSizer131 = new wxBoxSizer( wxVERTICAL );

	m_panel411 = new wxPanel( m_panel401, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer138;
	bSizer138 = new wxBoxSizer( wxVERTICAL );

	m_material_materialPreview_panel = new wxPanel( m_panel411, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	bSizer138->Add( m_material_materialPreview_panel, 1, wxEXPAND | wxALL, 5 );

	m_auiToolBar2 = new wxAuiToolBar( m_panel411, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT );
	m_material_previewSpotLight_tool = m_auiToolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/spot_light.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_material_previewPointLight_tool = m_auiToolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/point_light.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar2->Realize();

	bSizer138->Add( m_auiToolBar2, 0, wxALL|wxEXPAND, 5 );


	m_panel411->SetSizer( bSizer138 );
	m_panel411->Layout();
	bSizer138->Fit( m_panel411 );
	bSizer131->Add( m_panel411, 1, wxEXPAND | wxALL, 5 );

	m_panel42 = new wxPanel( m_panel401, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_RAISED|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer132;
	bSizer132 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer133;
	bSizer133 = new wxBoxSizer( wxVERTICAL );

	m_staticText57 = new wxStaticText( m_panel42, wxID_ANY, wxT("Texture Level"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText57->Wrap( -1 );
	bSizer133->Add( m_staticText57, 0, wxALL, 5 );

	wxBoxSizer* bSizer159;
	bSizer159 = new wxBoxSizer( wxHORIZONTAL );

	m_material_addTextureLevel_button = new wxButton( m_panel42, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer159->Add( m_material_addTextureLevel_button, 0, wxALL, 5 );

	m_material_removeTextureLevel_button = new wxButton( m_panel42, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer159->Add( m_material_removeTextureLevel_button, 0, wxALL, 5 );


	bSizer133->Add( bSizer159, 0, wxEXPAND, 5 );

	m_material_textureLevel_propertyGrid = new wxPropertyGrid(m_panel42, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_DEFAULT_STYLE|wxPG_HIDE_MARGIN|wxPG_SPLITTER_AUTO_CENTER);
	m_propertyGridItem23 = m_material_textureLevel_propertyGrid->Append( new wxImageFileProperty( wxT("Name") ) );
	bSizer133->Add( m_material_textureLevel_propertyGrid, 1, wxALL|wxEXPAND, 5 );


	bSizer132->Add( bSizer133, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer134;
	bSizer134 = new wxBoxSizer( wxVERTICAL );

	m_panel441 = new wxPanel( m_panel42, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer137;
	bSizer137 = new wxBoxSizer( wxVERTICAL );

	m_material_texturePreview_bitmap = new wxStaticBitmap( m_panel441, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer137->Add( m_material_texturePreview_bitmap, 1, wxALL|wxEXPAND, 5 );


	m_panel441->SetSizer( bSizer137 );
	m_panel441->Layout();
	bSizer137->Fit( m_panel441 );
	bSizer134->Add( m_panel441, 4, wxEXPAND | wxALL, 5 );


	bSizer132->Add( bSizer134, 1, wxEXPAND, 5 );


	m_panel42->SetSizer( bSizer132 );
	m_panel42->Layout();
	bSizer132->Fit( m_panel42 );
	bSizer131->Add( m_panel42, 1, wxEXPAND | wxALL, 5 );


	m_panel401->SetSizer( bSizer131 );
	m_panel401->Layout();
	bSizer131->Fit( m_panel401 );
	bSizer97->Add( m_panel401, 1, wxEXPAND | wxALL, 5 );


	m_panel38->SetSizer( bSizer97 );
	m_panel38->Layout();
	bSizer97->Fit( m_panel38 );
	m_splitter4->SplitVertically( m_panel37, m_panel38, 300 );
	bSizer93->Add( m_splitter4, 1, wxEXPAND, 5 );


	bSizer92->Add( bSizer93, 1, wxEXPAND, 5 );


	m_panel36->SetSizer( bSizer92 );
	m_panel36->Layout();
	bSizer92->Fit( m_panel36 );
	m_auinotebook2->AddPage( m_panel36, wxT("Material"), false, wxNullBitmap );

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
	m_project_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Serenity3D_Frame::OnNewProjectMenuSelection ), this, m_newProject_menuItem->GetId());
	this->Connect( m_s3d_select_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DSelectClicked ) );
	this->Connect( m_s3d_boxSelect_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DBoxClicked ) );
	this->Connect( m_s3d_move_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DMoveClicked ) );
	this->Connect( m_s3d_rotate_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DRotateClicked ) );
	this->Connect( m_s3d_scale_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DScaleClicked ) );
	this->Connect( m_s3d_octreeActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DDumpClicked ) );
	this->Connect( m_s3d_animatedActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DWizClicked ) );
	this->Connect( m_s3d_billboardActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DBillboardClicked ) );
	this->Connect( m_s3d_lightActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DLightClicked ) );
	this->Connect( m_s3d_terrainActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DTerrainClicked ) );
	this->Connect( m_s3d_waterActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DWaterClicked ) );
	this->Connect( m_s3d_particleActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DEffectClicked ) );
	this->Connect( m_s3d_plane_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DPlaneClicked ) );
	this->Connect( m_s3d_cube_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DCubeClicked ) );
	this->Connect( m_s3d_sphere_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DSphereClicked ) );
	this->Connect( m_s3d_path_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DPathClicked ) );
	m_stagePOV_comboBox->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::OnViewComboSelect ), NULL, this );
	m_mesh_importMesh_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnMeshImportButtonClick ), NULL, this );
	m_mesh_animationPreview_panel->Connect( wxEVT_SIZE, wxSizeEventHandler( Serenity3D_Frame::OnAnimationPreviewSize ), NULL, this );
	this->Connect( m_mesh_meshAnimation_stop_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnAnimationStopClicked ) );
	this->Connect( m_tbar_play_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnPlayClicked ) );
	this->Connect( m_tool7->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnStopClicked ) );
}

Serenity3D_Frame::~Serenity3D_Frame()
{
	// Disconnect Events
	this->Disconnect( m_s3d_select_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DSelectClicked ) );
	this->Disconnect( m_s3d_boxSelect_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DBoxClicked ) );
	this->Disconnect( m_s3d_move_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DMoveClicked ) );
	this->Disconnect( m_s3d_rotate_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DRotateClicked ) );
	this->Disconnect( m_s3d_scale_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DScaleClicked ) );
	this->Disconnect( m_s3d_octreeActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DDumpClicked ) );
	this->Disconnect( m_s3d_animatedActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DWizClicked ) );
	this->Disconnect( m_s3d_billboardActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DBillboardClicked ) );
	this->Disconnect( m_s3d_lightActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DLightClicked ) );
	this->Disconnect( m_s3d_terrainActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DTerrainClicked ) );
	this->Disconnect( m_s3d_waterActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DWaterClicked ) );
	this->Disconnect( m_s3d_particleActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DEffectClicked ) );
	this->Disconnect( m_s3d_plane_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DPlaneClicked ) );
	this->Disconnect( m_s3d_cube_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DCubeClicked ) );
	this->Disconnect( m_s3d_sphere_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DSphereClicked ) );
	this->Disconnect( m_s3d_path_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DPathClicked ) );
	m_stagePOV_comboBox->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::OnViewComboSelect ), NULL, this );
	m_mesh_importMesh_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnMeshImportButtonClick ), NULL, this );
	m_mesh_animationPreview_panel->Disconnect( wxEVT_SIZE, wxSizeEventHandler( Serenity3D_Frame::OnAnimationPreviewSize ), NULL, this );
	this->Disconnect( m_mesh_meshAnimation_stop_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnAnimationStopClicked ) );
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

MyFrame3::MyFrame3( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxVERTICAL );

	m_panel38 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	m_staticText32 = new wxStaticText( m_panel38, wxID_ANY, wxT("NEW OCTREE ACTOR"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	m_staticText32->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxEmptyString ) );

	bSizer77->Add( m_staticText32, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( m_panel38, wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer78->Add( m_staticText33, 0, wxALL, 5 );

	m_textCtrl11 = new wxTextCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer78->Add( m_textCtrl11, 1, wxALL, 5 );


	bSizer77->Add( bSizer78, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( m_panel38, wxID_ANY, wxT("MESH"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer79->Add( m_staticText34, 0, wxALL, 5 );

	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrl12 = new wxTextCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( m_textCtrl12, 1, wxALL, 5 );

	m_button17 = new wxButton( m_panel38, wxID_ANY, wxT("Find"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( m_button17, 0, wxALL, 5 );


	bSizer80->Add( bSizer81, 0, wxEXPAND, 5 );

	m_listBox3 = new wxListBox( m_panel38, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer80->Add( m_listBox3, 1, wxALL|wxEXPAND, 5 );


	bSizer79->Add( bSizer80, 1, wxEXPAND, 5 );


	bSizer77->Add( bSizer79, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );


	bSizer82->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button18 = new wxButton( m_panel38, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_button18, 0, wxALL, 5 );

	m_button19 = new wxButton( m_panel38, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_button19, 0, wxALL, 5 );


	bSizer77->Add( bSizer82, 0, wxEXPAND, 5 );


	m_panel38->SetSizer( bSizer77 );
	m_panel38->Layout();
	bSizer77->Fit( m_panel38 );
	bSizer76->Add( m_panel38, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer76 );
	this->Layout();

	this->Centre( wxBOTH );
}

MyFrame3::~MyFrame3()
{
}

MyFrame31::MyFrame31( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxVERTICAL );

	m_panel38 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	m_staticText32 = new wxStaticText( m_panel38, wxID_ANY, wxT("NEW OCTREE ACTOR"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	m_staticText32->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxEmptyString ) );

	bSizer77->Add( m_staticText32, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( m_panel38, wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer78->Add( m_staticText33, 0, wxALL, 5 );

	m_textCtrl11 = new wxTextCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer78->Add( m_textCtrl11, 1, wxALL, 5 );


	bSizer77->Add( bSizer78, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( m_panel38, wxID_ANY, wxT("MESH"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer79->Add( m_staticText34, 0, wxALL, 5 );

	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrl12 = new wxTextCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( m_textCtrl12, 1, wxALL, 5 );

	m_button17 = new wxButton( m_panel38, wxID_ANY, wxT("Find"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( m_button17, 0, wxALL, 5 );


	bSizer80->Add( bSizer81, 0, wxEXPAND, 5 );

	m_listBox3 = new wxListBox( m_panel38, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer80->Add( m_listBox3, 1, wxALL|wxEXPAND, 5 );


	bSizer79->Add( bSizer80, 1, wxEXPAND, 5 );


	bSizer77->Add( bSizer79, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );


	bSizer82->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button18 = new wxButton( m_panel38, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_button18, 0, wxALL, 5 );

	m_button19 = new wxButton( m_panel38, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_button19, 0, wxALL, 5 );


	bSizer77->Add( bSizer82, 0, wxEXPAND, 5 );


	m_panel38->SetSizer( bSizer77 );
	m_panel38->Layout();
	bSizer77->Fit( m_panel38 );
	bSizer76->Add( m_panel38, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer76 );
	this->Layout();

	this->Centre( wxBOTH );
}

MyFrame31::~MyFrame31()
{
}

MyFrame5::MyFrame5( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxVERTICAL );

	m_setMaterial_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	wxBoxSizer* b_setMaterial_Sizer;
	b_setMaterial_Sizer = new wxBoxSizer( wxHORIZONTAL );

	m_materialLabel_panel = new wxPanel( m_setMaterial_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	wxBoxSizer* b_materialLabel_Sizer;
	b_materialLabel_Sizer = new wxBoxSizer( wxVERTICAL );

	m_materialNumber_staticText = new wxStaticText( m_materialLabel_panel, wxID_ANY, wxT("Material [0]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_materialNumber_staticText->Wrap( -1 );
	b_materialLabel_Sizer->Add( m_materialNumber_staticText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	m_materialLabel_panel->SetSizer( b_materialLabel_Sizer );
	m_materialLabel_panel->Layout();
	b_materialLabel_Sizer->Fit( m_materialLabel_panel );
	b_setMaterial_Sizer->Add( m_materialLabel_panel, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_materialID_panel = new wxPanel( m_setMaterial_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	wxBoxSizer* b_materialID_Sizer;
	b_materialID_Sizer = new wxBoxSizer( wxHORIZONTAL );

	m_materialID_comboBox = new wxComboBox( m_materialID_panel, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	b_materialID_Sizer->Add( m_materialID_comboBox, 1, wxALL, 5 );


	m_materialID_panel->SetSizer( b_materialID_Sizer );
	m_materialID_panel->Layout();
	b_materialID_Sizer->Fit( m_materialID_panel );
	b_setMaterial_Sizer->Add( m_materialID_panel, 4, wxALL, 5 );


	m_setMaterial_panel->SetSizer( b_setMaterial_Sizer );
	m_setMaterial_panel->Layout();
	b_setMaterial_Sizer->Fit( m_setMaterial_panel );
	bSizer141->Add( m_setMaterial_panel, 0, wxEXPAND | wxALL, 0 );

	m_setMaterial_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	wxBoxSizer* b_setMaterial_Sizer1;
	b_setMaterial_Sizer1 = new wxBoxSizer( wxHORIZONTAL );

	m_materialLabel_panel1 = new wxPanel( m_setMaterial_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b_materialLabel_Sizer1;
	b_materialLabel_Sizer1 = new wxBoxSizer( wxVERTICAL );

	m_materialNumber_staticText1 = new wxStaticText( m_materialLabel_panel1, wxID_ANY, wxT("Material [0]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_materialNumber_staticText1->Wrap( -1 );
	b_materialLabel_Sizer1->Add( m_materialNumber_staticText1, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );


	m_materialLabel_panel1->SetSizer( b_materialLabel_Sizer1 );
	m_materialLabel_panel1->Layout();
	b_materialLabel_Sizer1->Fit( m_materialLabel_panel1 );
	b_setMaterial_Sizer1->Add( m_materialLabel_panel1, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );

	m_materialID_panel1 = new wxPanel( m_setMaterial_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b_materialID_Sizer1;
	b_materialID_Sizer1 = new wxBoxSizer( wxHORIZONTAL );

	m_materialID_comboBox1 = new wxComboBox( m_materialID_panel1, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	b_materialID_Sizer1->Add( m_materialID_comboBox1, 1, wxALL, 5 );


	m_materialID_panel1->SetSizer( b_materialID_Sizer1 );
	m_materialID_panel1->Layout();
	b_materialID_Sizer1->Fit( m_materialID_panel1 );
	b_setMaterial_Sizer1->Add( m_materialID_panel1, 4, wxALL|wxEXPAND, 5 );


	m_setMaterial_panel1->SetSizer( b_setMaterial_Sizer1 );
	m_setMaterial_panel1->Layout();
	b_setMaterial_Sizer1->Fit( m_setMaterial_panel1 );
	bSizer141->Add( m_setMaterial_panel1, 0, wxEXPAND | wxALL, 0 );

	m_propertyGrid2 = new wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_DEFAULT_STYLE);
	m_propertyGridItem1 = m_propertyGrid2->Append( new wxPropertyCategory( wxT("Name1"), wxT("Test") ) );
	m_propertyGridItem2 = m_propertyGrid2->Append( new wxEditEnumProperty( wxT("Name2") ) );
	m_propertyGridItem3 = m_propertyGrid2->Append( new wxMultiChoiceProperty( wxT("Name3") ) );
	bSizer141->Add( m_propertyGrid2, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer141 );
	this->Layout();

	this->Centre( wxBOTH );
}

MyFrame5::~MyFrame5()
{
}
