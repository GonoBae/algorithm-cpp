// 위장

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    // 옷 종류 + 개수
    unordered_map<string, int> tmp;
    int answer = 1;
    for (auto c : clothes)
    {
        ++tmp[c[1]];
    }
    // 3차 방정식 식이다.
    // (x + a)(x + b)(x + c) => 1 + a + b + c + ab + bc + ca + abc (x 가 1 임)
    for (auto x : tmp) {
        answer *= (x.second + 1);
    }
    --answer;
    return answer;
}

int main()
{
    vector<vector<string>> clothes = {
        {"yellow_hat", "headgear"},
        {"blue_sunglasses", "eyewear"},
        {"green_turban", "headgear"}};
    int result = solution(clothes);
    cout << result;
    return 0;
}