// DP : 하나의 문제를 단 한번만 풀도록 하는 알고리즘
// 메모이제이션 : 계산한 결과는 배열에 저장

// N Kg 배달 (3kg 과 5kg 봉지가 있다.) -> 봉지의 최소 개수
#include <iostream>

using namespace std;
int dp[5001];
int DP(int num) {
    if(dp[num] != 0) return dp[num];
    if(dp[num - 3]) dp[num] = dp[num - 3] + 1;
    if(dp[num - 5]) dp[num] = dp[num] ? min(dp[num], dp[num - 5] + 1) : dp[num - 5] + 1;
    return dp[num];
}

int main() {
    int N;
    cin >> N;
    dp[3] = dp[5] = 1;
    for(int i = 6; i <= N; ++i) {
        DP(N);
    }
    cout << (dp[N] == 0 ? dp[N] : -1);
    return 0;
}