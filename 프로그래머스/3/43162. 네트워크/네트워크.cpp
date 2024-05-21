#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int node, int n, vector<vector<int>> &computer, vector<int> &visited) {
    queue<int> q;
    
    q.push(node);
    visited[node] = 1;
    
    while (!q.empty()) {
        
        int currentNode = q.front();
        q.pop();
        
        for (int i = 0; i < n; i++) {
            if (i == currentNode)
                continue;

            if (computer[currentNode][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return 1;
    
}

int solution(int n, vector<vector<int>> computers) {
    
    if (n == 1)
        return 1;
    
    int answer = 0;
    
    vector<int> visited (n, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            
            if (visited[i] != 1) {
                answer += bfs(i, n, computers, visited);
            }
        }
    }
    return answer;
}