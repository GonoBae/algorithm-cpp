#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1;
    char temp = s[0];
    int cnt = 1;
    for(int i = 1; i < s.size(); ++i) {
        if(cnt == 0) {
            temp = s[i];
            ++answer;
        }
        if(temp == s[i]) ++cnt;
        else --cnt;
    }
    return answer;
}