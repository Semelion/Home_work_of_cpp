#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector <int > estimates;
    estimates.resize(n);

    for(int i = 0; i < n; i++){
        int a,b,c,d;
        std::cin >> a >> b >> c >> d;
        estimates.at(i) = a + b + c + d;
    }

    std::vector <int > rate;
    rate.resize(n);

    for (int i = 0; i < n; i++) {
        rate.at(i) = -1;
    }

    for(int i = 0; i < n; i++){
        int max = 0;
        int i_max = 0;
        for(int j = 0; j < n; j++){
            if(estimates.at(j) > max && std::find(rate.begin(), rate.end(), j) == rate.end()){
                max = estimates.at(j);
                i_max = j;
            }

        }
        if(i_max == 0){
            std::cout << i + 1 << "\n";
            break;
        }
        rate.at(i) = i_max;
    }
//    int answer = 0;
//    for (int i = 0; i < n; i++) {
//        if(rate.at(i) == 0){
//            answer = i + 1;
//            break;
//        }
//    }
//    std::cout << answer << "\n";
}