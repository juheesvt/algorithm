#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <climits>
#include <queue>
#include <list>
#include <stack>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int MAX_INVEN = 64 * 1000 * 1000;
int m, n, inven;

vector<vector<int>> ground;
vector<int> cache;


bool checkGround(int target) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ground[i][j] != target)
                return false;
        }
    }
    return true;
} 

bool checkInven(int target) {
    int sum = 0;
    int need = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ground[i][j] > target) {
                sum += ground[i][j] - target;
            } else {
                need += target - ground[i][j];
            }
        }
    }

    sum += inven;

    if (sum > MAX_INVEN || need > MAX_INVEN) {
        return false;
    } else if (need <= sum) {
        return true;
    } else {
        return false;
    }
}

int deleteBlock(int i, int j) {
    return 2;
}

int stackBlock(int i, int j) {
    return 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> m >> n >> inven;
    
    ground = vector(m, vector<int>(n, 0));

    int temp;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            ground[i][j] = temp;
        }
    }

    int target = 257;
    int minTime = 500 * 500 * 255 * 2, maxTarget = target;
    while (target > 0) {

        target -= 1;
        int time = 0;
        
        // invent check
        if (!checkInven(target))
            continue;

        // 땅 고르기 작업
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int differ = target - ground[i][j];
                if (differ > 0) { // target > ground[i][j]
                    time += differ;
                } else if (differ < 0) { // target < ground[i][j]
                    time += (2 * abs(differ));
                }
            }
        }

        // minTime 갱신
        if (time < minTime) {
            minTime = time;
            maxTarget = target;
        }
    }
    cout << minTime << " " << maxTarget;
    return 0;
}
