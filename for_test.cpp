#include <iostream>

struct {
    int x = 0;
    int y = 0;
} myStructure;

int main(){
    myStructure.x = 5;
    std::cout << myStructure.x << " " << myStructure.y << "\n";
}