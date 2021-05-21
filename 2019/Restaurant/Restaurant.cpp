//
// Created by Michael on 5/21/2021.
//

#include "Restaurant.h"

void Restaurant::addItem( RestaurantItem *add) {
    auto* foodPtr = dynamic_cast<Food*>(add);
    if(foodPtr){
        auto* ptr = (RestaurantItem*) foodPtr;
        items.push_back(ptr);
    }
    auto* drinkPtr = dynamic_cast<Drink*>(add);
    if(drinkPtr){
        auto* ptrDr = (RestaurantItem*)drinkPtr;
        items.push_back(ptrDr);
    }
}

void Restaurant::removeItem(int idx) {
    if(idx>=0&&idx<items.size()){
        delete items[idx];
        items.erase(items.begin()+idx);
    }
}

void Restaurant::changePrice(int idx, const double &newPrice) {
    if(idx>=0&&idx<items.size()){
        items[idx]->setPrice(newPrice);
    }
}

void Restaurant::changeName(int idx, const std::string &newName) {
    if(idx>=0&&idx<items.size()){
        auto *ptr = dynamic_cast<Food*>(items[idx]);
        if(ptr){
            ptr->setName(newName);
        }
        auto *ptrDrink = dynamic_cast<Drink*>(items[idx]);
        if(ptrDrink){
            ptrDrink->setName(newName);
        }

    }
}

void Restaurant::print() const {
    for(int i=0;i<items.size();i++){
        items[i]->print();
    }
}

void Restaurant::printNonAlcohol() const {
    for(int i=0;i<items.size();i++){
        auto *ptr = dynamic_cast<Drink*>(items[i]);
        if(ptr){
            if(ptr->getPercentage()==0){
                items[i]->print();
            }
        }
        else{
            items[i]->print();
        }

    }
}
