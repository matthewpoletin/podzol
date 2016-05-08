#ifndef __LINE_H__
#define __LINE_H__

#include "IObject.h"

class Line : public IObject
{
public:
	Line(Vec2i pos1, Vec2i pos2);
	~Line();

	virtual void Draw(u8g_t* m_u8g) override;

protected:
private:
	Line( const Line &c );
	Line& operator=( const Line &c );

	Vec2i m_pos1;
	Vec2i m_pos2;

};

#endif //__LINE_H__