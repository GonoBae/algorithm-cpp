#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// A : 1 -> AA : 2 -> AAA : 3 -> AAAA : 4 -> AAAAA : 5
//                               AAAE : 10
// I : 1563
// 각 단계 781        각 단계 31   각 단계 6    각 단계 1
// 다음 단계는 현재 단계 * 5 + 1
int solution(string word) {
    int answer = 0, cnt = 0;
    switch(word.size()) {
        case 1 : cnt = 781; break;
        case 2 : cnt = 156; break;
        case 3 : cnt = 31; break;
        case 4 : cnt = 6; break;
        case 5 : cnt = 1; break;
    }
    for(int i = word.size() - 1; i >= 0; --i) {
        switch(word[i]) {
            case 'A':
                answer += 1;
                break;
            case 'E':
                answer += cnt * 1 + 1;
                break;
            case 'I':
                answer += cnt * 2 + 1;
                break;
            case 'O':
                answer += cnt * 3 + 1;
                break;
            case 'U':
                answer += cnt * 4 + 1;
                break;
        }
        cnt = (cnt * 5) + 1;
    }
    return answer;
}

int main() {
    string word = "EIO";
    int result = solution(word);
    cout << result;
    return 0;
}