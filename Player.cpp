#include "Player.h"

Player::Player(char *name, int maxHP, int force) : m_maxHP(maxHP), m_force(force)
{
    if (maxHP <= 0)
    {
        this->m_maxHP = 100;
    }

    if (force <= 0)
    {
        this->m_force = 5;
    }
    this->m_name = new char[strlen(name) + 1];
    strcpy(this->m_name, name);
    this->m_level = 1;
    this->m_healthPoints = maxHP;
    this->m_coins = 0;
}

Player::Player(const Player &player) : m_level(player.m_level), m_force(player.m_force),
                                       m_maxHP(player.m_maxHP), m_healthPoints(player.m_healthPoints), m_coins(player.m_coins)
{
    this->m_name = new char[strlen(player.m_name) + 1];
    strcpy(this->m_name, player.m_name);
}

Player &Player::operator=(const Player &other)
{
    delete this->m_name;
    this->m_name = new char[strlen(other.m_name) + 1];
    strcpy(this->m_name, other.m_name);
    this->m_level = other.m_level;
    this->m_force = other.m_force;
    this->m_maxHP = other.m_maxHP;
    this->m_force = other.m_force;
    this->m_healthPoints = other.m_healthPoints;
    this->m_coins = m_coins;
}

Player::~Player()
{
    delete this->m_name;
}

void Player::printInfo() const
{
    printPlayerInfo(this->m_name, this->m_level, this->m_force, this->m_healthPoints, this->m_coins);
}

void Player::levelUp()
{
    if (this->m_level < 10)
    {
        this->m_level++;
    }
}

int Player::getLevel() const
{
    return this->m_level;
}

void Player::buff(int buffAmount)
{
    if(buffAmount > 0)
    {
        this->m_force += buffAmount;
    }
}

void Player::heal(int healAmount)
{
    if (healAmount > 0)
    {
        this->m_healthPoints += healAmount;
        if (this->m_healthPoints > this->m_maxHP)
        {
            this->m_healthPoints =this->m_maxHP;
        }
    }
}

void Player::damage(int damageAmount)
{
    if (damageAmount > 0)
    {
        this->m_healthPoints -= damageAmount;
        if (this->m_healthPoints < 0)
        {
            this->m_healthPoints = 0;
        }
    }
}

bool Player::isKnockedOut() const
{
    this->m_healthPoints == 0 ? true : false;
}

void Player::addCoins(int addition)
{
    if (addition > 0)
    {
        this->m_coins += addition;
    }
}

bool Player::pay(int coinsAmount)
{
    if (this->m_coins < coinsAmount)
    {
        return false;
    }
    if (coinsAmount <= 0)
    {
        return true;
    }
    this->m_coins -= coinsAmount;
    return true;
}

int Player::getAttackStrength() const
{
    return (this->m_force + this->m_level);
}