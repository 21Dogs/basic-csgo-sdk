// sdk by 21Dogs
//
// credits -
// pantsusdk - vmt hooking method
// antario - Render.Text func & global font concept
// penersdk - automatically updating interface function

#include <windows.h>
#include <iostream>

#include "hooks.h"
#include "interfaces.h"

CHooks Hooks;
CInterfaces Interfaces;

void WINAPI initial_thread()
{
	AllocConsole();
	SetConsoleTitleA("debugging console");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);

	std::cout << "initial thread created" << std::endl;

	Interfaces.initialise_interfaces();
	Hooks.initalise_hooks();

	return;
}

BOOL WINAPI DllMain(HMODULE hmInstance, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)initial_thread, NULL, NULL, NULL);
		break;

	default:
		break;
	}

	return 1;
}