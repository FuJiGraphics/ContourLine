#include <FZLib/Helpers/StringHelper.h>
#include <iostream>

int main()
{
	// 윈도우 클래스 등록
	std::string str = "test";
	FZLib::StringHelper::StringToWString(str);
	return 0;
}
