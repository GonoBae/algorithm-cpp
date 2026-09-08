#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[26];

int main() {
    int N, result = 0;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        int cnt = 1;
        for(int j = str.length() - 1; j >= 0; --j) {
            int idx = str[j] - 'A';
            arr[idx] += cnt;
            cnt *= 10;
        }
    }
    sort(arr, arr + 26, greater<int>());
    int cnt = 9;
    for(int i = 0; i < 26; ++i) {
        if(arr[i] == 0) break;
        result += (cnt * arr[i]);
        --cnt;
    }
    cout << result;
    return 0;
}