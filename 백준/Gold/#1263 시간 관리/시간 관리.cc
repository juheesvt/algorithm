#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 101;
int n, m, u, v;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
	
	cin >> n;

	vector<pair<int, int>> task (n, pair<int, int>());
	for (int i = 0; i < n; i++) {
		cin >> task[i].first >> task[i].second;
	}

    sort(task.begin(), task.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        return a.second > b.second;
	});

    int time = task[0].second - task[0].first;
    for (int i = 1; i < n; i++) {
        time = min(task[i].second - task[i].first, time - task[i].first);
    }
    cout << (time < 0 ? -1 : time);

    return 0;
}
