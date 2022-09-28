#include <iostream>
#include <vector>

int main(){
    int t;
    std::cin >> t;
    while (t--){
        int a,b;
        std::cin >> a >> b;

        std::vector<char> s;
        s.resize(a+b);

        for(int i = 0; i < a+b; i++){
            std::cin >> s[i];
        }
        bool can_change_s = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                b--;
            } else if(s[i] == '0'){
                a--;
            }
            if(s[i] == '?'){
                can_change_s = true;
            }
        }
        if(can_change_s) {
            bool NONchet;
            if (s.size() % 2 != 0) {
                NONchet = true;
            } else {
                NONchet = false;
            }

            if (NONchet && s.size() > 1) {
                for (int i = 0; i < (s.size()) / 2; i++) {
                    if (s[i] == '?' && s[s.size() - i - 1] != '?') {
                        s[i] = s[s.size() - i - 1];
                        if (s[i] == '0') {
                            a--;
                        } else {
                            b--;
                        }
                    } else if (s[i] != '?' && s[s.size() - i - 1] == '?') {
                        s[s.size() - i - 1] = s[i];
                        if (s[i] == '0') {
                            a--;
                        } else {
                            b--;
                        }
                    } else if (s[i] == '?' && s[s.size() - i - 1] == '?') {
                        if (a > b) {
                            s[i] = '0';
                            s[s.size() - i - 1] = '0';
                            a -= 2;
                        } else {
                            s[i] = '1';
                            s[s.size() - i - 1] = '1';
                            b -= 2;
                        }
                    }
                }
                if (s[s.size() / 2] == '?') {
                    if (a > 0) {
                        s[s.size() / 2] = '0';
                        a--;
                    } else {
                        s[s.size() / 2] = '1';
                        b--;
                    }
                }
            } else if(s.size() > 1){
                for (int i = 0; i < s.size() / 2; i++) {
                    if (s[i] == '?' && s[s.size() - i - 1] != '?') {
                        s[i] = s[s.size() - i];
                        if (s[i] == '0') {
                            a--;
                        } else {
                            b--;
                        }
                    } else if (s[i] != '?' && s[s.size() - i - 1] == '?') {
                        s[s.size() - i - 1] = s[i];
                        if (s[i] == '0') {
                            a--;
                        } else {
                            b--;
                        }
                    } else if (s[i] == '?' && s[s.size() - i - 1] == '?') {
                        if (a > b) {
                            s[i] = '0';
                            s[s.size() - i - 1] = '0';
                            a -= 2;
                        } else {
                            s[i] = '1';
                            s[s.size() - i - 1] = '1';
                            b -= 2;
                        }
                    }
                }
            } else if(s.size() == 1){
                if(a > b){
                    s[0] = '0';
                } else{
                    s[0] = '1';
                }
            }
            if (a < 0 || b < 0) {
                std::cout << -1 << "\n";
            } else {
                for (int i = 0; i < s.size(); i++) {
                    std::cout << s[i];
                }
                std::cout << "\n";
            }
        } else{
            std::cout << -1 << "\n";
        }
    }
    return 0;
}
