#include "Globals.h"

extern System* g_system;

void DrawText(const u8g_fntpgm_uint8_t* font, char* text, int posX, int posY)
{
	g_system->GetGraphics()->DrawText(font, MyString(text), Vec2i(posX, posY));
}

void DrawPixel(int posX, int posY)
{
	g_system->GetGraphics()->DrawPixel(Vec2i(posX, posY));
}

void DrawLine(int pos1X, int pos1Y, int pos2X, int pos2Y)
{
	g_system->GetGraphics()->DrawLine(Vec2i(pos1X, pos1Y), Vec2i(pos2X, pos2Y));
}

//void DrawCircle(int posX, int posY, int radius, int option)
//{
//
//}

void DrawBitmap(const uint8_t* bitmap, int posX, int posY, int height)
{
	g_system->GetGraphics()->DrawBitmap(Vec2i(posX, posY), bitmap);
}
//
//void GetSystem(void)
//{
	//return g_system;
//}
//
//void GetADC(void)
//{
	//return g_system->GetADC();
//}