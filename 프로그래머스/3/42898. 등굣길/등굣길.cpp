#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    const int MODULAR = 1000000007;
    vector<vector<int>> cache (n, vector<int>(m, 0));
    
    for (auto coor: puddles) {
        cache[coor[1] - 1][coor[0] - 1] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        if (cache[i][0] == -1) {
            for (int j = i; j < n; j++) {
                cache[j][0] = -1;
            }
            break;
        } else {
            cache[i][0] = 1;
        }
    }
    
    
    for (int i = 0; i < m; i++) {
        if (cache[0][i] == -1) {
            for (int j = i; j < m; j++) {
                cache[0][j] = -1;
            }
            break;
        } else {
            cache[0][i] = 1;
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (cache[i][j] == -1)
                continue;
            
            if (cache[i - 1][j] == -1 && cache[i][j - 1] == -1) {
                cache[i][j] = -1;
            } else if (cache[i - 1][j] == -1) {
                cache[i][j] = cache[i][j - 1];
            } else if (cache[i][j - 1] == -1) {
                cache[i][j] = cache[i - 1][j];
            } else {
                cache[i][j] = (cache[i - 1][j] + cache[i][j - 1]) % MODULAR;
            }
        }
    }
    return cache[n - 1][m - 1] == -1 ? 0:cache[n - 1][m - 1];
}