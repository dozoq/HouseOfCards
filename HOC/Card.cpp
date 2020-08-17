#include "Card.h"
int Card::Id = 0;
Card::Card() : suit(CardSuit::DIAMOND), figure(CardFigure::ACE) {
    this->cID = Card::Id++;
}
Card::Card(CardSuit s) : suit(s), figure(CardFigure::ACE) {
    this->cID = Card::Id++;
}
Card::Card(CardFigure f) : suit(CardSuit::DIAMOND), figure(f) {
    this->cID = Card::Id++;
}
Card::Card(CardSuit s, CardFigure f) : suit(s), figure(f) {
    this->cID = Card::Id++;
}
std::string Card::show() const
{
    std::string message;
    message.append(this->getFigureStr());
    message.append(" Of ");
    message.append(this->getSuitStr());
    message.append("'s (");
    message.append(std::to_string(this->cID));
    message.append(")");
    return message;

}
CardSuit Card::getSuit() const
{
    return this->suit;
}
CardFigure Card::getFigure() const
{
    return this->figure;
}
std::string Card::getSuitStr() const
{
    std::string suitStr;
    switch (this->suit)
    {
    case CardSuit::DIAMOND:
        suitStr = "Diamond";
        break;
    case CardSuit::CLUB:
        suitStr = "Club";
        break;
    case CardSuit::HEART:
        suitStr = "Heart";
        break;
    case CardSuit::SPADE:
        suitStr = "Spade";
        break;
    }
    return suitStr;
}
std::string Card::getFigureStr() const
{
    std::string figureStr{};
    switch (this->figure)
    {
    case CardFigure::TWO:
        figureStr = "Two";
        break;
    case CardFigure::THREE:
        figureStr = "Three";
        break;
    case CardFigure::FOUR:
        figureStr = "Four";
        break;
    case CardFigure::FIVE:
        figureStr = "Five";
        break;
    case CardFigure::SIX:
        figureStr = "Six";
        break;
    case CardFigure::SEVEN:
        figureStr = "Seven";
        break;
    case CardFigure::EIGHT:
        figureStr = "Eight";
        break;
    case CardFigure::NINE:
        figureStr = "Nine";
        break;
    case CardFigure::TEN:
        figureStr = "Ten";
        break;
    case CardFigure::JACK:
        figureStr = "Jack";
        break;
    case CardFigure::QUEEN:
        figureStr = "Queen";
        break;
    case CardFigure::KING:
        figureStr = "King";
        break;
    case CardFigure::ACE:
        figureStr = "Ace";
        break;
    }
    return figureStr;
}
int Card::getCID() {
    return this->cID;
}
bool Card::operator==(const Card& card)
{
    if (this->figure == card.getFigure())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Card::operator >(const Card& card)
{
    if (static_cast<int>(this->figure) > static_cast<int>(card.getFigure()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Card::operator <(const Card& card)
{
    if (static_cast<int>(this->figure) < static_cast<int>(card.getFigure()))
    {
        return true;
    }
    else
    {
        return false;
    }
}