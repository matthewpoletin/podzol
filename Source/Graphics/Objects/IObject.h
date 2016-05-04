#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "../../Maths/Vec2i.h"

#include <u8glib/u8g.h>

class IObject
{
public:
	virtual ~IObject() {}

	virtual void Draw(u8g_t* m_u8g) = 0;
};

#endif //__OBJECT_H__