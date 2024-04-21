#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <list>
#include <stack>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t;
    cin >> t;

    
    while (t--) {
        string s;
        cin >> s;

        stack<char> answer, temp;
        
        for (char item : s) {
            if (item == '<') {
                if (!answer.empty()) {
                    temp.push(answer.top());
                    answer.pop();
                }
            } else if (item == '>') {
                if (!temp.empty()) {
                    answer.push(temp.top());
                    temp.pop();
                }
            } else if (item == '-') {
                if (!answer.empty()) {
                    answer.pop();
                }
            } else {
                answer.push(item);
            }
        }

        string result = "";

        while (!answer.empty()) {
            result += answer.top();
            answer.pop();
        }
        reverse(result.begin(), result.end());

        while (!temp.empty()) {
            result += temp.top();
            temp.pop();
        }

        cout << result;
        cout << '\n';
    }
    return 0;
}