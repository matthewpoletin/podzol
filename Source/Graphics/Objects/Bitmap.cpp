#include "Bitmap.h"

Bitmap::Bitmap(const uint8_t* bitmap, Vec2i pos) : m_pBitmap(bitmap), m_pos(pos)
{
}

Bitmap::~Bitmap()
{
	//delete m_pBitmap;
}

void Bitmap::Draw(u8g_t* u8g)
{
	u8g_DrawBitmap(u8g, m_pos.GetX(), m_pos.GetY(), 1, 8, m_pBitmap);
}