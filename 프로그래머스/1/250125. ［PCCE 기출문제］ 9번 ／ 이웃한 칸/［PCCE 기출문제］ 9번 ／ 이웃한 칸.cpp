#include <string>
#include <vector>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int mh = board.size() - 1;
    int mw = board[0].size() - 1;
    
    for (int i = 0; i < 4; i++) {
        int nx = h + dx[i];
        int ny = w + dy[i];

        if (nx < 0 || nx > mh || ny < 0 || ny > mh)
            continue;
        
        if (board[h][w] == board[nx][ny])
            answer++;
    }
    
    return answer;
}