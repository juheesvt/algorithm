#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <list>
#include <stack>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int t, m, n, k;

vector<vector<int>> ground;
vector<vector<int>> visited;


int bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    visited[i][j] = 1;

    while (!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for (int r = 0; r < 4; r++) {
            int nextX = currentX + dx[r];
            int nextY = currentY + dy[r];

            if (nextX < 0 || nextX >= m || 0 > nextY || nextY >= n)
                continue;

            if (ground[nextX][nextY] == 1 && visited[nextX][nextY] == 0) {
                q.push(make_pair(nextX, nextY));
                visited[nextX][nextY] = 1;
            }
        }
    }
    return 1;
}


int main() {

    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> m >> n >> k;
        
        ground = vector(m, vector<int>(n, 0));
        visited = vector(m, vector<int>(n, 0)); 

        int x, y;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            ground[x][y] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ground[i][j] == 1 && visited[i][j] == 0) {
                    cnt += bfs(i, j);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}