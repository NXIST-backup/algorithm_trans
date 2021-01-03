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

int t;
int n;


int main()
{
    cin >> t;

    while (t--) {

        cin >> n;
        int flag=0;
        int k = 0;
        vector<int> odd;
        for (int i = 0; i < n;i++)
        {
            int x;
            cin >> x;
            if(x%2==0)
            {
                flag = 1;
                k = i+1;
            }
            else
            {
                if(odd.size()<2)
                odd.push_back(i+1);
                if(odd.size()>=2&&!flag)
                    flag = 2;
            }
        }
        if(flag==1)
        {
            cout << 1 << endl;
            cout << k << endl;
        }
        else if(flag==2)
        {
            cout << 2 << endl;
            for (int i = 0; i < 2;i++)
                cout << odd[i] << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
}