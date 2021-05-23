
#include <iostream>
#include "Food.h"

Food::Food(const std::string& inputName, double inputSize) : RestaurantItem(FOOD), name(inputName),size(inputSize) {

}

std::string Food::getName() const {
    return name;
}

void Food::setName(const std::string &to) {
    name = to;
}

void Food::setSize(const double &to) {
    size = to;
}

bool Food::operator>(const Food &compare) const {
    return this->size>compare.size;
}

void Food::print() const {
    RestaurantItem::print();
    std::cout<<name<<" ,"<<std::to_string(size)<<std::endl;
}

void Food::testItem() {
    RestaurantItem::testItem();
    Food a("Apple",0.125);

    assert(a.getType()==FOOD);
    assert(a.getName()=="Apple");
    assert(a.getQuantity()==0);

    a.print();
}
