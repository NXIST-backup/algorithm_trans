#include "iostream"
#include "vector"
#include "cmath"
#include <stdlib.h>
using namespace std;

const int N = 1e5 + 10;

int a, b, c, d;

int main()
{
    cin >> a >> b >> c >> d;

    if(a>b||d>c)
    {
        if((a==0&&b==0)||(d==0&&c==0))
        {
            if(a==b+1)
            {
                cout << "YES" << endl;
                for (int i = 0; i < b;i++)
                    cout << "0 1 ";
                cout << "0 ";
            }
            else if(d==c+1)
            {
                cout << "YES" << endl;
                for (int i = 0; i < c;i++)
                    cout << "3 2 ";
                cout << "3 ";
            }
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;

    }
    else
    {
        if(abs(c-d-b+a)!=1)
        {
            if((a==0&&b==0)||(d==0&&c==0)||(a==0&&d==0))
            {
                if(a==b&&b!=0)
                {
                    cout << "YES" << endl;
                    for (int i = 0; i < b;i++)
                        cout << "0 1 ";
                }
                else if(c==d&&c!=0)
                {
                    cout << "YES" << endl;
                    for (int i = 0; i < c;i++)
                        cout << "2 3 ";
                }
                else if(b==c&&c!=0)
                {
                    cout << "YES" << endl;
                    for (int i = 0; i < c;i++)
                        cout << "1 2 ";
                }
                else
                    cout << "NO" << endl;
            }
            else if(a==b&&b==c&&c==d&&a!=0)
            {
                cout << "YES" << endl;
                for (int i = 0; i < a;i++)
                    cout << "0 1 ";
                for (int i = 0; i < a;i++)
                    cout << "2 3 ";
            }
            else
                cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            if(b-a>c-d)
            {
                for (int i = 0; i < a;i++)
                    cout << "1 0 ";
                cout << "1 ";
                for (int i = 0; i < c - d;i++)
                    cout << "2 1 ";
                for (int i = 0; i < d;i++)
                    cout << "2 3 ";
            }
            else
            {
                for (int i = 0; i < a;i++)
                    cout << "0 1 ";
                for (int i = 0; i < b - a;i++)
                    cout << "2 1 ";
                cout << "2 ";
                for (int i = 0; i < d;i++)
                    cout << "3 2 ";
            }
        }
    }
}