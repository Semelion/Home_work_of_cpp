#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

int main(){
    int t;
    std::cin >> t;

    for(int t_c = 0; t_c < t; t_c++){
        int len_pas;
        std::cin >> len_pas;

        std::string password = "";
        std::cin >> password;

        std::vector<int> special_symbols;
        special_symbols.resize(24);
        int k;
        std::cin >> k;
        for(int i = 0; i < k; i++){
            unsigned char ch;
            std::cin >> ch;
            special_symbols[ch] = 1;
        }
        for(int i = 0; i < special_symbols.size(); i++){
            std::cout << special_symbols[i] << "\n";
        }
    }
//        bool flag = true;
//        int count = 0;
//        while (flag) {
//            bool change = false;
//            for (int i = 0; i < password.size()-1; i++) {
//                bool have_1_in_psw = false;
//                int n = 0;
//                if(password[i+1] == 1){
//                    have_1_in_psw = true;
//                    for(int j = i+1; j < password.size(); j++){
//                        if(password[j] != 1){
//                            break;
//                        } else{
//                            n++;
//                        }
//                    }
//                }
//                for (int j = 0; j < special_symbols.size(); j++) {
//                    if (password[i + 1 + n] == special_symbols[j]) {
//                        password[i] = 1;
//                        change = true;
//                        break;
//                    }
//                }
//                if(have_1_in_psw){
//                    i += n;
//                }
//            }
//            if (change) {
//                count++;
//            } else {
//                flag = false;
//            }
//        }
//        std::cout << count << "\n";
//    }
}