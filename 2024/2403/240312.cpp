#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    vector<int> V;
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        int coin;
        cin >> coin;
        V.push_back(coin);
    }
    int n = 0;

    // 1번
    // while(K != 0)
    // {
    //     if(K >= V[N - 1])
    //     {
    //         K -= V[N - 1];
    //         n++;
    //     }
    //     else
    //     {
    //         N -= 1;
    //     }
    // }

    // 2번
    while(K != 0)
    {
        if(K >= V[N - 1])
        {
            n += K / V[N - 1];
            K %= V[N - 1];
        }
        else
        {
            N--;
        }
    }

    cout << n;
    return 0;
}