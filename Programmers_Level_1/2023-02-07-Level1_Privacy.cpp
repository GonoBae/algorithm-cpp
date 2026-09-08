#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

// ## 사용하지 않은 것!
// map 사용
// stringstream 은 자료형을 골라서 담아준다.
// vector.back() 을 사용해서 끝 자리를 담아줄 수 있다.

// ================== 풀이 ================ //
// 문자 분리하고 일 수 계산하기
int calc(string day) {
    int y = 0, m = 0, d = 0, cnt = 1;
    stringstream ss(day);
    string buffer;
    while(getline(ss, buffer, '.')) {
        if(cnt == 1) y = stoi(buffer);
        else if(cnt == 2) m = stoi(buffer);
        else if(cnt == 3) d = stoi(buffer);
        ++cnt;
    }
    
    return (((y - 1) * 336) + ((m - 1) * 28) + d);
}

// 약관 종류 검색해서 일 수 더해주기 (map 을 사용해서 담아줘도 됨)
int findNum(string day, vector<string> terms) {
    char c = day[day.size() - 1];
    for(int i = 0; i < terms.size(); ++i) {
        if(c == terms[i][0]) {
            string s = terms[i].substr(2);
            return stoi(s) * 28 - 1;
        }
    }
    // 예외처리 필요없어서 생략
    return -1;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int todayCnt = calc(today);
    for(int i = 0; i < privacies.size(); ++i) {
        int Cnt = calc(privacies[i]);
        int plus = findNum(privacies[i], terms);
        // 현재 날짜를 넘긴 번호 벡터에 담아주기
        if(todayCnt > Cnt + plus) answer.push_back(i + 1);
    }
    return answer;
}