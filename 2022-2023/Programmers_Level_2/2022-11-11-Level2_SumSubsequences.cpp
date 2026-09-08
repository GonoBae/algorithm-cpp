#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    unordered_set<int> US;
    // 카운트 세기
    for(int cnt = 1; cnt <= elements.size(); ++cnt) {
        // 시작 인덱스
        for(int i = 0; i < elements.size(); ++i) {
            int sum = 0;
            // 카운트를 포함하는 끝 인덱스
            for(int j = i; j < i + cnt; ++j) {
                if(j >= elements.size()) sum += elements[j - elements.size()];
                else sum += elements[j];
            }
            US.insert(sum);
        }
    }
    
    answer = US.size();
    return answer;
}

int main() {
    vector<int> elements = {7, 9, 1, 1, 4};
    int result = solution(elements);
    cout << result;
    return 0;
}