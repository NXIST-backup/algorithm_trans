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

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

const int N = 3e5 + 50;
int t;
int n;
int st[N];
int ans = 0;
int main()
{
    cin >> t;

    while(t--){
        cin >> n;
        memset(st, 0, sizeof st);
        ans = 0;
        string belt;
        cin >> belt;
        int flag1 = 0;
        int flag2 = 0;
        for (int i = 0; i < n;i++){
            if(belt[i]=='-'){
                if(!st[i])
                    st[i] = 1;
                if(!st[(i+1)%n])
                    st[(i + 1)%n] = 1;
            }
            else if(belt[i]=='>')
                flag1 = 1;
            else
                flag2 = 1;
        }

        if(flag1&&flag2)
        {
            for (int i = 0; i < n;i++)
                if(st[i])
                    ans++;
        }
        else
            ans = n;
        cout << ans << endl;
    }
}