#include <pch.h>
#include "System.h"
#include "Window.h"

namespace ZVLab {

	ZVSharedPtr<System> System::s_pInstance = nullptr;

	System& System::GetInstance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance.reset(new System);
		}
		return (*s_pInstance);
	}

	bool System::Startup()
	{
		if (m_bInitialized)
		{
			return false;
		}
		m_bInitialized = true;


		return true;
	}

	bool System::Shutdown()
	{
		return false;
	}

} // namespace ZVLab
