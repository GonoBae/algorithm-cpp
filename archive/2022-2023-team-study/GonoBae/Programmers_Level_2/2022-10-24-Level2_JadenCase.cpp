#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for(int i = 0; i < s.size(); ++i) {
        // 맨 앞글자는 항상 대문자
        if(i == 0) s[i] = toupper(s[i]);
        else {
            // 앞이 빈칸이면 대문자
            if(s[i - 1] == ' ') s[i] = toupper(s[i]);
            // 나머지는 소문자
            else s[i] = tolower(s[i]);
        }
        answer += s[i];
    }
    return answer;
}

int main() {
    string s = "3people unFollowed me";
    string result = solution(s);
    cout << result;
    return 0;
}