#pragma once
#include "Core.h"

namespace ZVLab {
	
	class Window;

	class System
	{
	private:
		static ZVSharedPtr<System> s_pInstance;

		bool					m_bInitialized	= false;
		ZVSharedPtr<Window>		m_pWindow;

	private:
		System() = default;
	
	public:
		static System& GetInstance();

		bool	Startup();
		bool	Shutdown();


	};



} // namespace ZVLab
