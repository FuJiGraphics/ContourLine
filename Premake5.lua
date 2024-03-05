workspace "Solution"
	startproject "Application"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

	outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    targetdir ("Build/Bin/"..outputDir.."/%{prj.name}")
    objdir ("Build/Bin-int/"..outputDir.."/%{prj.name}")

	project "Application"
		location "Application"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "off"
	systemversion "latest"

    pchheader "pch.h"
    pchsource "%{prj.name}/src/pch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

	includedirs
    {
        "%{prj.name}/src",
		"%{prj.name}/src/"
    }

    filter "system:Windows"
    defines
    {
        "PV_PLATFORM_WINDOWS",
    }

    filter "configurations:Debug"
        defines "PV_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "PV_RELEASE"
        runtime "Release"
        optimize "On"


	project "ContourLine"
		location "ContourLine"
		kind "WindowedApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "off"
    systemversion "latest"  

	IncludeDir = {};
	IncludeDir["GLM"] = "Vendor/GLM"
	IncludeDir["FZLIB"] = "%{prj.name}/vendor/FZLib/Dist/include/"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

	includedirs
    {
        "%{prj.name}/src",
        "%{IncludeDir.GLM}",
		"%{IncludeDir.FZLIB}",
    }

	links
	{
		"GLM",
	}

	libdirs 
	{ 
	}

    filter "system:Windows"
    defines
    {
        "PV_PLATFORM_WINDOWS",
    }

	filter "configurations:Debug"
        defines "PV_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "PV_RELEASE"
        runtime "Release"
        optimize "On"
