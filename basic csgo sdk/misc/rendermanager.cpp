#include "rendermanager.h"


void CRender::text(char* text, int x, int y, int font, Color col)
{
	char Buffer[1024] = { '\0' };

	va_list Args;
	va_start(Args, text);
	vsprintf_s(Buffer, text, Args);
	va_end(Args);

	size_t Size = strlen(Buffer) + 1;

	wchar_t* WideBuffer = new wchar_t[Size];
	mbstowcs_s(0, WideBuffer, Size, Buffer, Size - 1);

	Interfaces.g_VGuiSurface->DrawSetTextColor(col);
	Interfaces.g_VGuiSurface->DrawSetTextFont(font);
	Interfaces.g_VGuiSurface->DrawSetTextPos(x, y);
	Interfaces.g_VGuiSurface->DrawPrintText(WideBuffer, Size, FONT_DRAW_DEFAULT);
}