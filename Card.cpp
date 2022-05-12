#include "Card.h"

Card::Card(CardType type, const CardStats &stats)
{

    this->m_effect = type;
    this->m_stats = CardStats(stats);
}

void Card::applyEncounter(Player& player) const
{
    if (this->m_effect == CardType::Battle)
    {
        if (player.getAttackStrength() >= this->m_stats.force)
        {
            player.addCoins(this->m_stats.loot);
            player.levelUp();
            printBattleResult(true);
        }
        else 
        {
            player.damage(this->m_stats.hpLossOnDefeat);
            printBattleResult(false);
        }
    }
    else if(this->m_effect == CardType::Buff)
    {
      if(player.pay(this->m_stats.cost) == true)
      {
          player.buff(this->m_stats.buff);
      }
    }

    else if (this->m_effect == CardType::Heal)
    {
        if (player.pay(this->m_stats.cost))
        {
            player.heal(this->m_stats.heal);
        }
    }

    else
    {
        player.addCoins(this->m_stats.loot);
    }
}

void Card::printInfo() const
{
    switch(this->m_effect)
    {
        case CardType::Battle :
        printBattleCardInfo(this->m_stats);
        break;
        case CardType::Buff :
        printBuffCardInfo(this->m_stats);
        break;
        case CardType::Heal :
        printHealCardInfo(this->m_stats);
        break;
        case CardType::Treasure :
        printTreasureCardInfo(this->m_stats);
        break;
    }
    
}