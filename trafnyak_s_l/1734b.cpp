#include <iostream>

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int m;
        std::cin >> m;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) std::cout << "1 ";
                else std::cout << "0 ";
            }
            std::cout << std::endl;
        }
    }

}