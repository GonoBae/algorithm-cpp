#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> PQ;
    for(int i = 0; i < scoville.size(); ++i) PQ.push(scoville[i]);
    while(PQ.top() < K)
    {
        if(PQ.size() < 2) {
            if(PQ.top() < K) return -1;
            else return answer;
        }
        int a = PQ.top(); PQ.pop();
        int b = PQ.top(); PQ.pop();
        PQ.push(a + b * 2);
        ++answer;
    }
    return answer;
}

// vector 를 그대로 사용하니 효율성 X
int solutionB(vector<int> scoville, int K) {
    int answer = 0;
    sort(scoville.begin(), scoville.end(), greater<int>());
    while(scoville.back() < K)
    {
        if(scoville.size() < 2) {
            if(scoville[0] < K) return -1;
            else return answer;
        }
        int a = scoville.back(); scoville.pop_back();
        int b = scoville.back(); scoville.pop_back();
        scoville.push_back(a + b * 2);
        sort(scoville.begin(), scoville.end(), greater<int>());
        ++answer;
    }
    return answer;
}

int main() {
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int k = 7;
    int result = solution(scoville, k);
    cout << result;
    return 0;
}