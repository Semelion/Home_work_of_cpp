//#include <iostream>
//#include <string>
//#include <array>
//#include <algorithm>
//
//int main(){
//    int t;
//    std::cin >> t;
//
//    for(int i = 0; i < t; i++){
//        int n;
//        std::cin >> n;
//
//        std::string password = "";
//        std::cin >> password;
//
//        std::array<char, 26> special_symbols = {0};
//        int k;
//        std::cin >> k;
//        for(int j = 0; j < k; j++){
//            std::cin >> special_symbols[j];
//        }
//
//        std::cout << password << "\n";
//        for(int j = 0; j < k; j++){
//            std::cout << special_symbols[j] << " ";
//        }
//        std::cout  << "\n";
//        int count = 0;
//        int temp = 0;
//        for(int j = 0; j < password.size(); j++){
//            if(std::find(special_symbols.begin(), special_symbols.end(), password[j+1])){
//                std::cout << password[j] << "\n";
//                std::cout << std::find(special_symbols.begin(), special_symbols.end(), password[j]) << "\n";
//            }
////                count = std::max(count,temp);
////                temp = 1;
////            }else{
////                temp+=1;
////            }
//        }
//        std::cout << count << "\n";
//
////        bool flag_can_erase = true;
////        while (flag_can_erase) {
////            for (int j = 0; j < password.size() - 1; j++) {
////                bool flag_have_erase = false;
////                for (int l = 0; l < special_symbols.size(); l++) {
////                    if (password[j + 1] == special_symbols[l]) {
////                        password.erase(j,1);
////                        flag_have_erase = true;
////                    }
////                }
////                if(!flag_have_erase){
////                    flag_can_erase = false;
////                }
////            }
////            count++;
////        }
//    }
//    return 0;
//}
//#include<iostream>
//#include <vector>
//int main(){
//    int T;
//    std::cin >> T;
//    while(T--){
//        int n;
//        std::cin >> n;
//
//        std::vector<char> s;
//        for(int i = 0; i < n; i++){
//            char temp;
//            std::cin >> temp;
//            s.push_back(temp);
//        }
//
//        int k;
//        std::cin >> k;
//
//        std::vector<int> c;
//        c.resize(26);
//        for(int i=0;i<k;++i){
//            char t;
//            scanf(" %c",&t);
//            c[t-'a']=1;
//        }
//
//        int l=0,r=0;
//        for(int i=0;i<n;++i){
//            if(c[s[i]-'a']){
//                if(r<i-l)r=i-l;
//                l=i;
//            }
//        }
//        std::cout << r << "\n";
//    }
//}//вместо erase можно заменять на символ не из алфавита

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

        std::vector<char> special_symbols;
        int k;
        std::cin >> k;
        special_symbols.resize(k);
        for(int i = 0; i < k; i++){
            std::cin >> special_symbols[i];
        }

        bool flag = true;
        int count = 0;
        while (flag) {
            bool change = false;
            for (int i = 0; i < password.size()-1; i++) {
                bool have_1_in_psw = false;
                int n = 0;
                if(password[i+1] == 1){
                    have_1_in_psw = true;
                    for(int j = i+1; j < password.size(); j++){
                        if(password[j] != 1){
                            break;
                        } else{
                            n++;
                        }
                    }
                }
                for (int j = 0; j < special_symbols.size(); j++) {
                    if (password[i + 1 + n] == special_symbols[j]) {
                        password[i] = 1;
                        change = true;
                        break;
                    }
                }
                if(have_1_in_psw){
                    i += n;
                }
            }
            if (change) {
                count++;
//                std::string temp = "";
//                for (int i = 0; i < password.size(); i++) {
//                    if (password[i] != 1) {
//                        temp.push_back(password[i]);
//                    }
//                }
//                password.resize(temp.size());
//                for(int i = 0; i < temp.size(); i++){
//                    password[i] = temp[i];
//                }
            } else {
                flag = false;
            }
        }
        std::cout << count << "\n";
    }
}