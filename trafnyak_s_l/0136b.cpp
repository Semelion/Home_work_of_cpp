#include <iostream>
#include <vector>
#include <cmath>

void numb10_to_3(int number_10, std::vector<int> &number3) {
    while (number_10 > 0) {
        number3.push_back(number_10 % 3);
        number_10 /= 3;
    }
}

void conclusion_int_vector(std::vector<int> &numbers1) {
    for (int i = 0; i < numbers1.size(); i++) {
        std::cout << numbers1[i];
    }
    std::cout << "\n";
}

int main() {
    int a10, c10;
    std::cin >> a10 >> c10;

    std::vector<int> a3;
    std::vector<int> c3;
    std::vector<int> b3;

    numb10_to_3(a10, a3);
    numb10_to_3(c10, c3);

    if (a3.size() < c3.size()) {
        int difference = c3.size() - a3.size();
        for (int i = 0; i < difference; i++) {
            a3.push_back(0);
        }
    } else if (c3.size() < a3.size()) {
        int difference = a3.size() - c3.size();
        for (int i = 0; i < difference; i++) {
            c3.push_back(0);
        }
    }

    b3.resize(c3.size());
    for (int i = 0; i < c3.size(); i++) {
        int num = c3[i] - a3[i];
        if (num < 0) {
            num = 3 + num;
        }
        b3[i] = num;
    }
//    conclusion_int_vector(a3);
//    conclusion_int_vector(b3);
//    conclusion_int_vector(c3);

    int b10 = 0;
    for (int i = 0; i < b3.size(); i++) {
        b10 += b3[i] * std::pow(3, i);
    }
    std::cout << b10;

    return 0;
}
