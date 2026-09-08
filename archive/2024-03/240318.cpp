#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> V;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string cmd;        
        cin >> cmd;
        if(cmd == "push")
        {
            int num;
            cin >> num;
            V.push_back(num);
        }
        else if(cmd == "pop")
        {
            if(V.size() > 0)
            {
                cout << V.back() << endl;
                V.pop_back();
            }
            else cout << -1 << endl;
        }
        else if(cmd == "size")
        {
            cout << V.size() << endl;
        }
        else if(cmd == "empty")
        {
            if(V.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(cmd == "top")
        {
            if(!V.empty()) cout << V.back() << endl;
            else cout << -1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}

// strcmp 로 비교할 수 있음
// 벡터를 배열로 변경할 수 있음