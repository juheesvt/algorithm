#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int main() {

    int f, s, g, u, d; 
    cin >> f >> s >> g >> u >> d;

    vector<int> visited(f + 1, 0);

    // bfs
    queue<int> q;

    // 첫 시작 위치 queue에 넣고 visited 체크하기
	q.push(s);
	visited[s] = 1;

	int next, floor;
	int flag = 0;
	while (!q.empty()) {
		floor = q.front();
		q.pop();

        // 목표 층에 도달하면 끝 @
		if (floor == g) {
			cout << visited[floor] - 1;
			flag = 1;
			break;
		}
		
        //d 위로 이동
		next = floor + u;
		if (next <= f && visited[next] == 0)  {
			q.push(next);
			visited[next] = visited[floor] + 1;
		}

        // 아래로 이동
		next = floor - d;
		if (next > 0 && visited[next] == 0) {
			q.push(next);
			visited[next] = visited[floor] + 1;
        }
	}

	if (!flag)	cout << "use the stairs";
    return 0;
}