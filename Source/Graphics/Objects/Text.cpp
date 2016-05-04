#include "Text.h"

Text::Text(Vec2i pos, MyString string, const u8g_fntpgm_uint8_t* font) : m_pos(pos), m_string(string), m_font(font)
{
}

Text::~Text()
{
}

void Text::Draw(u8g_t* u8g)
{
	u8g_SetFont(u8g, m_font);
	u8g_DrawStr(u8g, m_pos.GetX(), m_pos.GetY(), m_string.c_str());
}