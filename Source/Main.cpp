//**************************************************************//
//System Clock			:1MHz
//Software				:Atmel Studio 7
//LCD Data Interfacing	:8-Bit
//Created:				15.03.2016 13:06:25
//Author :				Matthew Poletin
//**************************************************************//

#include <stdio.h>
#include <string.h>

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <stdlib.h>

#include "Globals.h"
#include "System.h"
#include "MyCpp/MyString.h"

extern System* g_system;

int main(void)
{
	g_system = new System();
	g_system->Init();

	int accelX;
	//, accelY, z;
	//char data[1];
//
	char line1[50], line2[50], line3[50];
	//Point p1(0,0,0);
//
	//const uint8_t rook_bitmap[] PROGMEM = {
		//0b00000000,         // 00000000
		//0b01010101,         // 01010101
		//0b01111111,         // 01111111
		//0b00111110,         // 00111110
		//0b00111110,         // 00111110
		//0b00111110,         // 00111110
		//0b00111110,         // 00111110
		//0b01111111          // 01111111
	//};
	//u8g_DrawBitmap(&m_u8g, 10, 10, 1, 8, rook_bitmap);

	char c[5];
	unsigned int it = 0;

	while(true)
	{
		g_system->GetGraphics()->Update();
		//g_system->GetAccelerometer()->Update();
		//accelX = g_system->GetAccelerometer()->GetX();
		//accelY = g_system->GetAccelerometer()->GetY();
		//z = g_system->GetAccelerometer()->GetZ();

		//data[0] = g_system->GetSR()->Update(100);

		//sprintf(line1, "x: %2d", accelX);
		//sprintf(line2, "y:%2d", y);
		//sprintf(line3, "z:%2d", z);

		itoa(it, c, 10);
		DrawText(u8g_font_4x6, c, 0, 12);
		it++;
		//g_system->GetGraphics()->DrawText(u8g_font_4x6, line1, 0, 6);
		//g_system->GetGraphics()->DrawText(u8g_font_4x6, line2, 5, 12);
		//g_system->GetGraphics()->DrawText(u8g_font_4x6, line3, 10, 18);
		//g_system->GetGraphics()->DrawText(u8g_font_baby, MyString("Hello"), 0, 15);
		//g_system->GetGraphics()->DrawLine(p1, p1);

		//g_system->GetGraphics()->DrawText(u8g_font_4x6, MyString(data), 0 , 24);


		//g_system->GetGraphics()->DrawLine(p1, p1);

		DrawText(u8g_font_4x6, "Hello", 0, 6);
		DrawText(u8g_font_4x6, "My friend", 0, 40);
	}

	return 0;
}