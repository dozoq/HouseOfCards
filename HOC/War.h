#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include "Deck.h"
#include "Card.h"

class War
{
public:
    War() noexcept = default;
    void start();
    void play();
    std::vector<Card> playerCardsInWar;
    std::vector<Card> computerCardsInWar;
    Card playerWarCard{};
    Card computerWarCard{};
protected:

private:
    void compareAndRemove();
    Deck computerDeck{};
    Deck playerDeck{};


};
