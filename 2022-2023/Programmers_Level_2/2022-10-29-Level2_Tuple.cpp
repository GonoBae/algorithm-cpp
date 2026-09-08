#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> cnt;
    string removeChars = "{}";
    s.erase(remove_if(
        s.begin(), s.end(), 
        [&removeChars](const char &c) {
            return removeChars.find(c) != string::npos;
            }), s.end());
    istringstream ss(s);
    string word;
    while(getline(ss, word, ',')) {
        int n = stoi(word);
        ++cnt[n];
    }
    vector<pair<int, int>> V(cnt.begin(), cnt.end());
    sort(V.begin(), V.end(), compare);
    for(auto v : V) {
        answer.push_back(v.first);
    }
    return answer;
}

int main() {
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    vector<int> result = solution(s);
    for(auto r : result) {
        cout << r;
    }
    return 0;
}