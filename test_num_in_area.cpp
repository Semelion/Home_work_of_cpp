#include <iostream>

int main(){
    double x, y;
    std::cin >> x >> y;
    if( (x*x + y*y <= 4) && (y >= 2 - x*x) ){
        std::cout << "true";
    } else{
        std::cout << "false";
    }
}