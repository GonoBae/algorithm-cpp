// 문제가 이상함
// idx 이동해서 하는 경우 VSCode 에서는 문제없고 VS 에서는 에러남

// 꼭 해봐야 하는 케이스
// {40, 40, 40, 40, 40} , 100 => 3
// {70, 70, 60, 40, 40} , 110 => 3

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 모두 되는 풀이
int solution(vector<int> people, int limit) {
    int answer = 0, N = people.size();
    sort(people.begin(), people.end(), greater<int>());
    for(int i = 0, j = N - 1; i <= j; ++i) {
        if(people[i] + people[j] <= limit) {
            --j;
        }
        ++answer;
    }
    return answer;
}

// 프로그래머스 에서는 맞지만 VS 에서 idx 에러나는 경우 (블로그)
int solutionA(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int idx = 0;
    // **두명씩 타는 케이스 홀수개 있으면 안됨**
    while(people.size() > idx) {
        // int curr = people[idx];
        int back = people.back(); people.pop_back();
        if(people[idx] + back <= limit) { ++answer; ++idx; }
        else ++answer;
    }
    return answer;
}

// 프로그래머스 에서는 맞지만 VS 에서 idx 에러나는 경우 2 (내가 푼거)
int solutionB(vector<int> people, int limit) {
    int answer = 0, idx = 1;
    vector<int> boat;
    // 역순 정렬
    sort(people.begin(), people.end(), greater<int>());
    for(const auto p : people) {
        // 절반 넘어가는 수치는 모두 vector 에 넣어줌.
        if(p > limit / 2) boat.push_back(p);
        else {
            // 비어 있으면 넣기
            if(boat.empty()) boat.push_back(p);
            else {
                // limit 값 넘으면 칸 하나 추가
                // **boat.size() - idx 가 음수가 되어서 안됨
                if(boat[boat.size() - idx] + p > limit) {
                    boat.push_back(p);
                }
                // 안 넘으면 보트 탄거니 idx 증가
                else ++idx;
            }
        }
    }
    answer = boat.size();
    return answer;
}

int main() {
    //vector<int> people = {60, 60, 50, 50, 40, 40, 40, 40, 40};
    vector<int> people = {40, 40, 40, 40, 40};
    int limit = 100;
    int result = solution(people, limit);
    cout << result;
    return 0;
}