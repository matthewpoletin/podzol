#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <string.h>

#include "u8glib/u8g.h"

#include "../Maths/Point.h"
#include "../MyCpp/MyString.h"
#include "Scene.h"

class Graphics
{
public:
	Graphics();
	~Graphics();

	bool Init(void);
	void Update(void);
	void Clear(void);

	void DrawText(const u8g_fntpgm_uint8_t* font, MyString text, Vec2i pos);
	void DrawLine(Point p1, Point p2);
	void DrawBitmap(Point pos, const uint8_t* bitmap);

protected:
private:
	Graphics(const Graphics &c);
	Graphics& operator=(const Graphics &c);

	u8g_t m_u8g;
	u8g_dev_t m_device;

	Scene* m_pScene;

};

#endif //__GRAPHICS_H__