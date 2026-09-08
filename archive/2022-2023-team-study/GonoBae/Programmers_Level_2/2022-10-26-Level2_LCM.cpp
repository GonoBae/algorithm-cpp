#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int idx = arr.size() - 1;
    int answer = arr[idx], last = arr[idx];
    bool flag = false;
    while(!flag) {
        for(int i = 0; i < idx + 1; ++i) {
            if(answer % arr[i] != 0) {
                flag = false;
                break;
            }
            flag = true;
        }
        if(flag) break;
        answer += last;
    }
    return answer;
}

int main() {
    vector<int> arr = {2, 6, 8, 14};
    int result = solution(arr);
    cout << result;
    return 0;
}