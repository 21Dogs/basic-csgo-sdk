#include "interfaces.h"

typedef void* (*create_interface_fn)(const char *Name, int *ReturnCode);

void* find_interface(const char* Module, const char* InterfaceName)
{
	void* Interface = nullptr;
	auto CreateInterface = reinterpret_cast<create_interface_fn>(GetProcAddress(GetModuleHandleA(Module), "CreateInterface"));

	char PossibleInterfaceName[1024];
	for (int i = 1; i < 100; i++)
	{
		sprintf(PossibleInterfaceName, "%s0%i", InterfaceName, i);
		Interface = CreateInterface(PossibleInterfaceName, 0);
		if (Interface)
			break;

		sprintf(PossibleInterfaceName, "%s00%i", InterfaceName, i);
		Interface = CreateInterface(PossibleInterfaceName, 0);
		if (Interface)
			break;
	}

	return Interface;
}

void CInterfaces::initialise_interfaces()
{
	g_VGuiPanel = reinterpret_cast<IPanel*>(find_interface("vgui2.dll", "VGUI_Panel"));
	g_VGuiSurface = reinterpret_cast<ISurface*>(find_interface("vguimatsurface.dll", "VGUI_Surface"));
}