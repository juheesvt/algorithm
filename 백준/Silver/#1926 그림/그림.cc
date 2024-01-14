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

int bfs(vector<vector<int>>& MAP, vector<vector<int>>& visited, int x, int y) {

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;

    int area = 1;
    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || MAP[nextX][nextY] == 0 || visited[nextX][nextY]) 
                continue;
            q.push(make_pair(nextX, nextY));
            visited[nextX][nextY] = 1;
            area += 1; 
        }
    }
    return area;
}


int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
	
	cin >> n >> m;

	vector<vector<int>> MAP (n, vector<int>(m, 0));
    vector<vector<int>> visited (n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> MAP[i][j];
        }
    }

    int paintingNum = 0;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (MAP[i][j] == 1 && visited[i][j] == 0) {
                paintingNum += 1;
                int area = bfs(MAP, visited, i, j);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }
    cout << paintingNum << "\n" << maxArea;

    return 0;
}
