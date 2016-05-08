#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <u8glib/u8g.h>
#include "MyCpp/MyString.h"
#include "System.h"

void DrawText(const u8g_fntpgm_uint8_t* font, char* text, int posX, int posY);
void DrawPixel(int posX, int posY);
void DrawLine(int pos1X, int pos1Y, int pos2X, int pos2Y);
//void DrawCircle(int posX, int posY, int radius, int option);
void DrawBitmap(const uint8_t* bitmap, int posX, int posY, int height);

#endif /* GLOBALS_H_ */