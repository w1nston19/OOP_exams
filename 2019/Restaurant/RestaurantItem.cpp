//
// Created by Michael on 5/21/2021.
//

#include "RestaurantItem.h"
#include <iostream>
RestaurantItem::RestaurantItem(Type inputItemType, unsigned int inputQuantity, double inputPrice) : itemType(inputItemType),
                                                                                                    quantity(inputQuantity),
                                                                                                    price(inputPrice){}

Type RestaurantItem::getType() const {
    return itemType;
}

unsigned int RestaurantItem::getQuantity() const {
    return quantity;
}

double RestaurantItem::getPrice() const {
    return price;
}

void RestaurantItem::setType(const Type &to) {
    this->itemType = to;
}

void RestaurantItem::setQuantity(const unsigned int &to) {
    quantity = to;
}

void RestaurantItem::setPrice(const double &to) {
    price = to;
}

void RestaurantItem::testItem() {
    RestaurantItem a(Type::DRINK,25,1.58);
    assert(a.getPrice()==1.58);
    assert(a.getQuantity()==25);
    assert(a.getType()==Type::DRINK);

    a.setType(FOOD);
    a.setQuantity(50);
    a.setPrice(4.55);

    assert(a.getPrice()==4.55);
    assert(a.getQuantity()==50);
    assert(a.getType()==Type::FOOD);
}

void RestaurantItem::print() const {
    switch ((int)itemType) {
        case 0: std::cout<<"Drink ,";break;
        case 1: std::cout<<"Food ,";break;
        default:std::cout<<"Default ,";break;
    }
    std::cout<<std::to_string(quantity)<<" ,"<<std::to_string(price)<<" ,";
}


