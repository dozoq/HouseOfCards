#include "Deck.h"
Deck::Deck()
{
    std::vector<Card> temp;
    for (int i{ 0 }; i < 4; i++)
    {
        for (int j{ 0 }; j < 14; j++)
        {
            temp.push_back(Card(static_cast<CardSuit>(i), static_cast<CardFigure>(j)));
        }
    }
    std::random_shuffle(temp.begin(), temp.end());
    for (int k{ 0 }; k < temp.size(); k++)
    {
        this->cardstack.push_back(temp[k]);
    }
}
Deck::Deck(int decks)
{
    std::vector<Card> temp;
    for (int d{ 0 }; d < decks; d++)
    {
        for (int i{ 0 }; i < 4; i++)
        {
            for (int j{ 0 }; j < 14; j++)
            {
                temp.push_back(Card(static_cast<CardSuit>(i), static_cast<CardFigure>(j)));
            }
        }
    }
    std::random_shuffle(temp.begin(), temp.end());
    for (int k{ 0 }; k < temp.size(); k++)
    {
        this->cardstack.push_back(temp[k]);
    }
}
Card Deck::peekTop()
{
    if (!this->cardstack.empty()) {
        return this->cardstack.back();
    }
    else
    {
        return Card();
    }
}
void Deck::shuffleDeck() {
    std::vector<Card> temp;
    for (int i{ 0 }; i < this->cardstack.size(); i++)
    {
        temp.push_back(this->cardstack.back());
        this->cardstack.pop_back();
    }
    std::random_shuffle(temp.begin(), temp.end());
    for (int k{ 0 }; k < temp.size(); k++)
    {
        this->cardstack.push_back(temp[k]);
    }
}
void Deck::addToDeck(const Card &card)
{
    this->cardstack.push_back(card);
}
Card Deck::Draw()
{
    if (!this->cardstack.empty()) {
        Card temp = this->cardstack.back();
        this->cardstack.pop_back();
        return temp;
    }
    else
    {
        throw "Empty deck draw!";
        return Card();
    }
}
void Deck::addUnderDeck(const Card& card)
{
    this->cardstack.push_front(card);
}
void Deck::addUnderDeck(const std::vector<Card>& cards)
{
    for (Card c : cards)
    {
        this->addUnderDeck(c);
    }
}
bool Deck::isEmpty() const
{
    return this->cardstack.empty();
}
void Deck::debugDeck()
{
    std::cout << "Deck:" << std::endl;
    for (Card card : this->cardstack)
    {
        std::cout << card.show() << std::endl;
    }
}
int Deck::decksize() const
{
    return this->cardstack.size();
}