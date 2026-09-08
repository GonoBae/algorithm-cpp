#include <iostream>
#include <string>
#include <vector>

using namespace std;

int f[100001];

int fibo(int n) {
    if(f[n]) return f[n];
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    return f[n] = (fibo(n - 1) + fibo(n - 2)) % 1234567;
}

int solution(int n) {
    int answer = fibo(n);
    return answer;
}

int main() {
    int n = 50;
    int result = solution(n);
    cout << result;
    return 0;
}