#include "ColorChangingRect.h"
#include <iostream>
namespace HOC::Rect 
{
	void ColorChangingRect::Init()
	{
		m_rectShape = sf::RectangleShape(sf::Vector2f(100,100));
		m_rectShape.setFillColor(sf::Color::Cyan);
	}

	void ColorChangingRect::Update(float dt)
	{
		switch (m_counter)
		{
		case 1:
			m_rectShape.setFillColor(sf::Color::Green);
			break;
		case 2:
			m_rectShape.setFillColor(sf::Color::Yellow);
			break;
		case 3:
			m_rectShape.setFillColor(sf::Color::Red);
			break;

		default:
			m_rectShape.setFillColor(sf::Color::Cyan);
			break;
		}
		if (m_counter == 3)
		{
			m_counter = 1;
		}
		m_counter++;

	}

	void ColorChangingRect::Draw(sf::RenderWindow& window)
	{
		window.draw(m_rectShape);
	}
	

	ColorChangingRect::ColorChangingRect() :GameObject{}
	{
		m_allObjects.push_back(std::make_shared<ColorChangingRect>(*this));
	}
	void ColorChangingRect::FixedUpdate(float dt)
	{
	}
	void ColorChangingRect::HandleEvent(sf::Event)
	{
	}
}


