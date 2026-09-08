#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define MAX 501
int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];
int cnt;
int num[MAX * MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
// dfs memory : 11916
void dfs(int x, int y) {
    if(visited[x][y]) return;
    visited[x][y] = true;
    ++num[cnt];
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
        if(map[nx][ny] == 0 || visited[nx][ny]) continue;
        dfs(nx, ny);
    }
}
// bfs memory : 4228
void bfs(int x, int y) {
    queue<pair<int, int> > Q;
    visited[x][y] = true;
    Q.push( make_pair(x, y) );
    while(!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        ++num[cnt];
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
            if(map[nx][ny] == 0 || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            Q.push( make_pair(nx, ny) );
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> map[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(map[i][j] == 0 || visited[i][j]) continue;
            ++cnt;
            bfs(i, j);
        }
    }
    cout << cnt << endl;
    cout << *max_element(num + 1, num + cnt + 1);
    return 0;
}