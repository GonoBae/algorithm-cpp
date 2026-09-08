#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, temp, answer = 0;
    vector<int> V;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int level;
        cin >> level;
        V.push_back(level);
    }
    for(int i = n - 1; i > 0; --i) {
        if(V[i] > V[i - 1]) continue;
        temp = V[i - 1] - V[i] + 1;
        V[i - 1] -= temp;
        answer += temp;
    }
    cout << answer;
    return 0;
}