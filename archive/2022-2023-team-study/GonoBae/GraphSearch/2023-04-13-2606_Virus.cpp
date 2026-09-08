#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool visit[101];
int cnt;
vector<vector<int>> V(101);
void dfs(int node) {
    visit[node] = true;
    ++cnt;
    for(auto n : V[node]) {
        if(!visit[n]) dfs(n);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i) {
        sort(V[i].begin(), V[i].end());
    }
    dfs(1);
    cout << cnt - 1;
    return 0;
}