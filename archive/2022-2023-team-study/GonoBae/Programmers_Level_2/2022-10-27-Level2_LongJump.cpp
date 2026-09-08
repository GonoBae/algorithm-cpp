#include <string>
#include <vector>

using namespace std;

long long d[2001];

long long dp(int n) {
    if(d[n]) return d[n];
    if(n == 1) return 1;
    if(n == 2) return 2;
    return d[n] = (dp(n - 1) + dp(n - 2)) % 1234567;
}

long long solution(int n) {
    long long answer = 0;
    answer = dp(n);
    return answer;
}