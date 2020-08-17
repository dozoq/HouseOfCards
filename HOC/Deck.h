#pragma once
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include "Card.h"


class Deck
{
public:
    Deck();
    Deck(int decks);
    Card peekTop();
    void shuffleDeck();
    Card Draw();
    void addToDeck(const Card &card);
    void addUnderDeck(const Card &card);
    void addUnderDeck(const std::vector<Card> &cards);
    void debugDeck();
    bool isEmpty() const;
    int decksize() const;
protected:

private:
    std::deque<Card> cardstack{};
};

