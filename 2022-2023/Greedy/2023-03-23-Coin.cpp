#include<iostream>
#include<vector>

using namespace std;

// 500, 100, 50, 10, 5, 1
int main() {
    int n, answer = 0;
    vector<int> coin = {500, 100, 50, 10, 5, 1};
    cin >> n;
    n = 1000 - n;
    for(int i = 0; i < coin.size(); ++i) {
        if(n >= coin[i]) {
            answer += n / coin[i];
            n %= coin[i];
        }
    }
    cout << answer;
    return 0;
}