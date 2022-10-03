#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <numbers>

int main(){
    int n,r;
    std::cin >> n >> r;

    std::cout << (r* sin(M_PI/n)/(1 - sin(M_PI/n)));
}