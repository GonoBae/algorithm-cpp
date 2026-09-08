#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> m1;
    map<string, int> m2;
    // 소문자로 다 바꿔주기
    for(int i = 0; i < str1.size(); ++i) {
        str1[i] = tolower(str1[i]);
    }
    for(int i = 0; i < str2.size(); ++i) {
        str2[i] = tolower(str2[i]);
    }
    // 알파벳만 담아주기
    for(int i = 0; i < str1.size() - 1; ++i) {
        if(!isalpha(str1[i])) continue;
        if(!isalpha(str1[i + 1])) continue;
        string str = "";
        str += str1[i]; str += str1[i + 1];
        ++m1[str];
    }
    for(int i = 0; i < str2.size() - 1; ++i) {
        if(!isalpha(str2[i])) continue;
        if(!isalpha(str2[i + 1])) continue;
        string str = "";
        str += str2[i]; str += str2[i + 1];
        ++m2[str];
    }
    
    int intersection = 0, sum = 0;
    // str1 의 요소를 반복하며 확인
    for(auto iter = m1.begin(); iter != m1.end(); ++iter) {
        auto find_iter = m2.find(iter->first);
        if(find_iter != m2.end()) {
            auto count_m1 = iter->second;
            auto count_m2 = find_iter->second;
            intersection += min(count_m1, count_m2);
            sum += max(count_m1, count_m2);
        }
        else {
            sum += iter->second;
        }
    }
    // str2 의 요소를 반복하며 확인
    // 같은 요소는 이미 확인하였으니 다른 것만 확인하면 됨
    for(auto iter = m2.begin(); iter != m2.end(); ++iter) {
        auto find_iter = m1.find(iter->first);
        if(find_iter == m1.end()) sum += iter->second;
    }
    if(sum == 0) answer = 65536;
    else {
        float f = (float)intersection / sum;
        answer = f * 65536;
    }
    return answer;
}

int main() {
    string str1 = "E=M*C^2";
    string str2 = "e=m*c^2";
    int result = solution(str1, str2);
    cout << result;
    return 0;
}