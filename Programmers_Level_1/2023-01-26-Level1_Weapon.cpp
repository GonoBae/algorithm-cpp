#include <iostream>
#include <string>
#include <vector>

using namespace std;

int divisor(int _n) {
    int cnt = 0;
    for (int i = 1; i * i <= _n; ++i) {
        if(_n % i) continue;
        else if (i * i == _n) ++cnt;
        else cnt += 2;
    }
    return cnt;
}

int solution(int number, int limit, int power)
{
    int answer = 0;
    // 반복문으로 각 수마다 약수를 구해야함
    // 5 -> 1, 2, 2, 3, 2
    for (int i = 1; i <= number; ++i)
    {
        int n = divisor(i);
        answer += (n > limit ? power : n);
    }
    return answer;
}

int main()
{
    int result = solution(5, 3, 2);
    cout << result;
    return 0;
}