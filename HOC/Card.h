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
    //Destructor
    virtual ~Card();
    //String methods
    std::string show();
    std::string getSuitStr();
    std::string getFigureStr();
    //Getters
    CardSuit getSuit() const;
    CardFigure getFigure() const;
    int getCID();
    bool operator ==(const Card& card);
    bool operator >(const Card& card);
    bool operator <(const Card& card);

protected:

private:
    int cID;
    CardSuit suit;
    CardFigure figure;
};

