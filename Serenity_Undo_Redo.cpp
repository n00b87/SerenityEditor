#include "SerenityEditorSerenity3D_Frame.h"



Serenity_StageAction SerenityEditorSerenity3D_Frame::stage_action_getCurrentActionState(Serenity_StageAction n_action)
{
    Serenity_StageAction current_action = n_action;

    for(int i = 0; i < current_action.action_actor.size(); i++)
    {
        int stage_index = current_action.action_actor[i].stage_index;
        int actor_index = current_action.action_actor[i].stage_actor_index;

        if(stage_index < 0 || stage_index >= project.stages.size())
            continue;

        if(actor_index < 0 || actor_index >= project.stages[stage_index].actors.size())
            continue;

        current_action.action_actor[i].actor_state = project.stages[stage_index].actors[actor_index];
    }

    return current_action;
}


void SerenityEditorSerenity3D_Frame::stage_action_createActor(Serenity_StageAction n_action)
{
    for(int i = 0; i < n_action.action_actor.size(); i++)
    {
        int stage_index = n_action.action_actor[i].stage_index;

        if(stage_index < 0 || stage_index >= project.stages.size())
            continue;


        n_action.action_actor[i].actor_state.node = NULL;

        int actor_project_index = n_action.action_actor[i].stage_actor_index;

        project.stages[stage_index].actors[actor_project_index] = n_action.action_actor[i].actor_state;


        Serenity_StageNode s_actor_node;
        s_actor_node.node_type = RC_STAGE_NODE_ACTOR;
        s_actor_node.group_label = _("");
        s_actor_node.active = false;
        s_actor_node.project_index = actor_project_index; //index in stage.actors

        int stage_node_index = -1;
        for(int n = 0; n < stage_tree_nodes.size(); n++)
        {
            if(stage_tree_nodes[n].node_type == RC_STAGE_NODE_NONE)
                continue;

            if(stage_tree_nodes[n].project_index == stage_index)
            {
                stage_node_index = n;
                break;
            }
        }

        int actor_node_index = -1;

        if(stage_node_index >= 0)
        {
            int group_node_index = -1;

            for(int g = 0; g < stage_tree_nodes[stage_node_index].groups.size(); g++)
            {
                if(stage_tree_nodes[stage_node_index].groups[g].node_type == RC_STAGE_NODE_NONE)
                    continue;

                if(n_action.action_actor[i].actor_state.group_name.compare(stage_tree_nodes[stage_node_index].groups[g].group_label)==0)
                {
                    group_node_index = g;
                    break;
                }
            }


            if(group_node_index >= 0)
            {
                wxTreeItemId group_item = stage_tree_nodes[stage_node_index].groups[group_node_index].tree_item;

                s_actor_node.tree_item = m_project_stage_treeCtrl->AppendItem(group_item, wxString(n_action.action_actor[i].actor_state.id_name), stage_tree_assetImage);
                s_actor_node.parent_item = group_item;

                actor_node_index = stage_tree_nodes[stage_node_index].actors.size();
                stage_tree_nodes[stage_node_index].actors.push_back(s_actor_node);
            }
            else
            {
                //std::cout << "DEBUG: ACTOR_ID = " << n_action.action_actor[i].actor_state.id_name << std::endl;
                s_actor_node.parent_item = stage_tree_nodes[stage_node_index].tree_item;
                s_actor_node.tree_item = m_project_stage_treeCtrl->AppendItem(s_actor_node.parent_item, wxString::FromUTF8(n_action.action_actor[i].actor_state.id_name), stage_tree_assetImage );

                actor_node_index = stage_tree_nodes[stage_node_index].actors.size();
                stage_tree_nodes[stage_node_index].actors.push_back(s_actor_node);

                //std::cout << "DEBUG: NEW NODE = " << actor_node_index << std::endl;
            }
        }



        //Update actor in current scene
        if(stage_index == stageTab_active_stage_project_index)
            refresh_actor(actor_project_index);
    }

	if(stage_window)
	{
		stage_window->selected_actors.clear();
	}

}

void SerenityEditorSerenity3D_Frame::stage_action_deleteActor(Serenity_StageAction n_action)
{
    for(int action_actor_index = 0; action_actor_index < n_action.action_actor.size(); action_actor_index++)
    {
        int stage_project_index = n_action.action_actor[action_actor_index].stage_index;
        int actor_project_index = n_action.action_actor[action_actor_index].stage_actor_index;

        if(stage_project_index < 0 || stage_project_index >= project.stages.size())
            continue;

        if(actor_project_index < 0 || actor_project_index >= project.stages[stage_project_index].actors.size())
            continue;

        int s_node_index = -1;
        int a_node_index = -1;


        for(int stage_node_index = 0; stage_node_index < stage_tree_nodes.size(); stage_node_index++)
        {
            for(int i = 0; i < stage_tree_nodes[stage_node_index].actors.size(); i++)
            {
                if(stage_tree_nodes[stage_node_index].actors[i].node_type == RC_STAGE_NODE_NONE)
                    continue;

                if(stage_tree_nodes[stage_node_index].actors[i].project_index == actor_project_index)
                {
                    s_node_index = stage_node_index;
                    a_node_index = i;
                    break;
                }
            }
        }


        delete_actor(stage_project_index, actor_project_index);

        if(a_node_index >= 0)
        {
            //std::cout << "DEBUG: DELETE NODE" << std::endl;
            m_project_stage_treeCtrl->Delete(stage_tree_nodes[s_node_index].actors[a_node_index].tree_item);
            stage_tree_nodes[s_node_index].actors[a_node_index].node_type = RC_STAGE_NODE_NONE;
            stage_tree_nodes[s_node_index].actors[a_node_index].active = false;
            stage_tree_nodes[s_node_index].actors[a_node_index].actors.clear();
            stage_tree_nodes[s_node_index].actors[a_node_index].groups.clear();
            stage_tree_nodes[s_node_index].actors[a_node_index].group_label = _("");
            stage_tree_nodes[s_node_index].actors[a_node_index].project_index = -1;
            stage_tree_nodes[s_node_index].actors[a_node_index].stage_group = -1;
        }

        if(stage_window)
        {
            stage_window->selected_actors.clear();
        }
    }

    m_project_stage_treeCtrl->SelectItem(m_project_stage_treeCtrl->GetRootItem());
}

void SerenityEditorSerenity3D_Frame::stage_action_copyActor(Serenity_StageAction n_action)
{
    stage_action_createActor(n_action);
}

void SerenityEditorSerenity3D_Frame::stage_action_transformActor(Serenity_StageAction n_action)
{
    for(int i = 0; i < n_action.action_actor.size(); i++)
    {
        int stage_index = n_action.action_actor[i].stage_index;

        if(stage_index < 0 || stage_index >= project.stages.size())
            continue;


        n_action.action_actor[i].actor_state.node = NULL;

        int actor_project_index = n_action.action_actor[i].stage_actor_index;

        if(actor_project_index < 0 || actor_project_index >= project.stages[stage_index].actors.size())
            continue;

        if(project.stages[stage_index].actors[actor_project_index].node)
        {
            //std::cout << "TEST: " << n_action.action_actor[i].actor_state.position.X << std::endl;
            project.stages[stage_index].actors[actor_project_index].node->setPosition(n_action.action_actor[i].actor_state.position);
            project.stages[stage_index].actors[actor_project_index].node->setRotation(n_action.action_actor[i].actor_state.rotation);
            project.stages[stage_index].actors[actor_project_index].node->setScale(n_action.action_actor[i].actor_state.scale);
            project.stages[stage_index].actors[actor_project_index].node->updateAbsolutePosition();

            project.stages[stage_index].actors[actor_project_index].position = n_action.action_actor[i].actor_state.position;
            project.stages[stage_index].actors[actor_project_index].rotation = n_action.action_actor[i].actor_state.rotation;
            project.stages[stage_index].actors[actor_project_index].scale = n_action.action_actor[i].actor_state.scale;
        }
    }
}

void SerenityEditorSerenity3D_Frame::stage_action_editActor(Serenity_StageAction n_action)
{

}


void SerenityEditorSerenity3D_Frame::stage_action_terrainBrush(Serenity_StageAction n_action)
{
    if(n_action.action_actor.size() <= 0)
        return;

    int stage_index = n_action.action_actor[0].stage_index;
    int actor_index = n_action.action_actor[0].stage_actor_index;

    if(stage_index < 0 || stage_index >= project.stages.size())
        return;

    if(actor_index < 0 || actor_index >= project.stages[stage_index].actors.size())
        return;

    if(!project.stages[stage_index].actors[actor_index].node)
        return;

    irr::scene::ITerrainSceneNode* terrain = (irr::scene::ITerrainSceneNode*) project.stages[stage_index].actors[actor_index].node;
    IMesh* pMesh = terrain->getMesh();


    for (int b=0; b < pMesh->getMeshBufferCount(); ++b)
    {
        irr::scene::IMeshBuffer* pMeshBuffer = pMesh->getMeshBuffer(b);
        // skip mesh buffers that are not the right type
        if (pMeshBuffer->getVertexType() != video::EVT_2TCOORDS) continue;

        video::S3DVertex2TCoords* pVertices = (video::S3DVertex2TCoords*)pMeshBuffer->getVertices();

        if(b >= n_action.action_actor[0].t_buffer.size())
            break;

        if(n_action.action_actor[0].t_buffer[b].t_vertices.size() != pMeshBuffer->getVertexCount())
            break;

        //std::cout << "BV: " << b << ", " << pMeshBuffer->getVertexCount() << std::endl;

        for(int i = 0; i < pMeshBuffer->getVertexCount(); i++)
        {
            pVertices[i] = n_action.action_actor[0].t_buffer[b].t_vertices[i];
        }
    }

    // force terrain render buffer to reload
    terrain->setPosition(terrain->getPosition());

    //std::cout << "TERRAIN U/R" << std::endl;
}


void SerenityEditorSerenity3D_Frame::stage_undo()
{
    Serenity_StageAction n_action;
    Serenity_StageAction current_action_state;

    if(undo_buffer.size() == 0)
    {
        return;
    }

    n_action = undo_buffer.top();
    undo_buffer.pop();

    current_action_state = stage_action_getCurrentActionState(n_action);

    switch(n_action.action_type)
    {
        // If the last action was create then delete action items
        case STAGE_ACTION_CREATE_ACTOR:
            stage_action_deleteActor(n_action);
        break;

        case STAGE_ACTION_DELETE_ACTOR:
            stage_action_createActor(n_action);
        break;

        case STAGE_ACTION_COPY_ACTOR:
            stage_action_deleteActor(n_action);
        break;

        case STAGE_ACTION_UNCOPY_ACTOR:
            stage_action_copyActor(n_action);
        break;

        case STAGE_ACTION_TRANSFORM_ACTOR:
            stage_action_transformActor(n_action);
        break;

        case STAGE_ACTION_EDIT_ACTOR:
            stage_action_editActor(n_action);
        break;

        case STAGE_ACTION_TERRAIN_BRUSH:
            stage_action_terrainBrush(n_action);
        break;
    }


    redo_buffer.push(current_action_state);
}

void SerenityEditorSerenity3D_Frame::stage_redo()
{
    Serenity_StageAction n_action;
    Serenity_StageAction current_action_state;

    if(redo_buffer.size() == 0)
    {
        return;
    }

    n_action = redo_buffer.top();
    redo_buffer.pop();

    current_action_state = stage_action_getCurrentActionState(n_action);

    switch(n_action.action_type)
    {
        // If the last action was create then delete action items
        case STAGE_ACTION_CREATE_ACTOR:
            stage_action_createActor(n_action);
        break;

        case STAGE_ACTION_DELETE_ACTOR:
            stage_action_deleteActor(n_action);
        break;

        case STAGE_ACTION_COPY_ACTOR:
            stage_action_copyActor(n_action);
        break;

        case STAGE_ACTION_UNCOPY_ACTOR:
            stage_action_deleteActor(n_action);
        break;

        case STAGE_ACTION_TRANSFORM_ACTOR:
            stage_action_transformActor(n_action);
        break;

        case STAGE_ACTION_EDIT_ACTOR:
            stage_action_editActor(n_action);
        break;

        case STAGE_ACTION_TERRAIN_BRUSH:
            stage_action_terrainBrush(n_action);
        break;
    }


    undo_buffer.push(current_action_state);
}


void SerenityEditorSerenity3D_Frame::clear_undo()
{
    while(!undo_buffer.empty()) undo_buffer.pop();

    //std::cout << "undo clear" << std::endl;
}

void SerenityEditorSerenity3D_Frame::clear_redo()
{
    while(!redo_buffer.empty()) redo_buffer.pop();

    //std::cout << "redo clear" << std::endl;
}
