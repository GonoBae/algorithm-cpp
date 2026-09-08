#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> tmp;
    int total = brown + yellow;
    // 약수 찾기
    for(int i = 1; i <= total; ++i) {
        if(total % i == 0) {
            tmp.push_back(i);
        }
    }
    // 약수로 얻은 값을 토대로 파라미터와 비교
    int tmpSize = tmp.size();
    if(tmpSize % 2 == 0) {
        for(int i = 0; i < tmp.size() / 2; ++i) {
            int b = tmp[tmpSize / 2 + i];
            int y = tmp[tmpSize / 2 - i - 1];
            if((b * 2) + ((y - 2) * 2) == brown) {
                answer.push_back(b);
                answer.push_back(y);
            }
        }
    } else {
        answer.push_back(tmp[tmpSize / 2]);
        answer.push_back(tmp[tmpSize / 2]);
    }

    return answer;
}

int main() {
    int brown = 18; int yellow = 6;
    vector<int> result = solution(brown, yellow);
    for(auto r : result) {
        cout << r << endl;
    }
    return 0;
}