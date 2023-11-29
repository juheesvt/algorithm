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
	
	cin >> n >> m;
	
	vector<vector<int>> MAP (n + 1, vector<int>());
	vector<int> visited (n + 1, 0);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		MAP[u].push_back(v);
		MAP[v].push_back(u);
	}

	int cnt = 0;
 
	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();

		for (int nextNode: MAP[currentNode]) {
			if (visited[nextNode]) 
				continue;

			q.push(nextNode);
			visited[nextNode] = 1;
			cnt++;
		}
	}

	cout << cnt;

    return 0;
}
