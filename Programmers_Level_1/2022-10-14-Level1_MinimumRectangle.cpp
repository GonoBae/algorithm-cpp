#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &v1, vector<int> &v2) {
    if(v1[1] == v2[1]) return (v1[0] < v2[0]);
    else return (v1[1] < v2[1]);
}

int solution(vector<vector<int>> sizes) {
    // 가로가 더 크도록 만들어 주어야 함
    for(int i = 0; i < sizes.size(); ++i) {
        sort(sizes[i].begin(), sizes[i].end());
    }
    // 가장 큰 가로
    sort(sizes.begin(), sizes.end());
    int w = sizes[sizes.size() - 1][0];

    // 가장 큰 세로
    sort(sizes.begin(), sizes.end(), compare);    
    int h = sizes[sizes.size() - 1][1];

    int answer = w * h;
    return answer;
}

int main() {
    // vector<vector<int>> sizes = {{60, 50}, {30, 70}, {60, 30}, {80, 40}};
    // vector<vector<int>> sizes = {{10, 7}, {12, 3}, {8, 15}, {14, 7}, {5, 15}};
    vector<vector<int>> sizes = {{14, 4}, {19, 6}, {6, 16}, {18, 7}, {7, 11}};
    int result = solution(sizes);
    cout << result;

    return 0;
}