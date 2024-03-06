#include <pch.h>
#include <FZLib/Helpers/StringHelper.h>

#include "Window.h"

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

	Window::~Window()
	{
		m_strAppName.clear();
	}

	bool Window::Startup(int width, int height, std::string&& appName)
	{
		auto[Width, Height, WinName, Handle] = m_tWinConfig;
		m_strAppName = appName;

		Width = width;
		Height = height;
		WinName = FZLib::StringHelper::StringToWString(m_strAppName);

		// Register Window Class
		WNDCLASS wc = {};
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpszClassName = WinName.c_str();
		int result = RegisterClass(&wc);
		if (result == 0)
			return false;

		// Generated a Window
		Handle = CreateWindowEx( 0, WinName.c_str(), WinName.c_str(),
								WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
								800, 600, NULL, NULL, wc.hInstance, NULL);
		if (Handle == NULL)
			return false;
		
		return true;
	}

}	// namespace ZVLab
