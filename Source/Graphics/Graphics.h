#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <string.h>

#include "u8glib/u8g.h"

#include "../MyCpp/MyString.h"
#include "Scene.h"
#include "Objects/Pixel.h"
#include "Objects/Text.h"
#include "Objects/Line.h"
//#include "Objects/Circle.h"
#include "Objects/Bitmap.h"

class Graphics
{
public:
	Graphics();
	~Graphics();

	bool Init(void);
	void Update(void);
	void Clear(void);

	void DrawPixel(Vec2i pos);
	void DrawText(const u8g_fntpgm_uint8_t* font, MyString text, Vec2i pos);
	void DrawLine(Vec2i p1, Vec2i p2);
	//void DrawCircle(Vec2i pos, Vec2i rad);
	void DrawBitmap(Vec2i pos, const uint8_t* bitmap);

protected:
private:
	Graphics(const Graphics &c);
	Graphics& operator=(const Graphics &c);

	u8g_t m_u8g;
	u8g_dev_t m_device;

	Scene* m_pScene;

};

#endif //__GRAPHICS_H__