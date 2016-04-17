#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <string.h>

#include "u8glib/u8g.h"

#include "MyString/MyString.h"

class Graphics
{
public:
	Graphics();
	~Graphics();

	bool Init(void);
	void Update(void);
	void DrawText(const u8g_fntpgm_uint8_t* font, MyString text, int posX, int posY);

protected:
private:
	Graphics(const Graphics &c);
	Graphics& operator=(const Graphics &c);

	u8g_t m_u8g;
	u8g_dev_t m_device;

};

#endif //__GRAPHICS_H__