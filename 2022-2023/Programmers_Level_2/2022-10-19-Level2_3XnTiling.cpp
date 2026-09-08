// 6 -> 41
// 8 -> 153
// 10 -> 571

// f(n) = 4 * f(n - 2) - f(n - 4) 점화식도 있었음

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define D 1000000007;
long long d[5001];

long long solution(int num) {
    // 0 은 연산을 위해 1
    if (num == 0) return 1;
    // 홀수 0
    if (num % 2 != 0) return 0;
    // 점화식 예외값
    if (num == 2) return 3;
    // 메모이제이션
    if (d[num] != 0) return d[num];

    // 고정된 증가
    d[num] += (3 * solution(num - 2));
    // num = 4 부터 모든 문양은 새로운 문양을 2개씩 가지게 된다.
    // 그래서 점화식은 2 (f(n - 4) + f(n - 6)----)
    // 마지막 + f(0) [2] 도 그렇게 나온 것
    for (int i = 4; i <= num; i += 2) {
        d[num] += 2 * solution(num - i);
    }

    return d[num] %= D;
}

int main() {
    int n = 6;
    int result = solution(n);
    cout << result;
    return 0;
}