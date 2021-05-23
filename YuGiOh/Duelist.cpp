/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Mihail Zonev
* @idnumber *****
* @task 1
* @compiler gcc
*/

#include <fstream>
#include "Duelist.hpp"

Deck &Duelist::getDeck()  {
    return this->deck;
}

bool Duelist::saveDeck(const std::string &name) {
    std::ofstream o(name,std::ios::trunc);
    if(o.is_open()){
        o<<this->getDeck();
        o.close();
        return true;
    }
    return false;
}

bool Duelist::loadDeck(const std::string &name) {
    std::ifstream i(name);
    if(i.is_open()){
        i>> this->deck;
        i.close();
        return true;
    }
    return false;
}

void Duelist::duel(Duelist &second) {
    if(deck.getNumberOfAllCards()!= second.deck.getNumberOfAllCards()){
        std::cout<<"Can not duel - not the same number of cards"<<std::endl;
        return;
    }
    if(deck>second.deck){
        std::cout<<name<<" wins"<<std::endl;
    }
    else{
        if(deck<second.deck){
            std::cout<<second.name<<" wins"<<std::endl;
        }
        else{
            std::cout<<"Tie\n";
        }
    }

}

void Duelist::duel(Duelist &first, Duelist &second) {
    first.duel(second);
}
