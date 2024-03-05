#include "Window.h"
#include <FZLib/Helpers/StringHelper.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

namespace ZVLab {

	Window::Window(int width, int height, const char* appName)
		: m_Width(width)
		, m_Height(height)
		, m_AppName(appName)
	{
		// Empty
	}

	Window::~Window()
	{
		m_Width = m_Height = 0;
		m_AppName.clear();
	}

	bool Window::Initialize()
	{
		// Register Window Class
		WNDCLASS wc = {};
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpszClassName = FZLib::StringHelper::StringToLPCWSTR(m_AppName.c_str());
		RegisterClass(&wc);

		// Generated a Window
		m_Hwnd = CreateWindowEx(
			0,
			L"DirectX11ConsoleApp",
			L"DirectX11 Console App",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			800, 600,
			NULL, NULL,
			wc.hInstance,
			NULL);



		return true;
	}

}	// namespace ZVLab
