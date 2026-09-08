#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

// k 진수로 바꿔보자.
void change(int n, int k, string& str) {
    if(n >= k) change(n / k, k, str);
    str += to_string(n % k);
}
// 소수인지 확인
bool isPrime(long n) {
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string str = "";
    change(n, k, str);
    
    // 0 을 기준으로 앞뒤 문자열 자르기
    istringstream ss(str);
    string buffer;

    // 문자열 체크하기
    while(getline(ss, buffer, '0')) {
        if(buffer == "" || buffer == "1") continue;
        if(isPrime(stol(buffer))) ++ answer;
    }

    return answer;
}

int main() {
    int n = 437674;
    int k = 3;
    int result = solution(n, k);
    cout << result;
    return 0;
}