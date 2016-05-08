#ifndef __PIXEL_H__
#define __PIXEL_H__

#include "IObject.h"
#include "../../Maths/Vec2i.h"

class Pixel : public IObject
{
public:
	Pixel(Vec2i pos);
	~Pixel();

	virtual void Draw(u8g_t* u8g) override;

protected:
private:
	Pixel( const Pixel &c );
	Pixel& operator=( const Pixel &c );

	Vec2i m_pos;

};

#endif //__PIXEL_H__