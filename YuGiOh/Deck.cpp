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
#include "Deck.hpp"
#include <random>
#include <algorithm>

Deck::Deck(const std::string &_name) : name(_name), monsters(0), magics(0), pendulums(0) {}

void Deck::setName(const std::string &_name) {
    name = _name;
}

std::string Deck::getName() const {
    return name;
}

unsigned int Deck::getNumberOfMonsters() const {
    return monsters;
}

unsigned int Deck::getNumberOfMagics() const {
    return magics;
}

unsigned int Deck::getNumberOfPendulums() const {
    return pendulums;
}

unsigned int Deck::getNumberOfAllCards() const {
    return monsters+pendulums+magics;
}

void Deck::addCard( Card *add) {
    auto* monPtr = dynamic_cast<MonsterCard*>(add);
    auto* magPtr = dynamic_cast<MagicCard*>(add);
    auto* penPtr = dynamic_cast<PendulumCard*>(add);
    if(penPtr){
        cards.push_back(new PendulumCard(*penPtr));
        pendulums++;
    }
    else{
        if(monPtr){
            cards.push_back(new MonsterCard(*monPtr));
            monsters++;
        }
        else{
            cards.push_back(new MagicCard(*magPtr));
            magics++;
        }
    }

}

std::vector<Card *> Deck::getCards() const {
    return cards;
}

void Deck::reworkCard(const int &idx,  Card *newCard) {
    if(idx < cards.size()){
        if(typeid(*this) == typeid(*newCard)){
            delete cards[idx];
            cards[idx] = newCard;
        }
    }
}

void Deck::erase() {
    for(int i=0;i<cards.size();i++){
        delete cards[i];
    }
    cards.clear();
    monsters = 0;
    magics = 0;
    pendulums = 0;
}

void Deck::shuffle() {
    unsigned seed = 0;
    std::shuffle(cards.begin(),cards.end(), std::default_random_engine(seed));
}

void Deck::sort() {
    std::vector<Card*> mons;
    std::vector<Card*> magix;
    std::vector<Card*> pendulumCards;
    shuffle();
    for(int i = 0;i < cards.size();i++){
        auto *tmpPen = dynamic_cast<PendulumCard*>(cards[i]);
        auto *tmpMon = dynamic_cast<MonsterCard*>(cards[i]);
        auto *tmpMagic = dynamic_cast<MagicCard*>(cards[i]);
        if(tmpPen){
            pendulumCards.push_back(new PendulumCard(*tmpPen));
        }
        else{
            if(tmpMon){
                mons.push_back(new MonsterCard(*tmpMon));
            }
            else{
                magix.push_back(new MagicCard(*tmpMagic));
            }
        }

    }
    this->erase();
    while(!mons.empty()){
        addCard(mons.front());
        delete mons.front();
        mons.erase(mons.begin());
    }
    while(!magix.empty()){
        addCard(magix.front());
        delete magix.front();
        magix.erase(magix.begin());
    }
    while(!pendulumCards.empty()){
        addCard(pendulumCards.front());
        delete pendulumCards.front();
        pendulumCards.erase(pendulumCards.begin());
    }
}

std::istream &operator>>(std::istream &i, Deck &tmp) {
    std::string tmpStr;
    std::getline(i,tmpStr,delimeter);
    tmp.setName(tmpStr);
    std::getline(i,tmpStr,delimeter);
    std::getline(i,tmpStr,delimeter);
    int tmpMonsters,tmpMagics,tmpPendulums;
    tmpMonsters = (int)Card::rework(tmpStr);
    std::getline(i,tmpStr,delimeter);
    tmpMagics = (int)Card::rework(tmpStr);
    std::getline(i,tmpStr,'\n');
    tmpPendulums = (int)Card::rework(tmpStr);
    for(int t = 0; t< tmpMonsters;t++){
        MonsterCard tmpMon;
        i>>tmpMon;
        tmp.addCard(&tmpMon);
    }
    for(int t = 0; t< tmpMagics;t++){
        MagicCard tmpMag;
        i>>tmpMag;
        tmp.addCard(&tmpMag);
    }
    for(int t = 0; t< tmpPendulums;t++){
        PendulumCard tmpPen;
        i>>tmpPen;
        tmp.addCard(&tmpPen);
    }
    return i;
}

std::ostream& operator<<(std::ostream& o, const Deck& tmp){
    Deck helper;
    helper.setName(tmp.getName());
    for(int i=0;i<tmp.cards.size();i++){
        helper.addCard(tmp.cards[i]);
    }
    helper.sort();
    o<<helper.getName()<<delimeter<<std::to_string(helper.getNumberOfAllCards())<<delimeter;
    o<<std::to_string(helper.monsters)<<delimeter;
    o<<std::to_string(helper.magics)<<delimeter;
    o<<std::to_string(helper.pendulums)<<"\n";
    int idx = 0;
    for(int i=0;i<helper.monsters;i++){
        auto * tmpMon = dynamic_cast<MonsterCard*>(helper.cards[idx]);
        o<<*tmpMon;
        idx++;
    }
    for(int i=0;i<helper.magics;i++){
        auto * tmpMag = dynamic_cast<MagicCard*>(helper.cards[idx]);
        o<<*tmpMag;
        idx++;
    }
    for(int i=0;i<helper.pendulums;i++){
        auto * tmpPen = dynamic_cast<PendulumCard*>(helper.cards[idx]);
        o<<*tmpPen;
        idx++;
    }
    helper.erase();
    return o;
}

bool Deck::operator>(Deck &compared) const {
    const int maxCards = (int)this->getNumberOfAllCards();
    int scoreThis = 0, scoreCompared = 0;
    for(int i=0 ;i<maxCards;i++){
        if((Card&)*cards[i]>(Card&)*compared.cards[i]){
            scoreThis++;
        }
        else{
            if((Card&)*cards[i]<(Card&)*compared.cards[i]){
                scoreCompared++;
            }
        }
    }
    return scoreThis>scoreCompared;
}

bool Deck::operator<(Deck &compared)  {
    const int maxCards = (int)this->getNumberOfAllCards();
    int scoreThis = 0, scoreCompared = 0;
    for(int i=0 ;i<maxCards;i++){
        if((Card&)*cards[i]>(Card&)*compared.cards[i]){
            scoreThis++;
        }
        else{
            if((Card&)*cards[i]<(Card&)*compared.cards[i]){
                scoreCompared++;
            }
        }
    }
    return scoreThis<scoreCompared;
}
