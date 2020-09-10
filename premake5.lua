workspace "Game"
	configurations	{ "Debug", "Release" }	
	platforms		{ "x64" }

	location		"build"

project "Game"
	kind			"WindowedApp"

	files {
		"premake5.lua",
		"GenerateProjectFiles.bat",
	}
		