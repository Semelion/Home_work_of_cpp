#include <iostream>
#include <string>

int main(){
    int t_;
    std::cin >> t_;
    for(int t = 0; t < t_; t++){
        std::string input;
        std::cin >> input;

        if(input.size() == 1){
            std::cout << 1 << "\n";
        } else{
            int count = 0;
            for(int i = 0; i < input.size(); i++){
                count++;
                if(input[i] == '0'){
                    break;
                } else if(input[i+1] == '1'){
                    count = 0;
                }
            }
            std::cout << count << "\n";
        }
    }
}

