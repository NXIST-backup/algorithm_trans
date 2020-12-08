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

int main()
{
    string s, ans;
    cin >> s;
    int loop = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
    
        if(s[i]<=57&&s[i]>=50)
            loop = s[i] - '0';
        else{
            for (int j = 0; j < loop;j++)
                ans.push_back(s[i]);
            loop = 1;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}