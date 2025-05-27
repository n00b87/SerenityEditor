/***************************************************************
 * Name:      SerenityEngineApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-10-21
 * Copyright:  ()
 * License:
 **************************************************************/

#include <wx/wx.h>
#include <wx/stdpaths.h>

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

    #ifdef _WIN32
    frame->SetIcon(wxIcon(aaaa));
    #else
    wxString editor_path = wxStandardPaths::Get().GetExecutablePath();

    wxFileName image_fname(editor_path);
	image_fname.AppendDir(_("icons"));

	wxFileName app_icon = image_fname;
	app_icon.SetFullName(_("serenity.ico"));
	frame->SetIcon(wxIcon(app_icon.GetAbsolutePath()));
    #endif // _WIN32

    frame->Show();

    return true;
}
