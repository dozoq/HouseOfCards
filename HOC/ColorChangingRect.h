#pragma once
#include "GameObject.h"
namespace HOC::Rect {
	class ColorChangingRect :
		public Game::GameObject
	{
	public:
		virtual void Init() override;
		virtual void Update(float dt) override;
		virtual void Draw(sf::RenderWindow & window) override;
		virtual void FixedUpdate(float dt) override;
		virtual void HandleEvent(sf::Event) override;
		ColorChangingRect();

	private:
		sf::RectangleShape		m_rectShape{};
		int						m_counter{1};

		
	};
}

