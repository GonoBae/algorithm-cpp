#include <iostream>
#include <queue>

using namespace std;
#define MAX 1000
int N, M, answer;
int map[MAX][MAX];
int mr[4] = {-1, 1, 0, 0};
int mc[4] = {0, 0, -1, 1};
queue<pair<int, int>> Q;
void bfs() {
    while(!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; ++i) {
            int nr = r + mr[i];
            int nc = c + mc[i];
            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(map[nr][nc] != 0) continue;
            map[nr][nc] = map[r][c] + 1;
            Q.push({nr, nc});
        }
    }
}

int main() {
    cin >> M >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> map[i][j];
            if(map[i][j] == 1) Q.push({i, j});
        }
    }
    bfs();
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(map[i][j] == 0) {
                cout << -1;
                return 0;
            }
            else {
                if(answer < map[i][j]) answer = map[i][j];
            }
        }
    }
    cout << answer - 1;
    return 0;
}