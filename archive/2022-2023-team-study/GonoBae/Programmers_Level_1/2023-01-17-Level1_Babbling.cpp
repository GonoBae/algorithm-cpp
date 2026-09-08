#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 연속 발음 X
int solutionA(vector<string> babbling) {
    int answer = 0;
    string prev = "";
    // ye(2), ma(2)
    // aya(3), woo(3)
    for(auto b : babbling) {
        string temp = "";
        bool check;
        for(int i = 0; i < b.size(); ++i) {
            check = false;
            temp += b[i];
            if(temp.size() < 2) continue;
            if((temp == "ye" || temp == "ma" || temp == "aya" || temp == "woo") && temp != prev) {
                prev = temp;
                temp = "";
                check = true;
                continue;
            }
        }
        if(check) ++answer;
        prev = "";
    }
    return answer;
}

int solution(vector<string> babbling) {
    int answer = 0;
    // ye(2), ma(2)
    // aya(3), woo(3)
    for(auto b : babbling) {
        string temp = "", prev = "";
        for(int i = 0; i < b.size(); ++i) {
            temp += b[i];
            if(temp.size() < 2) continue;
            if((temp == "ye" || temp == "ma" || temp == "aya" || temp == "woo") && temp != prev) {
                prev = temp;
                temp = "";
                continue;
            }
        }
        if(temp.size() == 0) ++answer;
    }
    return answer;
}

int main() {
    vector<string> babbling1 = {"aya", "yee", "u", "maa"};
    vector<string> babbling2 = {"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"};
    vector<string> babbling3 = {"ayaaaya"};
    int result = solution(babbling3);
    cout << result;
    return 0;
}