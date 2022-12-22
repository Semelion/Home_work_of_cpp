#include <iostream>
#include <string>

#define alphabet_size 7
const char alphabet[alphabet_size] = {'a', 'e', 'i', 'o', 'u', 'y', ' '};

bool char_in_alphabet(const char &ch){
    bool flag = false;
    for(int i = 0; i < alphabet_size; i++){
        if(ch == alphabet[i]){
            flag = true;
            break;
        }
    }
    return flag;
}

int main(){
    std::string input;
    std::cin >> input;

    bool flag = true;
    for(int i = 0; i < input.size(); i++){
        if( (!char_in_alphabet(input[i]) && char_in_alphabet(input[i+1])) ||
            (input[i] == 'n') || (char_in_alphabet(input[i]))){
            flag = true;
        } else{
            flag = false;
            break;
        }
    }

    if(flag){
        std::cout << "YES";
    } else{
        std::cout << "NO";
    }
}