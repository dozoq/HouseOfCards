// HOC.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//Standard C/Cpp includes
#include <iostream>
#include <ctime>
#include <time.h>
#include <chrono>
//SFML Includes
#include "SFML/Graphics.hpp"
//My Includes
#include "Card.h"
#include "Deck.h"
#include "War.h"
#include "Object.h"
#include "ColorChangingRect.h"

//Function iterating through all objects and calling their Init() function
void ProcessObjectInit();

//Function iterating through all objects and calling their HandleEvent(sf::Event) function
void ProcessObjectEvent(sf::Event);

//Function iterating through all objects and calling their Draw() function
void ProcessObjectDraw(sf::RenderWindow & window);

//Function iterating through all objects and calling their Update(float) function
void ProcessObjectUpdate(float dt);

//Function iterating through all objects and calling their FixedUpdate(float) function for physics
void ProcessObjectFixedUpdate(float dt);

void Setup();

int main()
{
    //DeltaTime variables
    sf::Clock clock{};
    float dt{ clock.restart().asSeconds() };
    float accumulator{0.f};

    float timestep{ 1.0f / 60.0f };

    //Was drawn in this frame?
    bool            drawn{ false };

    //sf Timer var to handle calculating delta time
    sf::Time Timer = sf::seconds(0.1f);

    //just window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    Setup();
    ProcessObjectInit();

    while (window.isOpen())
    {
        accumulator += clock.getElapsedTime().asSeconds();
        dt = clock.restart().asSeconds();
        sf::Event event;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
            ProcessObjectEvent(event);
        }
        ProcessObjectUpdate(dt);
        while (accumulator >= timestep) 
        {
            accumulator -= timestep;
            ProcessObjectFixedUpdate(timestep);
            drawn = false;
            
            
        }
        
        
        if (drawn) 
        {
            sf::sleep(Timer);
        }
        else
        {
            window.clear();
            ProcessObjectDraw(window);
            window.display();
            drawn = true;
        }
    }

    return 0;

    //std::srand(unsigned(std::time(0))); //Real random cards
    //Card card = Card();
    //Deck* deck1 = new Deck();
    //std::cout << deck1->Draw().show() << " next: " << deck1->peekTop().show() << std::endl;
    //deck1->debugDeck();
    //deck1->addUnderDeck(card);
    //deck1->debugDeck();
    //std::cout << "TOP: " << deck1->Draw().show() << std::endl;
    //War* war1 = new War();
    //war1->start();
    //war1->play();
    //delete war1;
    //getchar();
    //return 0;
}

void ProcessObjectInit()
{
    std::cout << "Init" << std::endl;
    for (auto object : HOC::Game::GameObject::GetObjects()) 
    {
        object->Init();
    }
}

void ProcessObjectEvent(sf::Event event)
{
    std::cout << "Event" << std::endl;
    for (auto object : HOC::Game::GameObject::GetObjects())
    {
        object->HandleEvent(event);
    }
}

void ProcessObjectDraw(sf::RenderWindow & window)
{
    std::cout << "Draw" << std::endl;
    for (auto object : HOC::Game::GameObject::GetObjects())
    {
        object->Draw(window);
    }
}

void ProcessObjectUpdate(float dt)
{
    std::cout << "Update: " << dt << std::endl;
    for (auto object : HOC::Game::GameObject::GetObjects())
    {
        object->Update(dt);
    }
}

void ProcessObjectFixedUpdate(float dt)
{
    std::cout << "FUpdate: " << dt << std::endl;
    for (auto object : HOC::Game::GameObject::GetObjects())
    {
        object->FixedUpdate(dt);
    }
}

void Setup()
{
    HOC::Rect::ColorChangingRect r1{};
}
