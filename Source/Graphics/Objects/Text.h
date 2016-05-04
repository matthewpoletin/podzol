#ifndef __TEXT_H__
#define __TEXT_H__

#include "IObject.h"
#include "../../MyCpp/MyString.h"

class Text : public IObject
{
public:
	Text(Vec2i pos, MyString string, const u8g_fntpgm_uint8_t* font);
	~Text();

	virtual void Draw(u8g_t* u8g) override;

protected:
private:
	Text( const Text &c );
	Text& operator=( const Text &c );

	Vec2i m_pos;
	MyString m_string;
	const u8g_fntpgm_uint8_t* m_font;

};

#endif //__TEXT_H__