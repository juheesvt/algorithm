#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int main() {

    int n, l, start, end;
    cin >> n >> l;

    vector<pair<int, int> > pool;
    for (int i = 0; i < n; ++i) {
        cin >> start >> end;
        pool.push_back(pair<int, int>(start, end));
    }

    // 웅덩이 좌표 정렬하기
    sort(pool.begin(), pool.end());

    int cnt = 0, over = 0;
    for (int i = 0 ; i < pool.size(); i++) {

        // 널판지의 마지막 길이가 현재 웅덩이의 시작 지점을 넘어가있을 때, 널판지의 마지막 지점을 현재 웅덩이의 시작 지점으로 갱신
        if(pool[i].first > over)
            over = pool[i].first;

        // 웅덩이를 계속 돌면서 널판지 추가하기
        while(over < pool[i].second) {
            over += l;
            cnt++;
        }
    }
    printf("%d", cnt);
}
