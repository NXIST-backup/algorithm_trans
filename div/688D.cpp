/*
  Problem Name:Checkpoints
  algorithm tag:位运算
*/

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
const int mod = 1e9 + 7;
typedef pair<int,int> pii;

int t;
ll k;


int main()
{
    cin >> t;

    while(t--){
        cin >> k;

        if(k%2){
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        while(k){
            ll tmp = k;
            tmp >>= 1;
            int cnt = -1;
            ll cur = 1;
            ll res = 0;
            while(tmp&1){
                cnt++;
                cur <<= 1;
                res += cur;
                tmp >>= 1;
            }
            if(cnt>=0){
                ans.push_back(1);
                for (int i = 1; i <= cnt;i++)
                    ans.push_back(0);
                k -= res;                
            }
            else{
                k -= 2;
                ans.push_back(1);
            }
        }
        cout << ans.size() << endl;
        for(auto item:ans)
            cout << item << " ";

        cout << endl;
    }
}