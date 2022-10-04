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

    bool flag = true;
    while (flag){
        for(double x = a; x <= b; x += delta) {
            double temp = double(std::pow(x, i)) * std::sin(i * M_PI / 4.0);
            summ += temp;

            double y = x * std::sin(M_PI / 4.0) / (1 - 2 * x * std::cos(M_PI / 4.0));
            std::cout << x << " | " << summ << " | " << y << "\n";

            if(std::abs(temp) < epsilon){
                flag = false;
                break;
            }
        }
        i++;
    }
    return 0;
}
