#include <iostream>
#include <string>

int main() {
    int n;
    int x = 0;
    int y = 0;
    int y_old = 0;
    int x_old = 0;
    int count = 0;
    std::cin >> n;

    std::string path;
    for (int i = 0; i < n; i++) {
        char temp;
        std::cin >> temp;
        path.push_back(temp);
    }


    int a = 0, b = 0, z = 0;
    for (int i = 0; i < n; i++) {
        if (path[i] == 'R')a++;
        else b++;
        if (a == b) {
            if (path[i + 1] == path[i])z++;
        }
    }
    std::cout << z;
    return 0;
}

