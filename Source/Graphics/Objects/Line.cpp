#include "Line.h"

Line::Line(Vec2i pos1, Vec2i pos2) : m_pos1(pos1), m_pos2(pos2)
{
}

Line::~Line()
{
}

void Line::Draw(u8g_t* m_u8g)
{
	u8g_DrawLine(m_u8g, m_pos1.GetX(), m_pos1.GetY(), m_pos2.GetX(), m_pos2.GetY());
}