#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> UM;
    int ix = 0;
    for(char c = 'A'; c <= 'Z'; ++c) {
        string s = ""; s += c;
        UM[s] = ++ix;
    }
    for(int i = 0; i < msg.size(); ++i) {
        for(int j = 1; j <= msg.size() - i; ++j) {
            string str = msg.substr(i, j);
            auto iter = UM.find(str);
            // 사전에 있으면
            if(iter != UM.end()) {
                if(i + j == msg.size()) {
                    answer.emplace_back(UM[str]);
                    i = msg.size();
                    break;
                }
                continue;
            }
            // 없으면
            else {
                UM[str] = ++ix;
                // 이전 문자열을 answer 에 담아야 함.
                answer.emplace_back(UM[str.substr(0, str.size() - 1)]);
                i += (j - 2);
                break;
            }
        }
    }
    return answer;
}

int main() {
    string msg = "TOBEORNOTTOBEORTOBEORNOT";
    vector<int> result = solution(msg);
    for(auto r : result) {
        cout << r << ' ';
    }
    return 0;
}