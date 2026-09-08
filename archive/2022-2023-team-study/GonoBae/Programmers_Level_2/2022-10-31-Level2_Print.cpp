#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, m = 0;
    queue<int> Q;
    // 인덱스 queue에 담기
    for(int i = 0; i < priorities.size(); ++i) {
        Q.push(i);
    }
    while(!Q.empty()) {
        int idx = Q.front();
        Q.pop();
        // 가장 높은 우선순위 찾기
        int max = *max_element(priorities.begin(), priorities.end());
        // queue 에서 하나씩 max 값과 비교
        if(priorities[idx] == max) {
            // 찾으면 return
            if(idx == location) return ++answer;
            // 우선순위는 max 인데 찾는 작업물이 아니면
            else {
                ++answer;
                // 우선순위 초기화
                priorities[idx] = -1;
                continue;
            }
        }
        // 우선순위 낮은 작업물 뒤로 빼놓기
        Q.push(idx);
    }
    return answer;
}

int main() {
    vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;
    int result = solution(priorities, location);
    cout << result;
    return 0;
}