#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

#define epsilon 0.001
#define delta 0.05
#define a 0.0
#define b 1.0

int main(){
    double summ = 0.0;
    long long i = 1;

    std::cout << " x | s(x) | f(x)\n";

    for(double x = a; x <= b; x += delta) {
        bool flag = true;
        while (flag) {
            double temp = double(std::pow(x, i)) * std::sin(i * M_PI / 4.0);
            summ += temp;
            if (std::abs(temp) < epsilon && temp != 0 || x == 0){
                flag = false;
                break;
            }
            i++;
        }-6
        double y = x * std::sin(M_PI / 4.0) / (1 - 2 * x * std::cos(M_PI / 4.0));
        std::cout << x << " | " << summ << " | " << y << "\n";
    }

    return 0;
}
