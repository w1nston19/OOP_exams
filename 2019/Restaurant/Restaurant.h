
#ifndef OOP_EXAMS_RESTAURANT_H
#define OOP_EXAMS_RESTAURANT_H

#include <vector>
#include "Drink.h"
#include "Food.h"

class Restaurant {
private:
    std::vector<RestaurantItem*> items;
public:
    void addItem( RestaurantItem* add);
    void removeItem(int idx);

    void changePrice(int idx,const double& newPrice);
    void changeName(int idx,const std::string& newName);

    void print() const;
    void printNonAlcohol() const;
};


#endif //OOP_EXAMS_RESTAURANT_H
