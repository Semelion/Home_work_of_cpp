#include <iostream>
#include <cmath>

int main() {
    int t_;
    std::cin >> t_;

    for (int t = 0; t < t_; t++) {
        int n;
        std::cin >> n;
        int count_2 = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            std::cin >> temp;
            while (temp > 0) {
                if (temp % 2 == 0) {
                    count_2++;
                } else {
                    break;
                }
                temp /= 2;
            }
        }

        if (count_2 >= n) {
            std::cout << "0\n";
        } else {
            int count = 1;
            count_2 += int(std::log2(n));
            int old = n - int(std::log2(n)) * 2 - 1;

            while (count_2 < n && old >= 0) {
                count_2 += int(std::log2(n - old));
                old = n - int(std::log2(n - old)) - 1;
                count++;
            }
//            std::cout << old << "\n";
            if (count_2 >= n) {
                std::cout << count << "\n";
            } else{
                std::cout << -1 << "\n";
            }
        }
    }
}