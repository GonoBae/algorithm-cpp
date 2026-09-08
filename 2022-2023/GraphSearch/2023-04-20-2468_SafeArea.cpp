#include <algorithm>
#include <iostream>

using namespace std;
#define MAX 101
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, cnt, F = 1;
int maxCnt;

void dfs(int x, int y) {
    if(visited[x][y]) return;
    visited[x][y] = true;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dy[i];
        int ny = y + dx[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(map[nx][ny] <= F || visited[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> map[i][j];
            if(map[i][j] > F) F = map[i][j];
        }
    }
    while(F >= 0) {
        cnt = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                visited[i][j] = false;
            }
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(map[i][j] <= F || visited[i][j]) continue;
                dfs(i, j);
                ++cnt;
            }
        }
        maxCnt = max(maxCnt, cnt);
        --F;
    }
    cout << maxCnt;
    return 0;
}