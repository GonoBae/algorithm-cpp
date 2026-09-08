#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> M;

bool comp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

// 재귀
void findAllCourse(string order, int course, string s, int ix) {
    if(s.size() == course) {
        if(M.find(s) != M.end()) M[s] += 1;
        else M[s] = 1;

        return;
    }
    
    for(int i = ix; i < order.size(); ++i) {
        findAllCourse(order, course, s + order[i], i + 1);
    }
}

// 완전탐색
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto c : course) {
        M.clear();
        for(int i = 0; i < orders.size(); ++i) {
            sort(orders[i].begin(), orders[i].end());
            if(c <= orders[i].size()) {
                findAllCourse(orders[i], c, "", 0);
            }
        }

        vector<pair<string, int>> V(M.begin(), M.end());
        sort(V.begin(), V.end(), comp);
        if(!V.empty()) {
            if(V[0].second >= 2) {
                for(int i = 0; i < V.size(); ++i) {
                    if(V[i].second == V[0].second) answer.push_back(V[i].first);
                    else break;
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}