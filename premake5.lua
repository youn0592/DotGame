workspace "Game"
	configurations	{ "Debug", "Release" }	
	platforms		{ "x64" }

	location		"build"

project "Game"
	kind			"WindowedApp"

	files {
		"Game/Source/**.cpp",
		"premake5.lua",
		"GenerateProjectFiles.bat",
	}
		