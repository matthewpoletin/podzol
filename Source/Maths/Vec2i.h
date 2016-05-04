#ifndef __VEC2I_H__
#define __VEC2I_H__

class Vec2i
{
public:
	Vec2i();
	//Vec2i(Vec2i &c);
	Vec2i(int x, int y);
	~Vec2i();

	Vec2i& operator=(const Vec2i &c);

	inline int& GetX(void) { return m_x; }
	inline int& GetY(void) { return m_y; }

protected:
private:

	int m_x;
	int m_y;

};

#endif //__VEC2I_H__