#include<iostream>

using namespace std;

int main() {
    int N, answer = 0;
    int arr[1000001];
    arr[1] = 0;
    arr[2] = arr[3] = 1;
    cin >> N;
    for(int i = 4; i <= N; ++i) {
        arr[N] = arr[N - 1] + 1;
        if(N % 2 == 0) arr[N] = min(arr[N], arr[N / 2] + 1);
        if(N % 3 == 0) arr[N] = min(arr[N], arr[N / 3] + 1);
    }
    cout << arr[N];
    return 0;
}