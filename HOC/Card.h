#pragma once
#include <string>
enum class CardSuit {
    DIAMOND,
    HEART,
    SPADE,
    CLUB
};
enum class CardFigure {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

class Card
{
public:
    static int Id;
    //Constructors
    Card();
    Card(CardSuit s, CardFigure f);
    Card(CardSuit s);
    Card(CardFigure f);
    //String methods
    std::string show() const;
    std::string getSuitStr() const;
    std::string getFigureStr() const;
    //Getters
    CardSuit getSuit() const;
    CardFigure getFigure() const;
    int getCID();
    bool operator ==(const Card& card);
    bool operator >(const Card& card);
    bool operator <(const Card& card);
private:
    int                  cID{ 0 };
    CardSuit             suit{ CardSuit::DIAMOND };
    CardFigure           figure{ CardFigure::ACE };
};

