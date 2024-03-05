#pragma once
#include <Windows.h>
#include <string>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

namespace ZVLab {

	class Window
	{
	public:
		Window(int width = 800, int height = 600, const char* appName = "App");
		~Window();

		bool Initialize();


	private:
		HWND			m_Hwnd;
		int				m_Width;
		int				m_Height;
		std::string		m_AppName;
	};

}
