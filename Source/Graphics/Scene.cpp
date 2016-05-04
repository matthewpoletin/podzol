#include "Scene.h"

Scene::Scene() : m_size(0)
{
	for (unsigned int counter = 0; counter < sceneLimit; counter++)
	{
		m_pObjects[counter] = nullptr;
	}
}

Scene::~Scene()
{

}

bool Scene::Init(void)
{
	return true;
}

void Scene::Insert(IObject* pOject)
{
	m_pObjects[m_size] = pOject;
	m_size++;
}

void Scene::Clear(void)
{
	for (unsigned int counter = 0; counter < sceneLimit; counter++)
	{
		m_pObjects[counter] = nullptr;
	}
	m_size = 0;
}

void Scene::DrawScene(u8g_t* u8g)
{
	for (unsigned int counter = 0; counter < m_size; counter++)
	{
		m_pObjects[counter]->Draw(u8g);
	}
}
