#include "hooks.h"

CRender Render;

VMTHook * PanelHook;

CHooks::PaintTraverse _PaintTraverse;

void __stdcall hk_PaintTraverse(int VGUIPanel, bool ForceRepaint, bool AllowForce)
{
	_PaintTraverse(Interfaces.g_VGuiPanel, VGUIPanel, ForceRepaint, AllowForce);

	if (!strcmp("FocusOverlayPanel", Interfaces.g_VGuiPanel->GetName(VGUIPanel)))
	{
		Render.text("sdk by 21Dogs", 300, 10, g::Consolas, Color(255, 255, 255, 255));
	}
}

void CHooks::initalise_hooks()
{
	PanelHook = new VMTHook((DWORD**)Interfaces.g_VGuiPanel);
	_PaintTraverse = (PaintTraverse)PanelHook->dwHookMethod((DWORD)hk_PaintTraverse, hookIndexes::pt);

	g::Consolas = Interfaces.g_VGuiSurface->CreateFont_();
	Interfaces.g_VGuiSurface->SetFontGlyphSet(g::Consolas, "Consolas", 15, 600, 0, 0, FONTFLAG_OUTLINE);
}