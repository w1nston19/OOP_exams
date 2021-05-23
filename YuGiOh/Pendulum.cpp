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
#include "Pendulum.hpp"
#include <iostream>

PendulumCard::PendulumCard(const std::string& _n,const std::string& _e,const unsigned int& rar,const unsigned int& att,const unsigned int& def,const  int& _scale,const CardType& type)
:Card(_n,_e,rar),MonsterCard(_n,_e,rar,att,def),MagicCard(_n,_e,rar,type) {
    if(_scale>=0&&_scale<=13){
        this->scale = _scale;
    }
    else{
        if(_scale<0){
            this->scale = 0;
            this->scale = 13;
        }
    }
}

PendulumCard::PendulumCard() : MonsterCard(),MagicCard(),scale(0) {}

std::ostream &operator<<(std::ostream &o, PendulumCard &tmp) {
    o<<(Card&)tmp;
    o<<delimeter<<std::to_string(tmp.att)<<delimeter<<std::to_string(tmp.def)<<delimeter<<std::to_string(tmp.scale)<<delimeter<<tmp.getTypeStr()<<std::endl;
    return o;
}

std::istream &operator>>(std::istream &i, PendulumCard &tmp) {
    std::string tmpStr;
    i>>(Card&)tmp;
    std::getline(i,tmpStr,'|');
    tmp.att = (int)Card::rework(tmpStr);
    std::getline(i,tmpStr,'|');
    tmp.def = (int)Card::rework(tmpStr);
    std::getline(i,tmpStr,'|');
    tmp.scale=(int)Card::rework(tmpStr);
    std::getline(i,tmpStr,'\n');
    tmp.setType(tmpStr);
    return i;
}


