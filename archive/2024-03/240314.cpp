#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    
    for(int i = 1; i <= K; i++)
    {
        N -= i;
    }
    if(N < 0)
    {
        cout << -1;
    }
    else
    {
        if(N % K == 0)
        {
            cout << K - 1;
        }
        else
        {
            cout << K;
        }
    }
    return 0;
}