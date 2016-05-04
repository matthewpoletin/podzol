#include "Line.h"

Line::Line()
{
}

Line::~Line()
{
}

void Line::Draw(u8g_t &m_u8g)
{
	u8g_DrawLine(&m_u8g, m_pos.GetX(), m_pos.GetY(), m_pos2.GetX(), m_pos2.GetY());
}