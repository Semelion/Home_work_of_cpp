#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    for (int num_of_dataset = 0; num_of_dataset < t; num_of_dataset++) {
        int n;
        int k;
        std::cin >> n >> k;

        std::string strip;
        std::cin >> strip;

        int last_count = 0;
        for(int i = 0; i < k; i++){
            if(strip[i] == 'B'){
                last_count++;
            }
        }
        int k_max = last_count;

        for(int i = k; i <= n-k; i++){
            int count = last_count;
            if(strip[i] == 'B'){
                count--;
            }
            if(strip[i+k] == 'B'){
                count++;
            }

            last_count = count;
            if(k_max < count){
                k_max = count;
            }
        }

        std::cout << k - k_max << "\n";

    }


    return 0;
}
