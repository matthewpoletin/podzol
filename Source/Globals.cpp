#include "Globals.h"

extern System* g_system;

void DrawText(const u8g_fntpgm_uint8_t* font, char* text, int posX, int posY)
{
	g_system->GetGraphics()->DrawText(font, MyString(text), Vec2i(posX, posY));
}