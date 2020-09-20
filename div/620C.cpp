//不断更新温度范围


#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;


int q;
int n, m;
vector<int> tl;
vector<pair<int, int>> tem;

int main()
{
    cin >> q;
    while (q--) {

        cin >> n >> m;
        tl.clear();
        tem.clear();
        for (int i = 0; i < n;i++)
        {
            int time, low, high;
            cin >> time >> low >> high;
            tl.push_back(time);
            tem.push_back({low, high});
        }

        int now = 0;
        int flag = 1;
        int low = m, high = m;
        for (int i = 0; i < tl.size();i++)
        {
            int t = tl[i] - now;
            now = tl[i];
            if(high+t>=tem[i].first&&low-t<=tem[i].second)
            {
                if(high+t<tem[i].second)
                    high = high + t;
                else
                    high = tem[i].second;
                if(low-t>tem[i].first)
                    low = low - t;
                else
                    low = tem[i].first;
            }
            else
            {
                flag = 0;
                break;
            }
        }

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}