// 5 와 3 보유
#include <iostream>
using namespace std;

// DP
int dp[5001];
int DP(int num) {
    if(dp[num]) return dp[num];
    if(dp[num - 3]) dp[num] = dp[num - 3] + 1; 
    if(dp[num - 5]) dp[num] = dp[num - 5] + 1;
    return dp[num];
}
int main() {
    int n;
    cin >> n;
    dp[3] = dp[5] = 1;
    for(int i = 6; i <= n; ++i) {
        DP(i);
    }
    cout << (dp[n] != 0 ? dp[n] : -1);
    return 0;
}

// Greedy
int main1() {
    int n, x = 0, y = 0;
    cin >> n;
    int c = 9999;
    // 3 이나 5 의 배수인가?
    // 아니면 5로 나누고 3으로 나누고
    while(true) {
        int a = n - (5 * x);
        if(a < 0) break;
        int b = a % 3;
        if(!b) {
            y = a / 3;
            if(x + y < c) c = x + y;
        }
        ++x;
    }
    if(c != 9999) cout << c;
    else cout << -1;
    return 0;
}