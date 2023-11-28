#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 100;
int visited[MAX][MAX];
int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
	
	cin >> n >> m;

	vector<vector<int>> MAP (n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			MAP[i][j] = tmp[j] - '0';	
		}
	}

	queue<pair<int, pair<int, int>>> q;
	q.push({1, {0, 0}}); 	
	visited[0][0] = 1;

	while (!q.empty()) {
		int curPath = q.front().first;
		int curX = q.front().second.first;
		int curY = q.front().second.second;	
		q.pop();

		if (curX == n - 1 && curY == m - 1) {
			cout << curPath;
			break;
		}
		
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || !MAP[nextX][nextY] || visited[nextX][nextY] ) continue;
			q.push({curPath + 1, {nextX, nextY}});
			visited[nextX][nextY] = 1;
		}	
	}
    return 0;
}
