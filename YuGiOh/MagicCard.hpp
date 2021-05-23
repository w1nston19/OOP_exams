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
#ifndef UNTITLED8_MAGICCARD_HPP
#define UNTITLED8_MAGICCARD_HPP
#include "Card.hpp"
enum class CardType{
    TRAP,
    BUFF,
    SPELL
};
class MagicCard: virtual public Card{
protected:
    CardType card;
public:
    MagicCard();
    MagicCard(const std::string& ,const std::string&, const unsigned int&,const CardType&);

    void setType(const CardType&);
    void setType(const std::string&);

    std::string getTypeStr();

    friend std::ostream& operator<<(std::ostream & o,  MagicCard& tmp);
    friend std::istream& operator>>(std::istream & i,  MagicCard& tmp);
};


#endif //UNTITLED8_MAGICCARD_HPP
