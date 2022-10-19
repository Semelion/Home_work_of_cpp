#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> nums;
        nums.resize(n);
        for (int i = 0; i < n; i++) {
            std::cin >> nums[i];
        }

        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res = (res & nums[i]);
        }
        std::cout << res << "\n";
    }
    return 0;
}
