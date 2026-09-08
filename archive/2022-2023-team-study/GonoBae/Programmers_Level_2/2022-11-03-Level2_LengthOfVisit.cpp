#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    unordered_set<string> record;
    int x = 0, y = 0, nx = 0, ny = 0;
    for(auto d : dirs) {
        string cur = "", next = "";
        switch(d) {
            case 'U': ny = y + 1; break;
            case 'D': ny = y - 1; break;
            case 'L': nx = x - 1; break;
            case 'R': nx = x + 1; break;
        }
        // 범위 벗어나면 좌표 원상복구
        if(nx < -5 || nx > 5 || ny < -5 || ny > 5) {
            nx = x; ny = y;
            continue;
        }
        // 현재좌표 , 이동한 좌표
        cur += to_string(x); cur += to_string(y);
        next += to_string(nx); next += to_string(ny);
        string road = cur; road += next;
        string reverseRoad = next; reverseRoad += cur;
        // 검색해보고 없으면 넣고 카운트
        if(record.find(road) == record.end() && record.find(reverseRoad) == record.end()) {
            record.insert(road);
            record.insert(reverseRoad);
            ++answer;
        }
        // 위치 이동
        x = nx; y = ny;
    }
    return answer;
}

int main() {
    string dirs = "LULLLLLLU";
    int result = solution(dirs);
    cout << result;
    return 0;
}