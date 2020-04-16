-- Setting up some parameters to load the GLFW and macros

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"



-- Setting up some default configurations for the workspace
workspace "SEE"
    architecture "x86_64"

    configurations {
        "Debug",
        "Development",
        "Release",
    }

    flags {
		"MultiProcessorCompile"
	}




-- Game Engine configuration
project "SEE"
    location "SEE"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("builds/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("builds/obj/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.c"
    }

    includedirs { 
        "3rd Party/GLFW/glfw-3.3.2-WIN64/include",
        "3rd Party/glad/include"
    }

    libdirs { 
        "3rd Party/GLFW/glfw-3.3.2-WIN64/lib-vc2019" 
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "WIN32"
        }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Development"
        defines "DEVELOPMENT"
        optimize "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"





project "Game"
    location "Game"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("builds/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("builds/obj/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.c"
    }

    includedirs {
        "SEE/src",
        "3rd Party/GLFW/glfw-3.3.2-WIN64/include",
        "3rd Party/glad/include" 
    }

    links {
        "SEE",
        "glfw3"
    }

    libdirs { 
        "3rd Party/GLFW/glfw-3.3.2-WIN64/lib-vc2019" 
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "WIN32"
        }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Development"
        defines "DEVELOPMENT"
        optimize "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"
