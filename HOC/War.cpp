#include "War.h"


void War::start()
{
    Deck temp = Deck(1);
    for (int i{ 2 }; i < 54; i++)
    {
        if (i % 2 == 0)
        {
            this->playerDeck.addToDeck(temp.Draw());
        }
        else {
            this->computerDeck.addToDeck(temp.Draw());
        }
    }
    std::cout << this->playerDeck.peekTop().show() << std::endl;
}
void War::play()
{
    bool play = true;
    while (play)
    {
        system("cls");
        std::cout << "Round starts:" << std::endl;
        this->playerWarCard = this->playerDeck.Draw();
        this->computerWarCard = this->computerDeck.Draw();
        std::cout << "Player Card:" << this->playerWarCard.show() << " Deck size: " << playerDeck.decksize() << std::endl << "Computer Card:" << this->computerWarCard.show() << " Deck size: " << computerDeck.decksize() << std::endl;
        this->compareAndRemove();
        std::cout << "Deck sum size:" << this->playerDeck.decksize() + this->computerDeck.decksize() << std::endl;
        if (this->playerDeck.isEmpty() || this->computerDeck.isEmpty())
        {
            play = false;
        }
        getchar();
    }
}
void War::compareAndRemove()
{
    if (this->playerWarCard > this->computerWarCard)
    {
        int randomizer = rand() % 2 + 1;
        std::cout << "Player Win Round!" << std::endl;
        if (randomizer == 1) {
            this->playerDeck.addUnderDeck(this->playerWarCard);
            this->playerDeck.addUnderDeck(this->computerWarCard);
            this->playerDeck.addUnderDeck(this->playerCardsInWar);
            this->playerDeck.addUnderDeck(this->computerCardsInWar);
        }
        else {
            this->playerDeck.addUnderDeck(this->computerWarCard);
            this->playerDeck.addUnderDeck(this->playerWarCard);
            this->playerDeck.addUnderDeck(this->computerCardsInWar);
            this->playerDeck.addUnderDeck(this->playerCardsInWar);
        }

        this->computerCardsInWar.clear();
        this->playerCardsInWar.clear();
    }
    else if (this->playerWarCard == this->computerWarCard)
    {
        std::cout << "War!" << std::endl;
        this->playerCardsInWar.push_back(this->playerWarCard);
        this->playerCardsInWar.push_back(this->playerDeck.Draw());
        this->computerCardsInWar.push_back(this->computerWarCard);
        this->computerCardsInWar.push_back(this->computerDeck.Draw());
        this->playerWarCard = this->playerDeck.Draw();
        this->computerWarCard = this->computerDeck.Draw();
        this->compareAndRemove();

    }
    else
    {
        int randomizer = rand() % 2 + 1;
        std::cout << "Computer Win Round!" << std::endl;
        if (randomizer == 1) {
            this->computerDeck.addUnderDeck(this->playerWarCard);
            this->computerDeck.addUnderDeck(this->computerWarCard);
            this->computerDeck.addUnderDeck(this->playerCardsInWar);
            this->computerDeck.addUnderDeck(this->computerCardsInWar);
        }
        else
        {
            this->computerDeck.addUnderDeck(this->computerWarCard);
            this->computerDeck.addUnderDeck(this->playerWarCard);
            this->computerDeck.addUnderDeck(this->computerCardsInWar);
            this->computerDeck.addUnderDeck(this->computerCardsInWar);
        }

        this->computerCardsInWar.clear();
        this->playerCardsInWar.clear();
    }
}