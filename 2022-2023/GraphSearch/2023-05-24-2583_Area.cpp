#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 100
int M, N, K, cnt, area;
bool map[MAX][MAX];
// 좌 우 상 하
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y) {
    map[x][y] = true;
    ++area;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dy[i];
        int ny = y + dx[i];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if(map[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main() {
    vector<int> V;
    cin >> M >> N >> K;
    for(int i = 0; i < K; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1; x < x2; ++x) {
            for(int y = y1; y < y2; ++y) {
                if(!map[y][x]) map[y][x] = true;
            }
        }
    }
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(!map[i][j]) {
                area = 0;
                dfs(i, j);
                V.push_back(area);
                ++cnt;
            }
        }
    }
    sort(V.begin(), V.end());
    cout << cnt << endl;
    for(auto v : V) {
        cout << v << ' ';
    }
    return 0;
}