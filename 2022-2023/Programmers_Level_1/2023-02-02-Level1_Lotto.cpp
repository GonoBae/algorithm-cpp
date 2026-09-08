#include <string>
#include <vector>

using namespace std;

// 1 : 6 , 2 : 5 , 3 : 4 , 4 : 3 , 5 : 2 , 6 : ~
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zerocnt = 0, num = 0;
    for(int i = 0; i < lottos.size(); ++i) {
        // 0 카운트
        if(lottos[i] == 0) ++zerocnt;
        // 같은 번호 카운트
        else {
            for(int j = 0; j < win_nums.size(); ++j) {
                if(lottos[i] == win_nums[j]) ++num;
            }
        }
    }
    
    // 등수는 7 - x
    int first = 7 - (num + zerocnt);
    int second = 7 - num;
    if(num == 0) --second;
    if(first == 7) --first;
    answer.push_back(first); answer.push_back(second);
    return answer;
}