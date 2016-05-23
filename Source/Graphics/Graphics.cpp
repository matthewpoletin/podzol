#include "Graphics.h"

Graphics::Graphics()
{
	m_pScene = new Scene();
}

Graphics::~Graphics()
{
}

bool Graphics::Init(void)
{
	/* activate pull-up, set ports to output, init U8glib */
	u8g_SetPinInput(PN(1,0)); u8g_SetPinLevel(PN(1,0), 1); u8g_SetPinOutput(PN(1,0));
	u8g_SetPinInput(PN(1,1)); u8g_SetPinLevel(PN(1,1), 1); u8g_SetPinOutput(PN(1,1));
	u8g_SetPinInput(PN(1,2)); u8g_SetPinLevel(PN(1,2), 1); u8g_SetPinOutput(PN(1,2));
	u8g_SetPinInput(PN(1,3)); u8g_SetPinLevel(PN(1,3), 1); u8g_SetPinOutput(PN(1,3));
	u8g_SetPinInput(PN(1,4)); u8g_SetPinLevel(PN(1,4), 1); u8g_SetPinOutput(PN(1,4));
	u8g_SetPinInput(PN(1,5)); u8g_SetPinLevel(PN(1,5), 1); u8g_SetPinOutput(PN(1,5));
	u8g_SetPinInput(PN(1,6)); u8g_SetPinLevel(PN(1,6), 1); u8g_SetPinOutput(PN(1,6));
	u8g_SetPinInput(PN(1,7)); u8g_SetPinLevel(PN(1,7), 1); u8g_SetPinOutput(PN(1,7));

	u8g_SetPinInput(PN(3,0)); u8g_SetPinLevel(PN(3,0), 1); u8g_SetPinOutput(PN(3,0));
	u8g_SetPinInput(PN(3,1)); u8g_SetPinLevel(PN(3,1), 1); u8g_SetPinOutput(PN(3,1));
	u8g_SetPinInput(PN(3,2)); u8g_SetPinLevel(PN(3,2), 1); u8g_SetPinOutput(PN(3,2));
	u8g_SetPinInput(PN(3,3)); u8g_SetPinLevel(PN(3,3), 1); u8g_SetPinOutput(PN(3,3));
	u8g_SetPinInput(PN(3,4)); u8g_SetPinLevel(PN(3,4), 1); u8g_SetPinOutput(PN(3,4));
	u8g_SetPinInput(PN(3,5)); u8g_SetPinLevel(PN(3,5), 1); u8g_SetPinOutput(PN(3,5));
	u8g_SetPinInput(PN(3,6)); u8g_SetPinLevel(PN(3,6), 1); u8g_SetPinOutput(PN(3,6));
	u8g_SetPinInput(PN(3,7)); u8g_SetPinLevel(PN(3,7), 1); u8g_SetPinOutput(PN(3,7));

	//m_device = u8g_dev_ks0108_128x64;
	m_device = u8g_dev_ks0108_128x64_fast;

	u8g_Init8Bit(&m_u8g, &m_device, PN(1,0), PN(1,1), PN(1,2), PN(1,3), PN(1,4), PN(1,5), PN(1,6), PN(1,7), PN(3,0), PN(3,6), PN(3, 5), PN(3, 2), PN(3, 1), PN(3,4));

	u8g_SetContrast(&m_u8g, 100);
	u8g_SetColorIndex(&m_u8g, 1);

	u8g_SetRot180(&m_u8g);

	m_pScene->Init();

	return true;
}

void Graphics::Update(void)
{
	u8g_FirstPage(&m_u8g);
	do 
	{
		m_pScene->DrawScene(&m_u8g);
	} while (u8g_NextPage(&m_u8g));
	m_pScene->Clear();
}

void Graphics::Clear(void)
{
	u8g_FirstPage(&m_u8g);
	do {
	} while( u8g_NextPage(&m_u8g) );
}

void Graphics::DrawPixel(Vec2i pos)
{
	Pixel* pPixel = new Pixel(pos);
	m_pScene->Insert(pPixel);
}

void Graphics::DrawText(const u8g_fntpgm_uint8_t* font, MyString text, Vec2i pos)
{
	Text* pText = new Text(pos, text, font);
	m_pScene->Insert(pText);
}

void Graphics::DrawLine(Vec2i p1, Vec2i p2)
{
	Line* pLine = new Line(p1, p2);
	m_pScene->Insert(pLine);
}

void Graphics::DrawBitmap(Vec2i pos, const uint8_t* bitmap)
{
	//Bitmap* pBitmap = new Bitmap(bitmap, pos);
	//m_pScene->Insert(pBitmap);
}