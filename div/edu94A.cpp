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


int main()
{
    cin >> t;

    while (t--) {
        cin >> n;

        string te;
        cin >> te;
        string ans;
        ans.push_back(te[0]);
        for (int i = 1; i < te.size()/2+1; i++) {
            bool flag = 1;
            int j = 0;
            for (j = 0; j < ans.size(); j++){
                if (te[i+j] == ans[j]) {
                    flag = 0;
                }
            }
            if(flag)
                ans.push_back(te[i + j]);
        }
        while(ans.size()<n){
            ans.push_back('0');
        }
        cout << ans << endl;
    }
}