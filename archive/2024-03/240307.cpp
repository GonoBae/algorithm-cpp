// 거스름돈 https://www.acmicpc.net/problem/5585

#include <iostream>

using namespace std;

int main()
{
    constexpr size_t size = 6;

    int money, base = 1000;
    int arrCoin[size] = {500, 100, 50, 10, 5, 1};
    int count = 0;
    cin >> money;
    int m = base - money;
    for(int i = 0; i < size; i++)
    {
        count += (m / arrCoin[i]);
        m %= arrCoin[i];
    }
    cout << count;
    return 0;
}