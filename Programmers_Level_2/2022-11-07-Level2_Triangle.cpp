#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 1, 4, 7, 10 => 아래
// 2, 5, 8, 11 => 오른쪽
// 3, 6, 9, 12 => 대각 위로
vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> V(n, vector<int>(n));
    int x = 0, y = -1;
    int count = 0;
    for(int i = 0; i < n; ++i) {
        switch((i + 1) % 3) {
            case 1: // 아래로
                for(int j = i; j < n; ++j) {
                    V[++y][x] = ++count;
                }
                break;
            case 2: // 오른쪽으로
                for(int j = i; j < n; ++j) {
                    V[y][++x] = ++count;
                }
                break;
            case 0: // 대각선 위로
                for(int j = i; j < n; ++j) {
                    V[--y][--x] = ++count;
                }
                break;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(V[i][j] == 0) break;
            answer.push_back(V[i][j]);
        }
    }
    return answer;
}

int main() {
    int n = 5;
    vector<int> result = solution(n);
    for(auto r : result) {
        cout << r << ' ';
    }
    return 0;
}