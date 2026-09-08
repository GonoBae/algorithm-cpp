#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    // 역순 정렬
    sort(citations.begin(), citations.end(), greater<int>());
    // 가장 큰 값부터 검사
    int hIdx = citations[0];
    for(int i = 0; i < citations[0]; ++i) {
        int cnt = 0;
        for(int j = 0; j < citations.size(); ++j) {
            // 인용수가 hIdx 이상인 값 ++
            if(hIdx <= citations[j]) {
                ++cnt;
            }
            // 더 작은 값은 계산할 필요가 없음
            else break;
        }
        // 인용 논문수가 hIdx 이상이면 끝
        if(cnt >= hIdx) break;
        --hIdx;
    }
    answer = hIdx;
    return answer;
}

int main() {
    vector<int> citations = {9, 7, 6, 2, 1};
    int result = solution(citations);
    cout << result;
    return 0;
}