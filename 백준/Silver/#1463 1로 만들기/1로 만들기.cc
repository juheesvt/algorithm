#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <map>

using namespace std;

const int MAX = 1000001;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cache[MAX];
    cache[1] = 0;
    for (int i=2; i<=n; i++) {
        cache[i] = INT_MAX;
    }

    for (int i=2; i<=n; i++) {
        if (i % 3 == 0)
            cache[i] = cache[int(i/3)] + 1;
        
        if (i % 2 == 0)
            cache[i] = min(cache[i], cache[int(i/2)] + 1);

        cache[i] = min(cache[i], cache[i - 1] + 1);
    }
    cout << cache[n];

    return 0;
}