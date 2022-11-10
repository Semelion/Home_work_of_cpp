#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> input;
    input.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> input.at(i);
    }

    std::sort(input.begin(), input.end());

    int count = 1;
    int answer = 0;
    for (int i = 0; i < n; i++) {
//        std::cout << input.at(i) << ":" << i+1 << "\n";
        if (input.at(i) >= count) {
            count++;
            answer++;
        }
    }
    std::cout << answer << "\n";
}

