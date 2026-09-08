#include <iostream>
#include <vector>

using namespace std;

// push x
// pop
// size
// empty
// front
// back

int main()
{
    vector<int> V;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "push")
        {
            int number;
            cin >> number;
            V.push_back(number);
        }
        else if(cmd == "pop")
        {
            if(V.size() > 0)
            {
                cout << V.front() << endl;
                V.erase(V.begin());
            }
            else cout << -1 << endl;
        }
        else if(cmd == "size")
        {
            cout << V.size() << endl;
        }
        else if(cmd == "empty")
        {
            if(V.size() > 0) cout << 0 << endl;
            else cout << 1 << endl;
        }
        else if(cmd == "front")
        {
            if(V.size() > 0) cout << V.front() << endl;
            else cout << -1 << endl;
        }
        else if(cmd == "back")
        {
            if(V.size() > 0) cout << V.back() << endl;
            else cout << -1 << endl;
        }
        else return 0;
    }
    return 0;
}