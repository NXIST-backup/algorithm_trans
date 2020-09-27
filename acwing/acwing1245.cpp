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

int n;

void del(int x,string &s)
{
    while(x){
        char c = x % 10 + '0';
        s.push_back(c);
        x /= 10;
    }
}



int main()
{
    cin >> n;
    ll ans = 0;

    for (int i = 1; i <= n;i++){
        string s;
        del(i, s);
        for(auto item:s){
            if(item=='0'||item=='1'||item=='2'||item=='9'){
                ans += i;
                break;
            }
        }
    }

    cout << ans << endl;
}