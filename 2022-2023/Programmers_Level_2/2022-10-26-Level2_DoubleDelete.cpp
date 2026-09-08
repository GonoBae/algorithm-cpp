#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> S;
    for(const auto c : s) {
        if(!S.empty()) {
            S.top() == c ? S.pop() : S.push(c);
        }
        else S.push(c);
    }
    S.empty() ? answer = 1 : answer = 0;
    return answer;
}

// 효율성만 실패한 경우 => erase 로 지우는 과정이 비용이 큼
int solutionA(string s)
{
    int answer = -1;
    int idx = 0;
    while(1) {
        if(idx >= s.size()) break;
        if(s[idx] == s[idx + 1]) {
            s.erase(idx, 2);
            if(idx > 0) --idx;
            continue;
        }
        ++idx;
    }
    idx == 0 ? answer = 1 : answer = 0;
    return answer;
}

int main() {
    string s = "cdcd";
    int result = solution(s);
    cout << result;
    return 0;
}