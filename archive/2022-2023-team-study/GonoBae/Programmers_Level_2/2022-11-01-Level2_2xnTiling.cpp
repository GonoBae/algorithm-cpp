#include <iostream>
#include <string>
#include <vector>

using namespace std;

int d[60001];

int solution(int n) {
    if(d[n] != 0) return d[n];
    return d[n] = (solution(n - 1) + solution(n - 2)) % 1000000007;
}

int main() {
    int n = 4;
    d[1] = 1, d[2] = 2;
    int result = solution(4);
    cout << result;
    return 0;
}