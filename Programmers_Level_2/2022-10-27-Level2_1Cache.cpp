#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    if(cacheSize == 0) {
        answer = (cities.size() * 5);
        return answer;
    }
    for(int i = 0; i < cities.size(); ++i) {
        string city = "";
        for(auto c : cities[i]) {
            city += tolower(c);
        }
        auto it = find(cache.begin(), cache.end(), city);
        // cache 안에 없다면 cache miss
        if(it == cache.end()) {
            if(cache.size() == cacheSize) {
                cache.erase(cache.begin());
            }
            cache.emplace_back(city);
            answer += 5;
        }
        // cache 안에 있다면 cache hit
        else {
            cache.erase(it);
            cache.emplace_back(city);
            answer += 1;
        }
    }
    return answer;
}

int main() {
    int cacheSize = 3;
    vector<string> cities = {
        "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"
        };
    int result = solution(cacheSize, cities);
    cout << result;
    return 0;
}