#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main() {
    int N, answer = 1;
    vector<pair<int, int>> V;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }
    sort(V.begin(), V.end(), comp);
    int time = V[0].second;
    for(int i = 1; i < V.size(); ++i) {
        if(V[i].first >= time) {
            time = V[i].second;
            ++answer;
        }
    }
    cout << answer;
    return 0;
}