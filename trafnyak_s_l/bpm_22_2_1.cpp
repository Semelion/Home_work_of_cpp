#include <iostream>
#include <cmath>

#define x_start 0.1
#define x_end   1
#define delta   0.05
#define eps     0.0001

int main(){
    std::cout << "x\tsum\n";

    for(double x = x_start; x <= x_end; x += delta){
        int i = 0;
        double element = std::pow(-1, i)*(std::pow(x, (2*i + 1)) / (2*i + 1));
        double sum = element;
        i++;

        while (element >= eps){
            element = std::pow(-1, i)*(std::pow(x, (2*i + 1)) / (2*i + 1));
            sum += element;
            i++;
        }
        std::cout << x << "\t" << sum << "\n";
    }
}