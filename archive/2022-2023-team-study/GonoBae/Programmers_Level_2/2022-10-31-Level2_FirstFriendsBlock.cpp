#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 배열을 원하는 컨테이너 시작주소값이 뒤(b)에 들어감
// true 이면 정렬완료
bool compare(pair<char, bool> a, pair<char, bool> b) {
    // true false => false true
    if(!a.second && b.second) return true;
    else return false;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<pair<char, bool>>> V(n);
    // 나눠담기
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            V[i].push_back({board[j][i], false});
        }
    }

    while(1) {
        int cnt = 0;
        // 전체 탐색
        for(int i = 0; i < n - 1; ++i) {
            for(int j = 0; j < m - 1; ++j) {
                char c = V[i][j].first;
                if(c == ' ') continue;
                if(c == V[i][j + 1].first && c == V[i + 1][j].first && c == V[i + 1][j + 1].first) {
                    V[i][j].second = true;
                    V[i][j + 1].second = true;
                    V[i + 1][j].second = true;
                    V[i + 1][j + 1].second = true;
                }
            }
        }
        // 2 x 2 블럭 글자제거 후 카운트
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(V[i][j].second && V[i][j].first != ' ') {
                    V[i][j].first = ' ';
                    ++cnt;
                }
            }
        }
        // 당기기
        for(int i = 0; i < m; ++i) {
            sort(V[i].rbegin(), V[i].rend(), compare);
        }
        if(cnt == 0) break;
        answer += cnt;
    }
    return answer;
}

bool comp(int a, int b) {
    if(a > b) return true;
    else return false;
}

int main() {
    int m = 4, n = 5;
    vector<string> board = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
    int result = solution(m, n, board);

    vector<int> num = {10, 2, 5, 3};
    sort(num.begin(), num.end(), comp);
    cout << result;
    return 0;
}