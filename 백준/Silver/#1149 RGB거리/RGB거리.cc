#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <map>

using namespace std;

const int MAX = 1001;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int home[MAX][3];
    int cache[MAX][3] = {0, };

    for (int i=0; i<n; i++) {
        cin >> home[i][0] >> home[i][1] >> home[i][2];
    }

    // cache[i][j] = i번째 집을 j번째 색으로 칠했을 때의 최솟값
    for (int i=0; i<3; i++) {
        cache[0][i] = home[0][i];
    }

    for (int i=1; i<n; i++) {
        cache[i][0] = min(cache[i - 1][1], cache[i - 1][2]) + home[i][0];
        cache[i][1] = min(cache[i - 1][0], cache[i - 1][2]) + home[i][1];
        cache[i][2] = min(cache[i - 1][0], cache[i - 1][1]) + home[i][2];
    }

    cout << min(cache[n - 1][0], min(cache[n - 1][1], cache[n - 1][2]));

    return 0;
}