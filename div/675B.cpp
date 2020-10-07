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

const int N = 150;
int t;
int n,m;
int a[N][N];


int main()
{
    cin >> t;

    while(t--){
        cin >> n >> m;
        for (int i = 1;i<=n;i++){
            for (int j = 1;j<=m;j++){
                cin >> a[i][j];
            }
        }
        ll cost = 0;
        vector<int> s;
        for (int i = 1; i <= (n - 1) / 2 + 1; i++) {
            for (int j = 1; j <= (m - 1) / 2 + 1; j++) {
                s.push_back(a[i][j]);
                if(n-i+1!=i)
                    s.push_back(a[n-i+1][j]);
                if(m-j+1!=j)    
                s.push_back(a[i][m-j+1]);
                if(n-i+1!=i||m-j+1!=j)
                    s.push_back(a[n-i+1][m-j+1]);
                sort(s.begin(), s.end());
                if(s.size()>1){
                    for(auto item:s){
                        cost += abs(item - s[1]);
                    }
                }
                s.clear();
            }
        }

        cout << cost << endl;
    }
}