#include "Graphics.h"

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
}

bool Graphics::Init(void)
{
	/* activate pull-up, set ports to output, init U8glib */
	u8g_SetPinInput(PN(2,0)); u8g_SetPinLevel(PN(2,0), 1); u8g_SetPinOutput(PN(2,0));
	u8g_SetPinInput(PN(2,1)); u8g_SetPinLevel(PN(2,1), 1); u8g_SetPinOutput(PN(2,1));
	u8g_SetPinInput(PN(2,2)); u8g_SetPinLevel(PN(2,2), 1); u8g_SetPinOutput(PN(2,2));
	u8g_SetPinInput(PN(2,3)); u8g_SetPinLevel(PN(2,3), 1); u8g_SetPinOutput(PN(2,3));
	u8g_SetPinInput(PN(2,4)); u8g_SetPinLevel(PN(2,4), 1); u8g_SetPinOutput(PN(2,4));
	u8g_SetPinInput(PN(2,5)); u8g_SetPinLevel(PN(2,5), 1); u8g_SetPinOutput(PN(2,5));
	u8g_SetPinInput(PN(2,6)); u8g_SetPinLevel(PN(2,6), 1); u8g_SetPinOutput(PN(2,6));
	u8g_SetPinInput(PN(2,7)); u8g_SetPinLevel(PN(2,7), 1); u8g_SetPinOutput(PN(2,7));

	m_device = u8g_dev_ks0108_128x64;

	u8g_Init8Bit(&m_u8g, &u8g_dev_ks0108_128x64_fast, PN(2, 0), PN(2, 1), PN(2, 2), PN(2, 3), PN(2, 4), PN(2, 5), PN(2, 6), PN(2, 7), PN(3, 4), PN(3, 0), PN(3, 1), 0, PN(3, 3), PN(3, 2));

	u8g_FirstPage(&m_u8g);

	return true;
}

// DrawText(u8g_font_6x10, .., .., ..);
void Graphics::DrawText(const u8g_fntpgm_uint8_t* font, char* text, int posX, int posY)
{
	u8g_SetFont(&m_u8g, font);
	u8g_DrawStr(&m_u8g, posX, posY, text);
}

void Graphics::Update(void)
{
	u8g_NextPage(&m_u8g);
}

//for(;;)
//{
//u8g_FirstPage(&u8g);
//do
//{
//draw();
//} while ( u8g_NextPage(&u8g) );
//u8g_Delay(100);
//}