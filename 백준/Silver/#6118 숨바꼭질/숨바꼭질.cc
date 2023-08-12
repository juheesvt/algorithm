#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<vector<int> > graph;
vector<int> visited;
vector<int> dist;

void bfs() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    visited[1] = 1;


    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i=0; i<graph[current].size(); i++) {
            int next = graph[current][i];
            if (visited[next] == 1) continue;
            q.push(next);
            dist[next] = dist[current] + 1;
            visited[next] = 1;
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    graph = vector<vector<int> > (n + 1, vector<int>());
    visited = vector<int> (n + 1, 0);
    dist = vector<int> (m + 1, 0);

    int u, v;
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs();

    int maxVal = 0;
    for (int i=1; i<=n; i++) {
        maxVal = max(maxVal, dist[i]);
    }

    int targetNode = 0, cnt = 0;
    bool flg = false;
    for (int i=1; i<=n; i++) {
        if (maxVal == dist[i]) {
            if (!flg) {
                flg = true;
                targetNode = i;
            }
            cnt++;
        }
    }
    cout << targetNode << " " << maxVal << " " << cnt;

    return 0;
}