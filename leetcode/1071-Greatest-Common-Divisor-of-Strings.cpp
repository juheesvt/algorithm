class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";

        int a = max(str1.length(), str2.length());
        int b = min(str1.length(), str2.length());
        int n = a % b;

        while (n) {
            a = b;
            b = n;
            n = a % b;
        }
        return str1.substr(0, b);
    }
    
};