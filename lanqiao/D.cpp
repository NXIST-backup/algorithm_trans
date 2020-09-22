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

queue<int> q[5];
void init(int n)
{
    for (int i = n; i <= 4;i++) {
        while(!q[i].empty())
            q[i].pop();
        q[i].push(1);
    }
}


int main()
{
    int n = 1000;
    for (int i = 0; i <= 4;i++) {
        q[i].push(1);
    }
    for (int i = 1; i <= 4;i++) {
        q[i].push(1);
    }
    ll ans = 0;

    while (n--){
        string s;
        char c;
        c=getchar();
        while(c!='\n'){
            s.push_back(c);
            c = getchar();
        }
        cout << s << endl;
        int zero = 0;
        for (int i = 0; i < s.size();i++){
            if(s[i]!=' '){
                if(s[i]=='R'){
                    init(zero / 4 + 1);
                    int temp = q[zero / 4].front() * (s[s.size() - 2]-'0');
                    q[zero / 4 + 1].pop();
                    q[zero / 4 + 1].push(temp);
                }
                else{
                    ans += (s.back() - '0') * q[zero / 4].front();
                }
                break;
            }   
            else
                zero++;
        }
        cout << ans << endl;
    }
    
}