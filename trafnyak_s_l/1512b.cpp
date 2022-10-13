#include <iostream>
#include <vector>

int main(){
    int t;
    std::cin >> t;
    for(int num_of_data_set = 0; num_of_data_set < t; t++){
        int n;
        std::cin >> n;
        std::vector<int> x;
        std::vector<int>y;

        for(int x_i = 0; x_i < n; x_i++){
            for(int y_i = 0; y_i < n; y_i++){
                char temp;
                std::cin >> temp;
                if(temp == '*'){
                    x.push_back(x_i);
                    y.push_back(y_i);
                }
            }
        }

        for(int x_i = 0; x_i < n; x_i++){
            for(int y_i = 0; y_i < n; y_i++){
                bool flag = false;
                for(int i = 0; i < x.size(); i++){
                    if(x[i] == x_i && y[i] == y_i){
                        std::cout << "*";
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    std::cout << ".";
                }
            }
            std::cout << "\n";
        }
    }
    return 0;
}