#ifndef __BITMAP_H__
#define __BITMAP_H__

#include "IObject.h"

class Bitmap : IObject
{
public:
	Bitmap(const uint8_t* bitmap, Vec2i pos);
	~Bitmap();

	virtual void Draw(u8g_t* u8g) override;

protected:
private:
	Bitmap( const Bitmap &c );
	Bitmap& operator=( const Bitmap &c );

	const uint8_t* m_pBitmap;
	Vec2i m_pos;

};

#endif //__BITMAP_H__