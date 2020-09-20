#include "iostream"
using namespace std;

const int N = 100050;

int que[N], tt=0,ss=1;

int main()
{
    int m;
    cin >> m;
    while(m--){
        string a;
        cin >> a;
        if(a=="push")
        {
            int x;
            cin >> x;
            que[++tt] = x;
        }
        if(a=="pop")
        {
            ++ss;
        }
        if(a=="empty")
        {
            if(ss>tt)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        if(a=="query")
        {
            cout << que[ss] << endl;
        }
    }
}