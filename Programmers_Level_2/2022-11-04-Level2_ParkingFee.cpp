#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    const int MAX_TIME = 1439;
    vector<int> answer;
    // map => key : 차 번호 , value : 총 주차시간
    map<string, int> HM;
    map<string, int> TotalM;
    
    string time, number, state;
    // 빈칸 기준으로 자르면 => 05:34 / 5961 / IN
    for(auto record : records) {
        istringstream ss(record);
        ss >> time >> number >> state;
        // 시간을 00:00 기준 분으로 환산
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int total = h * 60 + m;
        // 입차, 출차 구분
        if(state == "IN") {
            HM[number] = total;
        }
        else if(state == "OUT") {
            TotalM[number] += total - HM[number];
            HM[number] = -1;
        }
    }

    // HM 에 value 값이 남아있는 경우는 출차를 하지 않은 경우
    for(auto i = HM.begin(); i != HM.end(); ++i) {
        if(i->second != -1) {
            TotalM[i->first] += MAX_TIME - HM[i->first];
        }
    }
    
    // 요금계산 => 기본요금(5000) + {(시간 - 기본시간) / 단위시간 * 추가요금}
    // 0 : 기본시간 , 1 : 기본요금 , 2 : 단위시간 , 3 : 추가요금
    int baseTime = fees[0], baseFee = fees[1], perTime = fees[2], alphaFee = fees[3];
    for(auto i = TotalM.begin(); i != TotalM.end(); ++i) {
        if(TotalM[i->first] - baseTime >= 0) {
            int test = (TotalM[i->first] - baseTime) % perTime == 0 ? 
            (TotalM[i->first] - baseTime) / perTime : (TotalM[i->first] - baseTime) / perTime + 1;
            int fee = baseFee + (test * alphaFee);
            answer.push_back(fee);
        }
        else {
            answer.push_back(baseFee);
        }
    }
    
    return answer;
}

int main() {
    vector<int> fees = {180, 5000, 10, 600};
    vector<string> records = {
        "05:34 5961 IN",
        "06:00 0000 IN",
        "06:34 0000 OUT",
        "07:59 5961 OUT",
        "07:59 0148 IN",
        "18:59 0000 IN",
        "19:09 0148 OUT",
        "22:59 5961 IN",
        "23:00 5961 OUT"
        };
    vector<int> result = solution(fees, records);
    for(auto r : result) {
        cout << r << endl;
    }
    return 0;
}