#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// 내 풀이
vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> user;
    vector<vector<string>> act(record.size());
    // 공백 기준 잘라서 나눠담기 (0 : cmd , 1 : id , 2 : nick)
    for(int i = 0; i < record.size(); ++i) {
        string str = record[i];
        int start = 0;
        int d = str.find(' ');
        while(d != -1) {
            act[i].push_back(str.substr(start, d - start));
            start = d + 1;
            d = str.find(' ', start);
        }
        act[i].push_back(str.substr(start, d - start));
    }
    for(int i = 0; i < act.size(); ++i) {
        if(act[i][0] == "Leave") continue;
        user[act[i][1]] = act[i][2];
    }
    

    // Enter , Leave , Change 구분해서 기능구현
    for(int i = 0; i < act.size(); ++i) {
        string cmd = act[i][0];
        if(cmd == "Enter") {
            answer.push_back(user[act[i][1]] + " is entered.");
        }
        else if(cmd == "Leave") {
            answer.push_back(user[act[i][1]] + " is left.");
        }
    }

    return answer;
}

// 참고
vector<string> solutionB(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> user;
    string cmd , id , nick;
    for(auto r : record) {
        stringstream ss(r);
        ss >> cmd;
        ss >> id;
        if(cmd == "Leave") continue;
        ss >> nick;
        user[id] = nick;
    }

    for(auto r : record) {
        stringstream ss(r);
        ss >> cmd;
        ss >> id;
        if(cmd == "Enter") {
            string str = user[id] + "님이 들어왔습니다.";
            answer.push_back(str);
        }
        else if(cmd == "Leave") {
            string str = user[id] + "님이 나갔습니다.";
            answer.push_back(str);
        }
    }
    return answer;
}

int main() {
    vector<string> record = {
        "Enter uid1234 Muzi",
        "Enter uid4567 Prodo",
        "Leave uid1234",
        "Enter uid1234 Prodo",
        "Change uid4567 Ryan"
        };
    vector<string> result = solution(record);
    for(auto r : result) {
        cout << r << endl;
    }
    return 0;
}