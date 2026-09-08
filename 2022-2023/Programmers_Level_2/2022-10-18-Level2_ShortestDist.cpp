// 최단거리 -> BFS
// 0 = 벽, 1 = 길
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Point {
    int x, y, dist;
};
int Move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int solution(vector<vector<int> > maps)
{
    int limitX = maps.size();
    int limitY = maps[0].size();
    vector<vector<bool>> visited(limitX, vector<bool>(limitY, false));
    queue<Point> Q;
    visited[0][0] = true;
    Q.push({0, 0, 1});
    while(!Q.empty()) {
        Point cur = Q.front();
        Q.pop();
        if(cur.x == maps.size() - 1 && cur.y == maps[0].size() - 1) return cur.dist;
        for(int i = 0; i < 4; ++i) {
            int nearX = cur.x + Move[i][0], nearY = cur.y + Move[i][1];
            if(nearX < 0 || nearX > limitX - 1 || nearY < 0 || nearY > limitY - 1) continue;
            if(visited[nearX][nearY]) continue;
            if(maps[nearX][nearY] == 0) continue;
            visited[nearX][nearY] = true;
            Q.push({nearX, nearY, cur.dist + 1});
        }
    }
    
    return -1;
}

int main() {
    vector<vector<int>> maps = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1}
    };
    int result = solution(maps);
    cout << result;
    return 0;
}