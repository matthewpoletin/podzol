#include "Pixel.h"

 Pixel::Pixel(Vec2i pos) : m_pos(pos)
{
}

Pixel::~Pixel()
{
}

void Pixel::Draw(u8g_t* u8g)
{
	u8g_DrawPixel(u8g, m_pos.GetX(), m_pos.GetY());
}
