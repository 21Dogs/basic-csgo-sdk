#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdarg.h>

#include "../main/interfaces.h"
#include "../misc/globals.h"

class CRender
{
public:
	DWORD Consolas;

	void text(char* text, int x, int y, int font, Color col);
	void box(int x, int y, int w, int h, Color col);
	void filledbox(int x, int y, int w, int h, Color col);
	void filledborderedbox(int x, int y, int w, int h, int t, Color col);
};

extern CRender Render;
