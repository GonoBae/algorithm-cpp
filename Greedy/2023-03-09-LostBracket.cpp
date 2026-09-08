#include <iostream>
#include <string>

using namespace std;

int main() {
    int answer = 0, prev = 0, helper = 0;
    bool flag = false;
    string str;
    cin >> str;
    for(int i = 0; i <= str.size(); ++i) {
        // 숫자가 아님
        if(isdigit(str[i]) == 0 || str[i] == string::npos) {
            string temp = "";
            if(str[i] == string::npos) temp = str.substr(prev, i - prev + 1);
            else temp = str.substr(prev, i - prev);
            int num = stoi(temp);
            if(prev == 0) answer += num;
            else {
                if(num < 0) {
                    answer += num;
                    flag = true;
                }
                else {
                    if(flag) answer -= num;
                    else answer += num;
                }
            }
            prev = i;
        }
    }
    if(helper) answer += helper;
    cout << answer;
    return 0;
}