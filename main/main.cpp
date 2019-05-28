#include "../utils/sThread.hpp"
#include <windows.h>


LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);  // LRESULT= LONG, CALLBACK=시스템함수
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First");

int init_windows_format(HINSTANCE hInstance, int nCmdShow);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	int ret;
	ret = init_windows_format(hInstance, nCmdShow);
	return ret;
}

int init_windows_format(HINSTANCE hInstance, int nCmdShow){

  HWND hWnd;
  MSG Message;
  WNDCLASS WndClass;
  g_hInst = hInstance;

  WndClass.cbClsExtra = 0;
  WndClass.cbWndExtra = 0;
  WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  // 배경색
  WndClass.hCursor = LoadCursor(NULL,IDC_ARROW);  // 커서 모양
  WndClass.hIcon = LoadIcon(NULL,IDI_APPLICATION);  // 아이콘 모양
  WndClass.hInstance = hInstance;
  WndClass.lpfnWndProc = WndProc;
  WndClass.lpszClassName = lpszClass;
  WndClass.lpszMenuName = NULL;
  WndClass.style = CS_HREDRAW | CS_VREDRAW;
  RegisterClass(&WndClass);  

	  // 윈도우 생성
  hWnd = CreateWindow(lpszClass,TEXT("STOCK"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT
    ,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,(HMENU)NULL,hInstance,NULL);
  ShowWindow(hWnd,nCmdShow);  // 윈도우를 화면에 띄움

  while(GetMessage(&Message,NULL,0,0)){  // 메시지 큐에서 메시지를 읽어들임
    TranslateMessage(&Message);  // 키보드 입력메시지를 가공하여 프로그램에서 쉽게 쓸수 있도록 함
    DispatchMessage(&Message);  // 메시지 큐에서 꺼낸 메시지를 윈도우의 메시지 처리함수(WndProc)로 전달
  }
  return (int)Message.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
  switch(iMessage){
  case WM_DESTROY:
    PostQuitMessage(0);  // 선처리 윈도우 종료
    return 0;
  }
  return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}
