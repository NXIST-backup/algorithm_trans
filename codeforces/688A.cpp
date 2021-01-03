/*
  Problem Name:Cancel the Trains
  algorithm tag:easy,implement
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


int main()
{
    int t;

    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a;
        for (int i = 1; i <= n + m;i++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n + m-1;i++){
            if(a[i]==a[i+1])
                ans++;
        }
        cout << ans << endl;
    }
}
