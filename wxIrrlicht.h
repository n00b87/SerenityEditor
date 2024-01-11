/* wxirrlicht.h -- A wxWidgets control that embeds the 'Irrlicht Engine'.

  Copyright (C) 2006 Yiannis Mandravellos <mandrav@codeblocks.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  ChangeLog
  ---------
    2 Sep 2006:
      * Original version released.
*/

/*
  2007/12/12
  	* changed version by loptr (devy@sourceforge.net)
*/

/*
  6 Jan 2024
  * n00b Edition - Updated to support GTK3 on linux
*/

#ifndef __LOPTRIRR_H__
#define __LOPTRIRR_H__

#ifdef _WIN32
#include <windows.h>
#endif //WINDOWS

#include <irrlicht/irrlicht.h>
#include <wx/wx.h>


class wxIrrlicht : public wxControl {
	public:
		wxIrrlicht(wxWindow* parent, wxWindowID id, bool bs=true, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = wxPanelNameStr);
		~wxIrrlicht();

        void InitIrr(irr::SIrrlichtCreationParameters* init_params = 0);
        void StartRendering(int milliseconds = 10);
        void StopRendering();
        void Render();
        virtual void OnCreateScene();
        virtual void OnPreRender() {}
        virtual void OnRender();
        virtual void OnPostRender();

        irr::IrrlichtDevice* GetDevice() const { return m_pDevice; }
        irr::video::IVideoDriver* GetVideoDriver() const { return m_pDriver; }
        irr::scene::ISceneManager* GetSceneManager() const { return m_pSceneManager; }
        irr::scene::ICameraSceneNode* GetCameraNode() const { return m_pCameraNode; }
        irr::gui::IGUIEnvironment* GetGuiEnvironment() const { return m_pGuiEnvironment; }

        wxWindow* parent_window;

	protected:
        void OnPaint(wxPaintEvent& event);
        void OnSize(wxSizeEvent& event);
        void OnParentSize(wxSizeEvent& event);
        void OnEraseBackground(wxEraseEvent& event) {}
        void OnTimer(wxTimerEvent& event);
        void OnMouse(wxMouseEvent& event);
        void OnKey(wxKeyEvent& event);

        irr::IrrlichtDevice* m_pDevice;
        irr::video::IVideoDriver* m_pDriver;
        irr::scene::ISceneManager* m_pSceneManager;
        irr::gui::IGUIEnvironment* m_pGuiEnvironment;
        irr::scene::ICameraSceneNode* m_pCameraNode;
		wxTimer m_Timer;
        irr::gui::IGUIStaticText* m_pFPSText;
        bool m_showFPS;
        bool m_windowIsActive;
        bool m_forceWindowInActive;
        bool m_forceWindowActive;

		enum {
			ID_IRR_TIMER=1000
		};

    private:
		DECLARE_EVENT_TABLE();

};//wxIrrlicht

#endif
