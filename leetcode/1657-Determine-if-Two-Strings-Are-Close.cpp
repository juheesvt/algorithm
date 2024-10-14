#include <vector>
#include <unordered_map>
class Solution {
public:
    unordered_map<char, int> makeDictionary(string words) {
        unordered_map<char, int> word_dict;
        for (auto& word: words) {
            if (word_dict.find(word) == word_dict.end()) {
                word_dict[word] = 0;
             }
            word_dict[word]++;
        }
        return word_dict;
    }
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) 
            return false;
        
        unordered_map<char, int> word1_dict = makeDictionary(word1);
        unordered_map<char, int> word2_dict = makeDictionary(word2);

        vector<char> word1_keys, word2_keys;
        vector<int> word1_values, word2_values;
        unordered_map<char, int>::iterator iter;

        for (iter = word1_dict.begin(); iter != word1_dict.end(); iter++) {
            word1_keys.push_back(iter->first);
            word1_values.push_back(iter->second);
        }

        for (iter = word2_dict.begin(); iter != word2_dict.end(); iter++) {
            word2_keys.push_back(iter->first);
            word2_values.push_back(iter->second);
        }

        sort(word1_keys.begin(), word1_keys.end());
        sort(word2_keys.begin(), word2_keys.end());

        if (word1_keys != word2_keys)
            return false;

        sort(word1_values.begin(), word1_values.end());
        sort(word2_values.begin(), word2_values.end());

        if (word1_values != word2_values) 
            return false;

        return true;
    }
};