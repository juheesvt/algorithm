#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 10001;
int visited[MAX];
int n, m, u, v, startNode;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(vector<vector<int>> &adjList, int currentNode) {
	visited[currentNode] = 1;
	cout << currentNode << " ";

	for (int nextNode: adjList[currentNode]) {
		if (visited[nextNode]) continue;
		dfs(adjList, nextNode); 
	}
	return;
}

void bfs(vector<vector<int>> &adjList) {

	queue<int> q;
	q.push(startNode);
	visited[startNode] = 1;
	cout << startNode << " ";

	while(!q.empty()) {
		int currentNode = q.front();
		q.pop();

		for (int nextNode: adjList[currentNode]) {
			if (visited[nextNode] == 0) {
				q.push(nextNode);
				visited[nextNode] = 1;
				cout << nextNode << " ";
			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
	
	cin >> n >> m >> startNode;

	vector<vector<int>> adjList (n + 1, vector<int>());

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(adjList[i].begin(), adjList[i].end());
	}

	fill(visited, visited + n + 1, 0);
	dfs(adjList, startNode);
	cout << endl;
	fill(visited, visited + n + 1, 0);
	bfs(adjList);

    return 0;
}
