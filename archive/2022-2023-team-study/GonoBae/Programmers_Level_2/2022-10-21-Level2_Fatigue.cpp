#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool visited[1001];
vector<vector<int>> dungeon;
int m;
void dfs(int curDungeon, int fatigue, int move) {
    visited[curDungeon] = true;
    fatigue -= dungeon[curDungeon][1];
    for(int i = 0; i < dungeon.size(); ++i) {
        if(!visited[i] && dungeon[i][0] <= fatigue) dfs(i, fatigue, move + 1);
    }
    m = max(move, m);
    visited[curDungeon] = false;
}

int solution(int k, vector<vector<int>> dungeons) {
    dungeon = dungeons;
    for(int i = 0; i < dungeon.size(); ++i) {
        if(k >= dungeon[i][0]) dfs(i, k, 1);
    }
    
    return m;
}

int main() {
    int k = 80;
    vector<vector<int>> dungeons = {
        {80, 20},
        {50, 40},
        {30, 10}
    };
    int result = solution(k, dungeons);
    cout << result;
    return 0;
}