#include <wx/wx.h>

#ifdef _WIN32
#include <windows.h>
#endif // WINDOWS

#ifdef __linux__
#include <gdk/gdk.h>
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#include <X11/Xlib.h>
#endif // __linux__

#include <irrlicht/irrlicht.h>
#include "wxIrrlicht.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

BEGIN_EVENT_TABLE(wxIrrlicht, wxControl)
    EVT_TIMER(ID_IRR_TIMER, wxIrrlicht::OnTimer)
    EVT_SIZE(wxIrrlicht::OnSize)
    EVT_PAINT(wxIrrlicht::OnPaint)
    EVT_ERASE_BACKGROUND(wxIrrlicht::OnEraseBackground)
    EVT_MOUSE_EVENTS(wxIrrlicht::OnMouse)
    EVT_KEY_DOWN(wxIrrlicht::OnKey)
    EVT_KEY_UP(wxIrrlicht::OnKey)
END_EVENT_TABLE()

wxIrrlicht::wxIrrlicht(wxWindow* parent, wxWindowID id, bool bs, const wxPoint& pos, const wxSize& size, long style, const wxString& name)
	: wxControl(parent, id, pos, size, style, wxDefaultValidator, name),
	m_pDevice(0),
    m_pDriver(0),
    m_pSceneManager(0),
    m_pGuiEnvironment(0),
    m_pCameraNode(0),
    m_Timer(this, ID_IRR_TIMER),
    m_pFPSText(0),
	m_showFPS(bs) {
	    SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	    parent_window = parent;
}//ctor

wxIrrlicht::~wxIrrlicht() {
	m_pDevice->drop();
}//dtor


void wxIrrlicht::InitIrr(irr::SIrrlichtCreationParameters* init_params) {
    SIrrlichtCreationParameters params;
    params.DriverType = EDT_OPENGL;

    SIrrlichtCreationParameters* actual_params = init_params ? init_params : &params;
    dimension2d<u32> irrSize(GetClientSize().GetX(), GetClientSize().GetY());
    actual_params->WindowSize = irrSize;

#ifdef __linux__
    wxWindow* renderPanel = parent_window;
    GtkWidget* widget = renderPanel->GetHandle();

    if(!widget)
    {
        wxMessageBox(_("Could not get window handle"));
        return;
    }

    if (!gtk_widget_get_realized(widget)) {
            gtk_widget_realize(widget);
    }


    GdkWindow* gdkWindow = gtk_widget_get_window(widget);

    Window xid;

    if (gdkWindow)
    {
        xid = GDK_WINDOW_XID(gdkWindow);
    }
    else
    {
        wxMessageBox(_("Could not get window ID"));
        return;
    }

    actual_params->WindowId = reinterpret_cast<void*>(xid);

#endif

#ifdef _WIN32
actual_params->WindowId = (HWND)this->GetHandle();
#endif // _WIN32


    m_pDevice = createDeviceEx(*actual_params);


    if (!m_pDevice) {
        throw "Can't create Irrlicht device!";
	}//if

	m_pDriver = m_pDevice->getVideoDriver();
	m_pSceneManager = m_pDevice->getSceneManager();
	m_pGuiEnvironment = m_pDevice->getGUIEnvironment();
    m_pDriver->OnResize(irrSize);

    parent_window->Connect( wxEVT_SIZE, wxSizeEventHandler( wxIrrlicht::OnParentSize ), NULL, this );
    m_forceWindowActive = true;
	Refresh();

}//InitIrr()

void wxIrrlicht::StartRendering(int milliseconds) {
    m_Timer.Start(milliseconds);
}//StartRendering()

void wxIrrlicht::StopRendering(){
    m_Timer.Stop();
}//StopRendering()

void wxIrrlicht::Render() {
    static bool rendering = false;

    if (rendering || !m_pDevice->run()) {
        return;
	}//if


    if(this->GetScreenRect().Contains( wxGetMousePosition() ))
        m_windowIsActive = true;
    else
        m_windowIsActive = false;

    if(m_forceWindowInActive)
        m_windowIsActive = false;

    if(m_forceWindowActive)
        m_windowIsActive = true;

    m_forceWindowInActive = false;
    m_forceWindowActive = false;

    rendering = true;
    OnPreRender();
    OnRender();
    OnPostRender();
    rendering = false;
}//Render()

void wxIrrlicht::OnCreateScene() {
	if (m_showFPS) {
		m_pFPSText = m_pGuiEnvironment->addStaticText(L"FPS: 0", rect<s32>(1, 1, 50, 10), false);
		m_pFPSText->setOverrideColor(SColor(255,255,255,255));
	}//if
}//OnCreateScene()

void wxIrrlicht::OnRender() {
    if (m_windowIsActive)
    {
        // draw everything here
        m_pDriver->beginScene(true, true, SColor(255,0,255,0));
        m_pSceneManager->drawAll();
        m_pGuiEnvironment->drawAll();
        m_pDriver->endScene();
    }
    else
        m_pDevice->yield();
}//OnRender()

void wxIrrlicht::OnPostRender() {

    if (m_pFPSText && m_showFPS) {
        int fps = m_pDriver->getFPS();

        static int lastFPS = 0;
        if (lastFPS != fps) {
            core::stringw str = L"FPS: ";
            str += fps;

            m_pFPSText->setText(str.c_str());
            lastFPS = fps;
        }//if
    }//if
}//OnPostRender()

void wxIrrlicht::OnPaint(wxPaintEvent& event){
    wxPaintDC paint_dc(this);

    Render();
}//OnPaint()

void wxIrrlicht::OnParentSize(wxSizeEvent& event)
{
    if (!m_pDriver) {
        return;
	}//if

    s32 w;
    s32 h;

    wxWindow* parent = (wxWindow*)event.GetEventObject();

    parent->GetClientSize(&w, &h);
    this->SetClientSize(w, h);

    dimension2d<u32> size(w, h);
    m_pDriver->OnResize(size);

    if (m_pCameraNode) {
        m_pCameraNode->setAspectRatio((float)w / (float)h);
	}//if

	m_forceWindowActive = true;
	parent->Refresh();
	Refresh();
}

void wxIrrlicht::OnSize(wxSizeEvent& event) {
    if (!m_pDriver) {
        return;
	}//if

    return;
}//OnSize

void wxIrrlicht::OnTimer(wxTimerEvent& event) {
    Render();
}

void wxIrrlicht::OnMouse(wxMouseEvent& event) {
    irr::SEvent sevt;

    sevt.EventType = irr::EET_MOUSE_INPUT_EVENT;


    if (event.IsButton()) {
        if (event.LeftDown())
            sevt.MouseInput.Event = irr::EMIE_LMOUSE_PRESSED_DOWN;
        else if (event.LeftUp())
            sevt.MouseInput.Event = irr::EMIE_LMOUSE_LEFT_UP;
        else if (event.MiddleDown())
            sevt.MouseInput.Event = irr::EMIE_MMOUSE_PRESSED_DOWN;
        else if (event.MiddleUp())
            sevt.MouseInput.Event = irr::EMIE_MMOUSE_LEFT_UP;
        else if (event.RightDown())
            sevt.MouseInput.Event = irr::EMIE_RMOUSE_PRESSED_DOWN;
        else if (event.RightUp())
            sevt.MouseInput.Event = irr::EMIE_RMOUSE_LEFT_UP;
    }//if

    else if (event.GetWheelRotation() != 0) {
        sevt.MouseInput.Wheel = (float)event.GetWheelRotation();
        sevt.MouseInput.Event = irr::EMIE_MOUSE_WHEEL;
    }//else if

    else if (event.Moving() || event.Dragging()) {
		sevt.MouseInput.Event = irr::EMIE_MOUSE_MOVED;
	}//else if

    sevt.MouseInput.X = event.GetX();
    sevt.MouseInput.Y = event.GetY();

    m_pDevice->postEventFromUser(sevt);

    if (!m_Timer.IsRunning()) {
        Render();
	}//if

    event.Skip();
}//OnMouse()

void wxIrrlicht::OnKey(wxKeyEvent& event) {
    irr::SEvent sevt;

    sevt.EventType = irr::EET_KEY_INPUT_EVENT;

    sevt.KeyInput.Key = (irr::EKEY_CODE)event.GetRawKeyCode();
    sevt.KeyInput.PressedDown = event.GetEventType() == wxEVT_KEY_DOWN;

    sevt.KeyInput.Shift = event.ShiftDown();
    sevt.KeyInput.Control = event.CmdDown();
#if wxUSE_UNICODE
    sevt.KeyInput.Char = event.GetUnicodeKey();
#else
    sevt.KeyInput.Char = event.GetKeyCode();
#endif

    m_pDevice->postEventFromUser(sevt);

    if (!m_Timer.IsRunning()) {
        Render();
	}//if

    event.Skip();
}//OnKey()
