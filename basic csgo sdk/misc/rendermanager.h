#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdarg.h>

#include "../main/interfaces.h"

class CRender
{
public:
	DWORD Consolas;

	void text(char* text, int x, int y, int font, Color col);
	void filledbox(int x, int y, int w, int h, Color col);
};

extern CRender Render;
