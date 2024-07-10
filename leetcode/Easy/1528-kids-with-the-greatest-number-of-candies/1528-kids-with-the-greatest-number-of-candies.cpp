#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result = {};
        int maxVal = *max_element(candies.begin(), candies.end());
        for (int val: candies) {
            result.push_back((val + extraCandies >= maxVal) ? true : false);
        }     
        return result;
    }
};