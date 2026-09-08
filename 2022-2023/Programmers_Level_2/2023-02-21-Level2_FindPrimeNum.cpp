#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> US;

// 소수 찾기
bool isPrime(int n)
{
    if(n == 0 || n == 1) return false;
    for(int i = 2; i * i <= n; ++i)
    {
        if(n % i == 0) return false;
    }
    return true;
}

// 조합 찾기
void dfs(string str, string s)
{
    if(s != "") US.insert(stoi(s));

    for(int i = 0; i < str.size(); ++i)
        dfs(str.substr(0, i) + str.substr(i + 1), s + str[i]);
}

int solution(string numbers)
{
    int answer = 0;
    dfs(numbers, "");

    for(auto us : US)
    {
        if(isPrime(us)) ++answer;
    }

    return answer;
}

int main()
{
    cout << solution("17");
    
    return 0;
}