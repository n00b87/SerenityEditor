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

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	m_editorMain_auinotebook = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_TAB_FIXED_WIDTH );
	m_stage_panel = new wxPanel( m_editorMain_auinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
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

	m_auiToolBar52->AddSeparator();

	m_s3d_animatedActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Animated Actor"), wxBitmap( wxT("icons/animated_mesh.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_s3d_octreeActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Octree Actor"), wxBitmap( wxT("icons/mesh.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_s3d_billboardActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Billboard"), wxBitmap( wxT("icons/billboard.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Add a billboard to the stage"), wxEmptyString, NULL );

	m_s3d_lightActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Light"), wxBitmap( wxT("icons/light-bulb.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Add a light to the stage"), wxEmptyString, NULL );

	m_s3d_terrainActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add/Edit Terrain"), wxBitmap( wxT("icons/terrain.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_s3d_waterActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Water"), wxBitmap( wxT("icons/sea.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_s3d_particleActor_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Particle Effect"), wxBitmap( wxT("icons/effect.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_s3d_cube_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Cube"), wxBitmap( wxT("icons/3d-cube.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_s3d_sphere_tool = m_auiToolBar52->AddTool( wxID_ANY, wxT("Add Sphere"), wxBitmap( wxT("icons/sphere.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

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
	bSizer46->Add( m_stagePOV_comboBox, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer46->Add( 0, 0, 1, wxEXPAND, 5 );

	m_auiToolBar5 = new wxAuiToolBar( m_panel47, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT );
	m_tool30 = m_auiToolBar5->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/camera.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar5->Realize();

	bSizer46->Add( m_auiToolBar5, 0, wxALL, 5 );


	bSizer46->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText84 = new wxStaticText( m_panel47, wxID_ANY, wxT("MODE"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText84->Wrap( -1 );
	bSizer46->Add( m_staticText84, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_renderMode_auiToolBar = new wxAuiToolBar( m_panel47, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT|wxAUI_TB_PLAIN_BACKGROUND );
	m_renderMode_auiToolBar->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_renderMode_auiToolBar->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	m_render_wire_tool = m_renderMode_auiToolBar->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/wireframe.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_render_solid_tool = m_renderMode_auiToolBar->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/solid.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_renderMode_auiToolBar->Realize();

	bSizer46->Add( m_renderMode_auiToolBar, 0, wxALL, 5 );


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

	m_auinotebook3 = new wxAuiNotebook( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_project_stages_panel = new wxPanel( m_auinotebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );

	m_splitter6 = new wxSplitterWindow( m_project_stages_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter6->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter6OnIdle ), NULL, this );

	m_panel305 = new wxPanel( m_splitter6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxVERTICAL );

	m_panel44 = new wxPanel( m_panel305, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer305;
	bSizer305 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer163;
	bSizer163 = new wxBoxSizer( wxHORIZONTAL );

	m_bpButton41 = new wxBitmapButton( m_panel44, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	m_bpButton41->SetBitmap( wxBitmap( wxT("icons/plus_stage.png"), wxBITMAP_TYPE_ANY ) );
	bSizer163->Add( m_bpButton41, 0, wxALL|wxEXPAND, 5 );

	m_bpButton51 = new wxBitmapButton( m_panel44, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	m_bpButton51->SetBitmap( wxBitmap( wxT("icons/remove_stage.png"), wxBITMAP_TYPE_ANY ) );
	bSizer163->Add( m_bpButton51, 0, wxALL|wxEXPAND, 5 );

	m_bpButton4 = new wxBitmapButton( m_panel44, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	m_bpButton4->SetBitmap( wxBitmap( wxT("icons/new-folder.png"), wxBITMAP_TYPE_ANY ) );
	bSizer163->Add( m_bpButton4, 0, wxALL|wxEXPAND, 5 );

	m_bpButton5 = new wxBitmapButton( m_panel44, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	m_bpButton5->SetBitmap( wxBitmap( wxT("icons/delete-folder.png"), wxBITMAP_TYPE_ANY ) );
	bSizer163->Add( m_bpButton5, 0, wxALL|wxEXPAND, 5 );

	m_bpButton6 = new wxBitmapButton( m_panel44, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	m_bpButton6->SetBitmap( wxBitmap( wxT("icons/edit-folder.png"), wxBITMAP_TYPE_ANY ) );
	bSizer163->Add( m_bpButton6, 0, wxALL|wxEXPAND, 5 );

	m_bpButton61 = new wxBitmapButton( m_panel44, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	m_bpButton61->SetBitmap( wxBitmap( wxT("icons/remove_actor.png"), wxBITMAP_TYPE_ANY ) );
	bSizer163->Add( m_bpButton61, 0, wxALL, 5 );


	bSizer305->Add( bSizer163, 0, wxEXPAND, 5 );

	m_project_stage_treeCtrl = new wxTreeCtrl( m_panel44, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	m_project_stage_treeCtrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer305->Add( m_project_stage_treeCtrl, 1, wxALL|wxEXPAND, 5 );


	m_panel44->SetSizer( bSizer305 );
	m_panel44->Layout();
	bSizer305->Fit( m_panel44 );
	bSizer101->Add( m_panel44, 1, wxEXPAND | wxALL, 5 );


	m_panel305->SetSizer( bSizer101 );
	m_panel305->Layout();
	bSizer101->Fit( m_panel305 );
	m_panel311 = new wxPanel( m_splitter6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );

	m_stage_propertyGridManager = new wxPropertyGridManager(m_panel311, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPGMAN_DEFAULT_STYLE|wxPG_SPLITTER_AUTO_CENTER);
	m_stage_propertyGridManager->SetExtraStyle( wxPG_EX_MODE_BUTTONS );

	m_lightActorProperties_propertyGridPage = m_stage_propertyGridManager->AddPage( wxT("Actor Properties"), wxNullBitmap );
	m_animatedActorPropertiesCat_propertyGridItem11111 = m_lightActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Light Properties"), wxT("actorPropertiesCat") ) );
	m_aniActorID_propertyGridItem11111 = m_lightActorProperties_propertyGridPage->Append( new wxStringProperty( wxT("ID"), wxT("actor_id") ) );
	m_propertyGridItem268 = m_lightActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Light Type"), wxT("light_type") ) );
	m_propertyGridItem272 = m_lightActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Cast Shadow"), wxT("cast_shadow") ) );
	m_propertyGridItem3041 = m_lightActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Use Attenuation"), wxT("use_attenuation") ) );
	m_propertyGridItem443 = m_lightActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Shape") ) );
	m_propertyGridItem444 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Inner Cone"), wxT("inner_cone") ) );
	m_propertyGridItem445 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Outer Cone"), wxT("outer_cone") ) );
	m_propertyGridItem269 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Radius"), wxT("radius") ) );
	m_propertyGridItem271 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Fall Off"), wxT("falloff") ) );
	m_propertyGridItem435 = m_lightActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Color") ) );
	m_propertyGridItem436 = m_lightActorProperties_propertyGridPage->Append( new wxColourProperty( wxT("Ambient"), wxT("ambient_color") ) );
	m_propertyGridItem437 = m_lightActorProperties_propertyGridPage->Append( new wxColourProperty( wxT("Diffuse"), wxT("diffuse_color") ) );
	m_propertyGridItem438 = m_lightActorProperties_propertyGridPage->Append( new wxColourProperty( wxT("Specular"), wxT("specular_color") ) );
	m_propertyGridItem439 = m_lightActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Attenuation") ) );
	m_propertyGridItem440 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Constant"), wxT("constant_attenuation") ) );
	m_propertyGridItem441 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Linear"), wxT("linear_attenuation") ) );
	m_propertyGridItem442 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Quadratic"), wxT("quadratic_attenuation") ) );
	m_propertyGridItem4611111 = m_lightActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Position") ) );
	m_propertyGridItem4711111 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("pos_x") ) );
	m_propertyGridItem4811111 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("pos_y") ) );
	m_propertyGridItem4911111 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("pos_z") ) );
	m_propertyGridItem5011111 = m_lightActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Rotation") ) );
	m_propertyGridItem5111111 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("rot_x") ) );
	m_propertyGridItem5211111 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("rot_y") ) );
	m_propertyGridItem5311111 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("rot_z") ) );
	m_propertyGridItem5411111 = m_lightActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Scale") ) );
	m_propertyGridItem5511111 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("scale_x") ) );
	m_propertyGridItem5611111 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("scale_y") ) );
	m_propertyGridItem5711111 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("scale_z") ) );
	m_propertyGridItem5811111 = m_lightActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Render Properties") ) );
	m_propertyGridItem453 = m_lightActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Material"), wxT("material_id") ) );
	m_propertyGridItem6011111 = m_lightActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Visible"), wxT("visible") ) );
	m_propertyGridItem6111111 = m_lightActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Shadow"), wxT("shadow") ) );
	m_propertyGridItem6211111 = m_lightActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Auto Culling"), wxT("auto_culling") ) );
	m_propertyGridItem2682 = m_lightActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Physics Properties") ) );
	m_propertyGridItem2692 = m_lightActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Shape"), wxT("physics_shape") ) );
	m_propertyGridItem2712 = m_lightActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Solid"), wxT("physics_solid") ) );
	m_propertyGridItem270 = m_lightActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Mass"), wxT("physics_mass") ) );

	m_particleActorProperties_propertyGridPage = m_stage_propertyGridManager->AddPage( wxT("Particle Actor Properties"), wxNullBitmap );
	m_animatedActorPropertiesCat_propertyGridItem111111 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Particle Properties") ) );
	m_aniActorID_propertyGridItem111111 = m_particleActorProperties_propertyGridPage->Append( new wxStringProperty( wxT("ID"), wxT("actor_id") ) );
	m_propertyGridItem2681 = m_particleActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Particle Type"), wxT("particle_type") ) );
	m_propertyGridItem333 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Min Size") ) );
	m_propertyGridItem334 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Width"), wxT("min_width") ) );
	m_propertyGridItem335 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Height"), wxT("min_height") ) );
	m_propertyGridItem336 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Max Size") ) );
	m_propertyGridItem337 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Width"), wxT("max_width") ) );
	m_propertyGridItem338 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Height"), wxT("max_height") ) );
	m_propertyGridItem322 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Color") ) );
	m_propertyGridItem323 = m_particleActorProperties_propertyGridPage->Append( new wxColourProperty( wxT("Min Start"), wxT("min_start_color") ) );
	m_propertyGridItem324 = m_particleActorProperties_propertyGridPage->Append( new wxColourProperty( wxT("Max Start"), wxT("max_start_color") ) );
	m_propertyGridItem325 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Speed") ) );
	m_propertyGridItem326 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Min Per Sec"), wxT("min_per_sec") ) );
	m_propertyGridItem327 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Max Per Sec"), wxT("max_per_sec") ) );
	m_propertyGridItem328 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Lifetime") ) );
	m_propertyGridItem329 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Min Life (milliseconds)"), wxT("min_life") ) );
	m_propertyGridItem330 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Max Life (milliseconds)"), wxT("max_life") ) );
	m_propertyGridItem364 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Normal") ) );
	m_propertyGridItem365 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("normal_x") ) );
	m_propertyGridItem366 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("normal_y") ) );
	m_propertyGridItem367 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("normal_z") ) );
	m_propertyGridItem339 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Direction") ) );
	m_propertyGridItem340 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("dir_x") ) );
	m_propertyGridItem341 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("dir_y") ) );
	m_propertyGridItem342 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("dir_z") ) );
	m_propertyGridItem331 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Deviation") ) );
	m_propertyGridItem332 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Max Angle"), wxT("max_angle") ) );
	m_propertyGridItem347 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Circle Parameters") ) );
	m_propertyGridItem348 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("center_x") ) );
	m_propertyGridItem349 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("center_y") ) );
	m_propertyGridItem350 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("center_z") ) );
	m_propertyGridItem2691 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Radius"), wxT("radius") ) );
	m_propertyGridItem343 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Mesh Settings") ) );
	m_propertyGridItem321 = m_particleActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Mesh"), wxT("particle_mesh_id") ) );
	m_propertyGridItem2701 = m_particleActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Use Every Vertex"), wxT("use_every_vertex") ) );
	m_propertyGridItem2721 = m_particleActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Use Normal Direction"), wxT("use_normal_direction") ) );
	m_propertyGridItem304 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Normal Direction Modifier"), wxT("normal_dir_mod") ) );
	m_propertyGridItem345 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Cylinder Settings") ) );
	m_propertyGridItem346 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Length"), wxT("cylinder_length") ) );
	m_propertyGridItem2711 = m_particleActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Use Outline Only"), wxT("use_outline_only") ) );
	m_propertyGridItem354 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Min Box Size") ) );
	m_propertyGridItem355 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("min_box_x") ) );
	m_propertyGridItem356 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("min_box_y") ) );
	m_propertyGridItem357 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("min_box_z") ) );
	m_propertyGridItem358 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Max Box Size") ) );
	m_propertyGridItem359 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("max_box_x") ) );
	m_propertyGridItem360 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("max_box_y") ) );
	m_propertyGridItem361 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("max_box_z") ) );
	m_propertyGridItem362 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Ring Settings") ) );
	m_propertyGridItem363 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Ring Thickness"), wxT("ring_thickness") ) );
	m_propertyGridItem46111111 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Position") ) );
	m_propertyGridItem47111111 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("pos_x") ) );
	m_propertyGridItem48111111 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("pos_y") ) );
	m_propertyGridItem49111111 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("pos_z") ) );
	m_propertyGridItem50111111 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Rotation") ) );
	m_propertyGridItem51111111 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("rot_x") ) );
	m_propertyGridItem52111111 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("rot_y") ) );
	m_propertyGridItem53111111 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("rot_z") ) );
	m_propertyGridItem54111111 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Scale") ) );
	m_propertyGridItem55111111 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("scale_x") ) );
	m_propertyGridItem56111111 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("scale_y") ) );
	m_propertyGridItem57111111 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("scale_z") ) );
	m_propertyGridItem58111111 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Render Properties") ) );
	m_propertyGridItem451 = m_particleActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Material"), wxT("material_id") ) );
	m_propertyGridItem60111111 = m_particleActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Visible"), wxT("visible") ) );
	m_propertyGridItem61111111 = m_particleActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Shadow"), wxT("shadow") ) );
	m_propertyGridItem62111111 = m_particleActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Auto Culling"), wxT("auto_culling") ) );
	m_propertyGridItem276 = m_particleActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Physics Properties") ) );
	m_propertyGridItem277 = m_particleActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Shape"), wxT("physics_shape") ) );
	m_propertyGridItem278 = m_particleActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Solid"), wxT("physics_solid") ) );
	m_propertyGridItem279 = m_particleActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Mass"), wxT("physics_mass") ) );

	m_propertyGridPage13 = m_stage_propertyGridManager->AddPage( wxT("Page"), wxNullBitmap );

	m_group_propertyGridPage = m_stage_propertyGridManager->AddPage( wxT("Group"), wxNullBitmap );

	m_animatedActorProperties_propertyGridPage = m_stage_propertyGridManager->AddPage( wxT("Animated Actor Properties"), wxNullBitmap );
	m_animatedActorPropertiesCat_propertyGridItem = m_animatedActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Animated Actor Properties") ) );
	m_aniActorID_propertyGridItem = m_animatedActorProperties_propertyGridPage->Append( new wxStringProperty( wxT("ID"), wxT("actor_id") ) );
	m_propertyGridItem41 = m_animatedActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Mesh"), wxT("animation_mesh_id") ) );
	m_propertyGridItem42 = m_animatedActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Animation"), wxT("ActorAnimationCat") ) );
	m_propertyGridItem43 = m_animatedActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Init Animation"), wxT("init_animation_id") ) );
	m_propertyGridItem44 = m_animatedActorProperties_propertyGridPage->Append( new wxIntProperty( wxT("Num Loops"), wxT("num_loops") ) );
	m_propertyGridItem46 = m_animatedActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Position") ) );
	m_propertyGridItem47 = m_animatedActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("pos_x") ) );
	m_propertyGridItem48 = m_animatedActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("pos_y") ) );
	m_propertyGridItem49 = m_animatedActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("pos_z") ) );
	m_propertyGridItem50 = m_animatedActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Rotation") ) );
	m_propertyGridItem51 = m_animatedActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("rot_x") ) );
	m_propertyGridItem52 = m_animatedActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("rot_y") ) );
	m_propertyGridItem53 = m_animatedActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("rot_z") ) );
	m_propertyGridItem54 = m_animatedActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Scale") ) );
	m_propertyGridItem55 = m_animatedActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("scale_x") ) );
	m_propertyGridItem56 = m_animatedActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("scale_y") ) );
	m_propertyGridItem57 = m_animatedActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("scale_z") ) );
	m_propertyGridItem58 = m_animatedActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Render Properties") ) );
	m_propertyGridItem452 = m_animatedActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Material"), wxT("material_id") ) );
	m_propertyGridItem60 = m_animatedActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Visible"), wxT("visible") ) );
	m_propertyGridItem61 = m_animatedActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Shadow"), wxT("shadow") ) );
	m_propertyGridItem62 = m_animatedActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Auto Culling"), wxT("auto_culling") ) );
	m_propertyGridItem2722 = m_animatedActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Physics Properties") ) );
	m_propertyGridItem273 = m_animatedActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Shape"), wxT("physics_shape") ) );
	m_propertyGridItem274 = m_animatedActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Solid"), wxT("physics_solid") ) );
	m_propertyGridItem275 = m_animatedActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Mass"), wxT("physics_mass") ) );

	m_projectProperties_propertyGridPage = m_stage_propertyGridManager->AddPage( wxT("Page"), wxNullBitmap );
	m_propertyGridItem432 = m_projectProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Project") ) );
	m_propertyGridItem433 = m_projectProperties_propertyGridPage->Append( new wxStringProperty( wxT("Name"), wxT("project_name") ) );

	m_stageProperties_propertyGridPage = m_stage_propertyGridManager->AddPage( wxT("Stage Properties"), wxNullBitmap );
	m_propertyGridItem15 = m_stageProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Stage Properties") ) );
	m_stageID_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxStringProperty( wxT("ID"), wxT("stage_id") ) );
	m_skyShape_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Sky Shape"), wxT("sky_shape") ) );
	m_propertyGridItem21 = m_stageProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Sky Dome") ) );
	m_propertyGridItem14 = m_stageProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Image"), wxT("sky_dome_image_id") ) );
	m_skyDome_hRes_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxUIntProperty( wxT("H Res"), wxT("skydome_hRes") ) );
	m_skyDome_vRes_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxUIntProperty( wxT("V Res"), wxT("skydome_vRes") ) );
	m_skyDomeTxPct_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Texture %"), wxT("sky_texture_pct") ) );
	m_skyDomeSpherePct_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Sphere %"), wxT("sky_sphere_pct") ) );
	m_skyDomeRadius_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Radius"), wxT("sky_radius") ) );
	m_skyBoxCat_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Sky Box") ) );
	m_skyBoxTopImage_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Image (Top)"), wxT("skybox_top_image") ) );
	m_skyBoxBottomImage_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Image (Bottom)"), wxT("skybox_bottom_image") ) );
	m_skyBoxLeftImage_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Image (Left)"), wxT("skybox_left_image") ) );
	m_skyBoxRightImage_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Image (Right)"), wxT("skybox_right_image") ) );
	m_skyBoxFrontImage_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Image (Front)"), wxT("skybox_front_image") ) );
	m_skyBoxBackImage_propertyGridItem = m_stageProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Image (Back)"), wxT("skybox_back_image") ) );

	m_octreeActorProperties_propertyGridPage = m_stage_propertyGridManager->AddPage( wxT("Actor Properties"), wxNullBitmap );
	m_animatedActorPropertiesCat_propertyGridItem1 = m_octreeActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Octree Actor Properties"), wxT("actorPropertiesCat") ) );
	m_aniActorID_propertyGridItem1 = m_octreeActorProperties_propertyGridPage->Append( new wxStringProperty( wxT("ID"), wxT("actor_id") ) );
	m_propertyGridItem411 = m_octreeActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Mesh"), wxT("mesh_id") ) );
	m_propertyGridItem461 = m_octreeActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Position") ) );
	m_propertyGridItem471 = m_octreeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("pos_x") ) );
	m_propertyGridItem481 = m_octreeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("pos_y") ) );
	m_propertyGridItem491 = m_octreeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("pos_z") ) );
	m_propertyGridItem501 = m_octreeActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Rotation") ) );
	m_propertyGridItem511 = m_octreeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("rot_x") ) );
	m_propertyGridItem521 = m_octreeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("rot_y") ) );
	m_propertyGridItem531 = m_octreeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("rot_z") ) );
	m_propertyGridItem541 = m_octreeActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Scale") ) );
	m_propertyGridItem551 = m_octreeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("scale_x") ) );
	m_propertyGridItem561 = m_octreeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("scale_y") ) );
	m_propertyGridItem571 = m_octreeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("scale_z") ) );
	m_propertyGridItem581 = m_octreeActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Render Properties") ) );
	m_propertyGridItem450 = m_octreeActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Material"), wxT("material_id") ) );
	m_propertyGridItem601 = m_octreeActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Visible"), wxT("visible") ) );
	m_propertyGridItem611 = m_octreeActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Shadow"), wxT("shadow") ) );
	m_propertyGridItem621 = m_octreeActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Auto Culling"), wxT("auto_culling") ) );
	m_propertyGridItem280 = m_octreeActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Physics Properties") ) );
	m_propertyGridItem281 = m_octreeActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Shape"), wxT("physics_shape") ) );
	m_propertyGridItem282 = m_octreeActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Solid"), wxT("physics_solid") ) );
	m_propertyGridItem283 = m_octreeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Mass"), wxT("physics_mass") ) );

	m_cubeActorProperties_propertyGridPage = m_stage_propertyGridManager->AddPage( wxT("Actor Properties"), wxNullBitmap );
	m_animatedActorPropertiesCat_propertyGridItem11 = m_cubeActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Cube Properties"), wxT("actorPropertiesCat") ) );
	m_aniActorID_propertyGridItem11 = m_cubeActorProperties_propertyGridPage->Append( new wxStringProperty( wxT("ID"), wxT("actor_id") ) );
	m_propertyGridItem149 = m_cubeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Size"), wxT("cube_size") ) );
	m_propertyGridItem4611 = m_cubeActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Position") ) );
	m_propertyGridItem4711 = m_cubeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("pos_x") ) );
	m_propertyGridItem4811 = m_cubeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("pos_y") ) );
	m_propertyGridItem4911 = m_cubeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("pos_z") ) );
	m_propertyGridItem5011 = m_cubeActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Rotation") ) );
	m_propertyGridItem5111 = m_cubeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("rot_x") ) );
	m_propertyGridItem5211 = m_cubeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("rot_y") ) );
	m_propertyGridItem5311 = m_cubeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("rot_z") ) );
	m_propertyGridItem5411 = m_cubeActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Scale") ) );
	m_propertyGridItem5511 = m_cubeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("scale_x") ) );
	m_propertyGridItem5611 = m_cubeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("scale_y") ) );
	m_propertyGridItem5711 = m_cubeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("scale_z") ) );
	m_propertyGridItem5811 = m_cubeActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Render Properties") ) );
	m_propertyGridItem449 = m_cubeActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Material"), wxT("material_id") ) );
	m_propertyGridItem6011 = m_cubeActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Visible"), wxT("visible") ) );
	m_propertyGridItem6111 = m_cubeActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Shadow"), wxT("shadow") ) );
	m_propertyGridItem6211 = m_cubeActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Auto Culling"), wxT("auto_culling") ) );
	m_propertyGridItem284 = m_cubeActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Physics Properties") ) );
	m_propertyGridItem285 = m_cubeActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Shape"), wxT("physics_shape") ) );
	m_propertyGridItem286 = m_cubeActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Solid"), wxT("physics_solid") ) );
	m_propertyGridItem287 = m_cubeActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Mass"), wxT("physics_mass") ) );

	m_sphereActorProperties_propertyGridPage = m_stage_propertyGridManager->AddPage( wxT("Actor Properties"), wxNullBitmap );
	m_animatedActorPropertiesCat_propertyGridItem111 = m_sphereActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Sphere Properties"), wxT("actorPropertiesCat") ) );
	m_aniActorID_propertyGridItem111 = m_sphereActorProperties_propertyGridPage->Append( new wxStringProperty( wxT("ID"), wxT("actor_id") ) );
	m_propertyGridItem1491 = m_sphereActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Radius"), wxT("radius") ) );
	m_propertyGridItem46111 = m_sphereActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Position") ) );
	m_propertyGridItem47111 = m_sphereActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("pos_x") ) );
	m_propertyGridItem48111 = m_sphereActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("pos_y") ) );
	m_propertyGridItem49111 = m_sphereActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("pos_z") ) );
	m_propertyGridItem50111 = m_sphereActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Rotation") ) );
	m_propertyGridItem51111 = m_sphereActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("rot_x") ) );
	m_propertyGridItem52111 = m_sphereActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("rot_y") ) );
	m_propertyGridItem53111 = m_sphereActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("rot_z") ) );
	m_propertyGridItem54111 = m_sphereActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Scale") ) );
	m_propertyGridItem55111 = m_sphereActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("scale_x") ) );
	m_propertyGridItem56111 = m_sphereActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("scale_y") ) );
	m_propertyGridItem57111 = m_sphereActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("scale_z") ) );
	m_propertyGridItem58111 = m_sphereActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Render Properties") ) );
	m_propertyGridItem448 = m_sphereActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Material"), wxT("material_id") ) );
	m_propertyGridItem60111 = m_sphereActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Visible"), wxT("visible") ) );
	m_propertyGridItem61111 = m_sphereActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Shadow"), wxT("shadow") ) );
	m_propertyGridItem62111 = m_sphereActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Auto Culling"), wxT("auto_culling") ) );
	m_propertyGridItem288 = m_sphereActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Physics Properties") ) );
	m_propertyGridItem289 = m_sphereActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Shape"), wxT("physics_shape") ) );
	m_propertyGridItem290 = m_sphereActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Solid"), wxT("physics_solid") ) );
	m_propertyGridItem291 = m_sphereActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Mass"), wxT("physics_mass") ) );

	m_billboardActorProperties_propertyGridPage = m_stage_propertyGridManager->AddPage( wxT("Actor Properties"), wxNullBitmap );
	m_animatedActorPropertiesCat_propertyGridItem1111 = m_billboardActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Billboard Properties"), wxT("actorPropertiesCat") ) );
	m_aniActorID_propertyGridItem1111 = m_billboardActorProperties_propertyGridPage->Append( new wxStringProperty( wxT("ID"), wxT("actor_id") ) );
	m_propertyGridItem461111 = m_billboardActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Position") ) );
	m_propertyGridItem471111 = m_billboardActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("pos_x") ) );
	m_propertyGridItem481111 = m_billboardActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("pos_y") ) );
	m_propertyGridItem491111 = m_billboardActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("pos_z") ) );
	m_propertyGridItem501111 = m_billboardActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Rotation") ) );
	m_propertyGridItem511111 = m_billboardActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("rot_x") ) );
	m_propertyGridItem521111 = m_billboardActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("rot_y") ) );
	m_propertyGridItem531111 = m_billboardActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("rot_z") ) );
	m_propertyGridItem541111 = m_billboardActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Scale") ) );
	m_propertyGridItem551111 = m_billboardActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("scale_x") ) );
	m_propertyGridItem561111 = m_billboardActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("scale_y") ) );
	m_propertyGridItem571111 = m_billboardActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("scale_z") ) );
	m_propertyGridItem581111 = m_billboardActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Render Properties") ) );
	m_propertyGridItem434 = m_billboardActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Material"), wxT("material_id") ) );
	m_propertyGridItem601111 = m_billboardActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Visible"), wxT("visible") ) );
	m_propertyGridItem611111 = m_billboardActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Shadow"), wxT("shadow") ) );
	m_propertyGridItem621111 = m_billboardActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Auto Culling"), wxT("auto_culling") ) );
	m_propertyGridItem292 = m_billboardActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Physics Properties") ) );
	m_propertyGridItem293 = m_billboardActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Shape"), wxT("physics_shape") ) );
	m_propertyGridItem294 = m_billboardActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Solid"), wxT("physics_solid") ) );
	m_propertyGridItem295 = m_billboardActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Mass"), wxT("physics_mass") ) );

	m_terrainActorProperties_propertyGridPage = m_stage_propertyGridManager->AddPage( wxT("Actor Properties"), wxNullBitmap );
	m_animatedActorPropertiesCat_propertyGridItem112 = m_terrainActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Terrain Properties"), wxT("actorPropertiesCat") ) );
	m_aniActorID_propertyGridItem112 = m_terrainActorProperties_propertyGridPage->Append( new wxStringProperty( wxT("ID"), wxT("actor_id") ) );
	m_propertyGridItem1492 = m_terrainActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Height Map"), wxT("hmap_image_id") ) );
	m_propertyGridItem46112 = m_terrainActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Position") ) );
	m_propertyGridItem47112 = m_terrainActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("pos_x") ) );
	m_propertyGridItem48112 = m_terrainActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("pos_y") ) );
	m_propertyGridItem49112 = m_terrainActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("pos_z") ) );
	m_propertyGridItem50112 = m_terrainActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Rotation") ) );
	m_propertyGridItem51112 = m_terrainActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("rot_x") ) );
	m_propertyGridItem52112 = m_terrainActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("rot_y") ) );
	m_propertyGridItem53112 = m_terrainActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("rot_z") ) );
	m_propertyGridItem54112 = m_terrainActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Scale") ) );
	m_propertyGridItem55112 = m_terrainActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("scale_x") ) );
	m_propertyGridItem56112 = m_terrainActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("scale_y") ) );
	m_propertyGridItem57112 = m_terrainActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("scale_z") ) );
	m_propertyGridItem58112 = m_terrainActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Render Properties") ) );
	m_propertyGridItem447 = m_terrainActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Material"), wxT("material_id") ) );
	m_propertyGridItem60112 = m_terrainActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Visible"), wxT("visible") ) );
	m_propertyGridItem61112 = m_terrainActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Shadow"), wxT("shadow") ) );
	m_propertyGridItem62112 = m_terrainActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Auto Culling"), wxT("auto_culling") ) );
	m_propertyGridItem296 = m_terrainActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Physics Properties") ) );
	m_propertyGridItem297 = m_terrainActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Shape"), wxT("physics_shape") ) );
	m_propertyGridItem298 = m_terrainActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Solid"), wxT("physics_solid") ) );
	m_propertyGridItem299 = m_terrainActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Mass"), wxT("physics_mass") ) );

	m_waterActorProperties_propertyGridPage = m_stage_propertyGridManager->AddPage( wxT("Actor Properties"), wxNullBitmap );
	m_animatedActorPropertiesCat_propertyGridItem113 = m_waterActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Water Properties"), wxT("actorPropertiesCat") ) );
	m_aniActorID_propertyGridItem113 = m_waterActorProperties_propertyGridPage->Append( new wxStringProperty( wxT("ID"), wxT("actor_id") ) );
	m_propertyGridItem1493 = m_waterActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Mesh"), wxT("mesh_id") ) );
	m_propertyGridItem428 = m_waterActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Wave Settings") ) );
	m_propertyGridItem429 = m_waterActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Height"), wxT("wave_height") ) );
	m_propertyGridItem430 = m_waterActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Length"), wxT("wave_length") ) );
	m_propertyGridItem431 = m_waterActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Speed"), wxT("wave_speed") ) );
	m_propertyGridItem46113 = m_waterActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Position") ) );
	m_propertyGridItem47113 = m_waterActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("pos_x") ) );
	m_propertyGridItem48113 = m_waterActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("pos_y") ) );
	m_propertyGridItem49113 = m_waterActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("pos_z") ) );
	m_propertyGridItem50113 = m_waterActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Rotation") ) );
	m_propertyGridItem51113 = m_waterActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("rot_x") ) );
	m_propertyGridItem52113 = m_waterActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("rot_y") ) );
	m_propertyGridItem53113 = m_waterActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("rot_z") ) );
	m_propertyGridItem54113 = m_waterActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Scale") ) );
	m_propertyGridItem55113 = m_waterActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("X"), wxT("scale_x") ) );
	m_propertyGridItem56113 = m_waterActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Y"), wxT("scale_y") ) );
	m_propertyGridItem57113 = m_waterActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Z"), wxT("scale_z") ) );
	m_propertyGridItem58113 = m_waterActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Render Properties") ) );
	m_propertyGridItem446 = m_waterActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Material"), wxT("material_id") ) );
	m_propertyGridItem60113 = m_waterActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Visible"), wxT("visible") ) );
	m_propertyGridItem61113 = m_waterActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Shadow"), wxT("shadow") ) );
	m_propertyGridItem62113 = m_waterActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Auto Culling"), wxT("auto_culling") ) );
	m_propertyGridItem300 = m_waterActorProperties_propertyGridPage->Append( new wxPropertyCategory( wxT("Physics Properties") ) );
	m_propertyGridItem301 = m_waterActorProperties_propertyGridPage->Append( new wxEnumProperty( wxT("Shape"), wxT("physics_shape") ) );
	m_propertyGridItem302 = m_waterActorProperties_propertyGridPage->Append( new wxBoolProperty( wxT("Solid"), wxT("physics_solid") ) );
	m_propertyGridItem303 = m_waterActorProperties_propertyGridPage->Append( new wxFloatProperty( wxT("Mass"), wxT("physics_mass") ) );
	bSizer31->Add( m_stage_propertyGridManager, 1, wxALL|wxEXPAND, 5 );


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

	m_panel422 = new wxPanel( m_scrolledWindow2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	m_panel422->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer691;
	bSizer691 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText28 = new wxStaticText( m_panel422, wxID_ANY, wxT("Grid Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	m_staticText28->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer691->Add( m_staticText28, 0, wxALL, 5 );


	bSizer68->Add( bSizer691, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer702;
	bSizer702 = new wxBoxSizer( wxHORIZONTAL );

	m_viewportSettings_showGrid_checkBox = new wxCheckBox( m_panel422, wxID_ANY, wxT("Show Grid"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_viewportSettings_showGrid_checkBox->SetValue(true);
	m_viewportSettings_showGrid_checkBox->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer702->Add( m_viewportSettings_showGrid_checkBox, 0, wxALL, 5 );


	bSizer68->Add( bSizer702, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer712;
	bSizer712 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText30 = new wxStaticText( m_panel422, wxID_ANY, wxT("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	m_staticText30->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer712->Add( m_staticText30, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_viewportSettings_gridSize_spinCtrl = new wxSpinCtrl( m_panel422, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0 );
	m_viewportSettings_gridSize_spinCtrl->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer712->Add( m_viewportSettings_gridSize_spinCtrl, 2, wxALL, 5 );


	bSizer68->Add( bSizer712, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer72;
	bSizer72 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( m_panel422, wxID_ANY, wxT("Spacing"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	m_staticText31->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer72->Add( m_staticText31, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_viewportSettings_gridSpacing_spinCtrl = new wxSpinCtrl( m_panel422, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0 );
	m_viewportSettings_gridSpacing_spinCtrl->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer72->Add( m_viewportSettings_gridSpacing_spinCtrl, 2, wxALL, 5 );


	bSizer68->Add( bSizer72, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText322 = new wxStaticText( m_panel422, wxID_ANY, wxT("Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText322->Wrap( -1 );
	m_staticText322->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer73->Add( m_staticText322, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_viewportSettings_gridColor_colourPicker = new wxColourPickerCtrl( m_panel422, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer73->Add( m_viewportSettings_gridColor_colourPicker, 2, wxALL, 5 );


	bSizer68->Add( bSizer73, 0, wxEXPAND, 5 );


	m_panel422->SetSizer( bSizer68 );
	m_panel422->Layout();
	bSizer68->Fit( m_panel422 );
	bSizer671->Add( m_panel422, 0, wxEXPAND | wxALL, 5 );

	m_panel392 = new wxPanel( m_scrolledWindow2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	m_panel392->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

	wxBoxSizer* bSizer167;
	bSizer167 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer168;
	bSizer168 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText58 = new wxStaticText( m_panel392, wxID_ANY, wxT("Tool Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText58->Wrap( -1 );
	m_staticText58->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer168->Add( m_staticText58, 0, wxALL, 5 );


	bSizer167->Add( bSizer168, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer169;
	bSizer169 = new wxBoxSizer( wxHORIZONTAL );

	m_toolSettings_showAxisLines_checkBox = new wxCheckBox( m_panel392, wxID_ANY, wxT("Show Axis Lines"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_toolSettings_showAxisLines_checkBox->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer169->Add( m_toolSettings_showAxisLines_checkBox, 0, wxALL, 5 );


	bSizer167->Add( bSizer169, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer170;
	bSizer170 = new wxBoxSizer( wxHORIZONTAL );

	m_toolSettings_showAxisRings_checkBox = new wxCheckBox( m_panel392, wxID_ANY, wxT("Show Axis Rings"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_toolSettings_showAxisRings_checkBox->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer170->Add( m_toolSettings_showAxisRings_checkBox, 0, wxALL, 5 );


	bSizer167->Add( bSizer170, 0, wxEXPAND, 5 );


	m_panel392->SetSizer( bSizer167 );
	m_panel392->Layout();
	bSizer167->Fit( m_panel392 );
	bSizer671->Add( m_panel392, 0, wxEXPAND | wxALL, 5 );

	m_panel403 = new wxPanel( m_scrolledWindow2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	m_panel403->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer172;
	bSizer172 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText59 = new wxStaticText( m_panel403, wxID_ANY, wxT("Camera"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText59->Wrap( -1 );
	m_staticText59->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer172->Add( m_staticText59, 0, wxALL, 5 );


	bSizer171->Add( bSizer172, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer173;
	bSizer173 = new wxBoxSizer( wxHORIZONTAL );

	m_cameraSettings_showPosition_checkBox = new wxCheckBox( m_panel403, wxID_ANY, wxT("Show Position"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_cameraSettings_showPosition_checkBox->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer173->Add( m_cameraSettings_showPosition_checkBox, 0, wxALL, 5 );


	bSizer171->Add( bSizer173, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer174;
	bSizer174 = new wxBoxSizer( wxHORIZONTAL );

	m_cameraSettings_showRotation_checkBox = new wxCheckBox( m_panel403, wxID_ANY, wxT("Show Rotation"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_cameraSettings_showRotation_checkBox->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer174->Add( m_cameraSettings_showRotation_checkBox, 0, wxALL, 5 );


	bSizer171->Add( bSizer174, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer175;
	bSizer175 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText60 = new wxStaticText( m_panel403, wxID_ANY, wxT("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText60->Wrap( -1 );
	m_staticText60->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer175->Add( m_staticText60, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_cameraSettings_moveSpeed_spinCtrlDouble = new wxSpinCtrlDouble( m_panel403, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 1 );
	m_cameraSettings_moveSpeed_spinCtrlDouble->SetDigits( 0 );
	m_cameraSettings_moveSpeed_spinCtrlDouble->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer175->Add( m_cameraSettings_moveSpeed_spinCtrlDouble, 2, wxALL, 5 );


	bSizer171->Add( bSizer175, 0, wxEXPAND, 5 );


	m_panel403->SetSizer( bSizer171 );
	m_panel403->Layout();
	bSizer171->Fit( m_panel403 );
	bSizer671->Add( m_panel403, 0, wxEXPAND | wxALL, 5 );

	m_panel412 = new wxPanel( m_scrolledWindow2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	m_panel412->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

	wxBoxSizer* bSizer177;
	bSizer177 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer178;
	bSizer178 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText61 = new wxStaticText( m_panel412, wxID_ANY, wxT("HUD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	m_staticText61->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer178->Add( m_staticText61, 0, wxALL, 5 );


	bSizer177->Add( bSizer178, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer179;
	bSizer179 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText62 = new wxStaticText( m_panel412, wxID_ANY, wxT("Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText62->Wrap( -1 );
	m_staticText62->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer179->Add( m_staticText62, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_viewHUD_color_colourPicker = new wxColourPickerCtrl( m_panel412, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer179->Add( m_viewHUD_color_colourPicker, 2, wxALL, 5 );


	bSizer177->Add( bSizer179, 0, wxEXPAND, 5 );


	m_panel412->SetSizer( bSizer177 );
	m_panel412->Layout();
	bSizer177->Fit( m_panel412 );
	bSizer671->Add( m_panel412, 0, wxEXPAND | wxALL, 5 );

	m_panel54 = new wxPanel( m_scrolledWindow2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	m_panel54->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

	wxBoxSizer* bSizer269;
	bSizer269 = new wxBoxSizer( wxVERTICAL );

	m_staticText113 = new wxStaticText( m_panel54, wxID_ANY, wxT("Orthographic Viewport"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText113->Wrap( -1 );
	m_staticText113->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer269->Add( m_staticText113, 0, wxALL, 5 );

	wxBoxSizer* bSizer270;
	bSizer270 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText114 = new wxStaticText( m_panel54, wxID_ANY, wxT("Near Plane:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText114->Wrap( -1 );
	m_staticText114->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer270->Add( m_staticText114, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_orthoViewNearPlane_spinCtrlDouble = new wxSpinCtrlDouble( m_panel54, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -100000, 100000, 0, 1 );
	m_orthoViewNearPlane_spinCtrlDouble->SetDigits( 1 );
	m_orthoViewNearPlane_spinCtrlDouble->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer270->Add( m_orthoViewNearPlane_spinCtrlDouble, 2, wxALL, 5 );


	bSizer269->Add( bSizer270, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer2701;
	bSizer2701 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1141 = new wxStaticText( m_panel54, wxID_ANY, wxT("Far Plane:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1141->Wrap( -1 );
	m_staticText1141->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer2701->Add( m_staticText1141, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_orthoViewFarPlane_spinCtrlDouble = new wxSpinCtrlDouble( m_panel54, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -100000, 100000, 0, 1 );
	m_orthoViewFarPlane_spinCtrlDouble->SetDigits( 1 );
	m_orthoViewFarPlane_spinCtrlDouble->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer2701->Add( m_orthoViewFarPlane_spinCtrlDouble, 2, wxALL, 5 );


	bSizer269->Add( bSizer2701, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer2702;
	bSizer2702 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1142 = new wxStaticText( m_panel54, wxID_ANY, wxT("Width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1142->Wrap( -1 );
	m_staticText1142->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer2702->Add( m_staticText1142, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_orthoViewWidth_spinCtrlDouble = new wxSpinCtrlDouble( m_panel54, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100000, 0, 1 );
	m_orthoViewWidth_spinCtrlDouble->SetDigits( 1 );
	m_orthoViewWidth_spinCtrlDouble->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer2702->Add( m_orthoViewWidth_spinCtrlDouble, 2, wxALL, 5 );


	bSizer269->Add( bSizer2702, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer2703;
	bSizer2703 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1143 = new wxStaticText( m_panel54, wxID_ANY, wxT("Height:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1143->Wrap( -1 );
	m_staticText1143->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer2703->Add( m_staticText1143, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_orthoViewHeight_spinCtrlDouble = new wxSpinCtrlDouble( m_panel54, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100000, 0, 1 );
	m_orthoViewHeight_spinCtrlDouble->SetDigits( 1 );
	m_orthoViewHeight_spinCtrlDouble->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer2703->Add( m_orthoViewHeight_spinCtrlDouble, 2, wxALL, 5 );


	bSizer269->Add( bSizer2703, 0, wxEXPAND, 5 );


	m_panel54->SetSizer( bSizer269 );
	m_panel54->Layout();
	bSizer269->Fit( m_panel54 );
	bSizer671->Add( m_panel54, 1, wxEXPAND | wxALL, 5 );

	m_panel541 = new wxPanel( m_scrolledWindow2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	m_panel541->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

	wxBoxSizer* bSizer2691;
	bSizer2691 = new wxBoxSizer( wxVERTICAL );

	m_staticText1131 = new wxStaticText( m_panel541, wxID_ANY, wxT("Perspective Viewport"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1131->Wrap( -1 );
	m_staticText1131->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer2691->Add( m_staticText1131, 0, wxALL, 5 );

	wxBoxSizer* bSizer2704;
	bSizer2704 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1144 = new wxStaticText( m_panel541, wxID_ANY, wxT("Near Plane:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1144->Wrap( -1 );
	m_staticText1144->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer2704->Add( m_staticText1144, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_perspectiveViewNearPlane_spinCtrlDouble = new wxSpinCtrlDouble( m_panel541, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -100000, 100000, 0, 1 );
	m_perspectiveViewNearPlane_spinCtrlDouble->SetDigits( 1 );
	m_perspectiveViewNearPlane_spinCtrlDouble->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer2704->Add( m_perspectiveViewNearPlane_spinCtrlDouble, 2, wxALL, 5 );


	bSizer2691->Add( bSizer2704, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer27011;
	bSizer27011 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText11411 = new wxStaticText( m_panel541, wxID_ANY, wxT("Far Plane:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11411->Wrap( -1 );
	m_staticText11411->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer27011->Add( m_staticText11411, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_perspectiveViewFarPlane_spinCtrlDouble = new wxSpinCtrlDouble( m_panel541, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -100000, 100000, 0, 1 );
	m_perspectiveViewFarPlane_spinCtrlDouble->SetDigits( 1 );
	m_perspectiveViewFarPlane_spinCtrlDouble->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer27011->Add( m_perspectiveViewFarPlane_spinCtrlDouble, 2, wxALL, 5 );


	bSizer2691->Add( bSizer27011, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer27021;
	bSizer27021 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText11421 = new wxStaticText( m_panel541, wxID_ANY, wxT("FOV:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11421->Wrap( -1 );
	m_staticText11421->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer27021->Add( m_staticText11421, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_perspectiveViewFOV_spinCtrlDouble = new wxSpinCtrlDouble( m_panel541, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 0, 1 );
	m_perspectiveViewFOV_spinCtrlDouble->SetDigits( 1 );
	m_perspectiveViewFOV_spinCtrlDouble->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer27021->Add( m_perspectiveViewFOV_spinCtrlDouble, 2, wxALL, 5 );


	bSizer2691->Add( bSizer27021, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer27031;
	bSizer27031 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText11431 = new wxStaticText( m_panel541, wxID_ANY, wxT("Aspect Ratio:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11431->Wrap( -1 );
	m_staticText11431->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer27031->Add( m_staticText11431, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_perspectiveViewAspect_spinCtrlDouble = new wxSpinCtrlDouble( m_panel541, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100000, 0, 1 );
	m_perspectiveViewAspect_spinCtrlDouble->SetDigits( 1 );
	m_perspectiveViewAspect_spinCtrlDouble->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer27031->Add( m_perspectiveViewAspect_spinCtrlDouble, 2, wxALL, 5 );


	bSizer2691->Add( bSizer27031, 0, wxEXPAND, 5 );


	m_panel541->SetSizer( bSizer2691 );
	m_panel541->Layout();
	bSizer2691->Fit( m_panel541 );
	bSizer671->Add( m_panel541, 1, wxEXPAND | wxALL, 5 );


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
	m_editorMain_auinotebook->AddPage( m_stage_panel, wxT("Stage"), true, wxNullBitmap );
	m_meshDB_panel = new wxPanel( m_editorMain_auinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
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
	bSizer251 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer235;
	bSizer235 = new wxBoxSizer( wxHORIZONTAL );

	m_mesh_createMesh_button = new wxButton( m_panel28, wxID_ANY, wxT("New"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer235->Add( m_mesh_createMesh_button, 1, wxALL, 5 );

	m_mesh_importMesh_button = new wxButton( m_panel28, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer235->Add( m_mesh_importMesh_button, 1, wxALL, 5 );


	bSizer251->Add( bSizer235, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer234;
	bSizer234 = new wxBoxSizer( wxHORIZONTAL );

	m_mesh_saveMesh_button = new wxButton( m_panel28, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer234->Add( m_mesh_saveMesh_button, 1, wxALL, 5 );

	m_mesh_removeMesh_button = new wxButton( m_panel28, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer234->Add( m_mesh_removeMesh_button, 1, wxALL, 5 );


	bSizer251->Add( bSizer234, 1, wxEXPAND, 5 );


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

	m_panel33 = new wxPanel( m_panel41, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	m_panel33->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

	wxBoxSizer* bSizer881;
	bSizer881 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer701;
	bSizer701 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText321 = new wxStaticText( m_panel33, wxID_ANY, wxT("ID\t\t\t"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText321->Wrap( -1 );
	m_staticText321->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer701->Add( m_staticText321, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_mesh_meshID_textCtrl = new wxTextCtrl( m_panel33, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer701->Add( m_mesh_meshID_textCtrl, 1, wxALL, 5 );


	bSizer881->Add( bSizer701, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer70;
	bSizer70 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32 = new wxStaticText( m_panel33, wxID_ANY, wxT("File\t\t"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	m_staticText32->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer70->Add( m_staticText32, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_mesh_meshFile_textCtrl = new wxTextCtrl( m_panel33, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer70->Add( m_mesh_meshFile_textCtrl, 1, wxALL, 5 );


	bSizer881->Add( bSizer70, 0, wxEXPAND, 5 );


	m_panel33->SetSizer( bSizer881 );
	m_panel33->Layout();
	bSizer881->Fit( m_panel33 );
	bSizer69->Add( m_panel33, 0, wxEXPAND | wxALL, 5 );

	m_panel34 = new wxPanel( m_panel41, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	m_panel34->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer89;
	bSizer89 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText323 = new wxStaticText( m_panel34, wxID_ANY, wxT("Materials"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323->Wrap( -1 );
	m_staticText323->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

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

	wxBoxSizer* bSizer144;
	bSizer144 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer143;
	bSizer143 = new wxBoxSizer( wxVERTICAL );

	m_button51 = new wxButton( m_setMaterial_scrolledWindow, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143->Add( m_button51, 0, wxALL, 5 );

	m_button52 = new wxButton( m_setMaterial_scrolledWindow, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143->Add( m_button52, 0, wxALL, 5 );

	m_button53 = new wxButton( m_setMaterial_scrolledWindow, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143->Add( m_button53, 0, wxALL, 5 );

	m_clear_button = new wxButton( m_setMaterial_scrolledWindow, wxID_ANY, wxT("UnSet"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143->Add( m_clear_button, 0, wxALL, 5 );


	bSizer144->Add( bSizer143, 0, wxEXPAND, 5 );

	m_mesh_materialList_listBox = new wxListBox( m_setMaterial_scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer144->Add( m_mesh_materialList_listBox, 1, wxALL|wxEXPAND, 5 );


	bSizer158->Add( bSizer144, 1, wxEXPAND, 5 );


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

	m_panel43 = new wxPanel( m_panel291, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	m_panel43->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );

	m_panel46 = new wxPanel( m_panel43, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	m_staticText33 = new wxStaticText( m_panel46, wxID_ANY, wxT("Animations"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	m_staticText33->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

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
	m_staticText27->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer731->Add( m_staticText27, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_mesh_animationID_textCtrl = new wxTextCtrl( m_panel451, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer731->Add( m_mesh_animationID_textCtrl, 2, wxALL, 5 );


	bSizer731->Add( 0, 0, 3, wxEXPAND, 5 );


	bSizer721->Add( bSizer731, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7311;
	bSizer7311 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText271 = new wxStaticText( m_panel451, wxID_ANY, wxT("Start Frame"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText271->Wrap( -1 );
	m_staticText271->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer7311->Add( m_staticText271, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_mesh_animationStartFrame_textCtrl = new wxTextCtrl( m_panel451, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7311->Add( m_mesh_animationStartFrame_textCtrl, 2, wxALL, 5 );


	bSizer7311->Add( 0, 0, 3, wxEXPAND, 5 );


	bSizer721->Add( bSizer7311, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer73111;
	bSizer73111 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2711 = new wxStaticText( m_panel451, wxID_ANY, wxT("End Frame"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2711->Wrap( -1 );
	m_staticText2711->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer73111->Add( m_staticText2711, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_mesh_animationEndFrame_textCtrl = new wxTextCtrl( m_panel451, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer73111->Add( m_mesh_animationEndFrame_textCtrl, 2, wxALL, 5 );


	bSizer73111->Add( 0, 0, 3, wxEXPAND, 5 );


	bSizer721->Add( bSizer73111, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer73112;
	bSizer73112 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2712 = new wxStaticText( m_panel451, wxID_ANY, wxT("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2712->Wrap( -1 );
	m_staticText2712->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

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
	m_editorMain_auinotebook->AddPage( m_meshDB_panel, wxT("Mesh"), false, wxNullBitmap );
	m_materialDB_panel = new wxPanel( m_editorMain_auinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer93;
	bSizer93 = new wxBoxSizer( wxHORIZONTAL );

	m_splitter4 = new wxSplitterWindow( m_materialDB_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter4->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter4OnIdle ), NULL, this );
	m_splitter4->SetMinimumPaneSize( 1 );

	m_panel37 = new wxPanel( m_splitter4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer94;
	bSizer94 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer95;
	bSizer95 = new wxBoxSizer( wxHORIZONTAL );

	m_material_newMaterial_button = new wxButton( m_panel37, wxID_ANY, wxT("New"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer95->Add( m_material_newMaterial_button, 1, wxALL, 5 );

	m_material_loadMaterial_button = new wxButton( m_panel37, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer95->Add( m_material_loadMaterial_button, 1, wxALL, 5 );


	bSizer94->Add( bSizer95, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer96;
	bSizer96 = new wxBoxSizer( wxHORIZONTAL );

	m_material_saveMaterial_button = new wxButton( m_panel37, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer96->Add( m_material_saveMaterial_button, 1, wxALL, 5 );

	m_material_removeMaterial_button = new wxButton( m_panel37, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer96->Add( m_material_removeMaterial_button, 1, wxALL, 5 );


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

	wxBoxSizer* bSizer1111;
	bSizer1111 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText421 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("File"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText421->Wrap( -1 );
	bSizer1111->Add( m_staticText421, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_material_materialFile_textCtrl = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer1111->Add( m_material_materialFile_textCtrl, 4, wxALL, 5 );


	bSizer100->Add( bSizer1111, 0, wxEXPAND, 5 );

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
	m_material_previewNoLight_tool = m_auiToolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/no_light.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_material_previewDirectionLight_tool = m_auiToolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/spot_light.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_material_previewPointLight_tool = m_auiToolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/point_light.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar2->AddSeparator();

	m_materialPreviewMesh_tool = m_auiToolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/3d-model.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_materialPreviewSettings_tool = m_auiToolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/setting.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_auiToolBar2->Realize();

	bSizer138->Add( m_auiToolBar2, 0, wxALL|wxEXPAND, 5 );


	m_panel411->SetSizer( bSizer138 );
	m_panel411->Layout();
	bSizer138->Fit( m_panel411 );
	bSizer131->Add( m_panel411, 1, wxEXPAND | wxALL, 5 );

	m_panel42 = new wxPanel( m_panel401, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	m_panel42->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

	wxBoxSizer* bSizer132;
	bSizer132 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer133;
	bSizer133 = new wxBoxSizer( wxVERTICAL );

	m_staticText57 = new wxStaticText( m_panel42, wxID_ANY, wxT("Texture Level"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText57->Wrap( -1 );
	m_staticText57->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer133->Add( m_staticText57, 0, wxALL, 5 );

	wxBoxSizer* bSizer159;
	bSizer159 = new wxBoxSizer( wxHORIZONTAL );

	m_material_addTextureLevel_button = new wxButton( m_panel42, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer159->Add( m_material_addTextureLevel_button, 0, wxALL, 5 );

	m_material_removeTextureLevel_button = new wxButton( m_panel42, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer159->Add( m_material_removeTextureLevel_button, 0, wxALL, 5 );

	m_material_setTextureLevel_button = new wxButton( m_panel42, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer159->Add( m_material_setTextureLevel_button, 0, wxALL, 5 );

	m_material_clearTextureLevel_button = new wxButton( m_panel42, wxID_ANY, wxT("UnSet"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer159->Add( m_material_clearTextureLevel_button, 0, wxALL, 5 );


	bSizer133->Add( bSizer159, 0, wxEXPAND, 5 );

	m_material_textureLevel_listBox = new wxListBox( m_panel42, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer133->Add( m_material_textureLevel_listBox, 1, wxALL|wxEXPAND, 5 );


	bSizer132->Add( bSizer133, 1, wxEXPAND, 5 );


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


	m_materialDB_panel->SetSizer( bSizer92 );
	m_materialDB_panel->Layout();
	bSizer92->Fit( m_materialDB_panel );
	m_editorMain_auinotebook->AddPage( m_materialDB_panel, wxT("Material"), false, wxNullBitmap );
	m_textureDB_panel = new wxPanel( m_editorMain_auinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer106;
	bSizer106 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer107;
	bSizer107 = new wxBoxSizer( wxHORIZONTAL );

	m_splitter5 = new wxSplitterWindow( m_textureDB_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter5->Connect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter5OnIdle ), NULL, this );

	m_panel39 = new wxPanel( m_splitter5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer108;
	bSizer108 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer1142;
	bSizer1142 = new wxBoxSizer( wxHORIZONTAL );

	m_texture_addTexture_button = new wxButton( m_panel39, wxID_ANY, wxT("Add Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1142->Add( m_texture_addTexture_button, 0, wxALL, 5 );

	m_texture_removeTexture_button = new wxButton( m_panel39, wxID_ANY, wxT("Remove Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1142->Add( m_texture_removeTexture_button, 0, wxALL, 5 );


	bSizer108->Add( bSizer1142, 0, wxEXPAND, 5 );

	m_texture_textureList_listBox = new wxListBox( m_panel39, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer108->Add( m_texture_textureList_listBox, 1, wxALL|wxEXPAND, 5 );


	m_panel39->SetSizer( bSizer108 );
	m_panel39->Layout();
	bSizer108->Fit( m_panel39 );
	m_panel402 = new wxPanel( m_splitter5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer109;
	bSizer109 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer110;
	bSizer110 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer112;
	bSizer112 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText40 = new wxStaticText( m_panel402, wxID_ANY, wxT("Texture ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	bSizer112->Add( m_staticText40, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_texture_textureID_textCtrl = new wxTextCtrl( m_panel402, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer112->Add( m_texture_textureID_textCtrl, 4, wxALL, 5 );


	bSizer110->Add( bSizer112, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer115;
	bSizer115 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText42 = new wxStaticText( m_panel402, wxID_ANY, wxT("File"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	bSizer115->Add( m_staticText42, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_texture_textureFile_textCtrl = new wxTextCtrl( m_panel402, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer115->Add( m_texture_textureFile_textCtrl, 4, wxALL, 5 );


	bSizer110->Add( bSizer115, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1121;
	bSizer1121 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText432 = new wxStaticText( m_panel402, wxID_ANY, wxT("Use Colorkey"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText432->Wrap( -1 );
	bSizer1121->Add( m_staticText432, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_texture_useColorKey_checkBox = new wxCheckBox( m_panel402, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1121->Add( m_texture_useColorKey_checkBox, 4, wxALL, 5 );


	bSizer110->Add( bSizer1121, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer113;
	bSizer113 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText41 = new wxStaticText( m_panel402, wxID_ANY, wxT("Colorkey"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	bSizer113->Add( m_staticText41, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_texture_colorKey_colourPicker = new wxColourPickerCtrl( m_panel402, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer113->Add( m_texture_colorKey_colourPicker, 4, wxALL, 5 );


	bSizer110->Add( bSizer113, 0, wxEXPAND, 5 );


	bSizer109->Add( bSizer110, 1, wxEXPAND, 5 );


	bSizer109->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxVERTICAL );

	m_texture_texturePreview_panel = new wxPanel( m_panel402, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	bSizer111->Add( m_texture_texturePreview_panel, 1, wxEXPAND | wxALL, 5 );


	bSizer111->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer109->Add( bSizer111, 3, wxEXPAND, 5 );


	m_panel402->SetSizer( bSizer109 );
	m_panel402->Layout();
	bSizer109->Fit( m_panel402 );
	m_splitter5->SplitVertically( m_panel39, m_panel402, 291 );
	bSizer107->Add( m_splitter5, 1, wxEXPAND, 5 );


	bSizer106->Add( bSizer107, 1, wxEXPAND, 5 );


	m_textureDB_panel->SetSizer( bSizer106 );
	m_textureDB_panel->Layout();
	bSizer106->Fit( m_textureDB_panel );
	m_editorMain_auinotebook->AddPage( m_textureDB_panel, wxT("Textures"), false, wxNullBitmap );

	bSizer1->Add( m_editorMain_auinotebook, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	m_toolBar3 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	m_tool33 = m_toolBar3->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/new-project.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool34 = m_toolBar3->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/folder.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool35 = m_toolBar3->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/save.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar3->AddSeparator();

	m_tool36 = m_toolBar3->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/build.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar3->Realize();


	this->Centre( wxBOTH );

	// Connect Events
	m_editorMain_auinotebook->Connect( wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGED, wxAuiNotebookEventHandler( Serenity3D_Frame::OnMainEditorNotebookPageChanged ), NULL, this );
	this->Connect( m_s3d_select_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DSelectClicked ) );
	this->Connect( m_s3d_boxSelect_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DBoxClicked ) );
	this->Connect( m_s3d_move_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DMoveClicked ) );
	this->Connect( m_s3d_rotate_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DRotateClicked ) );
	this->Connect( m_s3d_scale_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DScaleClicked ) );
	this->Connect( m_s3d_animatedActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DWizClicked ) );
	this->Connect( m_s3d_octreeActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DDumpClicked ) );
	this->Connect( m_s3d_billboardActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DBillboardClicked ) );
	this->Connect( m_s3d_lightActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DLightClicked ) );
	this->Connect( m_s3d_terrainActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DTerrainClicked ) );
	this->Connect( m_s3d_waterActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DWaterClicked ) );
	this->Connect( m_s3d_particleActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DEffectClicked ) );
	this->Connect( m_s3d_cube_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DCubeClicked ) );
	this->Connect( m_s3d_sphere_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DSphereClicked ) );
	m_stagePOV_comboBox->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::OnViewComboSelect ), NULL, this );
	m_stagePOV_comboBox->Connect( wxEVT_COMBOBOX_CLOSEUP, wxCommandEventHandler( Serenity3D_Frame::OnStageViewComboClose ), NULL, this );
	m_stagePOV_comboBox->Connect( wxEVT_COMBOBOX_DROPDOWN, wxCommandEventHandler( Serenity3D_Frame::OnStageViewComboOpen ), NULL, this );
	this->Connect( m_tool30->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnStageCameraNavigate ) );
	this->Connect( m_render_wire_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_RenderMode_WireFrame ) );
	this->Connect( m_render_solid_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_RenderMode_Solid ) );
	m_stageViewport_panel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( Serenity3D_Frame::OnStageUpdate ), NULL, this );
	m_auinotebook3->Connect( wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGED, wxAuiNotebookEventHandler( Serenity3D_Frame::OnProjectPropertiesNotebookChanged ), NULL, this );
	m_bpButton41->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_NewStage ), NULL, this );
	m_bpButton51->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_DeleteStage ), NULL, this );
	m_bpButton4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_NewGroup ), NULL, this );
	m_bpButton5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_DeleteGroup ), NULL, this );
	m_bpButton6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_EditGroup ), NULL, this );
	m_bpButton61->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_DeleteActor ), NULL, this );
	m_project_stage_treeCtrl->Connect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( Serenity3D_Frame::On_Stage_StageNodeActivated ), NULL, this );
	m_project_stage_treeCtrl->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( Serenity3D_Frame::On_Stage_StageNodeSelected ), NULL, this );
	m_stage_propertyGridManager->Connect( wxEVT_PG_CHANGED, wxPropertyGridEventHandler( Serenity3D_Frame::OnStagePropertyGridChanged ), NULL, this );
	m_viewportSettings_showGrid_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_StageSettings_ShowGrid ), NULL, this );
	m_viewportSettings_gridSize_spinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( Serenity3D_Frame::On_StageSettings_SetGridSize ), NULL, this );
	m_viewportSettings_gridSpacing_spinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( Serenity3D_Frame::On_StageSettings_SetGridSpacing ), NULL, this );
	m_viewportSettings_gridColor_colourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_StageSettings_SetGridColor ), NULL, this );
	m_toolSettings_showAxisLines_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_StageSettings_ShowAxisLines ), NULL, this );
	m_toolSettings_showAxisRings_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_StageSettings_ShowAxisRings ), NULL, this );
	m_cameraSettings_showPosition_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_StageSettings_ShowViewCameraPosition ), NULL, this );
	m_cameraSettings_showRotation_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_StageSettings_ShowViewCameraRotation ), NULL, this );
	m_cameraSettings_moveSpeed_spinCtrlDouble->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::On_StageSettings_ViewCameraSpeed ), NULL, this );
	m_viewHUD_color_colourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_StageSettings_ViewHUDColor ), NULL, this );
	m_orthoViewNearPlane_spinCtrlDouble->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnOrthoNearPlaneChange ), NULL, this );
	m_orthoViewFarPlane_spinCtrlDouble->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnOrthoFarPlaneChange ), NULL, this );
	m_orthoViewWidth_spinCtrlDouble->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnOrthoWidthChange ), NULL, this );
	m_orthoViewHeight_spinCtrlDouble->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnOrthoHeightChange ), NULL, this );
	m_perspectiveViewNearPlane_spinCtrlDouble->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnPerspectiveNearPlaneChange ), NULL, this );
	m_perspectiveViewFarPlane_spinCtrlDouble->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnPerspectiveFarPlaneChange ), NULL, this );
	m_perspectiveViewFOV_spinCtrlDouble->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnPerspectiveFOVChange ), NULL, this );
	m_perspectiveViewAspect_spinCtrlDouble->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnPerspectiveAspectChange ), NULL, this );
	m_mesh_createMesh_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Create_ButtonClick ), NULL, this );
	m_mesh_importMesh_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Load_ButtonClick ), NULL, this );
	m_mesh_saveMesh_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Save_ButtonClick ), NULL, this );
	m_mesh_removeMesh_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Remove_ButtonClick ), NULL, this );
	m_mesh_mesh_listBox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_MeshList_Select ), NULL, this );
	m_mesh_meshID_textCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_MeshID ), NULL, this );
	m_button51->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_AddMaterial ), NULL, this );
	m_button52->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_RemoveMaterial ), NULL, this );
	m_button53->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_SetMaterial ), NULL, this );
	m_clear_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Material_Clear ), NULL, this );
	m_mesh_animationPreview_panel->Connect( wxEVT_SIZE, wxSizeEventHandler( Serenity3D_Frame::OnAnimationPreviewSize ), NULL, this );
	this->Connect( m_mesh_meshAnimation_play_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_previewPlay ) );
	this->Connect( m_mesh_meshAnimation_stop_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_previewStop ) );
	m_mesh_newAnimation_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_NewAnimation ), NULL, this );
	m_mesh_deleteAnimation_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_DeleteAnimation ), NULL, this );
	m_mesh_meshAnimation_listBox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_AnimationList_Select ), NULL, this );
	m_mesh_animationID_textCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Animation_AnimationID ), NULL, this );
	m_mesh_animationStartFrame_textCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Animation_StartFrame ), NULL, this );
	m_mesh_animationEndFrame_textCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Animation_EndFrame ), NULL, this );
	m_mesh_animationSpeed_textCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Animation_Speed ), NULL, this );
	m_material_newMaterial_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_NewMaterial_ButtonClicked ), NULL, this );
	m_material_loadMaterial_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_LoadMaterial_ButtonClicked ), NULL, this );
	m_material_saveMaterial_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_SaveMaterial_ButtonClicked ), NULL, this );
	m_material_removeMaterial_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_RemoveMaterial_ButtonClicked ), NULL, this );
	m_material_material_listBox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Material_MaterialList_Select ), NULL, this );
	m_material_id_textCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Material_MaterialID_Update ), NULL, this );
	m_material_type_comboBox->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Material_MaterialType_Update ), NULL, this );
	m_material_ambient_colourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_Material_Ambient_Update ), NULL, this );
	m_material_diffuse_colourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_Material_Diffuse_Update ), NULL, this );
	m_material_emissive_colourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_Material_Emissive_Update ), NULL, this );
	m_material_specular_colourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_Material_Specular_Update ), NULL, this );
	m_material_antiAlias_comboBox->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Material_AntiAlias_Update ), NULL, this );
	m_material_backFaceCulling_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_BackfaceCulling_Update ), NULL, this );
	m_material_frontFaceCulling_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_FrontfaceCulling_Update ), NULL, this );
	m_material_blendFactor_spinCtrlDouble->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::On_Material_BlendFactor_Update ), NULL, this );
	m_material_blendMode_comboBox->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Material_BlendMode_Update ), NULL, this );
	m_material_colorMask_comboBox->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Material_ColorMask_Update ), NULL, this );
	m_material_colorMode_comboBox->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Material_ColorMode_Update ), NULL, this );
	m_material_fog_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_Fog_Update ), NULL, this );
	m_material_gouradShading_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_GouradShading_Update ), NULL, this );
	m_material_lighting_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_Lighting_Update ), NULL, this );
	m_material_normalize_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_Normalize_Update ), NULL, this );
	m_material_pointCloud_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_PointCloud_Update ), NULL, this );
	m_material_shineness_spinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( Serenity3D_Frame::On_Material_Shineness_Update ), NULL, this );
	this->Connect( m_material_previewNoLight_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_previewNoLight_Selected ) );
	this->Connect( m_material_previewDirectionLight_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_previewDirectionlight_Selected ) );
	this->Connect( m_material_previewPointLight_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_previewPointlight_Selected ) );
	this->Connect( m_materialPreviewMesh_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnSetMaterialPreviewMesh ) );
	this->Connect( m_materialPreviewSettings_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_previewSettings_Selected ) );
	m_material_addTextureLevel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_AddTextureLevel_ButtonClicked ), NULL, this );
	m_material_removeTextureLevel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_RemoveTextureLevel_ButtonClicked ), NULL, this );
	m_material_setTextureLevel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_SetTextureLevel_ButtonClicked ), NULL, this );
	m_material_clearTextureLevel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_ClearTextureLevel_ButtonClicked ), NULL, this );
	m_texture_addTexture_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Texture_AddTexture_ButtonClicked ), NULL, this );
	m_texture_removeTexture_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Texture_RemoveTexture_ButtonClicked ), NULL, this );
	m_texture_textureList_listBox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Texture_TextureList_Select ), NULL, this );
	m_texture_textureID_textCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Texture_TextureID_Update ), NULL, this );
	m_texture_useColorKey_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Texture_UseColorkey_Update ), NULL, this );
	m_texture_colorKey_colourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_Texture_Colorkey_Update ), NULL, this );
	this->Connect( m_tool33->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnNewProjectMenuSelection ) );
	this->Connect( m_tool34->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnLoadProjectMenuSelection ) );
	this->Connect( m_tool35->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnSaveProjectMenuSelection ) );
	this->Connect( m_tool36->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnCodeGen ) );
}

Serenity3D_Frame::~Serenity3D_Frame()
{
	// Disconnect Events
	m_editorMain_auinotebook->Disconnect( wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGED, wxAuiNotebookEventHandler( Serenity3D_Frame::OnMainEditorNotebookPageChanged ), NULL, this );
	this->Disconnect( m_s3d_select_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DSelectClicked ) );
	this->Disconnect( m_s3d_boxSelect_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DBoxClicked ) );
	this->Disconnect( m_s3d_move_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DMoveClicked ) );
	this->Disconnect( m_s3d_rotate_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DRotateClicked ) );
	this->Disconnect( m_s3d_scale_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DScaleClicked ) );
	this->Disconnect( m_s3d_animatedActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DWizClicked ) );
	this->Disconnect( m_s3d_octreeActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DDumpClicked ) );
	this->Disconnect( m_s3d_billboardActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DBillboardClicked ) );
	this->Disconnect( m_s3d_lightActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DLightClicked ) );
	this->Disconnect( m_s3d_terrainActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DTerrainClicked ) );
	this->Disconnect( m_s3d_waterActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DWaterClicked ) );
	this->Disconnect( m_s3d_particleActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DEffectClicked ) );
	this->Disconnect( m_s3d_cube_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DCubeClicked ) );
	this->Disconnect( m_s3d_sphere_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnS3DSphereClicked ) );
	m_stagePOV_comboBox->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::OnViewComboSelect ), NULL, this );
	m_stagePOV_comboBox->Disconnect( wxEVT_COMBOBOX_CLOSEUP, wxCommandEventHandler( Serenity3D_Frame::OnStageViewComboClose ), NULL, this );
	m_stagePOV_comboBox->Disconnect( wxEVT_COMBOBOX_DROPDOWN, wxCommandEventHandler( Serenity3D_Frame::OnStageViewComboOpen ), NULL, this );
	this->Disconnect( m_tool30->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnStageCameraNavigate ) );
	this->Disconnect( m_render_wire_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_RenderMode_WireFrame ) );
	this->Disconnect( m_render_solid_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_RenderMode_Solid ) );
	m_stageViewport_panel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( Serenity3D_Frame::OnStageUpdate ), NULL, this );
	m_auinotebook3->Disconnect( wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGED, wxAuiNotebookEventHandler( Serenity3D_Frame::OnProjectPropertiesNotebookChanged ), NULL, this );
	m_bpButton41->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_NewStage ), NULL, this );
	m_bpButton51->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_DeleteStage ), NULL, this );
	m_bpButton4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_NewGroup ), NULL, this );
	m_bpButton5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_DeleteGroup ), NULL, this );
	m_bpButton6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_EditGroup ), NULL, this );
	m_bpButton61->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Stage_DeleteActor ), NULL, this );
	m_project_stage_treeCtrl->Disconnect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( Serenity3D_Frame::On_Stage_StageNodeActivated ), NULL, this );
	m_project_stage_treeCtrl->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( Serenity3D_Frame::On_Stage_StageNodeSelected ), NULL, this );
	m_stage_propertyGridManager->Disconnect( wxEVT_PG_CHANGED, wxPropertyGridEventHandler( Serenity3D_Frame::OnStagePropertyGridChanged ), NULL, this );
	m_viewportSettings_showGrid_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_StageSettings_ShowGrid ), NULL, this );
	m_viewportSettings_gridSize_spinCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( Serenity3D_Frame::On_StageSettings_SetGridSize ), NULL, this );
	m_viewportSettings_gridSpacing_spinCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( Serenity3D_Frame::On_StageSettings_SetGridSpacing ), NULL, this );
	m_viewportSettings_gridColor_colourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_StageSettings_SetGridColor ), NULL, this );
	m_toolSettings_showAxisLines_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_StageSettings_ShowAxisLines ), NULL, this );
	m_toolSettings_showAxisRings_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_StageSettings_ShowAxisRings ), NULL, this );
	m_cameraSettings_showPosition_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_StageSettings_ShowViewCameraPosition ), NULL, this );
	m_cameraSettings_showRotation_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_StageSettings_ShowViewCameraRotation ), NULL, this );
	m_cameraSettings_moveSpeed_spinCtrlDouble->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::On_StageSettings_ViewCameraSpeed ), NULL, this );
	m_viewHUD_color_colourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_StageSettings_ViewHUDColor ), NULL, this );
	m_orthoViewNearPlane_spinCtrlDouble->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnOrthoNearPlaneChange ), NULL, this );
	m_orthoViewFarPlane_spinCtrlDouble->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnOrthoFarPlaneChange ), NULL, this );
	m_orthoViewWidth_spinCtrlDouble->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnOrthoWidthChange ), NULL, this );
	m_orthoViewHeight_spinCtrlDouble->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnOrthoHeightChange ), NULL, this );
	m_perspectiveViewNearPlane_spinCtrlDouble->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnPerspectiveNearPlaneChange ), NULL, this );
	m_perspectiveViewFarPlane_spinCtrlDouble->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnPerspectiveFarPlaneChange ), NULL, this );
	m_perspectiveViewFOV_spinCtrlDouble->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnPerspectiveFOVChange ), NULL, this );
	m_perspectiveViewAspect_spinCtrlDouble->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::OnPerspectiveAspectChange ), NULL, this );
	m_mesh_createMesh_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Create_ButtonClick ), NULL, this );
	m_mesh_importMesh_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Load_ButtonClick ), NULL, this );
	m_mesh_saveMesh_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Save_ButtonClick ), NULL, this );
	m_mesh_removeMesh_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Remove_ButtonClick ), NULL, this );
	m_mesh_mesh_listBox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_MeshList_Select ), NULL, this );
	m_mesh_meshID_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_MeshID ), NULL, this );
	m_button51->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_AddMaterial ), NULL, this );
	m_button52->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_RemoveMaterial ), NULL, this );
	m_button53->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_SetMaterial ), NULL, this );
	m_clear_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Material_Clear ), NULL, this );
	m_mesh_animationPreview_panel->Disconnect( wxEVT_SIZE, wxSizeEventHandler( Serenity3D_Frame::OnAnimationPreviewSize ), NULL, this );
	this->Disconnect( m_mesh_meshAnimation_play_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_previewPlay ) );
	this->Disconnect( m_mesh_meshAnimation_stop_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_previewStop ) );
	m_mesh_newAnimation_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_NewAnimation ), NULL, this );
	m_mesh_deleteAnimation_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_DeleteAnimation ), NULL, this );
	m_mesh_meshAnimation_listBox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_AnimationList_Select ), NULL, this );
	m_mesh_animationID_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Animation_AnimationID ), NULL, this );
	m_mesh_animationStartFrame_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Animation_StartFrame ), NULL, this );
	m_mesh_animationEndFrame_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Animation_EndFrame ), NULL, this );
	m_mesh_animationSpeed_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Mesh_Animation_Speed ), NULL, this );
	m_material_newMaterial_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_NewMaterial_ButtonClicked ), NULL, this );
	m_material_loadMaterial_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_LoadMaterial_ButtonClicked ), NULL, this );
	m_material_saveMaterial_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_SaveMaterial_ButtonClicked ), NULL, this );
	m_material_removeMaterial_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_RemoveMaterial_ButtonClicked ), NULL, this );
	m_material_material_listBox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Material_MaterialList_Select ), NULL, this );
	m_material_id_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Material_MaterialID_Update ), NULL, this );
	m_material_type_comboBox->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Material_MaterialType_Update ), NULL, this );
	m_material_ambient_colourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_Material_Ambient_Update ), NULL, this );
	m_material_diffuse_colourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_Material_Diffuse_Update ), NULL, this );
	m_material_emissive_colourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_Material_Emissive_Update ), NULL, this );
	m_material_specular_colourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_Material_Specular_Update ), NULL, this );
	m_material_antiAlias_comboBox->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Material_AntiAlias_Update ), NULL, this );
	m_material_backFaceCulling_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_BackfaceCulling_Update ), NULL, this );
	m_material_frontFaceCulling_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_FrontfaceCulling_Update ), NULL, this );
	m_material_blendFactor_spinCtrlDouble->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Serenity3D_Frame::On_Material_BlendFactor_Update ), NULL, this );
	m_material_blendMode_comboBox->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Material_BlendMode_Update ), NULL, this );
	m_material_colorMask_comboBox->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Material_ColorMask_Update ), NULL, this );
	m_material_colorMode_comboBox->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Material_ColorMode_Update ), NULL, this );
	m_material_fog_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_Fog_Update ), NULL, this );
	m_material_gouradShading_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_GouradShading_Update ), NULL, this );
	m_material_lighting_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_Lighting_Update ), NULL, this );
	m_material_normalize_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_Normalize_Update ), NULL, this );
	m_material_pointCloud_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_PointCloud_Update ), NULL, this );
	m_material_shineness_spinCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( Serenity3D_Frame::On_Material_Shineness_Update ), NULL, this );
	this->Disconnect( m_material_previewNoLight_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_previewNoLight_Selected ) );
	this->Disconnect( m_material_previewDirectionLight_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_previewDirectionlight_Selected ) );
	this->Disconnect( m_material_previewPointLight_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_previewPointlight_Selected ) );
	this->Disconnect( m_materialPreviewMesh_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnSetMaterialPreviewMesh ) );
	this->Disconnect( m_materialPreviewSettings_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_previewSettings_Selected ) );
	m_material_addTextureLevel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_AddTextureLevel_ButtonClicked ), NULL, this );
	m_material_removeTextureLevel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_RemoveTextureLevel_ButtonClicked ), NULL, this );
	m_material_setTextureLevel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_SetTextureLevel_ButtonClicked ), NULL, this );
	m_material_clearTextureLevel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Material_ClearTextureLevel_ButtonClicked ), NULL, this );
	m_texture_addTexture_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Texture_AddTexture_ButtonClicked ), NULL, this );
	m_texture_removeTexture_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Texture_RemoveTexture_ButtonClicked ), NULL, this );
	m_texture_textureList_listBox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Serenity3D_Frame::On_Texture_TextureList_Select ), NULL, this );
	m_texture_textureID_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Serenity3D_Frame::On_Texture_TextureID_Update ), NULL, this );
	m_texture_useColorKey_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Serenity3D_Frame::On_Texture_UseColorkey_Update ), NULL, this );
	m_texture_colorKey_colourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Serenity3D_Frame::On_Texture_Colorkey_Update ), NULL, this );
	this->Disconnect( m_tool33->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnNewProjectMenuSelection ) );
	this->Disconnect( m_tool34->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnLoadProjectMenuSelection ) );
	this->Disconnect( m_tool35->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnSaveProjectMenuSelection ) );
	this->Disconnect( m_tool36->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Serenity3D_Frame::OnCodeGen ) );

}

SetMeshMaterialLevel_Dialog::SetMeshMaterialLevel_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer114;
	bSizer114 = new wxBoxSizer( wxVERTICAL );

	m_findMaterial_searchCtrl = new wxSearchCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_findMaterial_searchCtrl->ShowSearchButton( true );
	#endif
	m_findMaterial_searchCtrl->ShowCancelButton( false );
	bSizer114->Add( m_findMaterial_searchCtrl, 0, wxALL|wxEXPAND, 5 );

	m_materialList_listBox = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer114->Add( m_materialList_listBox, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer116;
	bSizer116 = new wxBoxSizer( wxHORIZONTAL );


	bSizer116->Add( 0, 0, 1, wxEXPAND, 5 );

	m_setMaterial_button = new wxButton( this, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_setMaterial_button, 0, wxALL, 5 );

	m_cancel_button = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_cancel_button, 0, wxALL, 5 );


	bSizer114->Add( bSizer116, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer114 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_findMaterial_searchCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SetMeshMaterialLevel_Dialog::OnSearch ), NULL, this );
	m_setMaterial_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMeshMaterialLevel_Dialog::OnSetMaterial ), NULL, this );
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMeshMaterialLevel_Dialog::OnCancel ), NULL, this );
}

SetMeshMaterialLevel_Dialog::~SetMeshMaterialLevel_Dialog()
{
	// Disconnect Events
	m_findMaterial_searchCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SetMeshMaterialLevel_Dialog::OnSearch ), NULL, this );
	m_setMaterial_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMeshMaterialLevel_Dialog::OnSetMaterial ), NULL, this );
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMeshMaterialLevel_Dialog::OnCancel ), NULL, this );

}

NewProject_Dialog::NewProject_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer162;
	bSizer162 = new wxBoxSizer( wxVERTICAL );

	m_panel61 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer163;
	bSizer163 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer164;
	bSizer164 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText65 = new wxStaticText( m_panel61, wxID_ANY, wxT("Name    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText65->Wrap( -1 );
	bSizer164->Add( m_staticText65, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_projectName_textCtrl = new wxTextCtrl( m_panel61, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer164->Add( m_projectName_textCtrl, 9, wxALL, 5 );


	bSizer163->Add( bSizer164, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer165;
	bSizer165 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText66 = new wxStaticText( m_panel61, wxID_ANY, wxT("Location"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText66->Wrap( -1 );
	bSizer165->Add( m_staticText66, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_projectLocation_dirPicker = new wxDirPickerCtrl( m_panel61, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	bSizer165->Add( m_projectLocation_dirPicker, 9, wxALL, 5 );


	bSizer163->Add( bSizer165, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer166;
	bSizer166 = new wxBoxSizer( wxHORIZONTAL );


	bSizer166->Add( 0, 0, 1, wxEXPAND, 5 );

	m_cancel_button = new wxButton( m_panel61, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer166->Add( m_cancel_button, 0, wxALL, 5 );

	m_create_button = new wxButton( m_panel61, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer166->Add( m_create_button, 0, wxALL, 5 );


	bSizer163->Add( bSizer166, 0, wxEXPAND, 5 );


	m_panel61->SetSizer( bSizer163 );
	m_panel61->Layout();
	bSizer163->Fit( m_panel61 );
	bSizer162->Add( m_panel61, 0, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer162 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewProject_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewProject_Dialog::OnCreateButtonClicked ), NULL, this );
}

NewProject_Dialog::~NewProject_Dialog()
{
	// Disconnect Events
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewProject_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewProject_Dialog::OnCreateButtonClicked ), NULL, this );

}

ExitEditorAlert_Dialog::ExitEditorAlert_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer146;
	bSizer146 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer148;
	bSizer148 = new wxBoxSizer( wxHORIZONTAL );


	bSizer148->Add( 0, 0, 1, wxEXPAND, 5 );

	m_alert_staticText = new wxStaticText( this, wxID_ANY, wxT("Do you want to save the project?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_alert_staticText->Wrap( -1 );
	bSizer148->Add( m_alert_staticText, 0, wxALL, 5 );


	bSizer148->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer146->Add( bSizer148, 1, wxEXPAND, 5 );


	bSizer146->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer149;
	bSizer149 = new wxBoxSizer( wxHORIZONTAL );


	bSizer149->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button56 = new wxButton( this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer149->Add( m_button56, 0, wxALL, 5 );

	m_button95 = new wxButton( this, wxID_ANY, wxT("Discard"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer149->Add( m_button95, 0, wxALL, 5 );

	m_button57 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer149->Add( m_button57, 0, wxALL, 5 );


	bSizer149->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer146->Add( bSizer149, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer146 );
	this->Layout();
	bSizer146->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button56->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExitEditorAlert_Dialog::OnSave ), NULL, this );
	m_button95->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExitEditorAlert_Dialog::OnDiscard ), NULL, this );
	m_button57->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExitEditorAlert_Dialog::OnCancel ), NULL, this );
}

ExitEditorAlert_Dialog::~ExitEditorAlert_Dialog()
{
	// Disconnect Events
	m_button56->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExitEditorAlert_Dialog::OnSave ), NULL, this );
	m_button95->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExitEditorAlert_Dialog::OnDiscard ), NULL, this );
	m_button57->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExitEditorAlert_Dialog::OnCancel ), NULL, this );

}

AddTexture_Dialog::AddTexture_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer113;
	bSizer113 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer114;
	bSizer114 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer115;
	bSizer115 = new wxBoxSizer( wxVERTICAL );

	wxArrayString m_files_checkListChoices;
	m_files_checkList = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_files_checkListChoices, 0 );
	bSizer115->Add( m_files_checkList, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer116;
	bSizer116 = new wxBoxSizer( wxHORIZONTAL );

	m_button19 = new wxButton( this, wxID_ANY, wxT("Select All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_button19, 1, wxALL, 5 );

	m_button20 = new wxButton( this, wxID_ANY, wxT("Deselect All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_button20, 1, wxALL, 5 );

	m_button23 = new wxButton( this, wxID_ANY, wxT("Show Duplicates"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_button23, 1, wxALL, 5 );

	m_button24 = new wxButton( this, wxID_ANY, wxT("Hide Duplicates"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_button24, 1, wxALL, 5 );


	bSizer115->Add( bSizer116, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer117;
	bSizer117 = new wxBoxSizer( wxHORIZONTAL );


	bSizer117->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button21 = new wxButton( this, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer117->Add( m_button21, 0, wxALL, 5 );

	m_button22 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer117->Add( m_button22, 0, wxALL, 5 );


	bSizer115->Add( bSizer117, 0, wxEXPAND, 5 );


	bSizer114->Add( bSizer115, 1, wxEXPAND, 5 );


	bSizer113->Add( bSizer114, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer113 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTexture_Dialog::OnSelectAll ), NULL, this );
	m_button20->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTexture_Dialog::OnDeselectAll ), NULL, this );
	m_button23->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTexture_Dialog::OnShowDuplicates ), NULL, this );
	m_button24->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTexture_Dialog::OnHideDuplicates ), NULL, this );
	m_button21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTexture_Dialog::OnLoad ), NULL, this );
	m_button22->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTexture_Dialog::OnCancel ), NULL, this );
}

AddTexture_Dialog::~AddTexture_Dialog()
{
	// Disconnect Events
	m_button19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTexture_Dialog::OnSelectAll ), NULL, this );
	m_button20->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTexture_Dialog::OnDeselectAll ), NULL, this );
	m_button23->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTexture_Dialog::OnShowDuplicates ), NULL, this );
	m_button24->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTexture_Dialog::OnHideDuplicates ), NULL, this );
	m_button21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTexture_Dialog::OnLoad ), NULL, this );
	m_button22->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTexture_Dialog::OnCancel ), NULL, this );

}

SetMaterialTextureLevel_Dialog::SetMaterialTextureLevel_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer114;
	bSizer114 = new wxBoxSizer( wxVERTICAL );

	m_findTexture_searchCtrl = new wxSearchCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_findTexture_searchCtrl->ShowSearchButton( true );
	#endif
	m_findTexture_searchCtrl->ShowCancelButton( false );
	bSizer114->Add( m_findTexture_searchCtrl, 0, wxALL|wxEXPAND, 5 );

	m_textureList_listBox = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer114->Add( m_textureList_listBox, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer116;
	bSizer116 = new wxBoxSizer( wxHORIZONTAL );


	bSizer116->Add( 0, 0, 1, wxEXPAND, 5 );

	m_setTexture_button = new wxButton( this, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_setTexture_button, 0, wxALL, 5 );

	m_cancel_button = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_cancel_button, 0, wxALL, 5 );


	bSizer114->Add( bSizer116, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer114 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_findTexture_searchCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SetMaterialTextureLevel_Dialog::OnSearch ), NULL, this );
	m_setTexture_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMaterialTextureLevel_Dialog::OnSetTexture ), NULL, this );
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMaterialTextureLevel_Dialog::OnCancel ), NULL, this );
}

SetMaterialTextureLevel_Dialog::~SetMaterialTextureLevel_Dialog()
{
	// Disconnect Events
	m_findTexture_searchCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SetMaterialTextureLevel_Dialog::OnSearch ), NULL, this );
	m_setTexture_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMaterialTextureLevel_Dialog::OnSetTexture ), NULL, this );
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMaterialTextureLevel_Dialog::OnCancel ), NULL, this );

}

SetMaterialPreviewMesh_Dialog::SetMaterialPreviewMesh_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer124;
	bSizer124 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer125;
	bSizer125 = new wxBoxSizer( wxHORIZONTAL );

	m_findMesh_searchCtrl = new wxSearchCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_findMesh_searchCtrl->ShowSearchButton( true );
	#endif
	m_findMesh_searchCtrl->ShowCancelButton( false );
	bSizer125->Add( m_findMesh_searchCtrl, 1, wxALL, 5 );


	bSizer124->Add( bSizer125, 0, wxEXPAND, 5 );

	m_meshList_listBox = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer124->Add( m_meshList_listBox, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer126;
	bSizer126 = new wxBoxSizer( wxHORIZONTAL );


	bSizer126->Add( 0, 0, 1, wxEXPAND, 5 );

	m_setMesh_button = new wxButton( this, wxID_ANY, wxT("Set Mesh"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer126->Add( m_setMesh_button, 1, wxALL, 5 );

	m_cube_button = new wxButton( this, wxID_ANY, wxT("Default Cube"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer126->Add( m_cube_button, 1, wxALL, 5 );

	m_sphere_button = new wxButton( this, wxID_ANY, wxT("Default Sphere"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer126->Add( m_sphere_button, 1, wxALL, 5 );

	m_cancel_button = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer126->Add( m_cancel_button, 1, wxALL, 5 );


	bSizer124->Add( bSizer126, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer124 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_findMesh_searchCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SetMaterialPreviewMesh_Dialog::OnSearch ), NULL, this );
	m_setMesh_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMaterialPreviewMesh_Dialog::OnSetMesh ), NULL, this );
	m_cube_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMaterialPreviewMesh_Dialog::OnDefaultCube ), NULL, this );
	m_sphere_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMaterialPreviewMesh_Dialog::OnDefaultSphere ), NULL, this );
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMaterialPreviewMesh_Dialog::OnCancel ), NULL, this );
}

SetMaterialPreviewMesh_Dialog::~SetMaterialPreviewMesh_Dialog()
{
	// Disconnect Events
	m_findMesh_searchCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SetMaterialPreviewMesh_Dialog::OnSearch ), NULL, this );
	m_setMesh_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMaterialPreviewMesh_Dialog::OnSetMesh ), NULL, this );
	m_cube_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMaterialPreviewMesh_Dialog::OnDefaultCube ), NULL, this );
	m_sphere_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMaterialPreviewMesh_Dialog::OnDefaultSphere ), NULL, this );
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetMaterialPreviewMesh_Dialog::OnCancel ), NULL, this );

}

MaterialPreviewSettings_Dialog::MaterialPreviewSettings_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer130;
	bSizer130 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer236;
	bSizer236 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText85 = new wxStaticText( this, wxID_ANY, wxT("Camera Control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText85->Wrap( -1 );
	bSizer236->Add( m_staticText85, 1, wxALL, 5 );

	m_auto_radioBtn = new wxRadioButton( this, wxID_ANY, wxT("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer236->Add( m_auto_radioBtn, 1, wxALL, 5 );

	m_manual_radioBtn = new wxRadioButton( this, wxID_ANY, wxT("Manual"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer236->Add( m_manual_radioBtn, 1, wxALL, 5 );


	bSizer236->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer130->Add( bSizer236, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer131;
	bSizer131 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText50 = new wxStaticText( this, wxID_ANY, wxT("Camera Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText50->Wrap( -1 );
	bSizer131->Add( m_staticText50, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_cameraSpeed_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer131->Add( m_cameraSpeed_textCtrl, 3, wxALL, 5 );


	bSizer130->Add( bSizer131, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer132;
	bSizer132 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText51 = new wxStaticText( this, wxID_ANY, wxT("Camera Distance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	bSizer132->Add( m_staticText51, 1, wxALL, 5 );

	m_cameraDistance_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer132->Add( m_cameraDistance_textCtrl, 3, wxALL, 5 );


	bSizer130->Add( bSizer132, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer134;
	bSizer134 = new wxBoxSizer( wxVERTICAL );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer134->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );


	bSizer130->Add( bSizer134, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer133;
	bSizer133 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText52 = new wxStaticText( this, wxID_ANY, wxT("Light Radius"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	bSizer133->Add( m_staticText52, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_lightRadius_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer133->Add( m_lightRadius_textCtrl, 3, wxALL, 5 );


	bSizer130->Add( bSizer133, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer135;
	bSizer135 = new wxBoxSizer( wxHORIZONTAL );


	bSizer135->Add( 0, 0, 1, wxEXPAND, 5 );

	m_apply_button = new wxButton( this, wxID_ANY, wxT("Apply"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer135->Add( m_apply_button, 0, wxALL, 5 );

	m_cancel_button = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer135->Add( m_cancel_button, 0, wxALL, 5 );


	bSizer130->Add( bSizer135, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer130 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_apply_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MaterialPreviewSettings_Dialog::OnApply ), NULL, this );
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MaterialPreviewSettings_Dialog::OnCancel ), NULL, this );
}

MaterialPreviewSettings_Dialog::~MaterialPreviewSettings_Dialog()
{
	// Disconnect Events
	m_apply_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MaterialPreviewSettings_Dialog::OnApply ), NULL, this );
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MaterialPreviewSettings_Dialog::OnCancel ), NULL, this );

}

AddMaterial_Dialog::AddMaterial_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer113;
	bSizer113 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer114;
	bSizer114 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer115;
	bSizer115 = new wxBoxSizer( wxVERTICAL );

	wxArrayString m_files_checkListChoices;
	m_files_checkList = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_files_checkListChoices, 0 );
	bSizer115->Add( m_files_checkList, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer116;
	bSizer116 = new wxBoxSizer( wxHORIZONTAL );

	m_button19 = new wxButton( this, wxID_ANY, wxT("Select All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_button19, 1, wxALL, 5 );

	m_button20 = new wxButton( this, wxID_ANY, wxT("Deselect All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_button20, 1, wxALL, 5 );

	m_button23 = new wxButton( this, wxID_ANY, wxT("Show Duplicates"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_button23, 1, wxALL, 5 );

	m_button24 = new wxButton( this, wxID_ANY, wxT("Hide Duplicates"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_button24, 1, wxALL, 5 );


	bSizer115->Add( bSizer116, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer117;
	bSizer117 = new wxBoxSizer( wxHORIZONTAL );


	bSizer117->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button21 = new wxButton( this, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer117->Add( m_button21, 0, wxALL, 5 );

	m_button22 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer117->Add( m_button22, 0, wxALL, 5 );


	bSizer115->Add( bSizer117, 0, wxEXPAND, 5 );


	bSizer114->Add( bSizer115, 1, wxEXPAND, 5 );


	bSizer113->Add( bSizer114, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer113 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMaterial_Dialog::OnSelectAll ), NULL, this );
	m_button20->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMaterial_Dialog::OnDeselectAll ), NULL, this );
	m_button23->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMaterial_Dialog::OnShowDuplicates ), NULL, this );
	m_button24->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMaterial_Dialog::OnHideDuplicates ), NULL, this );
	m_button21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMaterial_Dialog::OnLoad ), NULL, this );
	m_button22->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMaterial_Dialog::OnCancel ), NULL, this );
}

AddMaterial_Dialog::~AddMaterial_Dialog()
{
	// Disconnect Events
	m_button19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMaterial_Dialog::OnSelectAll ), NULL, this );
	m_button20->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMaterial_Dialog::OnDeselectAll ), NULL, this );
	m_button23->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMaterial_Dialog::OnShowDuplicates ), NULL, this );
	m_button24->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMaterial_Dialog::OnHideDuplicates ), NULL, this );
	m_button21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMaterial_Dialog::OnLoad ), NULL, this );
	m_button22->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMaterial_Dialog::OnCancel ), NULL, this );

}

AddMesh_Dialog::AddMesh_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer113;
	bSizer113 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer114;
	bSizer114 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer115;
	bSizer115 = new wxBoxSizer( wxVERTICAL );

	wxArrayString m_files_checkListChoices;
	m_files_checkList = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_files_checkListChoices, 0 );
	bSizer115->Add( m_files_checkList, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer116;
	bSizer116 = new wxBoxSizer( wxHORIZONTAL );

	m_button19 = new wxButton( this, wxID_ANY, wxT("Select All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_button19, 1, wxALL, 5 );

	m_button20 = new wxButton( this, wxID_ANY, wxT("Deselect All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_button20, 1, wxALL, 5 );

	m_button23 = new wxButton( this, wxID_ANY, wxT("Show Duplicates"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_button23, 1, wxALL, 5 );

	m_button24 = new wxButton( this, wxID_ANY, wxT("Hide Duplicates"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( m_button24, 1, wxALL, 5 );


	bSizer115->Add( bSizer116, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer117;
	bSizer117 = new wxBoxSizer( wxHORIZONTAL );


	bSizer117->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button21 = new wxButton( this, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer117->Add( m_button21, 0, wxALL, 5 );

	m_button22 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer117->Add( m_button22, 0, wxALL, 5 );


	bSizer115->Add( bSizer117, 0, wxEXPAND, 5 );


	bSizer114->Add( bSizer115, 1, wxEXPAND, 5 );


	bSizer113->Add( bSizer114, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer113 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMesh_Dialog::OnSelectAll ), NULL, this );
	m_button20->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMesh_Dialog::OnDeselectAll ), NULL, this );
	m_button23->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMesh_Dialog::OnShowDuplicates ), NULL, this );
	m_button24->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMesh_Dialog::OnHideDuplicates ), NULL, this );
	m_button21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMesh_Dialog::OnLoad ), NULL, this );
	m_button22->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMesh_Dialog::OnCancel ), NULL, this );
}

AddMesh_Dialog::~AddMesh_Dialog()
{
	// Disconnect Events
	m_button19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMesh_Dialog::OnSelectAll ), NULL, this );
	m_button20->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMesh_Dialog::OnDeselectAll ), NULL, this );
	m_button23->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMesh_Dialog::OnShowDuplicates ), NULL, this );
	m_button24->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMesh_Dialog::OnHideDuplicates ), NULL, this );
	m_button21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMesh_Dialog::OnLoad ), NULL, this );
	m_button22->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMesh_Dialog::OnCancel ), NULL, this );

}

AddArchiveSource_Dialog::AddArchiveSource_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer159;
	bSizer159 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer160;
	bSizer160 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText49 = new wxStaticText( this, wxID_ANY, wxT("Container"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText49->Wrap( -1 );
	bSizer160->Add( m_staticText49, 1, wxALL, 5 );

	m_listBox12 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer160->Add( m_listBox12, 4, wxALL|wxEXPAND, 5 );


	bSizer159->Add( bSizer160, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer161;
	bSizer161 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText50 = new wxStaticText( this, wxID_ANY, wxT("Source"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText50->Wrap( -1 );
	bSizer161->Add( m_staticText50, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_textCtrl19 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer161->Add( m_textCtrl19, 4, wxALL, 5 );


	bSizer159->Add( bSizer161, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer162;
	bSizer162 = new wxBoxSizer( wxHORIZONTAL );


	bSizer162->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button72 = new wxButton( this, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer162->Add( m_button72, 0, wxALL, 5 );

	m_button73 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer162->Add( m_button73, 0, wxALL, 5 );


	bSizer159->Add( bSizer162, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer159 );
	this->Layout();

	this->Centre( wxBOTH );
}

AddArchiveSource_Dialog::~AddArchiveSource_Dialog()
{
}

CreateStageGroup_Dialog::CreateStageGroup_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer164;
	bSizer164 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer159;
	bSizer159 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText54 = new wxStaticText( this, wxID_ANY, wxT("Stage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	bSizer159->Add( m_staticText54, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_stage_comboBox = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer159->Add( m_stage_comboBox, 4, wxALL, 5 );


	bSizer164->Add( bSizer159, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer144;
	bSizer144 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText48 = new wxStaticText( this, wxID_ANY, wxT("Group Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText48->Wrap( -1 );
	bSizer144->Add( m_staticText48, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_groupName_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer144->Add( m_groupName_textCtrl, 4, wxALL, 5 );


	bSizer164->Add( bSizer144, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer145;
	bSizer145 = new wxBoxSizer( wxHORIZONTAL );


	bSizer145->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button54 = new wxButton( this, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer145->Add( m_button54, 0, wxALL, 5 );

	m_button55 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer145->Add( m_button55, 0, wxALL, 5 );


	bSizer164->Add( bSizer145, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer164 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button54->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateStageGroup_Dialog::OnCreate ), NULL, this );
	m_button55->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateStageGroup_Dialog::OnCancel ), NULL, this );
}

CreateStageGroup_Dialog::~CreateStageGroup_Dialog()
{
	// Disconnect Events
	m_button54->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateStageGroup_Dialog::OnCreate ), NULL, this );
	m_button55->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateStageGroup_Dialog::OnCancel ), NULL, this );

}

DeleteGroupAlert_Dialog::DeleteGroupAlert_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer146;
	bSizer146 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer147;
	bSizer147 = new wxBoxSizer( wxHORIZONTAL );


	bSizer147->Add( 0, 0, 1, wxEXPAND, 5 );

	m_deleteGroupName_staticText = new wxStaticText( this, wxID_ANY, wxT("Delete Group: [GROUP_NAME]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_deleteGroupName_staticText->Wrap( -1 );
	bSizer147->Add( m_deleteGroupName_staticText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer147->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer146->Add( bSizer147, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer148;
	bSizer148 = new wxBoxSizer( wxHORIZONTAL );


	bSizer148->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText50 = new wxStaticText( this, wxID_ANY, wxT("Are you sure you want to delete this group?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText50->Wrap( -1 );
	bSizer148->Add( m_staticText50, 0, wxALL, 5 );


	bSizer148->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer146->Add( bSizer148, 1, wxEXPAND, 5 );


	bSizer146->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer149;
	bSizer149 = new wxBoxSizer( wxHORIZONTAL );


	bSizer149->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button56 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer149->Add( m_button56, 0, wxALL, 5 );

	m_button57 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer149->Add( m_button57, 0, wxALL, 5 );


	bSizer149->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer146->Add( bSizer149, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer146 );
	this->Layout();
	bSizer146->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button56->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeleteGroupAlert_Dialog::OnDelete ), NULL, this );
	m_button57->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeleteGroupAlert_Dialog::OnCancel ), NULL, this );
}

DeleteGroupAlert_Dialog::~DeleteGroupAlert_Dialog()
{
	// Disconnect Events
	m_button56->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeleteGroupAlert_Dialog::OnDelete ), NULL, this );
	m_button57->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeleteGroupAlert_Dialog::OnCancel ), NULL, this );

}

EditStageGroup_Dialog::EditStageGroup_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer150;
	bSizer150 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer159;
	bSizer159 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText53 = new wxStaticText( this, wxID_ANY, wxT("Group Label"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	bSizer159->Add( m_staticText53, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_groupLabel_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer159->Add( m_groupLabel_textCtrl, 1, wxALL, 5 );


	bSizer150->Add( bSizer159, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer152;
	bSizer152 = new wxBoxSizer( wxVERTICAL );

	m_stageLabel_staticText = new wxStaticText( this, wxID_ANY, wxT("Stage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stageLabel_staticText->Wrap( -1 );
	bSizer152->Add( m_stageLabel_staticText, 0, wxALL, 5 );

	wxArrayString m_stageList_checkListChoices;
	m_stageList_checkList = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_stageList_checkListChoices, 0 );
	bSizer152->Add( m_stageList_checkList, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer153;
	bSizer153 = new wxBoxSizer( wxHORIZONTAL );

	m_button58 = new wxButton( this, wxID_ANY, wxT("Select All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer153->Add( m_button58, 0, wxALL, 5 );

	m_button59 = new wxButton( this, wxID_ANY, wxT("Deselect All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer153->Add( m_button59, 0, wxALL, 5 );


	bSizer152->Add( bSizer153, 0, wxEXPAND, 5 );


	bSizer151->Add( bSizer152, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer156;
	bSizer156 = new wxBoxSizer( wxVERTICAL );


	bSizer156->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button62 = new wxButton( this, wxID_ANY, wxT("Add >>"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer156->Add( m_button62, 0, wxALL|wxEXPAND, 5 );

	m_button63 = new wxButton( this, wxID_ANY, wxT("<< Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer156->Add( m_button63, 0, wxALL|wxEXPAND, 5 );


	bSizer156->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer151->Add( bSizer156, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer154;
	bSizer154 = new wxBoxSizer( wxVERTICAL );

	m_groupLabel_staticText = new wxStaticText( this, wxID_ANY, wxT("Group"), wxDefaultPosition, wxDefaultSize, 0 );
	m_groupLabel_staticText->Wrap( -1 );
	bSizer154->Add( m_groupLabel_staticText, 0, wxALL, 5 );

	wxArrayString m_groupList_checkListChoices;
	m_groupList_checkList = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_groupList_checkListChoices, 0 );
	bSizer154->Add( m_groupList_checkList, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer155;
	bSizer155 = new wxBoxSizer( wxHORIZONTAL );

	m_button60 = new wxButton( this, wxID_ANY, wxT("Select All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer155->Add( m_button60, 0, wxALL, 5 );

	m_button61 = new wxButton( this, wxID_ANY, wxT("Deselect All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer155->Add( m_button61, 0, wxALL, 5 );


	bSizer154->Add( bSizer155, 0, wxEXPAND, 5 );


	bSizer151->Add( bSizer154, 1, wxEXPAND, 5 );


	bSizer150->Add( bSizer151, 8, wxEXPAND, 5 );


	bSizer150->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer157;
	bSizer157 = new wxBoxSizer( wxHORIZONTAL );


	bSizer157->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button64 = new wxButton( this, wxID_ANY, wxT("Apply"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer157->Add( m_button64, 0, wxALL, 5 );

	m_button65 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer157->Add( m_button65, 0, wxALL, 5 );


	bSizer150->Add( bSizer157, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer150 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button58->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnStageSelectAll ), NULL, this );
	m_button59->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnStageDeselectAll ), NULL, this );
	m_button62->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnAdd ), NULL, this );
	m_button63->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnRemove ), NULL, this );
	m_button60->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnGroupSelectAll ), NULL, this );
	m_button61->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnGroupDeselectAll ), NULL, this );
	m_button64->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnApply ), NULL, this );
	m_button65->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnCancel ), NULL, this );
}

EditStageGroup_Dialog::~EditStageGroup_Dialog()
{
	// Disconnect Events
	m_button58->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnStageSelectAll ), NULL, this );
	m_button59->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnStageDeselectAll ), NULL, this );
	m_button62->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnAdd ), NULL, this );
	m_button63->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnRemove ), NULL, this );
	m_button60->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnGroupSelectAll ), NULL, this );
	m_button61->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnGroupDeselectAll ), NULL, this );
	m_button64->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnApply ), NULL, this );
	m_button65->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditStageGroup_Dialog::OnCancel ), NULL, this );

}

NewStage_Dialog::NewStage_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer161;
	bSizer161 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer162;
	bSizer162 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText55 = new wxStaticText( this, wxID_ANY, wxT("Stage ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText55->Wrap( -1 );
	bSizer162->Add( m_staticText55, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_stageID_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer162->Add( m_stageID_textCtrl, 1, wxALL, 5 );


	bSizer161->Add( bSizer162, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer163;
	bSizer163 = new wxBoxSizer( wxHORIZONTAL );


	bSizer163->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button67 = new wxButton( this, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer163->Add( m_button67, 0, wxALL, 5 );

	m_button68 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer163->Add( m_button68, 0, wxALL, 5 );


	bSizer161->Add( bSizer163, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer161 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button67->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewStage_Dialog::OnCreate ), NULL, this );
	m_button68->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewStage_Dialog::OnCancel ), NULL, this );
}

NewStage_Dialog::~NewStage_Dialog()
{
	// Disconnect Events
	m_button67->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewStage_Dialog::OnCreate ), NULL, this );
	m_button68->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewStage_Dialog::OnCancel ), NULL, this );

}

DeleteStageAlert_Dialog::DeleteStageAlert_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer146;
	bSizer146 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer147;
	bSizer147 = new wxBoxSizer( wxHORIZONTAL );


	bSizer147->Add( 0, 0, 1, wxEXPAND, 5 );

	m_deleteGroupName_staticText = new wxStaticText( this, wxID_ANY, wxT("Delete Stage: [STAGE_NAME]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_deleteGroupName_staticText->Wrap( -1 );
	bSizer147->Add( m_deleteGroupName_staticText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer147->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer146->Add( bSizer147, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer148;
	bSizer148 = new wxBoxSizer( wxHORIZONTAL );


	bSizer148->Add( 0, 0, 1, wxEXPAND, 5 );

	m_alert_staticText = new wxStaticText( this, wxID_ANY, wxT("Are you sure you want to delete this stage?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_alert_staticText->Wrap( -1 );
	bSizer148->Add( m_alert_staticText, 0, wxALL, 5 );


	bSizer148->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer146->Add( bSizer148, 1, wxEXPAND, 5 );


	bSizer146->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer149;
	bSizer149 = new wxBoxSizer( wxHORIZONTAL );


	bSizer149->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button56 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer149->Add( m_button56, 0, wxALL, 5 );

	m_button57 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer149->Add( m_button57, 0, wxALL, 5 );


	bSizer149->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer146->Add( bSizer149, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer146 );
	this->Layout();
	bSizer146->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button56->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeleteStageAlert_Dialog::OnDelete ), NULL, this );
	m_button57->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeleteStageAlert_Dialog::OnCancel ), NULL, this );
}

DeleteStageAlert_Dialog::~DeleteStageAlert_Dialog()
{
	// Disconnect Events
	m_button56->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeleteStageAlert_Dialog::OnDelete ), NULL, this );
	m_button57->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeleteStageAlert_Dialog::OnCancel ), NULL, this );

}

DeleteActorAlert_Dialog::DeleteActorAlert_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer146;
	bSizer146 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer147;
	bSizer147 = new wxBoxSizer( wxHORIZONTAL );


	bSizer147->Add( 0, 0, 1, wxEXPAND, 5 );

	m_deleteGroupName_staticText = new wxStaticText( this, wxID_ANY, wxT("Delete Actor: [ACTOR_NAME]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_deleteGroupName_staticText->Wrap( -1 );
	bSizer147->Add( m_deleteGroupName_staticText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer147->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer146->Add( bSizer147, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer148;
	bSizer148 = new wxBoxSizer( wxHORIZONTAL );


	bSizer148->Add( 0, 0, 1, wxEXPAND, 5 );

	m_alert_staticText = new wxStaticText( this, wxID_ANY, wxT("Are you sure you want to delete this actor?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_alert_staticText->Wrap( -1 );
	bSizer148->Add( m_alert_staticText, 0, wxALL, 5 );


	bSizer148->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer146->Add( bSizer148, 1, wxEXPAND, 5 );


	bSizer146->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer149;
	bSizer149 = new wxBoxSizer( wxHORIZONTAL );


	bSizer149->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button56 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer149->Add( m_button56, 0, wxALL, 5 );

	m_button57 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer149->Add( m_button57, 0, wxALL, 5 );


	bSizer149->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer146->Add( bSizer149, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer146 );
	this->Layout();
	bSizer146->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button56->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeleteActorAlert_Dialog::OnDelete ), NULL, this );
	m_button57->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeleteActorAlert_Dialog::OnCancel ), NULL, this );
}

DeleteActorAlert_Dialog::~DeleteActorAlert_Dialog()
{
	// Disconnect Events
	m_button56->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeleteActorAlert_Dialog::OnDelete ), NULL, this );
	m_button57->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeleteActorAlert_Dialog::OnCancel ), NULL, this );

}

NewAnimatedActor_Dialog::NewAnimatedActor_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxVERTICAL );

	m_panel38 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( m_panel38, wxID_ANY, wxT("Actor ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer78->Add( m_staticText33, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_actorID_textCtrl = new wxTextCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer78->Add( m_actorID_textCtrl, 9, wxALL, 5 );


	bSizer77->Add( bSizer78, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( m_panel38, wxID_ANY, wxT("Mesh ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer79->Add( m_staticText34, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );

	m_meshSearch_searchCtrl = new wxSearchCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_meshSearch_searchCtrl->ShowSearchButton( true );
	#endif
	m_meshSearch_searchCtrl->ShowCancelButton( false );
	bSizer81->Add( m_meshSearch_searchCtrl, 1, wxALL, 5 );


	bSizer79->Add( bSizer81, 9, wxEXPAND, 5 );


	bSizer77->Add( bSizer79, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxHORIZONTAL );


	bSizer80->Add( 0, 0, 1, wxEXPAND, 5 );

	m_mesh_listBox = new wxListBox( m_panel38, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer80->Add( m_mesh_listBox, 9, wxALL|wxEXPAND, 5 );


	bSizer77->Add( bSizer80, 9, wxEXPAND, 5 );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );


	bSizer82->Add( 0, 0, 1, wxEXPAND, 5 );

	m_cancel_button = new wxButton( m_panel38, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_cancel_button, 0, wxALL, 5 );

	m_create_button = new wxButton( m_panel38, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_create_button, 0, wxALL, 5 );


	bSizer77->Add( bSizer82, 0, wxEXPAND, 5 );


	m_panel38->SetSizer( bSizer77 );
	m_panel38->Layout();
	bSizer77->Fit( m_panel38 );
	bSizer76->Add( m_panel38, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer76 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_meshSearch_searchCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( NewAnimatedActor_Dialog::OnSearchText ), NULL, this );
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewAnimatedActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewAnimatedActor_Dialog::OnCreateButtonClicked ), NULL, this );
}

NewAnimatedActor_Dialog::~NewAnimatedActor_Dialog()
{
	// Disconnect Events
	m_meshSearch_searchCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( NewAnimatedActor_Dialog::OnSearchText ), NULL, this );
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewAnimatedActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewAnimatedActor_Dialog::OnCreateButtonClicked ), NULL, this );

}

NewOctreeActor_Dialog::NewOctreeActor_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxVERTICAL );

	m_panel38 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( m_panel38, wxID_ANY, wxT("Actor ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer78->Add( m_staticText33, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_actorID_textCtrl = new wxTextCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer78->Add( m_actorID_textCtrl, 9, wxALL, 5 );


	bSizer77->Add( bSizer78, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( m_panel38, wxID_ANY, wxT("Mesh ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer79->Add( m_staticText34, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );

	m_meshSearch_searchCtrl = new wxSearchCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_meshSearch_searchCtrl->ShowSearchButton( true );
	#endif
	m_meshSearch_searchCtrl->ShowCancelButton( false );
	bSizer81->Add( m_meshSearch_searchCtrl, 1, wxALL, 5 );


	bSizer79->Add( bSizer81, 9, wxEXPAND, 5 );


	bSizer77->Add( bSizer79, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxHORIZONTAL );


	bSizer80->Add( 0, 0, 1, wxEXPAND, 5 );

	m_mesh_listBox = new wxListBox( m_panel38, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer80->Add( m_mesh_listBox, 9, wxALL|wxEXPAND, 5 );


	bSizer77->Add( bSizer80, 9, wxEXPAND, 5 );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );


	bSizer82->Add( 0, 0, 1, wxEXPAND, 5 );

	m_cancel_button = new wxButton( m_panel38, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_cancel_button, 0, wxALL, 5 );

	m_create_button = new wxButton( m_panel38, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_create_button, 0, wxALL, 5 );


	bSizer77->Add( bSizer82, 0, wxEXPAND, 5 );


	m_panel38->SetSizer( bSizer77 );
	m_panel38->Layout();
	bSizer77->Fit( m_panel38 );
	bSizer76->Add( m_panel38, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer76 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_meshSearch_searchCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( NewOctreeActor_Dialog::OnSearchText ), NULL, this );
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewOctreeActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewOctreeActor_Dialog::OnCreateButtonClicked ), NULL, this );
}

NewOctreeActor_Dialog::~NewOctreeActor_Dialog()
{
	// Disconnect Events
	m_meshSearch_searchCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( NewOctreeActor_Dialog::OnSearchText ), NULL, this );
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewOctreeActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewOctreeActor_Dialog::OnCreateButtonClicked ), NULL, this );

}

NewBillboardActor_Dialog::NewBillboardActor_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxVERTICAL );

	m_panel38 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( m_panel38, wxID_ANY, wxT("Actor ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer78->Add( m_staticText33, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_actorID_textCtrl = new wxTextCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer78->Add( m_actorID_textCtrl, 4, wxALL, 5 );


	bSizer77->Add( bSizer78, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( m_panel38, wxID_ANY, wxT("Material ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer79->Add( m_staticText34, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );

	m_materialSearch_searchCtrl = new wxSearchCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_materialSearch_searchCtrl->ShowSearchButton( true );
	#endif
	m_materialSearch_searchCtrl->ShowCancelButton( false );
	bSizer81->Add( m_materialSearch_searchCtrl, 1, wxALL, 5 );


	bSizer79->Add( bSizer81, 4, wxEXPAND, 5 );


	bSizer77->Add( bSizer79, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxHORIZONTAL );


	bSizer80->Add( 0, 0, 1, wxEXPAND, 5 );

	m_material_listBox = new wxListBox( m_panel38, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer80->Add( m_material_listBox, 4, wxALL|wxEXPAND, 5 );


	bSizer77->Add( bSizer80, 9, wxEXPAND, 5 );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );


	bSizer82->Add( 0, 0, 1, wxEXPAND, 5 );

	m_cancel_button = new wxButton( m_panel38, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_cancel_button, 0, wxALL, 5 );

	m_create_button = new wxButton( m_panel38, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_create_button, 0, wxALL, 5 );


	bSizer77->Add( bSizer82, 0, wxEXPAND, 5 );


	m_panel38->SetSizer( bSizer77 );
	m_panel38->Layout();
	bSizer77->Fit( m_panel38 );
	bSizer76->Add( m_panel38, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer76 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_materialSearch_searchCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( NewBillboardActor_Dialog::OnSearchText ), NULL, this );
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewBillboardActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewBillboardActor_Dialog::OnCreateButtonClicked ), NULL, this );
}

NewBillboardActor_Dialog::~NewBillboardActor_Dialog()
{
	// Disconnect Events
	m_materialSearch_searchCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( NewBillboardActor_Dialog::OnSearchText ), NULL, this );
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewBillboardActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewBillboardActor_Dialog::OnCreateButtonClicked ), NULL, this );

}

NewLightActor_Dialog::NewLightActor_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxVERTICAL );

	m_panel38 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( m_panel38, wxID_ANY, wxT("Actor ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer78->Add( m_staticText33, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_actorID_textCtrl = new wxTextCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer78->Add( m_actorID_textCtrl, 4, wxALL, 5 );


	bSizer77->Add( bSizer78, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer250;
	bSizer250 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText85 = new wxStaticText( m_panel38, wxID_ANY, wxT("Light Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText85->Wrap( -1 );
	bSizer250->Add( m_staticText85, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_type_comboBox = new wxComboBox( m_panel38, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer250->Add( m_type_comboBox, 4, wxALL, 5 );


	bSizer77->Add( bSizer250, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );


	bSizer82->Add( 0, 0, 1, wxEXPAND, 5 );

	m_cancel_button = new wxButton( m_panel38, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_cancel_button, 0, wxALL, 5 );

	m_create_button = new wxButton( m_panel38, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_create_button, 0, wxALL, 5 );


	bSizer77->Add( bSizer82, 0, wxEXPAND, 5 );


	m_panel38->SetSizer( bSizer77 );
	m_panel38->Layout();
	bSizer77->Fit( m_panel38 );
	bSizer76->Add( m_panel38, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer76 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewLightActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewLightActor_Dialog::OnCreateButtonClicked ), NULL, this );
}

NewLightActor_Dialog::~NewLightActor_Dialog()
{
	// Disconnect Events
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewLightActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewLightActor_Dialog::OnCreateButtonClicked ), NULL, this );

}

NewParticleActor_Dialog::NewParticleActor_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxVERTICAL );

	m_panel38 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( m_panel38, wxID_ANY, wxT("Actor ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer78->Add( m_staticText33, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_actorID_textCtrl = new wxTextCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer78->Add( m_actorID_textCtrl, 4, wxALL, 5 );


	bSizer77->Add( bSizer78, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer250;
	bSizer250 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText85 = new wxStaticText( m_panel38, wxID_ANY, wxT("Particle Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText85->Wrap( -1 );
	bSizer250->Add( m_staticText85, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_type_comboBox = new wxComboBox( m_panel38, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer250->Add( m_type_comboBox, 4, wxALL, 5 );


	bSizer77->Add( bSizer250, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );


	bSizer82->Add( 0, 0, 1, wxEXPAND, 5 );

	m_cancel_button = new wxButton( m_panel38, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_cancel_button, 0, wxALL, 5 );

	m_create_button = new wxButton( m_panel38, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_create_button, 0, wxALL, 5 );


	bSizer77->Add( bSizer82, 0, wxEXPAND, 5 );


	m_panel38->SetSizer( bSizer77 );
	m_panel38->Layout();
	bSizer77->Fit( m_panel38 );
	bSizer76->Add( m_panel38, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer76 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewParticleActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewParticleActor_Dialog::OnCreateButtonClicked ), NULL, this );
}

NewParticleActor_Dialog::~NewParticleActor_Dialog()
{
	// Disconnect Events
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewParticleActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewParticleActor_Dialog::OnCreateButtonClicked ), NULL, this );

}

NewTerrainActor_Dialog::NewTerrainActor_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxVERTICAL );

	m_panel38 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( m_panel38, wxID_ANY, wxT("Actor ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer78->Add( m_staticText33, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_actorID_textCtrl = new wxTextCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer78->Add( m_actorID_textCtrl, 4, wxALL, 5 );


	bSizer77->Add( bSizer78, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( m_panel38, wxID_ANY, wxT("Height Map"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer79->Add( m_staticText34, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );

	m_textureSearch_searchCtrl = new wxSearchCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_textureSearch_searchCtrl->ShowSearchButton( true );
	#endif
	m_textureSearch_searchCtrl->ShowCancelButton( false );
	bSizer81->Add( m_textureSearch_searchCtrl, 1, wxALL, 5 );


	bSizer79->Add( bSizer81, 4, wxEXPAND, 5 );


	bSizer77->Add( bSizer79, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxHORIZONTAL );


	bSizer80->Add( 0, 0, 1, wxEXPAND, 5 );

	m_texture_listBox = new wxListBox( m_panel38, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer80->Add( m_texture_listBox, 4, wxALL|wxEXPAND, 5 );


	bSizer77->Add( bSizer80, 9, wxEXPAND, 5 );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );


	bSizer82->Add( 0, 0, 1, wxEXPAND, 5 );

	m_cancel_button = new wxButton( m_panel38, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_cancel_button, 0, wxALL, 5 );

	m_create_button = new wxButton( m_panel38, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_create_button, 0, wxALL, 5 );


	bSizer77->Add( bSizer82, 0, wxEXPAND, 5 );


	m_panel38->SetSizer( bSizer77 );
	m_panel38->Layout();
	bSizer77->Fit( m_panel38 );
	bSizer76->Add( m_panel38, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer76 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_textureSearch_searchCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( NewTerrainActor_Dialog::OnSearchText ), NULL, this );
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewTerrainActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewTerrainActor_Dialog::OnCreateButtonClicked ), NULL, this );
}

NewTerrainActor_Dialog::~NewTerrainActor_Dialog()
{
	// Disconnect Events
	m_textureSearch_searchCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( NewTerrainActor_Dialog::OnSearchText ), NULL, this );
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewTerrainActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewTerrainActor_Dialog::OnCreateButtonClicked ), NULL, this );

}

NewWaterActor_Dialog::NewWaterActor_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxVERTICAL );

	m_panel38 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( m_panel38, wxID_ANY, wxT("Actor ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer78->Add( m_staticText33, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_actorID_textCtrl = new wxTextCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer78->Add( m_actorID_textCtrl, 4, wxALL, 5 );


	bSizer77->Add( bSizer78, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer297;
	bSizer297 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText101 = new wxStaticText( m_panel38, wxID_ANY, wxT("Wave Height"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	bSizer297->Add( m_staticText101, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_waveHeight_spinCtrlDouble = new wxSpinCtrlDouble( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 1 );
	m_waveHeight_spinCtrlDouble->SetDigits( 0 );
	bSizer297->Add( m_waveHeight_spinCtrlDouble, 4, wxALL, 5 );


	bSizer77->Add( bSizer297, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer2971;
	bSizer2971 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1011 = new wxStaticText( m_panel38, wxID_ANY, wxT("Wave Length"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1011->Wrap( -1 );
	bSizer2971->Add( m_staticText1011, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_waveLength_spinCtrlDouble = new wxSpinCtrlDouble( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 1 );
	m_waveLength_spinCtrlDouble->SetDigits( 0 );
	bSizer2971->Add( m_waveLength_spinCtrlDouble, 4, wxALL, 5 );


	bSizer77->Add( bSizer2971, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer2972;
	bSizer2972 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1012 = new wxStaticText( m_panel38, wxID_ANY, wxT("Wave Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1012->Wrap( -1 );
	bSizer2972->Add( m_staticText1012, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_waveSpeed_spinCtrlDouble = new wxSpinCtrlDouble( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 1 );
	m_waveSpeed_spinCtrlDouble->SetDigits( 0 );
	bSizer2972->Add( m_waveSpeed_spinCtrlDouble, 4, wxALL, 5 );


	bSizer77->Add( bSizer2972, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( m_panel38, wxID_ANY, wxT("Mesh ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer79->Add( m_staticText34, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );

	m_meshSearch_searchCtrl = new wxSearchCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_meshSearch_searchCtrl->ShowSearchButton( true );
	#endif
	m_meshSearch_searchCtrl->ShowCancelButton( false );
	bSizer81->Add( m_meshSearch_searchCtrl, 1, wxALL, 5 );


	bSizer79->Add( bSizer81, 4, wxEXPAND, 5 );


	bSizer77->Add( bSizer79, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxHORIZONTAL );


	bSizer80->Add( 0, 0, 1, wxEXPAND, 5 );

	m_mesh_listBox = new wxListBox( m_panel38, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer80->Add( m_mesh_listBox, 4, wxALL|wxEXPAND, 5 );


	bSizer77->Add( bSizer80, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );


	bSizer82->Add( 0, 0, 1, wxEXPAND, 5 );

	m_cancel_button = new wxButton( m_panel38, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_cancel_button, 0, wxALL, 5 );

	m_create_button = new wxButton( m_panel38, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_create_button, 0, wxALL, 5 );


	bSizer77->Add( bSizer82, 0, wxEXPAND, 5 );


	m_panel38->SetSizer( bSizer77 );
	m_panel38->Layout();
	bSizer77->Fit( m_panel38 );
	bSizer76->Add( m_panel38, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer76 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_meshSearch_searchCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( NewWaterActor_Dialog::OnSearchText ), NULL, this );
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewWaterActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewWaterActor_Dialog::OnCreateButtonClicked ), NULL, this );
}

NewWaterActor_Dialog::~NewWaterActor_Dialog()
{
	// Disconnect Events
	m_meshSearch_searchCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( NewWaterActor_Dialog::OnSearchText ), NULL, this );
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewWaterActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewWaterActor_Dialog::OnCreateButtonClicked ), NULL, this );

}

NewCubeActor_Dialog::NewCubeActor_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxVERTICAL );

	m_panel38 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( m_panel38, wxID_ANY, wxT("Actor ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer78->Add( m_staticText33, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_actorID_textCtrl = new wxTextCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer78->Add( m_actorID_textCtrl, 4, wxALL, 5 );


	bSizer77->Add( bSizer78, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer297;
	bSizer297 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText101 = new wxStaticText( m_panel38, wxID_ANY, wxT("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	bSizer297->Add( m_staticText101, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_size_spinCtrlDouble = new wxSpinCtrlDouble( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 5, 100, 5, 1 );
	m_size_spinCtrlDouble->SetDigits( 0 );
	bSizer297->Add( m_size_spinCtrlDouble, 4, wxALL, 5 );


	bSizer77->Add( bSizer297, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );


	bSizer82->Add( 0, 0, 1, wxEXPAND, 5 );

	m_cancel_button = new wxButton( m_panel38, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_cancel_button, 0, wxALL, 5 );

	m_create_button = new wxButton( m_panel38, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_create_button, 0, wxALL, 5 );


	bSizer77->Add( bSizer82, 0, wxEXPAND, 5 );


	m_panel38->SetSizer( bSizer77 );
	m_panel38->Layout();
	bSizer77->Fit( m_panel38 );
	bSizer76->Add( m_panel38, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer76 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewCubeActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewCubeActor_Dialog::OnCreateButtonClicked ), NULL, this );
}

NewCubeActor_Dialog::~NewCubeActor_Dialog()
{
	// Disconnect Events
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewCubeActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewCubeActor_Dialog::OnCreateButtonClicked ), NULL, this );

}

NewSphereActor_Dialog::NewSphereActor_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxVERTICAL );

	m_panel38 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( m_panel38, wxID_ANY, wxT("Actor ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer78->Add( m_staticText33, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_actorID_textCtrl = new wxTextCtrl( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer78->Add( m_actorID_textCtrl, 4, wxALL, 5 );


	bSizer77->Add( bSizer78, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer297;
	bSizer297 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText101 = new wxStaticText( m_panel38, wxID_ANY, wxT("Radius"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	bSizer297->Add( m_staticText101, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_radius_spinCtrlDouble = new wxSpinCtrlDouble( m_panel38, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 1 );
	m_radius_spinCtrlDouble->SetDigits( 0 );
	bSizer297->Add( m_radius_spinCtrlDouble, 4, wxALL, 5 );


	bSizer77->Add( bSizer297, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );


	bSizer82->Add( 0, 0, 1, wxEXPAND, 5 );

	m_cancel_button = new wxButton( m_panel38, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_cancel_button, 0, wxALL, 5 );

	m_create_button = new wxButton( m_panel38, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_create_button, 0, wxALL, 5 );


	bSizer77->Add( bSizer82, 0, wxEXPAND, 5 );


	m_panel38->SetSizer( bSizer77 );
	m_panel38->Layout();
	bSizer77->Fit( m_panel38 );
	bSizer76->Add( m_panel38, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer76 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewSphereActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewSphereActor_Dialog::OnCreateButtonClicked ), NULL, this );
}

NewSphereActor_Dialog::~NewSphereActor_Dialog()
{
	// Disconnect Events
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewSphereActor_Dialog::OnCancelButtonClicked ), NULL, this );
	m_create_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NewSphereActor_Dialog::OnCreateButtonClicked ), NULL, this );

}

CreateMesh_Dialog::CreateMesh_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer237;
	bSizer237 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer266;
	bSizer266 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText108 = new wxStaticText( this, wxID_ANY, wxT("Mesh ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText108->Wrap( -1 );
	bSizer266->Add( m_staticText108, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_meshID_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer266->Add( m_meshID_textCtrl, 4, wxALL, 5 );


	bSizer237->Add( bSizer266, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer238;
	bSizer238 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText86 = new wxStaticText( this, wxID_ANY, wxT("Shape"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText86->Wrap( -1 );
	bSizer238->Add( m_staticText86, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_shape_comboBox = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer238->Add( m_shape_comboBox, 4, wxALL, 5 );


	bSizer237->Add( bSizer238, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer239;
	bSizer239 = new wxBoxSizer( wxVERTICAL );

	m_shape_simplebook = new wxSimplebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_plane_panel = new wxPanel( m_shape_simplebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer240;
	bSizer240 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer241;
	bSizer241 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText87 = new wxStaticText( m_plane_panel, wxID_ANY, wxT("Tile Width"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText87->Wrap( -1 );
	bSizer241->Add( m_staticText87, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_planeTileWidth_spinCtrl = new wxSpinCtrl( m_plane_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 10 );
	bSizer241->Add( m_planeTileWidth_spinCtrl, 4, wxALL, 5 );


	bSizer240->Add( bSizer241, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer242;
	bSizer242 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText88 = new wxStaticText( m_plane_panel, wxID_ANY, wxT("Tile Height"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText88->Wrap( -1 );
	bSizer242->Add( m_staticText88, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_planeTileHeight_spinCtrl = new wxSpinCtrl( m_plane_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 10 );
	bSizer242->Add( m_planeTileHeight_spinCtrl, 4, wxALL, 5 );


	bSizer240->Add( bSizer242, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer243;
	bSizer243 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText89 = new wxStaticText( m_plane_panel, wxID_ANY, wxT("X Count"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText89->Wrap( -1 );
	bSizer243->Add( m_staticText89, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_planeCountX_spinCtrl = new wxSpinCtrl( m_plane_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 10 );
	bSizer243->Add( m_planeCountX_spinCtrl, 4, wxALL, 5 );


	bSizer240->Add( bSizer243, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer244;
	bSizer244 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText90 = new wxStaticText( m_plane_panel, wxID_ANY, wxT("Y Count"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText90->Wrap( -1 );
	bSizer244->Add( m_staticText90, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_planeCountY_spinCtrl = new wxSpinCtrl( m_plane_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 10 );
	bSizer244->Add( m_planeCountY_spinCtrl, 4, wxALL, 5 );


	bSizer240->Add( bSizer244, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer245;
	bSizer245 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText91 = new wxStaticText( m_plane_panel, wxID_ANY, wxT("Texture Repeat X"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	bSizer245->Add( m_staticText91, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_planeTxRepeatX_spinCtrl = new wxSpinCtrl( m_plane_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 10 );
	bSizer245->Add( m_planeTxRepeatX_spinCtrl, 4, wxALL, 5 );


	bSizer240->Add( bSizer245, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer246;
	bSizer246 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText92 = new wxStaticText( m_plane_panel, wxID_ANY, wxT("Texture Repeat Y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText92->Wrap( -1 );
	bSizer246->Add( m_staticText92, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_planeTxRepeatY_spinCtrl = new wxSpinCtrl( m_plane_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 10 );
	bSizer246->Add( m_planeTxRepeatY_spinCtrl, 4, wxALL, 5 );


	bSizer240->Add( bSizer246, 0, wxEXPAND, 5 );


	m_plane_panel->SetSizer( bSizer240 );
	m_plane_panel->Layout();
	bSizer240->Fit( m_plane_panel );
	m_shape_simplebook->AddPage( m_plane_panel, wxT("a page"), false );
	m_cone_panel = new wxPanel( m_shape_simplebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer248;
	bSizer248 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer249;
	bSizer249 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText93 = new wxStaticText( m_cone_panel, wxID_ANY, wxT("Radius"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText93->Wrap( -1 );
	bSizer249->Add( m_staticText93, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_coneRadius_spinCtrlDouble = new wxSpinCtrlDouble( m_cone_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 5, 1 );
	m_coneRadius_spinCtrlDouble->SetDigits( 0 );
	bSizer249->Add( m_coneRadius_spinCtrlDouble, 4, wxALL, 5 );


	bSizer248->Add( bSizer249, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer250;
	bSizer250 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText94 = new wxStaticText( m_cone_panel, wxID_ANY, wxT("Length"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText94->Wrap( -1 );
	bSizer250->Add( m_staticText94, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_coneLength_spinCtrlDouble = new wxSpinCtrlDouble( m_cone_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 20, 1 );
	m_coneLength_spinCtrlDouble->SetDigits( 0 );
	bSizer250->Add( m_coneLength_spinCtrlDouble, 4, wxALL, 5 );


	bSizer248->Add( bSizer250, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer251;
	bSizer251 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText95 = new wxStaticText( m_cone_panel, wxID_ANY, wxT("Tesselation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText95->Wrap( -1 );
	bSizer251->Add( m_staticText95, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_coneTesselation_spinCtrl = new wxSpinCtrl( m_cone_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 10 );
	bSizer251->Add( m_coneTesselation_spinCtrl, 4, wxALL, 5 );


	bSizer248->Add( bSizer251, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer252;
	bSizer252 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText96 = new wxStaticText( m_cone_panel, wxID_ANY, wxT("Top Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText96->Wrap( -1 );
	bSizer252->Add( m_staticText96, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_coneTopColor_colourPicker = new wxColourPickerCtrl( m_cone_panel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer252->Add( m_coneTopColor_colourPicker, 4, wxALL, 5 );


	bSizer248->Add( bSizer252, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer253;
	bSizer253 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText97 = new wxStaticText( m_cone_panel, wxID_ANY, wxT("Bottom Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText97->Wrap( -1 );
	bSizer253->Add( m_staticText97, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_coneBottomColor_colourPicker = new wxColourPickerCtrl( m_cone_panel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer253->Add( m_coneBottomColor_colourPicker, 4, wxALL, 5 );


	bSizer248->Add( bSizer253, 0, wxEXPAND, 5 );


	m_cone_panel->SetSizer( bSizer248 );
	m_cone_panel->Layout();
	bSizer248->Fit( m_cone_panel );
	m_shape_simplebook->AddPage( m_cone_panel, wxT("a page"), false );
	m_cylinder_panel = new wxPanel( m_shape_simplebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2481;
	bSizer2481 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2491;
	bSizer2491 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText931 = new wxStaticText( m_cylinder_panel, wxID_ANY, wxT("Radius"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText931->Wrap( -1 );
	bSizer2491->Add( m_staticText931, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_cylinderRadius_spinCtrlDouble = new wxSpinCtrlDouble( m_cylinder_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 10, 1 );
	m_cylinderRadius_spinCtrlDouble->SetDigits( 0 );
	bSizer2491->Add( m_cylinderRadius_spinCtrlDouble, 4, wxALL, 5 );


	bSizer2481->Add( bSizer2491, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer2501;
	bSizer2501 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText941 = new wxStaticText( m_cylinder_panel, wxID_ANY, wxT("Length"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText941->Wrap( -1 );
	bSizer2501->Add( m_staticText941, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_cylinderLength_spinCtrlDouble = new wxSpinCtrlDouble( m_cylinder_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 15, 1 );
	m_cylinderLength_spinCtrlDouble->SetDigits( 0 );
	bSizer2501->Add( m_cylinderLength_spinCtrlDouble, 4, wxALL, 5 );


	bSizer2481->Add( bSizer2501, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer2511;
	bSizer2511 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText951 = new wxStaticText( m_cylinder_panel, wxID_ANY, wxT("Tesselation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText951->Wrap( -1 );
	bSizer2511->Add( m_staticText951, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_cylinderTesselation_spinCtrl = new wxSpinCtrl( m_cylinder_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 10 );
	bSizer2511->Add( m_cylinderTesselation_spinCtrl, 4, wxALL, 5 );


	bSizer2481->Add( bSizer2511, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer2521;
	bSizer2521 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText961 = new wxStaticText( m_cylinder_panel, wxID_ANY, wxT("Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText961->Wrap( -1 );
	bSizer2521->Add( m_staticText961, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_cylinderColor_colourPicker = new wxColourPickerCtrl( m_cylinder_panel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer2521->Add( m_cylinderColor_colourPicker, 4, wxALL, 5 );


	bSizer2481->Add( bSizer2521, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer2531;
	bSizer2531 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText971 = new wxStaticText( m_cylinder_panel, wxID_ANY, wxT("Close Top"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText971->Wrap( -1 );
	bSizer2531->Add( m_staticText971, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_cylinderCloseTop_checkBox = new wxCheckBox( m_cylinder_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2531->Add( m_cylinderCloseTop_checkBox, 4, wxALL, 5 );


	bSizer2481->Add( bSizer2531, 0, wxEXPAND, 5 );


	m_cylinder_panel->SetSizer( bSizer2481 );
	m_cylinder_panel->Layout();
	bSizer2481->Fit( m_cylinder_panel );
	m_shape_simplebook->AddPage( m_cylinder_panel, wxT("a page"), false );

	bSizer239->Add( m_shape_simplebook, 1, wxEXPAND | wxALL, 5 );


	bSizer237->Add( bSizer239, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer247;
	bSizer247 = new wxBoxSizer( wxHORIZONTAL );


	bSizer247->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button89 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer247->Add( m_button89, 0, wxALL, 5 );

	m_button90 = new wxButton( this, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer247->Add( m_button90, 0, wxALL, 5 );


	bSizer237->Add( bSizer247, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer237 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_shape_comboBox->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( CreateMesh_Dialog::OnShapeSelected ), NULL, this );
	m_button89->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateMesh_Dialog::OnCancel ), NULL, this );
	m_button90->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateMesh_Dialog::OnCreate ), NULL, this );
}

CreateMesh_Dialog::~CreateMesh_Dialog()
{
	// Disconnect Events
	m_shape_comboBox->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( CreateMesh_Dialog::OnShapeSelected ), NULL, this );
	m_button89->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateMesh_Dialog::OnCancel ), NULL, this );
	m_button90->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateMesh_Dialog::OnCreate ), NULL, this );

}

SetCamera_Dialog::SetCamera_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer264;
	bSizer264 = new wxBoxSizer( wxVERTICAL );

	m_panel53 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer265;
	bSizer265 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer266;
	bSizer266 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText105 = new wxStaticText( m_panel53, wxID_ANY, wxT("Position"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText105->Wrap( -1 );
	bSizer266->Add( m_staticText105, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_staticText108 = new wxStaticText( m_panel53, wxID_ANY, wxT("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText108->Wrap( -1 );
	bSizer266->Add( m_staticText108, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_posX_textCtrl = new wxTextCtrl( m_panel53, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer266->Add( m_posX_textCtrl, 0, wxALL, 5 );

	m_staticText109 = new wxStaticText( m_panel53, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText109->Wrap( -1 );
	bSizer266->Add( m_staticText109, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_posY_textCtrl = new wxTextCtrl( m_panel53, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer266->Add( m_posY_textCtrl, 0, wxALL, 5 );

	m_staticText110 = new wxStaticText( m_panel53, wxID_ANY, wxT("Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText110->Wrap( -1 );
	bSizer266->Add( m_staticText110, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_posZ_textCtrl = new wxTextCtrl( m_panel53, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer266->Add( m_posZ_textCtrl, 0, wxALL, 5 );


	bSizer265->Add( bSizer266, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer2661;
	bSizer2661 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1051 = new wxStaticText( m_panel53, wxID_ANY, wxT("Rotation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1051->Wrap( -1 );
	bSizer2661->Add( m_staticText1051, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_staticText111 = new wxStaticText( m_panel53, wxID_ANY, wxT("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	bSizer2661->Add( m_staticText111, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_rotX_textCtrl = new wxTextCtrl( m_panel53, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2661->Add( m_rotX_textCtrl, 0, wxALL, 5 );

	m_staticText112 = new wxStaticText( m_panel53, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText112->Wrap( -1 );
	bSizer2661->Add( m_staticText112, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_rotY_textCtrl = new wxTextCtrl( m_panel53, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2661->Add( m_rotY_textCtrl, 0, wxALL, 5 );

	m_staticText113 = new wxStaticText( m_panel53, wxID_ANY, wxT("Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText113->Wrap( -1 );
	bSizer2661->Add( m_staticText113, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_rotZ_textCtrl = new wxTextCtrl( m_panel53, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer2661->Add( m_rotZ_textCtrl, 0, wxALL, 5 );


	bSizer265->Add( bSizer2661, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer270;
	bSizer270 = new wxBoxSizer( wxHORIZONTAL );


	bSizer270->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button94 = new wxButton( m_panel53, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer270->Add( m_button94, 0, wxALL, 5 );

	m_button95 = new wxButton( m_panel53, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer270->Add( m_button95, 0, wxALL, 5 );


	bSizer265->Add( bSizer270, 0, wxEXPAND, 5 );


	m_panel53->SetSizer( bSizer265 );
	m_panel53->Layout();
	bSizer265->Fit( m_panel53 );
	bSizer264->Add( m_panel53, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer264 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button94->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetCamera_Dialog::OnCancel ), NULL, this );
	m_button95->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetCamera_Dialog::OnSet ), NULL, this );
}

SetCamera_Dialog::~SetCamera_Dialog()
{
	// Disconnect Events
	m_button94->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetCamera_Dialog::OnCancel ), NULL, this );
	m_button95->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetCamera_Dialog::OnSet ), NULL, this );

}
