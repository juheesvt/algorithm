#include <iostream>
#include <vector>

using namespace std;

const int MAX = 51;
int n, m;
int nx, ny;

int visited[MAX][MAX] = {0, };
char floor[MAX][MAX] = {' ', };

int dfs(int x, int y, char type) {
    visited[x][y] = 1;

    if ((type == '-' && y == m - 1) || (type == '|' && x == n - 1))
        return 1;

    if (type == '-') {
        nx = x;
        ny = y + 1; 
    } else {
        nx = x + 1;
        ny = y; 
    }

    if (0 <= nx && nx < n && 0 <= ny && ny < m) {
        if (type == floor[nx][ny] && visited[nx][ny] == 0) {
            return dfs(nx, ny, floor[nx][ny]);
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        cin >> floor[i][j];
      }
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (visited[i][j] == 0) {
          cnt += dfs(i, j, floor[i][j]);
        }
      }
    }
    
    cout << cnt;
    return 0;
}