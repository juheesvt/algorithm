#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 1000000;

int main() {

	vector<int> stock (MAX, 0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> stock[i];
		}

		long long profit = 0, max = 0;
		for (int i=n-1; i>=0; i--) {
			if (stock[i] > max) {
				max = stock[i];
			} else {
				profit += (max - stock[i]);
			}
		}
		cout << profit << endl;
	}

    return 0;
}