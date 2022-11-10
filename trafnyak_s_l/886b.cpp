#include <iostream>
#include <vector>
#include <cmath>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> logs_of_lunch;
    logs_of_lunch.resize(n);
    for(int i = 0; i < n; i++){
        std::cin >> logs_of_lunch.at(i);
    }

    int max = 0;
    for(int i = 0; i < n; i++){
        if(max < logs_of_lunch.at(i)){
            max = logs_of_lunch.at(i);
        }
    }

    std::vector<int> last_visit;
    last_visit.resize(max);
    for(int i = 0; i < last_visit.size(); i++){
        last_visit.at(i) = -1;
    }

    for(int i = 0; i < n; i++){
        last_visit.at(logs_of_lunch.at(i)) = i;
    }


}