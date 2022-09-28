#include <iostream>
#include <string>
#include <array>
#include <algorithm>

int main(){
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        std::cin >> n;

        std::string password = "";
        std::cin >> password;

        std::array<char, 26> special_symbols = {0};
        int k;
        std::cin >> k;
        for(int j = 0; j < k; j++){
            std::cin >> special_symbols[j];
        }

        std::cout << password << "\n";
        for(int j = 0; j < k; j++){
            std::cout << special_symbols[j] << " ";
        }
        std::cout  << "\n";
        int count = 0;
        int temp = 0;
        for(int j = 0; j < password.size(); j++){
            if(std::find(special_symbols.begin(), special_symbols.end(), password[j+1])){
                std::cout << password[j] << "\n";
                std::cout << std::find(special_symbols.begin(), special_symbols.end(), password[j]) << "\n";
            }
//                count = std::max(count,temp);
//                temp = 1;
//            }else{
//                temp+=1;
//            }
        }
        std::cout << count << "\n";

//        bool flag_can_erase = true;
//        while (flag_can_erase) {
//            for (int j = 0; j < password.size() - 1; j++) {
//                bool flag_have_erase = false;
//                for (int l = 0; l < special_symbols.size(); l++) {
//                    if (password[j + 1] == special_symbols[l]) {
//                        password.erase(j,1);
//                        flag_have_erase = true;
//                    }
//                }
//                if(!flag_have_erase){
//                    flag_can_erase = false;
//                }
//            }
//            count++;
//        }
    }
    return 0;
}
