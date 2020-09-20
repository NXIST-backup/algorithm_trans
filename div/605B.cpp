#include "iostream"
#include "cstring"

using namespace std;

const int N = 1e5 + 10;
string op;
int q;


int main()
{
    cin >> q;
    while (q--) {

        cin >> op;

        int l=0, r=0, u=0, d=0;

        for (int i = 0; i < op.size();i++)
        {
            if(op[i]=='U')
                u++;
            if(op[i]=='D')
                d++;
            if(op[i]=='R')
                r++;
            if(op[i]=='L')
                l++;
        }

        if(u>d)
        {
            u = d;
        }
        else
        {
            d = u;
        }
        if(l>r)
        {
            l = r;
        }
        else
        {
            r = l;
        }

        if(u==0&&l!=0)
        {
            cout << 2 << endl;
            cout << "LR" << endl;
        }
        else if(l==0&&u!=0)
        {
            cout << 2 << endl;
            cout << "UD" << endl;
        }
        else
        {
            cout << u + r + d + l << endl;
            for (int i = 0; i < u;i++)
                cout << "U";
            for (int i = 0; i < r;i++)
                cout << "R";
            for (int i = 0; i < d;i++)
                cout << "D";
            for (int i = 0; i < l;i++)
                cout << "L";
            cout << endl;
        }
    }
}