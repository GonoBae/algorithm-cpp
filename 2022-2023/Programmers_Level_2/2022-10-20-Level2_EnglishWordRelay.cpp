#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> us;
    char oldC = ' ', newC = ' ';
    // 나오는 단어가 이전 단어의 마지막 알파벳에 이어지는가?
    for(int i = 0; i < words.size(); ++i) {
        // 새로운 단어의 시작 알파벳
        newC = words[i][0];

        // 이미 나온 적이 있는 단어
        // 시작 알파벳이 이전 단어의 마지막 알파벳과 같은가
        if((us.find(words[i]) != us.end()) || (newC != oldC && oldC != ' ')) {
            // 몇 번째 사람 , 몇 번째 턴
            int p = ((i+1) % n);
            int t = 0;
            if(p == 0) t = (i+1) / n;
            else t = (i+1) / n + 1;

            if(p == 0) p = n;
            answer.push_back(p);
            answer.push_back(t);
            break;
        }

        us.insert(words[i]);
        oldC = words[i][words[i].size() - 1];
    }
    if(answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}

int main() {
    int n = 3;
    vector<string> words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
    // vector<string> words = {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"};
    // vector<string> words = {"hello", "one", "even", "never", "now", "world", "draw"};
    vector<int> result = solution(n, words);
    for(auto r : result) {
        cout << r;
    }
    return 0;
}