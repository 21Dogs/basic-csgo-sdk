#pragma once
#include <windows.h>

#include "interfaces.h"

#include "../misc/globals.h"
#include "../misc/vmt.h"
#include "../misc/rendermanager.h"

#include "../menu/menu.h"

extern VMTHook * PanelHook;

enum hookIndexes
{
	pt = 41,
};

class CHooks
{
public:
	void initalise_hooks();

	typedef void(__thiscall *PaintTraverse)(void*, unsigned int, bool, bool);
}; 

extern CHooks Hooks;
