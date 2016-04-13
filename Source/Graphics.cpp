#include "Graphics.h"

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
}

bool Graphics::Init(void)
{
	///* activate pull-up, set ports to output, init U8glib */
	//u8g_SetPinInput(PN(2,5)); u8g_SetPinLevel(PN(2,5), 1); u8g_SetPinOutput(PN(2,5));
	////u8g_SetPinInput(PN(2,4)); u8g_SetPinLevel(PN(2,4), 1); u8g_SetPinOutput(PN(2,4));
	m_device = u8g_dev_ks0108_128x64_fast;

	//u8g_Init8Bit(&u8g, &u8g_dev_ks0108_128x64_fast, PN(PORTC, 0), PN(PORTC, 1), PN(PORTC, 2), PN(PORTC, 3), PN(PORTC, 4), PN(PORTC, 5), PN(PORTC, 6), PN(PORTC, 7), PN(PORTD, 4), PN(PORTD, 0), PN(PORTD, 1), 0, PN(PORTD, 3), PN(PORTD, 2));

	return true;
}

// DrawText(u8g_font_6x10, .., .., ..);
void Graphics::DrawText(u8g_fntpgm_uint8_t font, char* text, int posX, int posY)
{
	//u8g_SetFont(&u8g, font);
	//u8g_DrawStr(&u8g, posX, posY, text);
}