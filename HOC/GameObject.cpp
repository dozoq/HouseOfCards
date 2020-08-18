#include "GameObject.h"
#include <iostream>
namespace HOC::Game {
	std::vector< std::shared_ptr<GameObject>> GameObject::m_allObjects{};

	void GameObject::Init()
	{
		std::cout << "BaseInit" << std::endl;
	}

	void GameObject::Update(float dt)
	{
	}

	void GameObject::FixedUpdate(float dt)
	{
	}

	void GameObject::Draw(sf::RenderWindow& window)
	{
	}

	void GameObject::HandleEvent(sf::Event)
	{
	}

	std::vector< std::shared_ptr<GameObject>> GameObject::GetObjects()
	{
		return m_allObjects;
	}

	GameObject::GameObject()
	{
	}
}