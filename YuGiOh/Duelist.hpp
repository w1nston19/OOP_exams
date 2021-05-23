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
#ifndef UNTITLED8_DUELIST_HPP
#define UNTITLED8_DUELIST_HPP
#include "Deck.hpp"

class Duelist {
    std::string name;
    Deck deck;
public:
    Duelist(const std::string& _name = ""): name(_name), deck(Deck()){};
    Deck& getDeck() ;

    bool saveDeck(const std::string& name);
    bool loadDeck(const std::string& name);

    void duel(Duelist& second);

    static void duel(Duelist& first, Duelist& second);
};


#endif //UNTITLED8_DUELIST_HPP
