#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string.h>
#include "utilities.h"


class Player
{
    char* m_name;
    int m_level;
    int m_maxHP;
    int m_force;
    int m_healthPoints;
    int m_coins;

    public:
    // c'tor
    Player(const char* m_name, int m_maxHP = 100, int m_force = 5);
    //copy c'tor
    Player(const Player& player);
    //assignment operator
    Player& operator=(const Player& other);
    //d'tor
    ~Player();

    //prints player info using aux function from utilities
    void printInfo() const;
    
    //bumps the player's level by 1
    void levelUp();

    //level getter
    int getLevel() const;
    
    //increases player's force by buffAmount
    void buff(int buffAmount);
    
    //heals player's HP by healAmount
    void heal(int healAmount);

    //damages players by damageAmount
    void damage(int damageAmount);

    //if healthPoints is 0 returns true - is knocked out
    bool isKnockedOut() const;

    //adds coins
    void addCoins(int addition);

    //performs payment and returns true if it succeeds or false if it fails
    bool pay(int coinsAmount);

    // returns attack strength which is level + force
    int getAttackStrength() const;
    
};

#endif //EX2_Player_H