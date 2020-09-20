#include "iostream"

using namespace std;

int t;
string a, b, c;



int main()
{
    cin >> t;

    while (t--) {

        cin >> a;
        cin >> b;
        cin >> c;
        int flag = 1;
        for (int i = 0; i < a.size();i++)
        {
            if(a[i]==b[i]==c[i])
                continue;
            else if(a[i]==c[i])
                continue;
            else if(b[i]==c[i])
                continue;
            else
                flag = 0;
        }

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}