#include <iostream>

using namespace std;
#define MAX 1001
bool visit[MAX];
int cnt, n, m;
bool map[MAX][MAX];
void dfs(int node) {
    visit[node] = true;
    for(int i = 1; i <= n; ++i) {
        if(map[node][i] && !visit[i]) dfs(i);
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        map[a][b] = true;
        map[b][a] = true;
    }
    for(int i = 1; i <= n; ++i) {
        if(visit[i]) continue;
        dfs(i);
        ++cnt;
    }
    cout << cnt;
    return 0;
}