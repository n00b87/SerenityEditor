Include "serenity.bas"

'WASD to Move
'Arrow Keys to Rotate

Sub Camera_Control(cam_canvas)
	current_canvas = ActiveCanvas()
	If Key(K_W) Then
		Canvas(cam_canvas)
		TranslateCamera(0,0,10)
    ElseIf Key(K_S) Then
		Canvas(cam_canvas)
		TranslateCamera(0,0,-10)
	End If

	If Key(K_A) Then 
		Canvas(cam_canvas)
		TranslateCamera(-10,0,0)
	ElseIf Key(K_D) Then
		Canvas(cam_canvas)
		TranslateCamera(10,0,0)
	End If

	If Key(K_R) Then
		Canvas(cam_canvas)
		Dim crx, cry, crz
		GetCameraPosition(crx, cry, crz)
		SetCameraPosition(crx, cry+10, crz)
	ElseIf Key(K_F) Then
		Canvas(cam_canvas)
		Dim crx, cry, crz
		GetCameraPosition(crx, cry, crz)
		SetCameraPosition(crx, cry-10, crz)
	End If


	If Key(K_UP) Then
		Canvas(cam_canvas)
		RotateCamera(1, 0, 0)
	ElseIf Key(K_DOWN) Then
		Canvas(cam_canvas)
		RotateCamera(-1, 0, 0)
	End If

	If Key(K_LEFT) Then
		Canvas(cam_canvas)
		Dim crx, cry, crz
		GetCameraRotation(crx, cry, crz)

		RotateCamera(-1*crx, 0, 0)
		RotateCamera(0, -1, 0)
		RotateCamera(crx, 0, 0)
	ElseIf Key(K_RIGHT) Then
		Canvas(cam_canvas)
		Dim crx, cry, crz
		GetCameraRotation(crx, cry, crz)
		SetCameraRotation(crx, cry+1, crz)
	End If
	
	Canvas(current_canvas)
End Sub







title$ = "Serenity3D Template"
w = 640
h = 480
fullscreen = FALSE
vsync = FALSE


'Open a graphics window
OpenWindow("Serenity3D Template", w, h, fullscreen, vsync)

'Open a 3D Canvas
m3d = OpenCanvas3D(0, 0, 640, 480, 0)

'Set the 3D Canvas as the active Canvas (Camera Actions will be done on active canvas)
Canvas(m3d)

'Move and Rotate the Camera
SetCameraPosition(0, 10, 0)
SetCameraRotation(-20,0,0)

'Load a Stage
Serenity_LoadStage("[STAGE_NAME_HERE]")

'Main Loop
While Not Key(K_ESCAPE)
	Camera_Control(m3d)
	Update()
Wend

