#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> S;
    
    // 1 ~ n 번까지 순차적으로 진행
    for(int i = 1; i < order.size() + 1; ++i) {
        // 맨 처음
        if(S.empty() && order[answer] != i) {
            S.push(i);
        }
        else {
            // 같은 순번이다?
            if(i == order[answer]) {
                ++answer;
                // 보조 컨테이너에 다음 차례가 있다?
                while(!S.empty() && S.top() == order[answer]) {
                    S.pop();
                    ++answer;
                }
            }
            // 같은 순번 아니면 담기
            else S.push(i);
        }
    }
    
    return answer;
}