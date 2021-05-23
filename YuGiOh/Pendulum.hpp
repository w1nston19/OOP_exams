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

#ifndef UNTITLED8_PENDULUM_HPP
#define UNTITLED8_PENDULUM_HPP
#include "MagicCard.hpp"
#include "MonsterCard.hpp"

class PendulumCard : public  MagicCard , public MonsterCard{
protected:
    int scale;
public:
    PendulumCard();
    PendulumCard(const std::string& ,const std::string& ,const unsigned int&,const unsigned int&,const unsigned int&,const  int&,const CardType&);

    friend std::ostream& operator<<(std::ostream & o,  PendulumCard& tmp);
    friend std::istream& operator>>(std::istream & i,  PendulumCard& tmp);
};


#endif //UNTITLED8_PENDULUM_HPP
