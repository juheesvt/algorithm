#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 10001;

int main() {

	int n, d, from, to, distance;
	cin >> n >> d;

	vector<int> map(d + 1, INT_MAX - 1);
	// fill(map.begin(), map.end(), 987654321);
	vector<pair<int, int> > sc[MAX];

	for (int i=0; i<n; i++) {
		cin >> from >> to >> distance;
		sc[to].push_back(make_pair(from, distance));
	}

	map[0] = 0;
	for (int i=1; i<=d; i++) {
		// 지름길이 없을 때
		if (sc[i].size() == 0) {
			map[i] = map[i - 1] + 1;
		} else {
			for (int j=0; j<sc[i].size(); j++) {
				// map에 저장된 값과 지름길의 출발지점에 누적거리에서 지름길을 통해 이동한 거리를 비교
				map[i] = min(map[i], min(map[i - 1] + 1, map[sc[i][j].first] + sc[i][j].second));
			}
		}
	}
	cout << map[d];

    return 0;
}