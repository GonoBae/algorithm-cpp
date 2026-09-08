#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> S;
    // 번호 set 에 넣기
    for(string p : phone_book)
        S.insert(p);
    for(auto iter1 = S.begin(); iter1 != S.end(); ++iter1) {
        for(auto iter2 = iter1; iter2 != S.end(); ++iter2) {
            // 같은 번호는 건너뛰기
            if(iter1 != iter2) {
                // 2 번째 번호가 1 번째 번호를 포함한다면
                if(iter2->find(*iter1) == 0) {
                    return false;
                }
                else break;
            }
        }
    }
    return answer;
}

// 효율성 테스트 마지막 2개 통과가 안됨
bool solutionB(vector<string> phone_book) {
    bool answer = true;
    // 오름차순 정렬
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size(); ++i) {
        for(int j = i + 1; j < phone_book.size(); ++j) {      
            // 이 구간을 반복문이 아닌 substr 로 자르면 됨      
            for(int k = 0; k < phone_book[i].size(); ++k) {
                if(phone_book[i][k] != phone_book[j][k]) {
                    answer = true;
                    break;
                }
                answer = false;
            }
            
            if(!answer) return answer;
        }
    }
    return answer;
}

int main() {
    // vector<string> phone_book {"119", "97674223", "1195524421"};
    // vector<string> phone_book {"123","456","789"};
    vector<string> phone_book {"12","123","1235","567","88"};
    bool result = solution(phone_book);
    cout << result;
    return 0;
}