workspace "StoneSword"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "StoneSword"
    location "StoneSword"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs{
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
            "SS_PLATFROM_WINDOWS",
            "SS_BUILD_DLL"
        }

        postbuildcommands{
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "SS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SS_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "SS_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"

    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/" .. outputdir .. "/%{prj.name}")


    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs{
        "StoneSword/vendor/spdlog/include",
        "StoneSword/src"
    }

    links{
        "StoneSword"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
            "SS_PLATFROM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SS_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "SS_DIST"
        optimize "On"
