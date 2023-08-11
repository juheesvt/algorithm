#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <map>

using namespace std;

const int MAX = 301;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int stair[MAX];
    int cache[MAX] = {0, };

    for (int i=1; i<=n; i++) {
        cin >> stair[i];
        // cache[i + 1] = stair[i];
    }

    cache[1] = stair[1], cache[2] = stair[1] + stair[2];
    for (int i=2; i<=n; i++) {
        // cache[i] = i번째 계단을 밟았을 때 최댓값
        cache[i] = max(cache[i - 3] + stair[i - 1] + stair[i], cache[i - 2] + stair[i]);
    }
    cout << cache[n];

    return 0;
}