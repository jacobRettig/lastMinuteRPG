#include "vid.h"
#include "sys.h"
#include <stdbool.h>
#include <stdio.h>

#define WINDOW_NAME "sgame"

void sys_error(const char *error_str){
	MessageBox(NULL,strcat("ERROR: ",error_str),"ERROR",MB_OK | MB_ICONSTOP);
	exit(1);
}

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

void sys_update(sys_t *sys, vid_t *vid, timer_t *timer){

	MSG msg = (MSG){0};

	while(PeekMessage(&msg,0,0,0,PM_REMOVE)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	extern uint8_t gflags;

	if(gflags & GF_RESIZE){

		RECT rec = (RECT){0};
		GetClientRect(sys->hw,&rec);

		vid->real_w = rec.right;
		vid->real_h = rec.bottom;

		timer->tstep = 0;

		gflags ^= GF_RESIZE;
	}
}

void sys_swapbuffers(sys_t *sys,vid_t *vid){
	StretchDIBits(sys->dc,0,0,vid->real_w,vid->real_h,0,0,vid->w,vid->h,
		vid->bmp,&sys->bmi,DIB_RGB_COLORS,SRCCOPY);

}

void sys_init(sys_t *sys, vid_t *vid){
	
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
				vid->w,vid->h,NULL,NULL,hinst,0))){
		sys_error("Failed to create window.");
	}

	STARTUPINFO info = (STARTUPINFO){0};
	GetStartupInfo(&info);

	if(!ShowWindow(sys->hw,info.wShowWindow)){
		sys_error("Failed to display window.");
	}

	sys->bmi.bmiHeader = (BITMAPINFOHEADER){0};
	sys->bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	sys->bmi.bmiHeader.biWidth = vid->w;
	sys->bmi.bmiHeader.biHeight = vid->h;
	sys->bmi.bmiHeader.biPlanes = 1;
	sys->bmi.bmiHeader.biBitCount = 24;
	sys->bmi.bmiHeader.biCompression = BI_RGB;

	if(!(sys->dc = GetDC(sys->hw))){
		sys_error("Failed to obtain device context.");
	}
}

void sys_shutdown(sys_t *sys){

	ReleaseDC(sys->hw,sys->dc);
	DestroyWindow(sys->hw);

}
