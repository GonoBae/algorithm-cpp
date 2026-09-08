#include <iostream>
#include <string>
#include <vector>

using namespace std;

void changeN(int n, int k, string& str) {
    if(n >= k) changeN(n / k, k, str);
    if(n % k < 10) str += to_string(n % k);
    else str += ('A' + (n % k - 10));
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string str = "";
    // 인원 카운트, 숫자 카운트
    int cnt = 0, num = 0;
    // 나의 순번 , 총 몇명
    while(1) {
        // n 진수로 변환
        changeN(num, n, str);
        // 나의 순번마다 뽑을 숫자의 갯수 => string.size()
        for(int i = 0; i < str.size(); ++i) {
            ++cnt;
            if(cnt == p) answer += str[i];
            if(cnt == m) cnt = 0;
            if(answer.size() == t) return answer;
        }
        ++num;
        str = "";
    }
    return answer;
}

int main() {
    int n = 16, t = 16, m = 2, p = 1;
    string result = solution(n, t, m, p);
    cout << result;
    return 0;
}