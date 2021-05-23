#ifndef OOP_EXAMS_DRINK_H
#define OOP_EXAMS_DRINK_H
#include "RestaurantItem.h"
#include "string"

class Drink : public RestaurantItem{
private:
    std::string name;
    double alcoholPercentage;
public:
    Drink(const std::string& inputName = "", const double& inputPer = 0);

    std::string getName() const;
    double getPercentage() const;

    void setName(const std::string & to);
    void setPercentage(const double& to);

    bool operator >(const Drink& compare);
    void print() const override;
};


#endif //OOP_EXAMS_DRINK_H
