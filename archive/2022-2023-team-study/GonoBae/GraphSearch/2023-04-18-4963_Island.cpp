#include <iostream>

using namespace std;
#define MAX 51
int map[MAX][MAX];
bool visited[MAX][MAX];
// 위, 아래, 왼, 오, 왼쪽 아래 대각, 오른쪽 아래 대각, 왼쪽 위 대각, 오른쪽 위 대각 
int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int w, h, cnt;

void resetmap() {
    for(int i = 0; i < MAX; ++i) {
        for(int j = 0; j < MAX; ++j) {
            map[i][j] = 0;
        }
    }
    for(int i = 0; i < MAX; ++i) {
        for(int j = 0; j < MAX; ++j) {
            visited[i][j] = false;
        }
    }
}

void dfs(int x, int y) {
    if(visited[x][y]) return;
    visited[x][y] = true;
    for(int i = 0; i < 8; ++i) {
        int nx = x + dy[i];
        int ny = y + dx[i];
        if(nx == 0 || ny == 0 || ny > w || nx > h) continue; // 범위
        if(map[nx][ny] == 0 || visited[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main() {
    while(true) {
        cnt = 0;
        resetmap();
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        for(int i = 1; i <= h; ++i) {
            for(int j = 1; j <= w; ++j) {
                cin >> map[i][j];
            }
        }
        for(int i = 1; i <= h; ++i) {
            for(int j = 1; j <= w; ++j) {
                if(map[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    ++cnt;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}