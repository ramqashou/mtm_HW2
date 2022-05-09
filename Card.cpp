#include "Card.h"

Card::Card(CardType type, const CardStats &stats)
{

    this->m_effect = type;
    this->m_stats = CardStats(stats);
}

Card::applyEncounter(Player& player) const
{
    if (this->type == Battle)
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
    else if(this->type == Buff)
    {
      if(player.pay(this->m_stats.cost) == true)
      {
          player.buff(this->m_stats.cost);
      }
    }

    else if (this->type == Heal)
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

void card::printInfo() const
{
    switch(this->m_effect)
    {
        case Battle :
        printBattleCardInfo(this->m_stats);
        break;
        case Buff :
        printBuffCardInfo(this->m_stats);
        break;
        case Heal :
        printHealCardInfo(this->m_stats);
        break;
        case Treasure :
        printTreasureCardInfo(this->m_stats);
        break;
    }
    
}