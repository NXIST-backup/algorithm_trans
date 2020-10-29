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

const int N = 2e5 + 50;
int t;

int main()
{
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        stack<char> sta;
        for (int i = 0; i < s.size();i++){
            if(sta.size()&&sta.top()=='A'&&s[i]=='B'){
                sta.pop();
                continue;
            }
            else
                sta.push(s[i]);
        }
        string s2;
        while(sta.size()){
            s2.push_back(sta.top());
            sta.pop();
        }

        reverse(s2.begin(), s2.end());
        for (int i = 0; i < s2.size();i++){
            if(sta.size()&&sta.top()=='B'&&s2[i]=='B'){
                sta.pop();
                continue;
            }
            else
                sta.push(s2[i]);
        }
        cout << sta.size() << endl;
    }
}