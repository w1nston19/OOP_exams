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
#ifndef OOP_EXAMS_DECK_HPP
#define OOP_EXAMS_DECK_HPP
#include "Pendulum.hpp"

class Deck {
private:
    std::string name;
    std::vector<Card*> cards;
    unsigned int monsters,magics,pendulums;

public:
    Deck(const std::string& _name = "");

    void setName(const std::string& _name);
    std::string getName() const;

    unsigned int getNumberOfMonsters() const;
    unsigned int getNumberOfMagics() const;
    unsigned int getNumberOfPendulums() const;
    unsigned int getNumberOfAllCards() const;

    void addCard( Card* add);
    std::vector<Card*> getCards() const;

    void reworkCard(const int& idx, Card* newCard);


    void erase();

    void shuffle();
    void sort();

    bool operator > (Deck& compared)const;
    bool operator < (Deck& compared);

    friend std::ostream& operator<<(std::ostream& o, const Deck& tmp);
    friend std::istream& operator>>(std::istream& i,  Deck& tmp);
};


#endif //OOP_EXAMS_DECK_HPP
