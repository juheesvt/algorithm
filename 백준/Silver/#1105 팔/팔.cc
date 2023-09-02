#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 1000000;

int main() {

	string l, r;
	cin >> l >> r;

	// 두 숫자의 자수 다르면 0
	if (l.length() != r.length()) {
		cout << 0;
	} else {
		int cnt = 0;

		// 맨 앞자리부터 검사하면서 숫자가 같을때까지 8의 갯수 세기
		for (int i=0; i<r.length(); i++) {
			if (l[i] == r[i] && l[i] == '8') {
				cnt++;
			} else if ( l[i] != r[i]) {
				break;
			}
		}
		cout << cnt;
	}
    return 0;
}