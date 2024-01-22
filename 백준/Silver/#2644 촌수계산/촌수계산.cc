#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 101;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> a >> b >> m;

    vector<vector<int>> graph = vector<vector<int>>(n + 1, vector<int>());
    vector<int> visited = vector<int>(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;
    queue<pair<int, int>> q;
    
    q.push(make_pair(a, 0));
    visited[a] = 1;

    int flg = false;
    while (!q.empty()) {
        int node = q.front().first;
        int currentCnt = q.front().second;
        q.pop();

        if (node == b) {
            cout << currentCnt;
            flg = true;
            break;
        }

        for (int nextNode: graph[node]) {
            if (visited[nextNode])
                continue;
            q.push(make_pair(nextNode, currentCnt + 1));
            visited[nextNode] = 1;
        }
    }

    if (!flg)
        cout << -1;

    return 0;
}
