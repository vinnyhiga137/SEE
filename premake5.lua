-- Setting up some parameters to load the GLFW and macros

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"



-- Setting up some default configurations for the workspace
workspace "SEE"
    architecture "x86_64"
    startproject "Game"

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
    staticruntime "off"

    targetdir ("builds/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("builds/obj/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/**.h",
        "%{prj.name}/**.hpp",
        "%{prj.name}/**.cpp",
        "%{prj.name}/**.c"
    }

    filter "system:windows"
        systemversion "latest"

        links {
            "glfw3",
            "opengl32.lib"
        }

        defines {
            "WIN32"
        }

        includedirs { 
            "3rd Party/GLFW/glfw-3.3.2-WIN64/include",
            "3rd Party/glad/include"
        }
    
        libdirs { 
            "3rd Party/GLFW/glfw-3.3.2-WIN64/lib-vc2019" 
        }

    filter "system:macosx"

        links {
            "glfw",
            "CoreVideo.framework",
            "Cocoa.framework",
            "IOKit.framework",
            "OpenGL.framework"
        }

        defines {
            "MAC"
        }

        includedirs { 
            --"3rd Party/GLFW/glfw-3.3.2-MACOS/include", -- If you want to use the 3rd Party folder
            "/usr/local/Cellar/glfw/3.3.2/include",
            "3rd Party/glad/include"
        }

        libdirs { 
            --"3rd Party/GLFW/glfw-3.3.2-MACOS/lib-macos", -- If you want to use the 3rd Party folder
            "/usr/local/Cellar/glfw/3.3.2/lib"
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
    staticruntime "off"

    targetdir ("builds/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("builds/obj/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/**.h",
        "%{prj.name}/**.hpp",
        "%{prj.name}/**.cpp",
        "%{prj.name}/**.c"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "WIN32"
        }

        links {
            "see"
        }

        includedirs { 
            "SEE/",
            "3rd Party/GLFW/glfw-3.3.2-WIN64/include",
            "3rd Party/glad/include"
        }

    filter "system:macosx"

        defines {
            "MAC"
        }

        links {
            "see",
            "glfw",
            "CoreVideo.framework",
            "Cocoa.framework",
            "IOKit.framework",
            "OpenGL.framework"
        }

        includedirs { 
            "SEE/",
            --"3rd Party/GLFW/glfw-3.3.2-MACOS/include", -- If you want to use the 3rd Party folder
            "/usr/local/Cellar/glfw/3.3.2/include",
            "3rd Party/glad/include"
        }

        libdirs { 
            --"3rd Party/GLFW/glfw-3.3.2-MACOS/lib-macos", -- If you want to use the 3rd Party folder
            "/usr/local/Cellar/glfw/3.3.2/lib"
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
