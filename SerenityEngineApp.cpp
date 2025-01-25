/***************************************************************
 * Name:      SerenityEngineApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-10-21
 * Copyright:  ()
 * License:
 **************************************************************/

#include <wx/wx.h>

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "SerenityEngineApp.h"
#include "SerenityEditorSerenity3D_Frame.h"

IMPLEMENT_APP(SerenityEngineApp);

bool SerenityEngineApp::OnInit()
{
	wxInitAllImageHandlers();
    SerenityEditorSerenity3D_Frame* frame = new SerenityEditorSerenity3D_Frame(NULL);

    frame->Show();

    return true;
}
