#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

#define epsilon 0.0001
#define delta 0.1
#define a 0.0
#define b 1.0

double factorial(long n){
    double fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int main(){
    double summ = 0.0;
    long i = 0;

    std::cout << " x | s(x) | f(x)\n";

    for(double x = a; x <= b; x += delta) {
        bool flag = true;
        while (flag) {
            double temp = double(std::pow(2*x, i)) / factorial(i);
            summ += temp;
            if (std::abs(temp) < epsilon) {
                flag = false;
                break;
            }
            i++;
        }
        double y = pow(M_E, 2*x);
        std::cout << x << " | " << summ << " | " << y << "\n";
    }
    return 0;
}
