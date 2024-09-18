class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countDict;

        for (int num: arr) {
            if (countDict.find(num) == countDict.end()) {
                countDict.insert({num, 1});
            } else {
                countDict[num]++;
            }
        }

        unordered_map<int, int> countCountDict;
        for (auto value: countDict) {
            if (countCountDict.find(value.second) == countCountDict.end()) {
                countCountDict.insert({value.second, 1});
            } else {
                countCountDict[value.second]++;
            }
        }

        for (auto value: countCountDict) 
            if (value.second != 1) return false;
        return true;
    }
};