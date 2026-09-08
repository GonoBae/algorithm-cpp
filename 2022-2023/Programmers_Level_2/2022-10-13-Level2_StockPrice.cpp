#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    for(int i = 0; i < prices.size() - 1; ++i) {
        for(int j = i + 1; j < prices.size(); ++j) {
            if(prices[i] > prices[j]) {
                ++answer[i];
                break;
            }
            ++answer[i];
        }
    }
    return answer;
}

int main() {
    vector<int> prices = {2, 2, 1, 1, 1};
    vector<int> result = solution(prices);
    for(auto r : result) {
        cout << r << ' ';
    }
}