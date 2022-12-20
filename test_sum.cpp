#include <iostream>

#define interval_min 0.1
#define interval_max 1.0
#define delta_x 0.05
#define eps 0.0001

int main() {
    for (double x = interval_min; x <= interval_max; x += delta_x) {
        int i = 0;
        double element = (2 * x);
        double summ = element;
        while (element >= eps) {
            i++;
            element = element * (2 * x) / i;
            summ += element;
        }

        std::cout << std::fixed << element << std::endl;
    }
}