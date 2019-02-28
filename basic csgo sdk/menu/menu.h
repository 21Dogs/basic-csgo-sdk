#pragma once
#include <windows.h>

#include "../misc/rendermanager.h"

class CMenu
{
public:
	void paint();

	struct
	{
		bool menu_opened;

	} variables;
};

extern CMenu Menu;