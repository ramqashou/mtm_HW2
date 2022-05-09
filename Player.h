#ifndef EX2_PLayer_H
#define EX2_Player_H

#include <string>
#include "utilities.h"


class Player 
{
    char* name;
    int level;
    int force;
    int maxHP;
    int healthPoints;
    int coins;

    public:
    // c'tor
    Player(char* name, int maxHP = 100, int force = 5);
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

    //if healthpoints is 0 returns true - is knocked out
    bool isKnockedOut() const;

    //adds coins
    void addCoins(int addition);

    //performs payment and returns true if it succeeds or false if it fails
    bool pay(int coins);

    // returns attack strength which is level+force
    int getAttackStrength() const;
    
};

#endif //EX2_Player_H