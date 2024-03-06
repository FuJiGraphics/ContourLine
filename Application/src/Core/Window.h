#pragma once

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

namespace ZVLab {

	struct WindowConfig
	{
		int				Width;
		int				Height;
		std::wstring	WindowName;
		HWND			Hwnd;
	};

	class Window
	{
	public:
		Window() = default;
		~Window();

		bool Startup(int width = 800, int height = 600, std::string&& appName = "App");


	private:
		WindowConfig	m_tWinConfig;
		std::string		m_strAppName;
	};

}
