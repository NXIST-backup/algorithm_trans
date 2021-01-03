#include "iostream"
using namespace std;
int q;
string s, t;
int main()
{
    cin >> q;
    while(q--){
        cin >> s >> t;
        int flag = 0;
        for (int i = 0; i < s.size();i++)
        {
            for (int j = 0; j < s.size();j++)
                if (s[i] == t[j])
                    flag = 1;
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}