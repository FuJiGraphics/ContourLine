#include "pch.h"
#include <Core/System.h>

int main()
{
	using namespace ZVLab;
	FZLib::LogSystem::SetPattern(FZLib::LogSystem::Pattern::Details);
	FZLOG_ERROR("Failed to initialize!");

	FZLib::LogSystem::SetPattern(FZLib::LogSystem::Pattern::LineScanner);
	FZLOG_ERROR("Failed to initialize!");

	FZLib::LogSystem::SetPattern(FZLib::LogSystem::Pattern::Simple);
	FZLOG_TRACE("F");
	return 0;
}
