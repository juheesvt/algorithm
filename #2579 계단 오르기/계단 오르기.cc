#include <iostream>

using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int MAX = 300;

    int n;
    cin >> n;
    
    int stair[301];
    int cache[301];

    for (int i=0; i<n; i++) {
        cin >> stair[i];
    }

    if (n <= 2) {
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += stair[i];
        }
        cout << sum;
    } else {
        cache[0] = stair[0];
        cache[1] = stair[0] + stair[1];

        for (int i=2; i<n; i++) {
            cache[i] = max(cache[i-3] + stair[i-1] + stair[i], cache[i-2] + stair[i]);
        }
        cout << cache[n - 1];
    }


    return 0;
}