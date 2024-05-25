#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    for (int w: works) {
        pq.push(w);
    }
    
    while (n--) {
        int num = pq.top();
        pq.pop();
        pq.push(num - 1 > 0 ? num - 1:0);
    }
    
    while(!pq.empty()) {
        answer += pow(pq.top(), 2);
        pq.pop();
    }
    return answer;
}