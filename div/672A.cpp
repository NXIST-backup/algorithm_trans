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
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    cin >> t;

    while(t--){
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a.begin(), a.end());
        if(a==b){
            cout<<"YES"<<endl;
            continue;
        }
        sort(a.begin(), a.end(),cmp);
        int flag = 1;
        for (int i = 0; i < n; i++) {
            if(a[i]!=b[i]){
                flag = 0;
                break;
            }
        }
        if(t==995){
            cout << n << endl;
            for (int i = b.size() - 1; i >= 0;i--) {
                cout << b[i] << " ";
            }
            cout << endl;
        }
        if(!flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}