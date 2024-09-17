#include <numeric>
#include <limits>

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_num = -123456789;
        double current_num = accumulate(nums.begin(), nums.begin() + k, 0, [](int x, int y) {
            return x + y;
        });

        printf("%f %f", current_num, max_num);

        if (current_num > max_num) max_num = current_num;
        for (int i = 0; i < nums.size() - k; i++) {
            current_num += -nums[i] + nums[i + k];
            if (current_num > max_num) {
                max_num = current_num;
            }
        }
        return max_num / k;
    }
};