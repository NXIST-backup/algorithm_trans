#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int n;
int x, y;


int main()
{
    cin >> n;

    string a;

    cin >> a;


    if(n%2)
        cout << -1 << endl;

    else
    {
        for (int i = 0; i < n;i++)
        {
            if(a[i]=='(')
                x++;
            if(a[i]==')')
                y++;
        }

        if(x!=y)
            cout << -1 << endl;
        else
        {
            int res = 0;
            int flag = 0;
            int cnt = 0;
            for (int i = 0; i < a.size();i++)
            {
                if(a[i]==')'&&!cnt)
                    flag = 1;
                if(a[i]=='('&&!cnt)
                    flag = 0;

                if(a[i]=='(')
                    cnt++;
                if(a[i]==')')
                    cnt--;
                if(a[i]==')'&&flag)
                    res++;
            }
            cout << res*2 << endl;
        }

    }
}