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

void InitADC()
{
	ADCSRA |= 1<<ADPS2; // frequency
	ADMUX |= 1<<ADLAR;	// representation
	ADMUX |= 1<<REFS0;	// refference
	ADCSRA |= 1<<ADIE;	// enable adc interrupts
	ADCSRA |= 1<<ADEN;	// enable adc
}

uint16_t ReadADC()
{
	sei();
	ADCSRA|=1<<ADSC;
	return ADC;
}

ISR(ADC_vect)
{
	char adcResult[4];
	itoa(ADCH, adcResult, 10);
	DrawText(u8g_font_4x6, adcResult, 0, 6);

	ADCSRA|=1<<ADSC;
}

int main(void)
{
	g_system = new System();
	g_system->Init();

	InitADC();
	
	//u8g_SetPinInput(PN(0, 0));
	//u8g_SetPinInput(PN(0, 1));
	//u8g_SetPinInput(PN(0, 2));
	//float accelX = 0.0f;
	//, accelY, z;
	//char line1[50];
	
	//char data;
	//, line2[50], line3[50];
	//Vec2i p1(0, 0);

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

	char c[5];
	unsigned int it = 0;

	while(true)
	{
		g_system->GetGraphics()->Update();

		ReadADC();

		//g_system->GetAccelerometer()->Update();
		//accelX = g_system->GetAccelerometer()->GetX();
		//accelY = g_system->GetAccelerometer()->GetY();
		//z = g_system->GetAccelerometer()->GetZ();

		//g_system->GetSR()->Update(200);
		//data = g_system->GetSR()->GetData();

		//sprintf(line1, "x: %4.2F", accelX);
		//sprintf(line2, "y:%2d", y);
		//sprintf(line3, "z:%2d", z);

		//DrawText(u8g_font_4x6, line1, 0, 6);
		//DrawText(u8g_font_4x6, &data, 0, 24);
		//DrawText(u8g_font_4x6, "NO GODS OR KINGS", 0, 6);
		//DrawText(u8g_font_4x6, "ONLY MAN", 0, 40);
		//DrawText(u8g_font_4x6, "", 32, 20);
		//DrawText(u8g_font_4x6, "", 0, 63);
		//DrawPixel(63, 31);
		//DrawLine(0, 0, 127, 63);
		//DrawBitmap(rook_bitmap, 40, 40, 8);

		itoa(it, c, 10);
		DrawText(u8g_font_4x6, c, 116, 6);
		it++;

	}

	return 0;
}