// 1. 대문자는 소문자로 치환
// 2. 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.) 를 제외한 모든 문자 제거
// 3. 마침표가 2번 이상 연속된 부분 마침표 하나로 치환
// 4. 마침표가 처음과 끝에 위치한다면 제거
// 5. 빈 문자열이라면 "a" 를 대입
// 6. 16자 이상이라면 첫 15개의 문자를 제외한 나머지 모두 제거
//    만약 제거 후 마침표가 끝에 위치한다면 끝에 위치한 마침표 제거
// 7. 2자 이하라면 마지막 문자를 문자의 길이가 3이 될 때 까지 붙임
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    // 1 단계
    for(int i = 0; i < new_id.length(); ++i) {
        new_id[i] = tolower(new_id[i]);
    }
    // 2 단계
    for(int i = 0; i < new_id.length(); ++i) {
        if((new_id[i] >= 48 && new_id[i] <= 57) 
        || (new_id[i] >= 97 && new_id[i] <= 122) 
        || new_id[i] == 45 || new_id[i] == 46 || new_id[i] == 95) {
            answer += new_id[i];
        }
    }
    // 3 단계 
    char check = '.';
    int ix = 0;
    for(int i = 0; i < answer.length(); ++i) {
        if(check != answer[i]) {
            answer[ix++] = answer[i];
        } else {
            if(answer[ix - 1] != check) {
                answer[ix++] = answer[i];
            } else {
                if(i == answer.length() - 1) answer.erase(answer.end() - 1);
                else {
                    answer.erase(i, 1);
                    i--;
                }
            }
        }
    }
    // 4 단계
    if(answer.front() == '.') answer.erase(answer.begin());
    // 5 단계
    if(answer.empty()) answer += 'a';
    // 6 단계
    if(answer.length() >= 16) answer = answer.substr(0, 15);
    if(answer.back() == '.') answer.erase(answer.end() - 1);
    // 7 단계
    if(answer.length() <= 2) {
        char c = answer.back();
        for(int i = answer.length() + 1; i <= 3; ++i) {
            answer += c;
        }
    }
    return answer;
}

int main() {
    string new_id = "...!@BaT#*..y.abcdefghijklm";
    string result = solution(new_id);
    cout << result;
    return 0;
}