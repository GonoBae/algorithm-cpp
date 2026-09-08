#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 내 풀이
string a, b;
int cntA, cntB;
void makebinary(int n, string& str, int& cnt) {
    if(n > 1) makebinary(n / 2, str, cnt);
    str += to_string(n % 2);
    if(n % 2 == 1) ++cnt;
}

int solution(int n) {
    int answer = n;
    makebinary(n, a, cntA);
    while(cntA != cntB) {
        ++answer;
        b = ""; cntB = 0;
        makebinary(answer, b, cntB);
    }
    return answer;
}

// 다른 사람 풀이
#include <bitset>

int solutionA(int n) {
    int num = bitset<20>(n).count();
    while(bitset<20>(++n).count() != num);
    return n;
}

int main() {
    int n = 1000000;
    int result = solutionA(n);
    cout << result;
    return 0;
}