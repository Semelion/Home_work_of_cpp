#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int x1, y1, x2, y2;
        bool flag = false;
        for (int y_i = 0; y_i < n; y_i++) {
            for (int x_i = 0; x_i < n; x_i++) {
                char temp;
                std::cin >> temp;
                if (temp == '*') {
                    if (flag) {
                        x2 = x_i;
                        y2 = y_i;
                    } else {
                        x1 = x_i;
                        y1 = y_i;
                        flag = true;
                    }
                }
            }
        }
        int x3, y3, x4, y4;

        if(x1 != x2 && y1 != y2){
            x3 = x1;
            y3 = y2;
            x4 = x2;
            y4 = y1;
        }else if(x1 == x2){
            if(x1 - 1 >= 0){
                x3 = x1 - 1;
                y3 = y1;
                x4 = x1 - 1;
                y4 = y2;
            } else{
                x3 = x1 + 1;
                y3 = y1;
                x4 = x1 + 1;
                y4 = y2;
            }
        }else{
            if(y1 - 1 >= 0){
                x3 = x1;
                y3 = y1 - 1;
                x4 = x1;
                y4 = y2 - 1;
            } else{
                x3 = x1;
                y3 = y1 + 1;
                x4 = x1;
                y4 = y2 + 1;
            }
        }

        for (int y_i = 0; y_i < n; y_i++) {
            for (int x_i = 0; x_i < n; x_i++) {
                if (x_i == x1 && y_i == y1) {
                    std::cout << "*";
                } else if (x_i == x2 && y_i == y2) {
                    std::cout << "*";
                } else if (x_i == x3 && y_i == y3) {
                    std::cout << "*";
                } else if (x_i == x4 && y_i == y4) {
                    std::cout << "*";
                } else {
                    std::cout << ".";
                }
            }
            std::cout << "\n";
        }
//        std::cout << "\n____________________\n";

    }
    return 0;
}