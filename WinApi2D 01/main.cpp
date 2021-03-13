//#include <windows.h>
//#include <gmtl/gmtl.h>
//#include "draw.h"
//#include "PhysicsWorld.h"
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//char szClassName[] = "CG_WAPI_Template";
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	HWND hWnd;
//	MSG lpMsg;
//	WNDCLASS wc;
//
//	// ��������� ��������� ������ ����
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.lpfnWndProc = WndProc;
//	wc.cbClsExtra = 0;
//	wc.cbWndExtra = 0;
//	wc.hInstance = hInstance;
//	wc.hIcon = NULL;
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//	wc.lpszMenuName = NULL;
//	wc.lpszClassName = (LPCWSTR)szClassName;
//
//	// ������������ ����� ����
//	if (!RegisterClass(&wc))
//	{
//		MessageBox(NULL, (LPCWSTR)"�� ���� ���������������� ����� ����!", (LPCWSTR)"������", MB_OK);
//		return 0;
//	}
//
//	int x = 200;
//	int y = 200;
//	int w = 600;
//	int h = 600;
//
//	RECT rect;
//	rect.left = x;
//	rect.top = y;
//	rect.right = x + w;
//	rect.bottom = y + h;
//
//	UINT style = WS_OVERLAPPEDWINDOW;
//
//	AdjustWindowRectEx(&rect, style, 0, 0);
//
//	// ������� �������� ���� ����������
//	hWnd = CreateWindow(
//		(LPCWSTR)szClassName, // ��� ������ 
//		L"������ WinAPI ����������", // ����� ���������
//		style, // ����� ���� 
//		rect.left, rect.top, rect.right - rect.left,
//		rect.bottom - rect.top,
//		(HWND)NULL, // ��������� �� ������������ ���� NULL 
//		(HMENU)NULL, // ������������ ���� ������ ���� 
//		(HINSTANCE)hInstance, // ��������� �� ������� ����������
//		NULL); // ���������� � �������� lParam � ������� WM_CREATE
//
//	if (!hWnd)
//	{
//		MessageBox(NULL, (LPCWSTR)"�� ������� ������� ������� ����!", (LPCWSTR)"������", MB_OK);
//		return 0;
//	}
//
//	// ���������� ���� ����
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);
//
//	// ��������� ���� ��������� ��������� �� �������� ����������
//	while (GetMessage(&lpMsg, NULL, 0, 0))
//	{
//		TranslateMessage(&lpMsg);
//		DispatchMessage(&lpMsg);
//	}
//	return (lpMsg.wParam);
//}
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
//LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
//{
//	PAINTSTRUCT ps;
//	RECT Rect;
//	HDC hdc, hCmpDC;
//	HBITMAP hBmp;
//
//	switch (messg)
//	{
//	case WM_TIMER:
//	{
//		break;
//	}
//	case WM_CREATE:
//	{
//		break;
//	}
//	case WM_KEYDOWN:
//	{
//		int KeyPressed;
//		KeyPressed = (int)wParam;
//		switch (KeyPressed)
//		{
//		default:
//			break;
//		}
//		InvalidateRect(hWnd, NULL, FALSE);
//		break;
//	}
//	case WM_ERASEBKGND:
//	{
//		return 1;
//		break;
//	}
//	case WM_PAINT:
//	{
//		GetClientRect(hWnd, &Rect);
//		hdc = BeginPaint(hWnd, &ps);
//
//		// �������� �������� ��������� ��� ������� �����������
//		hCmpDC = CreateCompatibleDC(hdc);
//		hBmp = CreateCompatibleBitmap(hdc, Rect.right - Rect.left,
//			Rect.bottom - Rect.top);
//		SelectObject(hCmpDC, hBmp);
//
//		// �������� ������� ������
//		LOGBRUSH br;
//		br.lbStyle = BS_SOLID;
//		br.lbColor = 0x222222;
//		HBRUSH brush;
//		brush = CreateBrushIndirect(&br);
//		FillRect(hCmpDC, &Rect, brush);
//		DeleteObject(brush);
//
//		// ����� ������ �� ��������� hCmpDC
//
//		// �������� ����������� �� �������� ��������� �� �����
//		SetStretchBltMode(hdc, COLORONCOLOR);
//		BitBlt(hdc, 0, 0, Rect.right - Rect.left, Rect.bottom - Rect.top,
//			hCmpDC, 0, 0, SRCCOPY);
//
//		// ������� �������� ��������� �������
//		DeleteDC(hCmpDC);
//		DeleteObject(hBmp);
//		hCmpDC = NULL;
//
//		EndPaint(hWnd, &ps);
//		break;
//	}
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//
//	default:
//		return (DefWindowProc(hWnd, messg, wParam, lParam));
//	}
//	return (0);
//}