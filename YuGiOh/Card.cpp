/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Mihail Zonev
* @idnumber 62595
* @task 1
* @compiler gcc
*/
#include "Card.hpp"
#include <iostream>

Card::Card(): name(""),effect(""), rarity(0) {}

Card::Card( const std::string& _name,const   std::string& _eff, const unsigned int& r):name(_name), effect(_eff) , rarity(r){}

void Card::setName(const std::string& _name)  {
    this->name = _name;
}

void Card::setEffect(const std::string& _eff) {
    this->effect = _eff;
}

std::string Card::getName()  {
    return this->name;
}

std::string Card::getEffect()  {
    return effect;
}

std::istream &operator>>(std::istream &i, Card &tmp) {
    std::string tmpStr;
    std::getline(i,tmp.name,delimeter);
    std::getline(i,tmp.effect,delimeter);
    std::getline(i,tmpStr,delimeter);
    tmp.rarity = Card::rework(tmpStr);
    return i;
}

std::ostream &operator<<(std::ostream &o, Card &tmp) {
    return o<<tmp.name<<delimeter<<tmp.effect<<delimeter<<tmp.rarity;
}

bool Card::operator<(const Card &tmp) const {
    return this->rarity<tmp.rarity;
}

bool Card::operator>(const Card &tmp) const {
    return this->rarity>tmp.rarity;
}
Card::~Card(){

}
