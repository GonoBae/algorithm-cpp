#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
1 2 3 4
2 2 3 4
3 3 3 4
4 4 4 4
*/

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    // 전체를 구하려고 하면 시간초과 뜸
    for(long long i = left; i <= right; ++i) {
        int x = i / n;
        int y = i % n;
        x = x >= y ? x + 1 : y + 1;
        answer.push_back(x);
    }
    return answer;
}

int main() {
    int n = 3;
    long long left = 2, right = 5;
    vector<int> result = solution(n, left, right);
    for(auto r : result) {
        cout << r;
    }
    return 0;
}