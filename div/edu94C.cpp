#include <ios>
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
const int N = 2e5 + 50;
int t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cin >> t;
    while (t--) {
        int x;
        string s;
        char w[N];
        memset(w, 0, sizeof w);
        cin >> s;
        cin >> x;
        for (int i = 0; i < s.size();i++){
            if(s[i]=='0'){
                if (i + x < s.size())
                    w[i + x] = '0';
                if (i - x >= 0)
                    w[i - x] = '0';
            }
        }
        bool flag = 1;
        for (int i = 0; i < s.size();i++){
            if(s[i]=='1'){
                if((i+x<s.size()&&w[i+x]!='0')||(i-x>=0&&w[i-x]!='0')){
                    if(w[i-x]!='0'&&i-x>=0)
                        w[i - x] = '1';
                    if(w[i+x]!='0'&&i+x<s.size())
                        w[i + x] = '1';
                }
                else{
                    flag = 0;
                    break;
                }
            }
        }
        if(flag){
            for (int i = 0; i < s.size();i++){
                if(w[i]!='0'&&w[i]!='1'){
                    w[i] = '1';
                }
            }
            cout << w << endl;
        }
        else
            cout << -1 << endl;
    }
}