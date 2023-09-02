#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 10000;

int main() {

	int n;
	cin >> n;

	int wine[MAX] = {0, };
	int cache[MAX] = {0, };
	for (int i=1; i<=n; i++) {
		cin >> wine[i];
	}

	cache[1] = wine[1], cache[2] = wine[1] + wine[2];
	for (int i=3; i<=n; i++) {
		// 1 0 1 1,  ? 1 0 1, ? ? 1, 0
		cache[i] = max(cache[i - 3] + wine[i - 1] + wine[i], max(cache[i - 2] + wine[i], cache[i - 1]));
	}
	cout << cache[n];

    return 0;
}