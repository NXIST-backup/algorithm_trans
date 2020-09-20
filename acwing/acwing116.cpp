//二进制状态压缩 +  暴力枚举

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;
char s[4][4];
char backup[4][4];
bool check()
{
    bool flag = 1;
    for (int i = 0; i < 4;i++){
        for (int j = 0; j < 4;j++)
            if(s[i][j]=='+'){
                flag = 0;
                return flag;
            }
    }
    return flag;
}
void turn_one(int x, int y)
{
    if (s[x][y] == '+') s[x][y] = '-';
    else s[x][y] = '+';
}

void turn_all(int x, int y)
{
    for (int i = 0; i < 4; i ++ )
    {
        turn_one(x, i);
        turn_one(i, y);
    }

    turn_one(x, y);
}

int main()
{
    for (int i = 0; i < 4;i++){
        cin >> s[i];
    }
    vector<pii> ans;

    memcpy(backup, s, sizeof s);
    for (int i = 0; i < 1<<16;i++){
        memcpy(s, backup, sizeof s);
        int res = 0;
        int tt = i;
        int idx = 0;
        while (tt) {
            if(tt&1){
                int x = idx / 4, y = idx % 4;
                res++;
                turn_all(x, y);
            }
            idx++;
            tt >>= 1;
        }
        if(check()){
            ans.push_back({i, res});
        }
    }
    int minN = 1e9;
    int minI = 0;
    for (int i = 0; i < ans.size();i++) {
        if(ans[i].second<minN){
            minN = ans[i].second;
            minI = ans[i].first;
        }
    }
    int idx = 0;
    cout << minN << endl;
    while (minI) { 
        if(minI&1){
            int x = idx / 4, y = idx % 4;
            cout << x+1 << " " << y+1 << endl;
        }
        idx++;
        minI >>= 1;
    }
}