#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();    
    if (n == 1) return triangle[0][0];

    vector<vector<long long>> trian (n, vector<long long> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            trian[i][j] = triangle[i][j];
        }
    }
    
    trian[1][0] += trian[0][0];
    trian[1][1] += trian[0][0];
    
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                trian[i][j] += trian[i - 1][j];
            } else if (j == i) {
                trian[i][j] += trian[i - 1][j - 1];
            } else {
                trian[i][j] += max(trian[i - 1][j - 1], trian[i - 1][j]);
            }
        }
    }
    return *max_element(trian[n - 1].begin(), trian[n - 1].end());
}