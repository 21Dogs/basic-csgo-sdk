#include "menu.h"

void CMenu::paint()
{
	if (GetAsyncKeyState(VK_INSERT) & 1) variables.menu_opened = !variables.menu_opened;

	if (variables.menu_opened)
	{
		// go crazy :)
	}
}