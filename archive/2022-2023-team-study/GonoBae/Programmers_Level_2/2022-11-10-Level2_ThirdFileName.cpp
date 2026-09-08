#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> p1, pair<string, int> p2) {
    // 문자
    string s1 = p1.first, s2 = p2.first;
    // 들어온 순서
    int i1 = p1.second, i2 = p2.second;
    string tmp1 = "", tmp2 = "";
    int ix1 = 0, ix2 = 0, ix3 = 0, ix4 = 0;
    for(int i = 0; i < s1.size(); ++i) {
        s1[i] = tolower(s1[i]);
        // 정수이면 자르고 인덱스 저장
        if(isdigit(s1[i]) && tmp1 == "") {
            tmp1 += s1.substr(0, i);
            ix1 = i;
        }
        // . 이면 인덱스 저장 후 탈출
        else if(s1[i] == '.') {
            ix2 = i;
            break;
        }
    }
    for(int i = 0; i < s2.size(); ++i) {
        s2[i] = tolower(s2[i]);
        if(isdigit(s2[i]) && tmp2 == "") {
            tmp2 += s2.substr(0, i);
            ix3 = i;
        }
        else if(s2[i] == '.') {
            ix4 = i;
            break;
        }
    }
    // 문자가 사전순 정렬
    if(tmp1 != tmp2) return tmp1 < tmp2;
    else {
        // 문자가 같다면
        tmp1 = "", tmp2 = "";
        tmp1 = s1.substr(ix1, ix2 - ix1);
        tmp2 = s2.substr(ix3, ix4 - ix3);
        // 숫자가 다르면 숫자정렬
        if(tmp1 != tmp2) return stoi(tmp1) < stoi(tmp2);
        else {
            // 같으면 들어온 순서 정렬
            return i1 < i2;
        }
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<string, int>> V;
    for(int i = 0; i < files.size(); ++i) {
        V.push_back({files[i], i});
    }
    stable_sort(V.begin(), V.end(), comp);
    for(auto v : V) {
        answer.push_back(v.first);
    }
    return answer;
}

int main() {
    vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
    vector<string> result = solution(files);
    for(auto r : result) {
        cout << r << ' ';
    }
    return 0;
}