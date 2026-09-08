#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> number;

int dfs(int target, int idx, int num) {
    if(idx == number.size()) {
        if(num == target) return 1;
        else return 0;
    }
    else {
        return dfs(target, idx + 1, num + number[idx])
            + dfs(target, idx + 1, num - number[idx]);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    number = numbers;
    answer = dfs(target, 0, 0);
    return answer;
}

int main() {
    vector<int> numbers = {1, 1, 1};
    int target = 1;
    int result = solution(numbers, target);
    cout << result;
    return 0;
}