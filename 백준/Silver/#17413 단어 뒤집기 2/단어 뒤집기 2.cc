#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <climits>
#include <queue>
#include <list>
#include <stack>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int MAX_INVEN = 64 * 1000 * 1000;
int m, n, inven;

vector<vector<int>> ground;
vector<int> cache;


bool checkGround(int target) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ground[i][j] != target)
                return false;
        }
    }
    return true;
} 

bool checkInven(int target) {
    int sum = 0;
    int need = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ground[i][j] > target) {
                sum += ground[i][j] - target;
            } else {
                need += target - ground[i][j];
            }
        }
    }

    sum += inven;

    if (sum > MAX_INVEN || need > MAX_INVEN) {
        return false;
    } else if (need <= sum) {
        return true;
    } else {
        return false;
    }
}

int deleteBlock(int i, int j) {
    return 2;
}

int stackBlock(int i, int j) {
    return 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    string str;
    getline(cin, str);
    vector<string> answers;

    int isReverse = 1;
    string tmp = "";
    for (int i=0; i < str.size(); i++) {
        if (str[i] == '<') {
            if (!isReverse) {
                answers.push_back(tmp);
            } else {
                reverse(tmp.begin(), tmp.end());
                answers.push_back(tmp);
            }
            isReverse = 0;
            tmp.clear();
            tmp.push_back(str[i]);
        } else if (str[i] == '>') {
            tmp.push_back(str[i]);
            answers.push_back(tmp);
            tmp.clear();
            isReverse = 1;
        } else if (str[i] == ' ') {
            if (!isReverse) {
                tmp.push_back(str[i]);
            } else {
                reverse(tmp.begin(), tmp.end());
                answers.push_back(tmp);
                answers.push_back(" ");
                tmp.clear();
            }
        } else if (i == str.size() - 1) {
            tmp.push_back(str[i]);
            if (!isReverse) {
                answers.push_back(tmp);
            } else {
                reverse(tmp.begin(), tmp.end());
                answers.push_back(tmp);
            }
            tmp.clear();
        } else {
            tmp.push_back(str[i]);
        }
    }

    for (auto answer: answers) {
        cout << answer;
    }

    
    return 0;
}
