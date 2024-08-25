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

    int n, s, m;
    cin >> n >> s >> m;

    int volumn[MAX];
    for (int i=1; i<=n; i++) {
        cin >> volumn[i];
    }

    int cache[MAX][MAX] = {0, };
    cache[0][s] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            if (cache[i - 1][j] == 1) {
                if (j + volumn[i] <= m) cache[i][j + volumn[i]] = 1;
                if (j - volumn[i] >= 0) cache[i][j - volumn[i]] = 1;
            }
            
        }
    }

    int maxVal = -1;
    for (int i=0; i<=m; i++) {
        if (cache[n][i] == 1 && maxVal < i) {
            maxVal = i;
        }
    }
    cout << maxVal;

    return 0;
}