#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str = "";

void binary(int n) {
    if (n > 1)
        binary(n / 2);
    str += to_string(n % 2);
}

vector<int> solution(string s) {
    vector<int> answer;
    int del = 0, remain = 0, cnt = 0;
    while (true) {
        for (auto c : s)
        {
            if (c == '0')
            {
                ++del;
                continue;
            }
            ++remain;
        }
        binary(remain);
        if(str != "") {
            s = str;
            str = "";
        }
        remain = 0;
        ++cnt;
        if(stoi(s) == 1 && s.size() == 1) break;
    }
    answer.push_back(cnt);
    answer.push_back(del);
    return answer;
}

int main() {
    string x = "110010101001";
    vector<int> result = solution(x);
    for(auto r : result) {
        cout << r;
    }
    return 0;
}