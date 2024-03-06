#pragma once
#include <memory>
#include <utility>

namespace ZVLab {

	template <typename _Ty>
	using ZVSharedPtr = std::shared_ptr<_Ty>;

	template <typename _Ty, typename ...Args> 
	constexpr ZVSharedPtr<_Ty> CreateZVShared(Args&& ...args)
	{
		return std::make_shared<_Ty>(std::forward<Args>(args)...);
	}

}
