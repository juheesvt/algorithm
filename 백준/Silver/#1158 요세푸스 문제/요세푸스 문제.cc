#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <list>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> answers;
    list<int> josephus;

    for (int i = 0; i < n; i++) {
        josephus.push_back(i + 1);
    }

    int count = 0;
    list<int>::iterator cur = josephus.begin();
    while (!josephus.empty()) {
        count += 1;
        if (count == k) {
            answers.push_back(*cur);
            if (cur == josephus.end()) {
                josephus.erase(cur);
                cur = josephus.begin();
                count = 0;
            } else {
                cur = josephus.erase(cur);
                count = 0;
            }
        } else {
            cur++;
        }

        if (cur == josephus.end()) {
            cur = josephus.begin();
        }
    }

    cout << "<";
    for (int i = 0; i < answers.size(); i++) {
        cout << answers[i];
        if (i != answers.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">";

    return 0; 
}
