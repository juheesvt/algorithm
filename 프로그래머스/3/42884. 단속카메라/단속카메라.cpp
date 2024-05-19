#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    vector<int> points;
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b) -> bool {
        return a[1] < b[1];
    });
    
    points.push_back(routes[0][1]);
    for (int i = 1; i < routes.size(); i++) {
        if (points[points.size() - 1] < routes[i][0]) {
            points.push_back(routes[i][1]);
        }
    }

    return points.size();
}