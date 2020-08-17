#pragma once
#include <iostream>
#include <vector>
#include "Card.h"

class Player
{
public:
    Player() noexcept = default;
    void giveCard(Card & card);
    void throwoutCard(Card & card);

protected:

private:
    std::vector<Card> hand{};
};

