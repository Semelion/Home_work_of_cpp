#include <iostream>
#include <cmath>

#define epsilon 0.001
#define delta 0.1
#define a -1.0
#define b 1.0

long factorial(long n){
    long fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int main(){
    double summ = 0.0;
    long long i = 0;

    std::cout << " x | s(x) | f(x)\n";

    for(double x = a; x <= b; x += delta) {
        bool flag = true;
        while (flag) {
            double temp = double(std::pow(-1, i)) * double(std::pow(x, 2 * i)) / double(factorial(2 * i));
            summ += temp;
            if (std::abs(temp) < epsilon) {
                flag = false;
                break;
            }
            i++;
        }
        std::cout << x << " | " << summ << " | " << std::cos(x) << "\n";
    }
    return 0;
}