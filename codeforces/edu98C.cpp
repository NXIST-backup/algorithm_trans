#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

int t;

int main()
{
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        int ans = 0;
        int a = 0, b = 0;
        for (int i = 0; i < s.size();i++){
            if(s[i]=='(')
                a++;
            if(s[i]==')'&&a)
                a--, ans++;
            if(s[i]=='[')
                b++;
            if(s[i]==']'&&b)
                b--, ans++;
        }
        cout << ans << endl;
    }
}