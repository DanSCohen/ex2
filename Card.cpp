#include "Card.h"



 Card :: Card(CardType type, const CardStats& stats) : m_effect(type), m_stats(stats)
 {};

void Card :: applyEncounter(Player& player) const{
    switch (m_effect)
    {

    case CardType :: Battle:
        bool battleResult = (player.getAttackStrength() >= m_stats.force) ;
        if(battleResult){
            player.levelUp();
            player.addCoins(m_stats.loot);
        }
        else {
            player.damage(m_stats.hpLossOnDefeat);
        }
        printBattleResult(battleResult);
        return;

    case CardType :: Buff:
        if(player.pay(m_stats.cost)) {
            player.levelUp();
        }
        return;

    case CardType :: Heal:
        if(player.pay(m_stats.cost)) {
            player.heal(m_stats.heal);
        }
        return;

    case CardType :: Treasure:
        player.addCoins(m_stats.loot);
        return;

    }
}

void Card :: printInfo() const{
    switch(m_effect){

        case CardType :: Battle:
            printBattleCardInfo(m_stats);
            return;

        case CardType :: Buff:
            printBuffCardInfo(m_stats);
            return;
        
        case CardType :: Heal:
            printHealCardInfo(m_stats);
            return;

        case CardType :: Treasure:
            printTreasureCardInfo(m_stats);
            return;

    }
}