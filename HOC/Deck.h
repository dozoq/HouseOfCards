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
    virtual ~Deck();
    Card peekTop();
    void shuffleDeck();
    Card Draw();
    void addToDeck(Card card);
    void addUnderDeck(Card card);
    void addUnderDeck(std::vector<Card> cards);
    void debugDeck();
    bool isEmpty() const;
    int decksize() const;
protected:

private:
    std::deque<Card> cardstack;
};

