// 1, 4, 7, * => L
// 3, 6, 9, # => R
// 2, 5, 8, 0 => 더 가까운 손 / 거리가 같다면 오른손잡이 = 오른손 , 외손잡이 = 왼손

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    pair<int, int> rPos = make_pair(4, 3);
    pair<int, int> lPos = make_pair(4, 1);
    for (int i = 0; i < numbers.size(); ++i)
    {
        int num = numbers[i];
        // 1, 4, 7
        if (num % 3 == 1)
        {
            // 무조건 왼손
            answer += "L";
            lPos = make_pair(num / 3 + 1, 1);
        }
        // 3, 6, 9
        else if (num % 3 == 0 && num != 0)
        {
            // 0 / 3 = 0 임
            // 무조건 오른손
            answer += "R";
            rPos = make_pair(num / 3, 3);
        }
        else
        {
            // 왼손, 오른손 거리비교 (2, 5, 8, 0)
            int line = num / 3 + 1;
            int sel = 2;
            // 0 처리
            if (num == 0) (line += 3);
            
            int lDis = abs(lPos.first - line) + abs(lPos.second - sel);
            int rDis = abs(rPos.first - line) + abs(rPos.second - sel);
            if (lDis > rDis)
            {
                answer += "R";
                rPos = make_pair(line, sel);
            }
            else if (lDis < rDis)
            {
                answer += "L";
                lPos = make_pair(line, sel);
            }
            else
            {
                if (hand == "right")
                {
                    answer += "R";
                    rPos = make_pair(line, sel);
                }
                else
                {
                    answer += "L";
                    lPos = make_pair(line, sel);
                }
            }
        }
    }
    return answer;
}

int main()
{
    vector<int> v = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string hand = "right";
    string result = solution(v, hand);
    cout << result;
    return 0;
}