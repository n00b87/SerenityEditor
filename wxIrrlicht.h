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

#include <irrlicht.h>
#include <wx/wx.h>
#include <wx/glcanvas.h>
#include "CGridSceneNode.h"
#include "camera.h"
#include "gui_freetype_font.h"

#define MAX_FONTS 8

struct viewport_camera
{
	Camera camera;
	irr::video::ITexture* texture;
	irr::video::ITexture* ui_layer;
	int pov;
	int x;
	int y;
	int w;
	int h;
	CGridSceneNode * gridSceneNode;
};

struct font_obj
{
    CGUITTFace* face;
    CGUIFreetypeFont* font;
    int font_size;
    bool active = false;
};

class wxIrrlicht : public wxControl {
	public:
		wxIrrlicht(wxWindow* parent, wxWindowID id, bool bs=true, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = wxPanelNameStr);
		~wxIrrlicht();

        void InitIrr(irr::SIrrlichtCreationParameters* init_params = 0);
        //void InitIrr(irr::IrrlichtDevice* device);

        void StartRendering(int milliseconds = 10);
        void StopRendering();
        void Render();
        virtual void OnCreateScene();
        virtual void OnPreRender() {}
        virtual void OnRender();
        virtual void OnPostRender();

        void force_refresh();

        irr::IrrlichtDevice* GetDevice() const { return m_pDevice; }
        irr::video::IVideoDriver* GetVideoDriver() const { return m_pDriver; }
        irr::scene::ISceneManager* GetSceneManager() const { return m_pSceneManager; }
        irr::scene::ICameraSceneNode* GetCameraNode() const { return m_pCameraNode; }
        irr::gui::IGUIEnvironment* GetGuiEnvironment() const { return m_pGuiEnvironment; }

        wxWindow* parent_window;
        wxGLCanvas* canvas;

        viewport_camera camera[4];
        int active_camera = 0;
        double material_view_camera_speed = 0.2;
        int num_views = 1; //will either be 1 or 4

        font_obj font[MAX_FONTS];
        int active_font = -1;

        irr::f32 grid_size = 2500;
        irr::f32 grid_spacing = 100;
        irr::video::SColor grid_color;
        bool grid_visible = true;

        void setGridSize(irr::f32 g_size);
        void setGridSpacing(irr::f32 g_spacing);
        void setGridColor(irr::u32 g_color);

        int irr_LoadFont(std::string font_file, int font_size);
        void irr_DrawText(std::string txt, int x, int y, irr::video::SColor color);
        void irr_DeleteFont(int font_id);
        void irr_SetFont(int font_id);

        irr::video::ITexture* back_buffer;


        int window_type = 0;
        irr::video::ITexture* view2D_texture;

	//protected:
        void OnPaint(wxPaintEvent& event);
        void OnSize(wxSizeEvent& event);
        void OnParentSize(wxSizeEvent& event);
        void OnEraseBackground(wxEraseEvent& event) {}
        void OnTimer(wxTimerEvent& event);
        void OnMouse(wxMouseEvent& event);
        void OnKey(wxKeyEvent& event);

        void SetCameraViewParam();
        void SetViews(int view_flag, int view0_pov=-1, int view1_pov=-1, int view2_pov=-1, int view3_pov=-1);

        void OnUpdate();

        void AnimationPreview_Update();

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
        bool rendering;
        bool m_init = false;

        wxPoint drag_start;
        wxPoint mouse_position;
        bool middle_drag_init = false;
        bool left_drag_init = false;
        bool right_drag_init = false;

        int cam_move_speed = 5;

        bool VIEW_KEY_W = false;
        bool VIEW_KEY_A = false;
        bool VIEW_KEY_S = false;
        bool VIEW_KEY_D = false;

        #ifdef __linux__
        GdkWindow* gdkWindow;
        #endif // __linux__

		enum {
			ID_IRR_TIMER=1000
		};

    private:
		//DECLARE_EVENT_TABLE();

};//wxIrrlicht

#endif
