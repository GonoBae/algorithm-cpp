#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    // 몫과 나머지
    int q = -1, r = 0;
    while(q != 0) {
        // 남는 병의 수
        if((n % a) != 0) {
            r = (n % a);
        }
        // 바꾼 병의 수를 구하고 더해줌
        q = (n / a) * b;
        answer += q;

        // 다시 바꿀 수 있는 병의 수 & 나머지 초기화
        n = (r + q);
        r = 0;
    }
    return answer;
}

int main() {
    int a = 2, b = 1, n = 20;
    int result = solution(a, b, n);
    cout << result;
    return 0;
}