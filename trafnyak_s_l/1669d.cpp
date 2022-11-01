#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    for (int t_ = 0; t_ < t; t_++) {
        int n;
        std::cin >> n;
        std::string input;
        std::cin >> input;

        bool flag = true;

        int r = 0;
        int b = 0;
        for (int i = 1; i < n; i++) {
            if(input[i] == 'W'){
                break;
            } else if(input[i] == 'R'){
                r++;
            } else{
                b++;
            }
            if (input[i] == 'W') {
                if(r == i || b == i){
                    flag = false;
                    break;
                }
                int i_old = i;
                r = 0;
                b = 0;
                for(i = i + 1; i <= n; i++){
                    if(input[i] == 'W'){
                        break;
                    } else if(input[i] == 'R'){
                        r++;
                    } else{
                        b++;
                    }
                }
                if(r == i - i_old || b == i - i_old){
                    flag = false;
                    break;
                }
            }
        }
        if (flag){
            std::cout << "yes\n";
        }else{
            std::cout << "no\n";
        }
    }
}
