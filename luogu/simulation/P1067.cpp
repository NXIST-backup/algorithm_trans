#include "iostream"

using namespace std;

int n;
int a[150];



int main()
{
    cin >> n;

    for (int i = 1; i <= n+1;i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n;i++)
    {
        if(a[i]!=0)
        {
            if(a[i]>0)
            {
                if(a[i]==1)
                {
                    if(i!=1)    
                        cout << '+' << 'x' << '^' << n - i + 1;
                    else
                        cout << 'x' << '^' << n - i + 1;
                }
                else
                {
                    if(i!=1)
                        cout << '+' << a[i] << 'x' << '^' << n - i + 1;
                    else
                        cout << a[i] << 'x' << '^' << n - i + 1;
                }
            }
            else
            {
                if(a[i]==-1)
                    cout << '-' << 'x' << '^' << n - i + 1;
                else
                    cout << a[i] << 'x' << '^' << n - i + 1;
            }
        }
    }

    if(a[n]>0)
    {
        if(a[n]==1)
            cout << '+'  << 'x';
        else
            cout << '+' << a[n] << 'x';

    }
    else if(a[n]<0)
    {
        if(a[n]==-1)
            cout << '-' << 'x';
        else
            cout << a[n] << 'x';
    }


    if(a[n+1])
    {
        if(a[n+1]>0)
            cout << '+' << a[n + 1];
        else
            cout << a[n + 1];
    }
}