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
#include "MonsterCard.hpp"
#include <iostream>

MonsterCard::MonsterCard():Card(),att(0),def(0) {}

MonsterCard::MonsterCard(const std::string& _name,const  std::string& _eff,const unsigned int& rar, const  unsigned int& _att,const  unsigned int& _def):Card(_name,_eff,rar) {
    att = _att;
    def = _def;
}

void MonsterCard::setAttackPoints(const unsigned int& _att)  {
    att = _att;
}

void MonsterCard::setDeffencePoints(const unsigned int& _def) {
    def = _def;
}

unsigned int MonsterCard::getAttackPoints() const {
    return att;
}

unsigned int MonsterCard::getDeffencePoints() const {
    return att;
}
std::ostream &operator<<(std::ostream &o,  MonsterCard &tmp) {
    o<<(Card&)tmp;
    o<<delimeter<<std::to_string(tmp.att)<<delimeter<<std::to_string(tmp.def)<<std::endl;
    return o;
}

std::istream &operator>>(std::istream &i, MonsterCard &tmp) {
    std::string inputStr;
    i>>(Card&)tmp;
    std::getline(i,inputStr,delimeter);
    tmp.setAttackPoints((int)Card::rework(inputStr));
    std::getline(i,inputStr,'\n');
    tmp.setDeffencePoints((int)Card::rework(inputStr));
    return i;
}

