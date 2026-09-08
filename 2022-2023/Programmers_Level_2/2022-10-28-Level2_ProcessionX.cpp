#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size());
    int sum = 0;
    for(int i = 0; i < arr1.size(); ++i) {
        for(int j = 0; j < arr2[0].size(); ++j) {
            for(int k = 0; k < arr2.size(); ++k) {
                sum += arr1[i][k] * arr2[k][j];
            }
            answer[i].push_back(sum);
            sum = 0;
        }
    }
    return answer;
}

int main() {
    // vector<vector<int>> arr1 = {{1, 4}, {3, 2}, {4, 1}};
    vector<vector<int>> arr1 = {{2, 3, 2}, {4, 2, 4}, {3, 1, 4}};
    vector<vector<int>> arr2 = {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}};
    vector<vector<int>> result = solution(arr1, arr2);
    for(auto R : result) {
        cout << '[';
        for(auto r : R) {
            cout << r;
        }
        cout << ']';
    }
    return 0;
}