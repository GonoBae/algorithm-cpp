#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int x, int y) {
    string sx = to_string(x);
    string sy = to_string(y);
    return stoi(sx + sy) > stoi(sy + sx);
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    for(auto n : numbers) {
        answer += to_string(n);
    }
    if(answer[0] == '0') answer = "0";
    return answer;
}