#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string str;
    vector<int> VI;
    // 빈칸을 기준으로 자르기 때문에 끝에 빈칸추가
    s += ' ';
    int prev = 0;
    int curr = s.find(' ');
    // 빈칸 기준으로 자르기
    while(curr != string::npos) {
        string sub = s.substr(prev, curr - prev);
        VI.push_back(stoi(sub));
        prev = curr + 1;
        curr = s.find(' ', prev);
    }
    sort(VI.begin(), VI.end());
    answer += to_string(VI[0]);
    answer += ' ';
    answer += to_string(VI[VI.size() - 1]);
    return answer;
}

int main() {
    string s = "-1 -2 -3 -4";
    string result = solution(s);
    cout << result;
    return 0;
}