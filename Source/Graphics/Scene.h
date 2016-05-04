#ifndef __SCENE_H__
#define __SCENE_H__

#include "Objects/IObject.h"
#include "Objects/Text.h"

#include <u8glib/u8g.h>

const size_t sceneLimit = 50;

class Scene
{
public:
	Scene();
	~Scene();

	bool Init(void);
	void Insert(IObject* pOject);
	void Clear(void);
	void DrawScene(u8g_t* u8g);

protected:
private:
	Scene( const Scene &c );
	Scene& operator=( const Scene &c );

	IObject* m_pObjects[sceneLimit];
	unsigned int m_size;

};

#endif //__SCENE_H__