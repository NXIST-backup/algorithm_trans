#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <string.h>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;
const int N = 3000;
int t;
map<int, int> mp;
int st1[N][N];
int st2[N][N];
int main()
{
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        vector<int> b;
        memset(st1, 0, sizeof st1);
        memset(st2, 0, sizeof st2);
        for (int i = 0; i < n;i++){
            int x;
            cin >> x;
            mp[x]++;
            a.push_back(x);
        }
        for(auto item:a){
            if(mp[item]>1)
                b.push_back(item);
        }
        if(b.size()>=4){

            for (int j = 1; j < b.size() - 2;j++){
                for (int i = 0; i < j;i++){
                    st1[j][b[i]]++;
                }
            }
            for (int k = 2; k < b.size()-1;k++){
                for (int l = b.size()-1; l > k;l--){
                    st2[k][b[l]]++;
                }
            }
            ll ans = 0;

            for (int j = 1; j < b.size() - 1;j++){
                for (int k = b.size() - 2; k > j;k--){
                    ans += st1[j][b[k]] * st2[k][b[j]];
                }
            }

            cout << ans << endl;
        }
        else
            cout << 0 << endl;
    }
}