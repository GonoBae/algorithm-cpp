#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.size(); ++i) {
        stack<char> S;
        for(int j = 0; j < s.size(); ++j) {
            if(S.empty()) S.push(s[j]);
            else {
                // 괄호 짝 검사
                if(S.top() == '[' && s[j] == ']') S.pop();
                else if(S.top() == '{' && s[j] == '}') S.pop();
                else if(S.top() == '(' && s[j] == ')') S.pop();
                else if(S.top() == ')' || S.top() == '}' || S.top() == ']') break;
                // 모두 아니면 push
                else S.push(s[j]);
            }
        }
        // stack 이 비어있으면 짝이 모두 맞음
        if(S.empty()) ++answer;
        // 회전
        char c = s[0];
        s.erase(s.begin());
        s += c;
        // stack 이 차있으면 비워주기
        while(!S.empty()) S.pop();
    }
    return answer;
}

int main() {
    string s = "[)(]";
    int result = solution(s);
    cout << result;
    return 0;
}