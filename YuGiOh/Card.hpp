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
#ifndef UNTITLED8_CARD_HPP
#define UNTITLED8_CARD_HPP


#include <string>
#include <vector>
#include <iostream>
const char delimeter = '|';
class Card {
protected:
    std::string name;
    std::string effect;
    unsigned int rarity;
public:
    Card();
    Card( const  std::string & ,const  std::string &, const unsigned int&);

    void setName(const std::string&);
    void setEffect(const std::string&);

     std::string getName() ;
     std::string getEffect() ;

    bool operator <(const Card&) const;
    bool operator >(const Card&) const;

    friend std::istream& operator>>(std::istream& i , Card& tmp);
    friend std::ostream& operator<<(std::ostream& o , Card& tmp);

    static unsigned int  rework(std::string input){
       unsigned int result= 0;
       for(int i=0;i<input.size();i++){
           result = result*10 + (int)(input[i]-'0');
       }
       return result;
    }

    virtual ~Card() = 0;
};


#endif //UNTITLED8_CARD_HPP
