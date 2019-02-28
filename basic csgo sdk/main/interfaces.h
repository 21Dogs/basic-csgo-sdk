#pragma once
#include <windows.h>
#include <stdio.h>

#include "../source sdk/IPanel.h"
#include "../source sdk/ISurface.h"

class CInterfaces
{
public:
	void initialise_interfaces();

	IPanel * g_VGuiPanel = nullptr;
	ISurface * g_VGuiSurface = nullptr;
};

extern CInterfaces Interfaces;