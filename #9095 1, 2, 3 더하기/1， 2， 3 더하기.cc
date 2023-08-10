#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <map>

using namespace std;

const int MAX = 11 + 1;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    int cache[MAX] = {0, };
    for (int i=0; i<t; i++) {
        int n;
        cin >> n;

        cache[1] = 1, cache[2] = 2, cache[3] = 4;
        for (int j=4; j<=n; j++) {
            cache[j] = cache[j - 1] + cache[j - 2] + cache[j - 3];
        }
        cout << cache[n] << endl;
    }


    return 0;
}