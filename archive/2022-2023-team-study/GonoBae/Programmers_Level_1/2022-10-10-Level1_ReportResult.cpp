// 동일한 유저에 대한 신고 횟수는 1회로 처리
// K번 이상 신고된 유저는 정지 => 신고한 모든 유저에게 메일 발송

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    // 각 유저가 신고한 유저를 체크해보자.
    unordered_map<string, unordered_set<string>> reportingUser;
    // 각 유저를 신고한 유저를 체크해보자.
    unordered_map<string, unordered_set<string>> reportedUser;

    // report 의 내용을 담기
    for(auto r : report) {
        int index = r.find(" ");
        string reporter = r.substr(0, index);
        string reported = r.substr(index + 1);

        reportingUser[reporter].insert(reported);
        reportedUser[reported].insert(reporter);
    }

    for(int i = 0; i < id_list.size(); ++i) {
        string user = id_list[i];
        unordered_map<string, unordered_set<string>>::iterator it = reportingUser.find(user);
        if(it == reportingUser.end()) continue;
        for(string bad : it->second) {
            if(reportedUser[bad].size() >= k) {
                ++answer[i];
            }
        }
    }
    
    return answer;
}

int main() {
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
    int k = 2;
    vector<int> result = solution(id_list, report, k);
    for(auto r : result) {
        cout << r << endl;
    }
    return 0;
}