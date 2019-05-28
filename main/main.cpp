#include "../utils/sThread.hpp"
#include <windows.h>


LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);  // LRESULT= LONG, CALLBACK=�ý����Լ�
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
  WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  // ����
  WndClass.hCursor = LoadCursor(NULL,IDC_ARROW);  // Ŀ�� ���
  WndClass.hIcon = LoadIcon(NULL,IDI_APPLICATION);  // ������ ���
  WndClass.hInstance = hInstance;
  WndClass.lpfnWndProc = WndProc;
  WndClass.lpszClassName = lpszClass;
  WndClass.lpszMenuName = NULL;
  WndClass.style = CS_HREDRAW | CS_VREDRAW;
  RegisterClass(&WndClass);  

	  // ������ ����
  hWnd = CreateWindow(lpszClass,TEXT("STOCK"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT
    ,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,(HMENU)NULL,hInstance,NULL);
  ShowWindow(hWnd,nCmdShow);  // �����츦 ȭ�鿡 ���

  while(GetMessage(&Message,NULL,0,0)){  // �޽��� ť���� �޽����� �о����
    TranslateMessage(&Message);  // Ű���� �Է¸޽����� �����Ͽ� ���α׷����� ���� ���� �ֵ��� ��
    DispatchMessage(&Message);  // �޽��� ť���� ���� �޽����� �������� �޽��� ó���Լ�(WndProc)�� ����
  }
  return (int)Message.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
  switch(iMessage){
  case WM_DESTROY:
    PostQuitMessage(0);  // ��ó�� ������ ����
    return 0;
  }
  return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}
