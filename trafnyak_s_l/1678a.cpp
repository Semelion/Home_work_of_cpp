#include <iostream>
#include <vector>

int main(){
    int t;
    std::cin >> t;
    for(int num_of_data_set = 0; num_of_data_set < t; t++){
        int n;
        std::cin >> n;

        std::vector<int> nums;
        nums.resize(n);
        for(int i = 0; i < nums.size(); i++){
            std::cin >> nums[i];
        }


        bool flag = false;
        int start_i = 0;
        int count = 0;
        int min = 200;
        if(nums[0] == 0){
            min = 0;
        } else {
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] < min){
                    min = nums[i];
                    start_i = i;
                }
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(i != start_i && nums[i] != 0){
                if(nums[i] == min){
                    nums[i] = 0;
                    count++;
                } else{
                    nums[i] = min;
                    count++;
                }
            }
        }

        std::cout << count << "\n";
    }
    return 0;
}