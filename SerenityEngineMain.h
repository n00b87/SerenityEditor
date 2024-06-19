/***************************************************************
 * Name:      SerenityEngineMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-10-21
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef SERENITYENGINEMAIN_H
#define SERENITYENGINEMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "SerenityEngineApp.h"

class SerenityEngineFrame: public wxFrame
{
    public:
        SerenityEngineFrame(wxFrame *frame, const wxString& title);
        ~SerenityEngineFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // SERENITYENGINEMAIN_H
