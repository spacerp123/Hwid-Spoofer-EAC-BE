#include "Main.h"
#include <Windows.h>
#include <string>
#include <tchar.h>
#include <urlmon.h>
#include <urlmon.h>
#include <iostream>
#include <tchar.h>
#include <urlmon.h>
#include <iostream>
#include <wincrypt.h>
#include <ShlObj.h>
#include <iostream>
#include <filesystem>
#include <random>
#include ".\xorstr.hpp"

#include  <windows.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <mmsystem.h>
#include <winbase.h>
#include <tchar.h>
#include <WinInet.h>
#include <direct.h>
#include <sstream>


#pragma comment(lib,"Wininet.lib")

#pragma comment(lib, "winmm.lib")

#define MB_ICONINFO 64
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#pragma comment(lib,"Wininet.lib")
#define _WIN32_WINNT 0x0500
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "urlmon.lib")
void ClearConsole()
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	SetConsoleCursorPosition(console, topLeft);
	return;
}




std::string random_string(const int len)
{
	const std::string alpha_numeric(_xor_("ABCDEFGHIJKLMNOPRSTUVZabcdefghijklmnoprstuvz").c_str());
	std::default_random_engine generator{ std::random_device{}() };
	const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };
	std::string str(len, 0);
	for (auto& it : str) {
		it = alpha_numeric[distribution(generator)];
	}

	return str;
}

void remove_scrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}
void wwwa ()
{

	
	int horizontal = 0, vertical = 0;
	int x = 350, y = 230; //// alta doðru

	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	SetConsoleCursorInfo(out, &cursorInfo);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 15;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	system("color 60");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	HWND hwnd = GetConsoleWindow();
	MoveWindow(hwnd, 0, 0, x, y, TRUE);
	SetWindowPos(hwnd, HWND_TOPMOST, 10, 10, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	LONG lStyle = GetWindowLong(hwnd, GWL_STYLE);
	lStyle &= ~(WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
	SetWindowLong(hwnd, GWL_STYLE, lStyle);
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(console, &csbi);
	COORD scrollbar = {
		csbi.srWindow.Right - csbi.srWindow.Left + 1,
		csbi.srWindow.Bottom - csbi.srWindow.Top + 1
	};
	if (console == 0)
		throw 0;
	else
		SetConsoleScreenBufferSize(console, scrollbar);
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hwnd, 0, (255 * 100) / 100, LWA_ALPHA);





}

void awa() //// LOG GEÇÝÞÝ
{


	int horizontal = 0, vertical = 0;
	int x = 400, y = 300; //// alta doðru

	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	SetConsoleCursorInfo(out, &cursorInfo);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 15;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	system("Color  60");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	HWND hwnd = GetConsoleWindow();
	MoveWindow(hwnd, 0, 0, x, y, TRUE);
	SetWindowPos(hwnd, HWND_TOPMOST, 10, 10, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	LONG lStyle = GetWindowLong(hwnd, GWL_STYLE);
	lStyle &= ~(WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
	SetWindowLong(hwnd, GWL_STYLE, lStyle);
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(console, &csbi);
	COORD scrollbar = {
		csbi.srWindow.Right - csbi.srWindow.Left + 1,
		csbi.srWindow.Bottom - csbi.srWindow.Top + 1
	};
	if (console == 0)
		throw 0;
	else
		SetConsoleScreenBufferSize(console, scrollbar);
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hwnd, 0, (255 * 100) / 100, LWA_ALPHA);





}
void init()
{
	POINT OldCursorPos;
	GetCursorPos(&OldCursorPos);
	remove_scrollbar();
	INPUT    Input = { 0 };
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));
	BlockInput(true);
	SetCursorPos(0, 0);
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));
	SetCursorPos(0, 0);
	SetCursorPos(OldCursorPos.x, OldCursorPos.y);
	BlockInput(false);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);
	HWND handle = GetConsoleWindow();
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_EX_RIGHTSCROLLBAR & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX & ~WS_MINIMIZEBOX);
	HANDLE hInput;
	DWORD prev_mode;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ENABLE_EXTENDED_FLAGS);
	HWND consoleWindowHandle = GetConsoleWindow();
	if (consoleWindowHandle)
	{
		SetWindowPos(
			consoleWindowHandle,
			HWND_TOPMOST,
			0, 0,
			0, 0,
			SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW
		);
		ShowWindow(
			consoleWindowHandle,
			SW_NORMAL
		);
	}
}

void licensesys()
{


			
			Sleep(200);
		
}


int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	wwwa();

	
	

	cout << "  Connections      \n"; Sleep(1000);
	system("cls");
	std::cout << " \n";
	std::cout << " \n";
	SetConsoleTitle(" H W I D - S P O O F E R ");


	

	ShowWindow(GetConsoleWindow(), SW_HIDE);
	

	LPCTSTR lpzClass = NAME;
	if (!RegMyWindowClass(hInstance, lpzClass))
		return 1;
	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect);
	int x = screen_rect.right / 2 - 150;
	int y = screen_rect.bottom / 3 - 75;
	HWND hWnd = CreateWindow(lpzClass, NAME, WS_POPUP, x, y, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);
	if (!hWnd) return 2;
	LPDIRECT3D9 pD3D;
	if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL) {
		UnregisterClass(lpzClass, hInstance);
	}

	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
	g_d3dpp.Windowed = TRUE;
	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	g_d3dpp.EnableAutoDepthStencil = TRUE;
	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	if (pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0) {
		pD3D->Release();
		UnregisterClass(lpzClass, hInstance);
		return 0;
	}

	ImGui_ImplDX9_Init(hWnd, g_pd3dDevice);

	ImGuiStyle* style = &ImGui::GetStyle();

	ImVec4* colors = style->Colors;


	colors[ImGuiCol_Text] = ImVec4(0.92f, 0.92f, 0.92f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.44f, 0.44f, 0.44f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);

	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
	colors[ImGuiCol_Border] = ImVec4(0.51f, 0.36f, 0.15f, 1.00f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.51f, 0.36f, 0.15f, 1.00f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.78f, 0.55f, 0.21f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.51f, 0.36f, 0.15f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.47f, 0.47f, 0.47f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.81f, 0.83f, 0.81f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.78f, 0.55f, 0.21f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.51f, 0.36f, 0.15f, 1.00f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.78f, 0.55f, 0.21f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.51f, 0.36f, 0.15f, 1.00f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.93f, 0.65f, 0.14f, 1.00f);

	colors[ImGuiCol_ResizeGrip] = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.78f, 0.55f, 0.21f, 1.00f);

	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);


	style->FramePadding = ImVec2(4, 2);
	style->ItemSpacing = ImVec2(10, 2);
	style->IndentSpacing = 12;
	style->ScrollbarSize = 10;

	style->WindowRounding = 4;
	style->FrameRounding = 4;

	style->ScrollbarRounding = 6;
	style->GrabRounding = 4;


	style->WindowTitleAlign = ImVec2(1.0f, 0.5f);


	style->DisplaySafeAreaPadding = ImVec2(4, 4);


	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}

		ImGui_ImplDX9_NewFrame();
		DWORD dwFlag = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;
		static bool open = true;
		if (!open) ExitProcess(0);

		ImGui::Begin(NAME_LOADER, &open, ImVec2(WINDOW_WIDTH, WINDOW_HEIGHT), 1.0f, dwFlag); {
			ImGui::PushItemWidth(-1.0f);
			static bool checkBox = true;
			static const char* items[]{ "Spoof Game Selected", "Rust","Apex Legends","Fortnite","Fivem Server Unban","COD Warzone","Rainbow Six Siege","Unturned","Zula", "IronSight","Wolfteam" };
			static int selectedItem = 0;
			
		
			ImGui::Text("_______________________________________");

			ImGui::Combo("Listbox", &selectedItem, items, ARRAYSIZE(items));
		

			ImGui::Text("_______________________________________");
			
			

			if (GetAsyncKeyState(VK_F4) != 0) {
			
				
				cleaner();
				
			}
		
			

	
		
			if (ImGui::Button(_xor_("Spoof").c_str(), ImVec2(ImGui::GetWindowSize().x * 0.96f, 0.0f)))
			{
				ShowWindow(GetConsoleWindow(), SW_SHOW);
				cout << "  Selected Info     \n";
				cout << "       \n";
				cout << "  MOBO SELECTED [+]     \n"; Sleep(1000);
				cout << "       \n";
				cout << "  CPU SELECTED [+]      \n"; Sleep(1000);
				cout << "       \n";
				cout << "  DISK SELECTED [+]     \n"; Sleep(1000);
				cout << "       \n";
				cout << "  SMBIOS SELECTED [+]     \n"; Sleep(1000);
				cout << "       \n";
				cout << "  ARP SELECTED [+]      \n"; Sleep(1000);
				cout << "       \n";
				cout << "  MAC SELECTED [+]     \n"; Sleep(1000);
				cout << "       \n";
				cout << "  BIOS SELECTED [+]     \n"; Sleep(1000);
				cout << "       \n";
				cout << "  NVME SELECTED [+]     \n"; Sleep(1000);
				cout << "       \n";
				cout << "  PCNAME SELECTED [+]     \n"; Sleep(1000);
				cout << "       \n";
			
				MessageBox(NULL, "ALL SELECTED [+]", "", MB_ICONINFO);
				ShowWindow(GetConsoleWindow(), SW_HIDE);
				
			
				spoofer();
				MessageBox(NULL, "Spoofer [+] ", "", MB_ICONINFO);
				ShowWindow(GetConsoleWindow(), SW_HIDE);
			

			}
		;
		
			ImGui::Text("_______________________________________");
			if (ImGui::Button(_xor_("Cleaner").c_str(), ImVec2(ImGui::GetWindowSize().x * 0.96f, 0.0f)))
			{
				MessageBox(NULL, "The Cleaner process may take a long time please wait ", "Warning", MB_ICONINFO);
			
				cleaner();
				MessageBox(NULL, "Cleaner [+] ", "", MB_ICONINFO);
				ShowWindow(GetConsoleWindow(), SW_HIDE);


			}
			ImGui::Text("  ");
			ImGui::TextColored(ImColor(255, 255, 0), " Products  3131.com");
			ImGui::Text("  ");
			ImGui::TextColored(ImColor(255, 255, 0), " Developer H W I D - SPOOFER ");
			ImGui::Text("_______________________________________");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "                  Status: ");
			ImGui::SameLine();
			ImGui::TextColored(ImColor(0, 255, 0), "Undetected");
		
		}
		ImGui::End();

		g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
		g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
		if (g_pd3dDevice->BeginScene() >= 0)
		{
			ImGui::Render();
			g_pd3dDevice->EndScene();
		}
		g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
	}
	ImGui_ImplDX9_Shutdown();
	if (g_pd3dDevice) g_pd3dDevice->Release();
	if (pD3D) pD3D->Release();
	UnregisterClass(NAME, hInstance);
	return 0;
	}
