// HOC.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <ctime>
#include "Card.h"
#include "Deck.h"
#include "War.h"


int main()
{

    std::srand(unsigned(std::time(0))); //Real random cards
    Card card = Card();
    Deck* deck1 = new Deck();
    std::cout << deck1->Draw().show() << " next: " << deck1->peekTop().show() << std::endl;
    deck1->debugDeck();
    deck1->addUnderDeck(card);
    deck1->debugDeck();
    std::cout << "TOP: " << deck1->Draw().show() << std::endl;
    War* war1 = new War();
    war1->start();
    war1->play();
    getchar();
    return 0;
}
