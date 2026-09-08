#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 2개 시간초과
int solutionA(vector<int> ingredient) {
    int answer = 0;
    string berg = "1231";
    string str;
    for(int i : ingredient) {
        str += to_string(i);
    }
    while(true) {
        int index = str.find(berg);
        if(index != string::npos) {
            // 존재
            ++answer;
            str.erase(str.begin() + index, str.begin() + index + 4);
        }
        else break;
    }
    return answer;
}

// find 의 시간이 오래걸림
int solution(vector<int> ingredient) {
    int answer = 0;
    string berg = "1231";
    string str;
    for(int i : ingredient) {
        str += to_string(i);
        int len = str.length();
        if(len >= 4) {
            string tmp = str.substr(len - 4);
            if(tmp == berg) {
                ++answer;
                str = str.substr(0, len - 4);
            }
        }
    }
    return answer;
}

int main() {
    vector<int> example1 {2, 1, 1, 2, 3, 1, 2, 3, 1};
    vector<int> example2 {1, 3, 2, 1, 2, 1, 3, 1, 2};
    int result = solution(example1);
    cout << result;
    return 0;
}