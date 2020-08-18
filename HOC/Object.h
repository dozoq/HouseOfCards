#pragma once
#include <vector>
#include <memory>
#include "SFML/Graphics.hpp"

namespace HOC::ENGINE{
class Object
{
public:
	//Initialization of object
	virtual void Init() = 0;
	//Update of object, logic only
	virtual void Update(float dt) = 0;
	//Physics/Fixed update for object
	virtual void FixedUpdate(float dt) = 0;
	//Draw for object
	virtual void Draw(sf::RenderWindow& window) = 0;
	//Event handle for object
	virtual void HandleEvent(sf::Event) = 0;
};
}
