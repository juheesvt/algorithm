#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 50;
int MAP[MAX][MAX];
int n, m, d, flag;
int curX, curY, nextX, nextY;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool check() {
	for (int i = 0; i < 4; i++) {
		nextX = curX + dx[i];
		nextY = curY + dy[i];

		if ( nextX < 0 || n < nextX || nextY < 0 || m < nextY ) 
			continue;

		if (MAP[nextX][nextY] == 0) {
			return true;
		}
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
	
	cin >> n >> m;
	cin >> curX >> curY >> d;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> MAP[i][j];
		}
	}

	int cnt = 0;
	bool isCleaning = true;
	
	while (isCleaning) {

		// 1. 현재 위치한 방이 청소되지 않은 경우
		if (MAP[curX][curY] == 0) {
			MAP[curX][curY] = -1;
			cnt++;
		} 

		// 2. 주변 4칸 중 청소되지 않은 칸 탐색
		flag = false;
		flag = check();

		if (!flag) {
			// 바라보는 방향 유지한채 후진할 위치 가져오기
			if (d == 0 || d == 2) {
				nextX = curX + (d == 0? 1: -1);
				nextY = curY;
			} else {
				nextY = curY + (d == 3? 1: -1);
				nextX = curX;
			}

			// 후진 가능하면 후진하기
			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && MAP[nextX][nextY] != 1) {
				curX = nextX, curY = nextY;
			} else { // 후진 못하면 프로그램 작동 종료
				isCleaning = false;
				break;
			}
		} else {
			// 바라보는 방향의 바로 앞칸이 청소 안된 구역일때까지 반시계 방향으로 90도 회전 후 이동
			for (int i = 0; i < 4; i++) {
				// 반시계 방향 90도 회전
				switch (d) {
					case 0:	d = 3; break;
					case 1:	d = 0; break;
					case 2:	d = 1; break;
					case 3:	d = 2; break;
				}

				if (d == 0 || d == 2) {
					nextX = curX + (d == 0? -1: 1);
					nextY = curY;
				} else {
					nextY = curY + (d == 3? -1: 1);
					nextX = curX;
				}
				
				if (MAP[nextX][nextY] == 0) {
					curX = nextX, curY = nextY;
					break;
				}
			}
		}
	}
	cout << cnt;
    return 0;
}
