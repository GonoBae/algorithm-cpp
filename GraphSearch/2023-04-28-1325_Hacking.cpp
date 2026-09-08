#include <iostream>
#include <vector>

using namespace std;
#define MAX 10001
vector<int> V[MAX];
vector<int> ans;
bool visited[MAX];
int cnt, max_cnt;

void reset(int _n) {
    for(int i = 1; i <= _n; ++i) {
        visited[i] = 0;
    }
}

void dfs(int node) {
    visited[node] = true;
    ++cnt;
    for(auto n : V[node]) {
        if(!visited[n]) dfs(n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        V[b].push_back(a);
    }
    for(int i = 1; i <= N; ++i) {
        cnt = 0;
        reset(N);
        dfs(i);
        if(cnt > max_cnt) {
            max_cnt = cnt;
            ans.clear();
            ans.push_back(i);
        }
        else if(cnt == max_cnt) ans.push_back(i);
    }
    for(auto a : ans) {
        cout << a << ' ';
    }
    return 0;
}