#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "u8glib/u8g.h"

class Graphics
{
public:
	Graphics();
	~Graphics();

	bool Init(void);
	void DrawText(const u8g_fntpgm_uint8_t* font, char* text, int posX, int posY);
	void Update(void);

protected:
private:
	Graphics(const Graphics &c);
	Graphics& operator=(const Graphics &c);

	u8g_t m_u8g;
	u8g_dev_t m_device;

};

#endif //__GRAPHICS_H__