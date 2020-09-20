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

string s;
string cpr;

bool check()
{
    bool flag = 0;
    for (int i = 0; i < s.size();i++){
        if(s[i]!=cpr[i])
            return flag=1;
    }
    return flag;
}
void turn_on(int x)
{
    if(s[x]=='*')
        s[x] = 'o';
    else
        s[x] = '*';
}
int main()
{
    cin >> s;
    cin >> cpr;
    int res = 0;
    while (check()) {
        for (int i = 0; i < s.size();i++){
            if(s[i]!=cpr[i]){
                if(i!=s.size()-1)
                    turn_on(i),turn_on(i+1);
                else
                    turn_on(i), turn_on(i - 1);
                res++;
            }
        }
    }

    cout << res << endl;
}