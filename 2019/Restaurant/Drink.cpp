#include <string>
#include "Drink.h"
#include <iostream>

Drink::Drink(const std::string &inputName, const double &inputPer): RestaurantItem(DRINK),
                                                                    name(inputName) {
    setPercentage(inputPer);
}

std::string Drink::getName() const {
    return name;
}

void Drink::setName(const std::string &to) {
    name = to;
}

void Drink::setPercentage(const double& to) {
    if(to>=0&&to<=99){
        alcoholPercentage = to;
    }
}

bool Drink::operator>(const Drink &compare) {
    return alcoholPercentage>compare.alcoholPercentage;
}

void Drink::print() const {
    RestaurantItem::print();
    std::cout<<name<<" ,"<<std::to_string(alcoholPercentage)<<std::endl;
}

double Drink::getPercentage() const {
    return alcoholPercentage;
}
