#include <iostream>
#include <queue>

using namespace std;
#define MAX 50
// 이동시간 저장 (물 = -1)
int map[MAX][MAX];
int ROW, COL, MAX_LENGTH;
// 좌 우 상 하
int dcol[4] = {-1, 1, 0, 0};
int drow[4] = {0, 0, -1, 1};

void reset() {
    for(int i = 0; i < ROW; ++i) {
        for(int j = 0; j < COL; ++j) {
            if(map[i][j] != -1) map[i][j] = 0;
        }
    }
    MAX_LENGTH = 0;
}
int bfs(int row, int col) {
    queue<pair<int, int>> Q;
    Q.push({row, col});
    map[row][col] = 1;
    while(!Q.empty()) {
        row = Q.front().first;
        col = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; ++i) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow < 0 || ncol < 0 || nrow >= ROW || ncol >= COL) continue;
            if(map[nrow][ncol]) continue;
            Q.push({nrow, ncol});
            map[nrow][ncol] = map[row][col] + 1;
            if(map[nrow][ncol] > MAX_LENGTH) MAX_LENGTH = map[nrow][ncol];
        }
    }
    return MAX_LENGTH - 1;
}

int main() {
    cin >> ROW >> COL;
    for(int i = 0; i < ROW; ++i) {
        for(int j = 0; j < COL; ++j) {
            char c;
            cin >> c;
            if(c == 'W') map[i][j] = -1;
        }
    }
    int ans = 0;
    for(int i = 0; i < ROW; ++i) {
        for(int j = 0; j < COL; ++j) {
            if(!map[i][j]) {
                int tmp = bfs(i, j);
                if(tmp > ans) ans = tmp;
                reset();
            }
        }
    }
    cout << ans;
    return 0;
}