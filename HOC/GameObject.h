#pragma once
#include "Object.h"
namespace HOC::Game {
	class GameObject :
		public ENGINE::Object
	{
	public:
		// Odziedziczono za pośrednictwem elementu Object
		virtual void Init() override;
		virtual void Update(float dt) override;
		virtual void FixedUpdate(float dt) override;
		virtual void Draw(sf::RenderWindow& window) override;
		virtual void HandleEvent(sf::Event) override;

		static std::vector<std::shared_ptr<GameObject>> GetObjects();
		static std::vector<std::shared_ptr<GameObject>> m_allObjects;
		GameObject();
	};
}
