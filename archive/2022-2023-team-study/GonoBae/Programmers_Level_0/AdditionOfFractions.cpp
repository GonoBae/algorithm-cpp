#include <string>
#include <vector>

using namespace std;

// 최대공약수
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

// 최소공배수
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    int a , b, c;
    // 분모, 분자, 약분을 위한 수
    b = lcm(denom1, denom2);
    a = numer1 * (b / denom1) + numer2 * (b / denom2);
    c = gcd(a, b);
    // 약분
    a /= c;
    b /= c;
    vector<int> answer;
    answer.push_back(a); answer.push_back(b);
    return answer;
}