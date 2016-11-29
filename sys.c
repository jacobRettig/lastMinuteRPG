#include "sys.h"
#include "draw.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <gl/gl.h>

#define WINDOW_NAME "Last Miniute RPG"

/*displays an error message when the system system reaches a fatal error*/
void sys_error(const char *error_str){
	MessageBox(NULL,strcat("ERROR: ",error_str),"ERROR",MB_OK | MB_ICONSTOP);
	exit(1);
}

/*windows message processing procedure*/
LRESULT CALLBACK sys_proc(HWND hw, UINT msg, WPARAM wp, LPARAM lp){

	switch(msg){
		case WM_QUIT:
		case WM_CLOSE:
		case WM_DESTROY:{
			extern uint8_t gflags;
			gflags ^= GF_MAINLOOP;
			return 0;
		}
		case WM_MOVING:
		case WM_SIZING:
		case WM_SIZE:{
			extern uint8_t gflags;
			gflags |= GF_RESIZE;
			return 0;
		}
		default:
			return DefWindowProc(hw,msg,wp,lp); 
	}
}

/*processes all windows messages. Must be called every frame or the program
 will be killed by windows.*/
void sys_update(sys_t *sys){

	MSG msg = (MSG){0};

	while(PeekMessage(&msg,0,0,0,PM_REMOVE)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	extern uint8_t gflags;

	if(gflags & GF_RESIZE){

		gflags ^= GF_RESIZE;

		//RECT tr = (RECT){0};

		//if(GetWindowRect(sys->hw,&tr)){
		//	glViewport(0,0,tr.right,tr.bottom);
		//}
	}
}

/*pushes the bitmap stored in vid to the screen. must be called every frame
 to actually display the graphics.*/
void sys_swapbuffers(sys_t *sys){
	SwapBuffers(sys->dc);
}

/*initializes the system system by setting up a new window for the program to
 draw to*/
void sys_init(sys_t *sys){
	
	HINSTANCE hinst = (HINSTANCE){0};

	if(!(hinst = GetModuleHandle(0))){
		sys_error("Failed to obtain module handle.");
	}

	WNDCLASSEX wc = (WNDCLASSEX){0};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = sys_proc;
	wc.hInstance = hinst;
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.lpszClassName = WINDOW_NAME;
	
	if(!RegisterClassEx(&wc)){
		sys_error("Failed to register the window class.");
	}

	if(!(sys->hw = CreateWindowEx(0,WINDOW_NAME,WINDOW_NAME,
				WS_OVERLAPPEDWINDOW | WS_VISIBLE,CW_USEDEFAULT,CW_USEDEFAULT,
				DEFAULT_W,DEFAULT_H,NULL,NULL,hinst,0))){
		sys_error("Failed to create window.");
	}

	STARTUPINFO info = (STARTUPINFO){0};
	GetStartupInfo(&info);

	if(!ShowWindow(sys->hw,info.wShowWindow)){
		sys_error("Failed to display window.");
	}

	if(!(sys->dc = GetDC(sys->hw))){
		sys_error("Failed to obtain device context.");
	}

	PIXELFORMATDESCRIPTOR pfd = (PIXELFORMATDESCRIPTOR){0};

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	int32_t fmt = 0;
	if(!(fmt = ChoosePixelFormat(sys->dc,&pfd))){
		sys_error("Failed to match pixel format.");
	}
	
	if(!SetPixelFormat(sys->dc,fmt,&pfd)){
		sys_error("Failed to set pixel format.");
	}

	if(!(sys->rc = wglCreateContext(sys->dc))){
		sys_error("Failed to create openGL context.");
	}

	if(!wglMakeCurrent(sys->dc,sys->rc)){
		sys_error("Failed to set openGL context.");
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	
	glEnable(GL_TEXTURE_2D);
	glOrtho(0,RELATIVE_W,0,RELATIVE_H,-1.0f,1.0f);
	
}

/*deletes the window that was set up in the initalization function*/
void sys_shutdown(sys_t *sys){

	wglMakeCurrent(NULL,NULL);
	wglDeleteContext(sys->rc);
	ReleaseDC(sys->hw,sys->dc);
	DestroyWindow(sys->hw);

}
