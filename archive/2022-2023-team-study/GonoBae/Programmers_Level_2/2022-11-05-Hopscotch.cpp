#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// dfs로 풀었더니 테스트케이스 말고는 죄다 시간초과
// 행의 갯수 : 100,000 이하 , 열의 개수 : 4
int solution(vector<vector<int>> land)
{
    int answer = 0;
    for(int i = 1; i < land.size(); ++i) {
        land[i][0] += max({land[i - 1][1], land[i - 1][2], land[i - 1][3]});
        land[i][1] += max({land[i - 1][0], land[i - 1][2], land[i - 1][3]});
        land[i][2] += max({land[i - 1][0], land[i - 1][1], land[i - 1][3]});
        land[i][3] += max({land[i - 1][0], land[i - 1][1], land[i - 1][2]});
    }
    answer = max({land[land.size() - 1][0], land[land.size() - 1][1], land[land.size() - 1][2], land[land.size() - 1][3]});
    return answer;
}

int main() {
    vector<vector<int> > land = {
        {1, 2, 3, 5},
        {5, 6, 7, 8},
        {4, 3, 2, 1}
    };
    int result = solution(land);
    cout << result;
    return 0;
}