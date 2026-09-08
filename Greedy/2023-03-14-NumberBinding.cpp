#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 둘 다 양수 => 양수 * 양수 (1 보다 커야함)
// 둘 다 음수 => 음수 * 음수
// 하나가 0 => 양수 + 0 / 음수 * 0

int main() {
    vector<int> V;
    int n, num, answer = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> num;
        V.push_back(num);
    }
    int nIx = V.size();
    sort(V.begin(), V.end(), greater<int>());
    for(int i = 0; i < V.size(); i += 2) {
        if(i + 1 >= V.size()) {
            answer += V[i];
            break;
        }
        int a = V[i];
        int b = V[i + 1];
        // 둘 다 양수
        if(a > 0 && b > 0) {
            // 둘 다 1 보다 큰 경우 곱셈이 이득
            if(a > 1 && b > 1) answer += (a * b);
            // 하나라도 1 인 경우 덧셈이 이득
            else answer += (a + b);
        }
        // 둘 중에 하나는 0 이하
        else {
            nIx = i;
            break;
        }
    }
    for(int i = V.size() - 1; i >= nIx; i -= 2) {
        if(i <= nIx) {
            answer += V[i];
            break;
        }
        int a = V[i];
        int b = V[i - 1];
        // 둘 다 0 이하인 경우 곱셈이 이득
        if(a <= 0 && b <= 0) answer += (a * b);
        // 하나라도 양수인 경우 덧셈이 이득
        else answer += (a + b);
    }
    cout << answer;
    return 0;
}