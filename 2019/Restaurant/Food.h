#ifndef OOP_EXAMS_FOOD_H
#define OOP_EXAMS_FOOD_H

#include "RestaurantItem.h"
#include <string>

class Food : public RestaurantItem{
protected:
    std::string name;
    double size;
public:
    Food(const std::string& inputName = "", double inputSize =0);

    std::string getName() const;

    void setName(const std::string & to);
    void setSize(const double& to);

    bool operator>(const Food& compare) const;

    void print() const override;
    void testItem() override;
};


#endif //OOP_EXAMS_FOOD_H
