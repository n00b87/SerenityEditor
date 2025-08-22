#include "SerenityEditor_FXVariable_Dialog.h"
#include "rc_stage.h"

SerenityEditor_FXVariable_Dialog::SerenityEditor_FXVariable_Dialog( wxWindow* parent )
:
FXVariable_Dialog( parent )
{
    bool set_flag = false;

    m_variable_comboBox->Insert(_("Alpha"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("Amplitude"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("BaseColor"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("BassFrequency"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("Beat"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("BViewSpace"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("Color"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("CoolColor"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("Depth"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("DiffuseCool"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("DiffuseWarm"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("EnableLighting"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("FrameHeight"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("FrameWidth"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("fvAmbient"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("fvDiffuse"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("fvSpecular"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("fSpecularPower"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("Intensity"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("MixRatio"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("PulseSharpness"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("SilhouetteColor"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("SilhouetteThreshold"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("SurfaceColor"), m_variable_comboBox->GetCount());
    m_variable_comboBox->Insert(_("WarmColor"), m_variable_comboBox->GetCount());
}

void SerenityEditor_FXVariable_Dialog::OnVariableChange( wxCommandEvent& event )
{
    if(m_variable_comboBox->GetStringSelection().compare(_("Alpha")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("Amplitude")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("BaseColor")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC3;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("BassFrequency")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("Beat")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("BViewSpace")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("Color")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC4;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("CoolColor")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC3;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("Depth")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("DiffuseCool")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("DiffuseWarm")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("EnableLighting")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("FrameHeight")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("FrameWidth")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("fvAmbient")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC4;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("fvDiffuse")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC4;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("fvSpecular")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC4;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("fSpecularPower")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("Intensity")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("MixRatio")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("PulseSharpness")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("SilhouetteColor")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC4;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("SilhouetteThreshold")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("SurfaceColor")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC3;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("WarmColor")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC3;
    }

    int none_panel_index = 0;
    int float_panel_index = -1;
    int color_panel_index = -1;

    for(int i = 0; i < m_vtype_simplebook->GetPageCount(); i++)
    {
        if(m_vtype_simplebook->GetPage(i)==m_type_float_panel)
        {
            float_panel_index = i;
        }
        else if(m_vtype_simplebook->GetPage(i)==m_type_color_panel)
        {
            color_panel_index = i;
        }
    }

    if(float_panel_index < 0 || color_panel_index < 0)
        return;

    switch(var_type)
    {
        case RC_FX_CONSTANT_TYPE_FLOAT:
        {
            m_vtype_simplebook->SetSelection(float_panel_index);
        }
        break;

        case RC_FX_CONSTANT_TYPE_VEC3:
        case RC_FX_CONSTANT_TYPE_VEC4:
        {
            m_vtype_simplebook->SetSelection(color_panel_index);
        }
        break;

        default:
        {
            m_vtype_simplebook->SetSelection(none_panel_index);
        }
        break;
    }
}

void SerenityEditor_FXVariable_Dialog::OnCancel( wxCommandEvent& event )
{
    Close();
}

void SerenityEditor_FXVariable_Dialog::OnSet( wxCommandEvent& event )
{
    f_name = m_variable_comboBox->GetStringSelection().Trim();

    switch(var_type)
    {
        case RC_FX_CONSTANT_TYPE_FLOAT:
        {
            f_value[0] = m_float_value_spinCtrlDouble->GetValue();
        }
        break;

        case RC_FX_CONSTANT_TYPE_VEC3:
        case RC_FX_CONSTANT_TYPE_VEC4:
        {
            wxColour v_color = m_color_value_colourPicker->GetColour();
            f_value[0] = ((double)v_color.GetRed()) / 255.0;
            f_value[1] = ((double)v_color.GetGreen()) / 255.0;
            f_value[2] = ((double)v_color.GetBlue()) / 255.0;
            f_value[3] = ((double)v_color.GetAlpha()) / 255.0;
        }
    }

    set_flag = true;
    Close();
}

void SerenityEditor_FXVariable_Dialog::initTitle(wxString title_str)
{
    SetTitle(title_str);
}

void SerenityEditor_FXVariable_Dialog::initVariable(wxString var_name, double n1, double n2, double n3, double n4)
{
    for(int i = 0; i < m_variable_comboBox->GetCount(); i++)
    {
        if(m_variable_comboBox->GetString(i).Trim().compare(var_name.Trim())==0)
        {
            m_variable_comboBox->SetSelection(i);
            break;
        }
    }


    if(m_variable_comboBox->GetStringSelection().compare(_("Alpha")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("Amplitude")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("BaseColor")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC3;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("BassFrequency")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("Beat")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("BViewSpace")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("Color")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC4;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("CoolColor")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC3;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("Depth")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("DiffuseCool")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("DiffuseWarm")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("EnableLighting")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("FrameHeight")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("FrameWidth")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("fvAmbient")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC4;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("fvDiffuse")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC4;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("fvSpecular")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC4;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("fSpecularPower")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("Intensity")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("MixRatio")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("PulseSharpness")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("SilhouetteColor")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC4;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("SilhouetteThreshold")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_FLOAT;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("SurfaceColor")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC3;
    }
    else if(m_variable_comboBox->GetStringSelection().compare(_("WarmColor")) == 0)
    {
        var_type = RC_FX_CONSTANT_TYPE_VEC3;
    }

    int none_panel_index = 0;
    int float_panel_index = -1;
    int color_panel_index = -1;

    for(int i = 0; i < m_vtype_simplebook->GetPageCount(); i++)
    {
        if(m_vtype_simplebook->GetPage(i)==m_type_float_panel)
        {
            float_panel_index = i;
        }
        else if(m_vtype_simplebook->GetPage(i)==m_type_color_panel)
        {
            color_panel_index = i;
        }
    }

    if(float_panel_index < 0 || color_panel_index < 0)
        return;

    switch(var_type)
    {
        case RC_FX_CONSTANT_TYPE_FLOAT:
        {
            m_vtype_simplebook->SetSelection(float_panel_index);
        }
        break;

        case RC_FX_CONSTANT_TYPE_VEC3:
        case RC_FX_CONSTANT_TYPE_VEC4:
        {
            m_vtype_simplebook->SetSelection(color_panel_index);
        }
        break;

        default:
        {
            m_vtype_simplebook->SetSelection(none_panel_index);
        }
        break;
    }


    switch(var_type)
    {
        case RC_FX_CONSTANT_TYPE_FLOAT:
        {
            m_float_value_spinCtrlDouble->SetValue(n1);
        }
        break;

        case RC_FX_CONSTANT_TYPE_VEC3:
        case RC_FX_CONSTANT_TYPE_VEC4:
        {
            m_color_value_colourPicker->SetColour( wxColour( (int) (n1*255.0), (int) (n2*255.0), (int) (n3*255.0), (int) (n4*255.0) ) );
        }
    }
}
