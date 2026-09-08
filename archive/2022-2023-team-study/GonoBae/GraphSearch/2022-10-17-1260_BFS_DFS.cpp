// BFS => 여러 놈을 한번씩 때린다. (queue)
//        가장 먼저 넣었던 것을 꺼내기 -> 연결된 점을 Queue에 넣기 -> Queue가 빌 때까지 반복
// DFS => 한 놈만 끝까지 팬다. (재귀함수, stack)
//        수행시간이 복불복
// 경로 탐색(최단거리 , 시간) , 네트워크 유형(연결) , 조합 유형(모든 조합 만들기)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1001

vector<vector<int>> V(MAX);
int N, M, num;
bool visited[MAX];

// BFS
void BFS(int node) {
    queue<int> Q;
    bool qVisited[MAX] = { false };
    Q.push(node);
    qVisited[node] = true;
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        cout << cur << ' ';
        for(int next : V[cur]) {
            if(!qVisited[next]) {
                qVisited[next] = true;
                Q.push(next);
            }
        }
    }
}

// DFS
void DFS(int node) {
    visited[node] = true;
    cout << node << ' ';
    for(int next : V[node]) {
        if(!visited[next]) {
            DFS(next);
        }
    }
}

// MAIN
int main() {
    cin >> N >> M >> num;
    while(M--) {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    for(int i = 1; i <= N; i++)
    {
        sort(V[i].begin(), V[i].end());
    }

    DFS(num);
    cout << endl;
    BFS(num);
    return 0;
}