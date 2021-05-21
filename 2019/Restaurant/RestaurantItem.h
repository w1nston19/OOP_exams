#ifndef OOP_EXAMS_RESTAURANTITEM_H
#define OOP_EXAMS_RESTAURANTITEM_H

#include <cassert>
enum Type{
    DRINK,
    FOOD,
    DEFAULT
};

class RestaurantItem {
protected:
    Type itemType;
    unsigned int quantity;
    double price;
public:
    RestaurantItem(Type inputItemType = Type::DEFAULT, unsigned int inputQuantity = 0 , double inputPrice = 0);

    Type getType() const;
    unsigned int getQuantity() const;
    double getPrice() const;

    void setType(const Type& to);
    void setQuantity(const unsigned int& to);
    void setPrice(const double & to);

    virtual void print() const;
    virtual void testItem();
};

#endif //OOP_EXAMS_RESTAURANTITEM_H
