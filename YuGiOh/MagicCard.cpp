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
#include "MagicCard.hpp"
#include <iostream>

MagicCard::MagicCard() : Card() {}

MagicCard::MagicCard(const std::string& name,const  std::string& eff,const unsigned int& rar,const CardType& _cardType)  : Card(name,eff,rar), card(_cardType){}

void MagicCard::setType(const CardType& inputType) {
    card = inputType;
}


std::string MagicCard::getTypeStr() {
    std::string result;
    switch (card) {
        case CardType::TRAP: result = result + "TRAP"; break;
        case CardType::BUFF: result = result + "BUFF"; break;
        case CardType::SPELL: result = result + "SPELL"; break;
    }
    return result;
}

std::ostream &operator<<(std::ostream &o, MagicCard &tmp) {
    o<<(Card&)tmp;
    o<<delimeter<<tmp.getTypeStr()<<std::endl;
    return o;
}

std::istream &operator>>(std::istream &i, MagicCard &tmp) {
    i>>(Card&)tmp;
    std::string type;
    std::getline(i,type,'\n');
    tmp.setType(type);
    return i;
}

void MagicCard::setType(const std::string& type) {
    if(type == "BUFF"){
        this->setType(CardType::BUFF);
    }
    else{
        if(type=="SPELL"){
            setType(CardType::SPELL);
        }
        else{
            setType(CardType::TRAP);
        }
    }
}
