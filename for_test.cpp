#include <iostream>

struct {
    int x = 0;
    int y = 0;
} myStructure;


struct car{
    std::string brand;
    std::string model;
    int year_of_make;
};

int main(){
    myStructure.x = 5;

    struct car sport_car;

    sport_car.brand = "Hadson";
    sport_car.model = "Hornet";
    sport_car.year_of_make = 1960;


    std::cout << sport_car.model << "\n";
}