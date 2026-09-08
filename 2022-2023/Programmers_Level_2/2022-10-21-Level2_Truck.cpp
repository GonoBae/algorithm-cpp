#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 첫 번째 풀이
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int curTotalWeight = 0;
    // 트럭 무게, 트럭이 다리에 진입하는 시간
    queue<pair<int, int>> Q;
    for(int i = 0; i < truck_weights.size(); ++i) {
        // 시간
        ++answer;
        
        if(answer == Q.front().second + bridge_length) {
            curTotalWeight -= Q.front().first;
            Q.pop();
        }
        // 다리가 견디는 무게가 10 일 때 트럭들의 무게가 3 3 3 7 이면 계속 반복해주어야 함
        while(truck_weights[i] + curTotalWeight > weight) {
            answer = Q.front().second + bridge_length;
            curTotalWeight -= Q.front().first;
            Q.pop();
        }
        Q.emplace(truck_weights[i], answer);
        curTotalWeight += truck_weights[i];
    }
    answer = Q.back().second + bridge_length;
    return answer;
}

// 두 번째 풀이 (블로그)
int solution2(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> truck;
    int sum = 0;
    int idx = 0;
    while(true) {
        if(idx == truck_weights.size()) {
            answer += bridge_length;
            break;
        }
        ++answer;
        if(truck.size() == bridge_length) {
            sum -= truck.front();
            truck.pop();
        }
        if(sum + truck_weights[idx] <= weight) {
            sum += truck_weights[idx];
            truck.push(truck_weights[idx]);
            ++idx;
        }
        else {
            truck.push(0);
        }
    }
    return answer;
}

int main() {
    // case 1
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = {7, 4, 5, 6};

    // case 2
    // int bridge_length = 100;
    // int weight = 100;
    // vector<int> truck_weights = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    int result = solution(bridge_length, weight, truck_weights);
    cout << result;
    return 0;
}