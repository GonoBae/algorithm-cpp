#include<string>
#include <iostream>
#include <stack>

using namespace std;

// 1번 풀이
// 짝이 맞아야 하기 때문에 더하고 빼면 0 이 되어야 함
// ) 기호가 늦게 나와야 하는데 먼저 나오게 되면 - 값이 나옴 => false
bool solution(string s)
{
    bool answer = true;
    int num = 0;
    for(auto c : s) {
        if(c == '(') ++num;
        else --num;
        if(num < 0) break;
    }
    if(num != 0) answer = false;
    return answer;
}

// 2번 풀이
// ( 이면 push , ) 이면 pop 을 하면 됨 => 짝지어지면 stack 에 아무것도 남지 않음
bool solution2(string s)
{
    bool answer = true;
    stack<char> S;
    for(auto c : s) {
        if(c == '(') S.push(c);
        else {
            if(S.empty() || S.top() != '(') {
                answer = false;
                break;
            }
            S.pop();
        }
    }
    if(!S.empty()) answer = false;
    return answer;
}

int main() {
    string s = "(())()((()))";
    bool result = solution2(s);
    cout << result;
    return 0;
}