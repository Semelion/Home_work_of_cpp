#include <iostream>

int main(){
    int x;
    std::cin >> x;
    int count = 0;
    count += x&1;
    while (x>>=1){
        count += x&1;
//        auto temp = x&1;
//        std::cout << x << " " << temp << "\n";
    }
    std::cout << count << "\n";
}