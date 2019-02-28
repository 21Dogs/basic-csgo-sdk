#include "hooks.h"

CRender Render;
CMenu Menu;

VMTHook * PanelHook;

CHooks::PaintTraverse _PaintTraverse;

HMODULE library;

void __stdcall hk_PaintTraverse(int VGUIPanel, bool ForceRepaint, bool AllowForce)
{
	_PaintTraverse(Interfaces.g_VGuiPanel, VGUIPanel, ForceRepaint, AllowForce);

	if (!strcmp("FocusOverlayPanel", Interfaces.g_VGuiPanel->GetName(VGUIPanel)))
	{
		Render.text("sdk by 21Dogs", 300, 10, g::Consolas, Color(255, 255, 255, 255));

		Menu.paint();
	}
}

void CHooks::initalise_hooks()
{
	PanelHook = new VMTHook((DWORD**)Interfaces.g_VGuiPanel);
	_PaintTraverse = (PaintTraverse)PanelHook->dwHookMethod((DWORD)hk_PaintTraverse, hookIndexes::pt);

	g::Consolas = Interfaces.g_VGuiSurface->CreateFont_();
	Interfaces.g_VGuiSurface->SetFontGlyphSet(g::Consolas, "Consolas", 15, 600, 0, 0, FONTFLAG_OUTLINE);

	while (TRUE)
	{
		if (GetAsyncKeyState(VK_DELETE) & 1)
		{
			if (PanelHook) PanelHook->~VMTHook();
			FreeConsole();
			FreeLibraryAndExitThread(library, true);
		}
	}
}