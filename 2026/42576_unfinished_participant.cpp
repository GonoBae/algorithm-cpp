// Programmers 42576 - 완주하지 못한 선수
// https://school.programmers.co.kr/learn/courses/30/lessons/42576
// Hash / unordered_map: average time O(n), space O(n)

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> participantCount;

    for (const string& name : participant)
    {
        ++participantCount[name];
    }

    for (const string& name : completion)
    {
        --participantCount[name];
    }

    for (const auto& entry : participantCount)
    {
        if (entry.second > 0)
        {
            return entry.first;
        }
    }

    return "";
}
