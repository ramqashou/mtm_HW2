#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) : m_player(playerName), m_numOfCards(numOfCards),
                                                                                     m_gameStatus(GameStatus::MidGame), m_CurrentCard(0)
{
    this->m_cardsArray = new Card[numOfCards];
    for (int i = 0; i < numOfCards; i++)
    {
        m_cardsArray[i] = cardsArray[i];
    }
}

void Mtmchkin::playNextCard()
{
    this->m_cardsArray[this->m_CurrentCard].printInfo();
    this->m_cardsArray[this->m_CurrentCard].applyEncounter(this->m_player);
    this->m_player.printInfo();
    this->m_CurrentCard++;
    if(this->m_CurrentCard == this->m_numOfCards)
    {
        this->m_CurrentCard = 0;
    }
    if(this->m_player.getLevel() == 10)
    {
        this->m_gameStatus = GameStatus::Win;
    }
    if(this->m_player.isKnockedOut())
    {
        this->m_gameStatus = GameStatus::Loss;
    }
}

bool Mtmchkin::isOver() const
{
    if (this->m_gameStatus == GameStatus::MidGame)
    {
        return false;
    }
    return true;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return this->m_gameStatus;
}

Mtmchkin::~Mtmchkin()
{
    delete[] this->m_cardsArray;
}

Mtmchkin::Mtmchkin(const Mtmchkin &game) : m_player(game.m_player), m_numOfCards(game.m_numOfCards),
                                           m_gameStatus(game.m_gameStatus), m_CurrentCard(game.m_CurrentCard)
{
    this->m_cardsArray = new Card[game.m_numOfCards];
    for (int i = 0; i < game.m_numOfCards; i++)
    {
        m_cardsArray[i] = game.m_cardsArray[i];
    }
}

Mtmchkin &Mtmchkin::operator=(const Mtmchkin &other)
{
    delete this->m_cardsArray;
    this->m_cardsArray = new Card[other.m_numOfCards];
    for (int i = 0; i < other.m_numOfCards; i++)
    {
        m_cardsArray[i] = other.m_cardsArray[i];
    }
    this->m_gameStatus = other.m_gameStatus;
    this->m_numOfCards = other.m_numOfCards;
    this->m_player = other.m_player;
    this->m_CurrentCard = other.m_CurrentCard;

    return *this;
}