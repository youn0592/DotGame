workspace "Game"
	configurations	{ "Debug", "Release" }	
	platforms		{ "x64" }
	location		"build"
	characterset	"MBCS"
	startproject	"Game"

project "Game"
	kind			"WindowedApp"
	location		"build/Game"

	files {
		"Game/Source/**.cpp",
		"Game/Source/**.h",
		"premake5.lua",
		"GenerateProjectFiles.bat",
	}
	includedirs{
		"Framework/Source",
		"Game/Source",
	}

	links{
		"Framework",
		"opengl32"
	}
		
project "Framework"

	kind			"StaticLib"
	location		"build/Framework"

	files{
		"Framework/Source/**.cpp",
		"Framework/Source/**.h"
	}

	includedirs{
		"Framework/Source",
	}