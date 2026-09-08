#include<iostream>
#include<algorithm>

using namespace std;
int C[26];
int main() {
    string str, answer = "";
    char center = 'a';
    int numCenter = 0;
    cin >> str;
    // 알파벳 별 개수 체크
    for(int i = 0; i < str.size(); ++i) {
        C[str[i] - 'A']++;
    }
    for(int i = 0; i < 26; ++i) {
        // 절반만큼 문자열에 채워주기
        for(int j = 0; j < C[i] / 2; ++j) {
            answer += i + 'A';
        }
        // 알파벳이 홀수 번 나온 경우
        if(C[i] % 2) {
            ++numCenter;
            // 두 번 이상 나온 경우 불가
            if(numCenter > 1) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            // 하나는 중간
            center = i + 'A';
        }
    }
    string copy(answer);
    if(center != 'a') answer += center;
    reverse(copy.begin(), copy.end());
    cout << answer + copy;
    return 0;
}