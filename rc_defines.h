#ifndef RC_DEFINES_H_INCLUDED
#define RC_DEFINES_H_INCLUDED

#define RC_MOUSEBUTTON_NONE   0
#define RC_MOUSEBUTTON_LEFT   1
#define RC_MOUSEBUTTON_RIGHT  2
#define RC_MOUSEBUTTON_MIDDLE 3

#define RC_VIEWPORT_MODE_EDIT		1
#define RC_VIEWPORT_MODE_CAMERA		2

#define RC_IRR_WINDOW_NAV3D		0
#define RC_IRR_WINDOW_MATERIAL	1
#define RC_IRR_WINDOW_VIEW2D	2

#if defined(__WXGTK__)
	#define HIDE_CURSOR wxSetCursor(wxCURSOR_BLANK)
	#define SHOW_CURSOR wxSetCursor(*wxSTANDARD_CURSOR)
#elif defined(__WXMSW__)
	#define HIDE_CURSOR ShowCursor(0)
	#define SHOW_CURSOR ShowCursor(1)
#endif

#define RC_CAMERA_VIEW_PERSPECTIVE  0
#define RC_CAMERA_VIEW_FRONT        1
#define RC_CAMERA_VIEW_BACK         2
#define RC_CAMERA_VIEW_LEFT         3
#define RC_CAMERA_VIEW_RIGHT        4
#define RC_CAMERA_VIEW_TOP          5
#define RC_CAMERA_VIEW_BOTTOM       6
#define RC_CAMERA_VIEW_ALL          7

#define RC_ID_ANY		0
#define RC_ID_TEXTURE	1
#define RC_ID_MATERIAL	2
#define RC_ID_MESH		3
#define RC_ID_ANIMATION	4
#define RC_ID_ACTOR		5
#define RC_ID_PATH		6

#endif // RC_DEFINES_H_INCLUDED
