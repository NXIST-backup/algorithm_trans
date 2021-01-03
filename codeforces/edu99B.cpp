#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;

const int N = 1e6;
int t;

int main()
{
    cin >> t;

    while (t--) {
        int n;

        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n;i++){
            int sum = i * (i + 1) / 2;
            if(sum>=n){
                sum = sum - n;
                if(sum==0||sum>=2){
                    ans = i;
                    break;
                }
                else{
                    ans = i + 1;
                    break;
                }
            }
            else
                continue;
        }

        cout<<ans<<endl;
    }
}