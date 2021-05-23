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
#ifndef UNTITLED8_MONSTERCARD_HPP
#define UNTITLED8_MONSTERCARD_HPP
#include "Card.hpp"

class MonsterCard : virtual public Card {
protected:
    unsigned int att,def;
public:
    MonsterCard();
    MonsterCard(const std::string& ,const std::string& ,const unsigned int& ,const unsigned int&,const unsigned int&);
    
    void setAttackPoints(const unsigned int& _att);
    void setDeffencePoints(const unsigned int& _def);

    unsigned int getAttackPoints() const;
    unsigned int getDeffencePoints() const;

    friend std::ostream& operator<<(std::ostream & o,  MonsterCard& tmp);
    friend std::istream& operator>>(std::istream & i,  MonsterCard& tmp);
};


#endif //UNTITLED8_MONSTERCARD_HPP
