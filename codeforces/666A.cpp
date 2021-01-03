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

int t;
int n;
int st[144];
const int N = 1050;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cin >> t;
    while (t--) {
        memset(st, 0, sizeof st);
        cin >> n;
        string a[N];
        for (int i = 0; i < n;i++){
            cin >> a[i];
        }
        for (int i = 0; i < n;i++){
            for (int j = 0; j < a[i].size();j++){
                st[a[i][j]]++;
            }
        }
        bool flag = 1;
        for (int i = 0; i < 144;i++){
            if(st[i]%n!=0){
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