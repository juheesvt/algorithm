#include <vector>
#include <string>
#include <cctype>

class Solution {
public:
    string strip(string s) {
        auto start_it = s.begin();
        auto end_it = s.rbegin();
        while (std::isspace(*start_it))
            ++start_it;
        while (std::isspace(*end_it))
            ++end_it;
        return string(start_it, end_it.base());
    }

    vector<string> split(string s, char delimiter) {
        vector<string> result;
        stringstream ss(s);
        string temp;

        while (getline(ss, temp, delimiter)){
            if (temp.length() == 0) continue;
            result.push_back(temp);
        }
        return result;
    }

    string reverseWords(string s) {
        string answer = "";
        string stripedS = strip(s);
        vector<string> words = split(stripedS, ' ');

        for (int i = words.size() - 1; i > 0; i--) {
            answer += words[i] + " ";
        }
        answer += words[0];
        return answer;
    }
};