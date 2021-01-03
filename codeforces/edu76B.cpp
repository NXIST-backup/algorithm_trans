#include<iostream>
#include<vector>

using namespace std;

int t;

int main()
{
    cin >> t;
    for (int i = 0; i < t;i++)
    {
        long x, y;
        cin >> x >> y;
        if(x==y)
        {
            cout << "YES" << endl;
            continue;
        }
        if(x>3)
        {
            int flag = 1;
            while(x)
            {
                x = x / 2 * 3;
                
                if(x>=y)
                {
                    flag = 0;
                    cout << "YES" << endl;
                    break;
                }
            }
            if(flag)
                cout << "NO" << endl;
        }
        else
        {
            if()
                cout << "NO" << endl;
        }
    }
    
}