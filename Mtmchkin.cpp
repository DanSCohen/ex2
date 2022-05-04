#include "Mtmchkin.h"
#include <string.h>

using std :: cout;
using std :: cerr;
using std :: endl;

Mtmchkin :: Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
    m_player( Player(playerName) ),m_deck( cardsArray ), m_deckSize( numOfCards ) {
        if(playerName == NULL){
            cerr << "NULL argument at" << playerName << endl; 
        }

        if(m_deck == NULL){
            cerr << "NULL argument at" << cardsArray << endl; 
        }

        if(m_deckSize <= 0){
            cerr << "Invalid number of cards" << endl;
        }

        m_currentCardNumber = 0;
        m_status = GameStatus :: MidGame;
}

Mtmchkin :: ~ Mtmchkin(){
    delete &m_player;
};

GameStatus Mtmchkin :: getGameStatus() const{
    return m_status;
};

bool Mtmchkin :: isOver(){
    if(m_status != GameStatus::MidGame){
        return true;
    }
    return false;
};

void Mtmchkin :: playNextCard(){
    const Card* currentCard = (m_deck + m_currentCardNumber);
    (*currentCard).printInfo();
    (*currentCard).applyEncounter(m_player);
    m_player.printInfo();

    if( m_player.isKnockedOut() ){
        m_status = GameStatus :: Loss;
    }

    else if( m_player.getLevel() == MAX_LEVEL ){
        m_status == GameStatus :: Win;
    }

    m_currentCardNumber = (m_currentCardNumber + 1) % m_deckSize;
}