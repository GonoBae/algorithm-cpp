#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int T, N;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        cin >> N;
        vector< pair<int, int> > V;
        int answer = 0;
        for(int j = 0; j < N; ++j) {
            int a, b;
            cin >> a >> b;
            V.push_back(make_pair(a, b));
        }
        sort(V.begin(), V.end());
        // 저장용
        pair<int, int> P;
        for(int j = 0; j < V.size(); ++j) {
            if(j == 0) {
                P = V[j];
                ++answer;
                continue;
            }
            else {
                // 정렬순대로 second 확인함 -> 위보다 작으면 괜찮음 + 갱신
                if(V[j].second < P.second) {
                    ++answer;
                    P = V[j];
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}