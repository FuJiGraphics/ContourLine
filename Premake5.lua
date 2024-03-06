workspace "Solution"
	startproject "Application"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

	outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	IncludeDir = {};
	IncludeDir["GLM"] = "Vendor/GLM"
	IncludeDir["FZLIB"] = "Vendor/FZLib"

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
		"%{IncludeDir.FZLIB}/include",
    }

	libdirs 
	{ 
		"%{IncludeDir.FZLIB}/lib/%{cfg.buildcfg}/%{cfg.architecture}",
	}

	links
	{
		"FZLib.lib",
	}

	prebuildcommands 
	{ 
		"{COPYFILE} %[Vendor/FZLib/lib/%{cfg.buildcfg}/%{cfg.architecture}/**.dll] %[Build/Bin/"..outputDir.."/%{prj.name}]",
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
		"%{IncludeDir.FZLIB}/Include",
        "%{IncludeDir.GLM}",
    }

	libdirs 
	{ 
		"%{IncludeDir.FZLIB}/lib/%{cfg.buildcfg}/%{cfg.architecture}",
	}

	links
	{
		"FZLib.lib",
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
