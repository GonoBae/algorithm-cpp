#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 메모리 : vector 가 배열의 2배
// ios_base::sync_with_stdio(false); cin.tie(NULL); -> 메모리 차이 없음

// 첫 번째 풀이 -> 시간초과
bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}
int main1() {
    int T, N, price;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        int answer = 0, prev = 0;
        vector<pair<int, int>> V;
        cin >> N;
        for(int j = 0; j < N; ++j) {
            cin >> price;
            V.push_back({price, j});
        }
        vector<pair<int, int>> v = {V.begin(), V.end()};
        sort(V.begin(), V.end(), cmp);

        for(int j = 0; j < N; ++j) {
            if(prev == V.size()) break;
            int max = V[j].first;
            int ix = V[j].second;
            for(int k = prev; k < ix; ++k) {
                int temp = (max - v[k].first);
                answer += temp;
            }
            prev = ix + 1;
        }
        cout << answer << endl;
    }
    return 0;
}

// 두 번째 풀이
int main() {
    int T, N, price;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        vector<int> V;
        long long answer = 0;
        cin >> N;
        for(int j = 0; j < N; ++j) {
            cin >> price;
            V.push_back(price);
        }
        int m = 0;
        for(int j = N - 1; j >= 0; --j) {
            if(m < V[j]) m = max(m, V[j]);
            else answer += (m - V[j]);
        }
        cout << answer << endl;
    }
    return 0;
}