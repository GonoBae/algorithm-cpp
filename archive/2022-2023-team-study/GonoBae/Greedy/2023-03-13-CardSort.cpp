#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n, cards, answer = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> PQ;
    while(n--) {
        cin >> cards;
        PQ.push(cards);
    }
    while(PQ.size() > 1) {
        int a = PQ.top();
        PQ.pop();
        int b = PQ.top();
        PQ.pop();
        answer += a + b;
        PQ.push(a + b);
    }
    cout << answer;
    return 0;
}