#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Q;
    // 작업에 소요되는 기간 queue에 담기
    for(int i = 0; i < progresses.size(); ++i) {
        int have = 100 - progresses[i];
        int speed = speeds[i];
        int day = (have) % speed != 0 ? 
            have / speed + 1 : have / speed;
        Q.push(day);
    }
    // 하나 빼놓기
    int d = Q.front();
    int cnt = 1;
    Q.pop();
    // 더 많은 기간이 남은 작업이 나올때까지 pop 과 카운트
    while(!Q.empty()) {
        if(Q.front() > d) {
            d = Q.front();
            Q.pop();
            answer.push_back(cnt);
            cnt = 1;
            continue;
        }
        Q.pop();
        ++cnt;
    }
    answer.push_back(cnt);
    return answer;
}

int main() {
    vector<int> progresses = {95, 90, 99, 99, 80, 99};
    vector<int> speeds = {1, 1, 1, 1, 1, 1};
    vector<int> result = solution(progresses, speeds);
    for(auto r : result) {
        cout << r;
    }
    return 0;
}