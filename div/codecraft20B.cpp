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

int t;
int n;
int ks=1;
string gt(string a,int k)
{
    string s1 = a.substr(0, k);
    if((k%2&&n%2==0)||(k%2==0&&n%2))
        reverse(s1.begin(), s1.end());
    string s2 = a.substr(k, a.size());
    string s = s2 + s1;
    
    return s;
}  


int main()
{
    cin >> t;


    while (t--) {
        cin >> n;

        string a;
        ks = 1;
        cin >> a;
        int ans = a[0];
        string res = a;
        for (int i = 1; i < a.size();i++)
        {
            if(a[i]<=ans)
            {
                string temp = gt(a, i);
                if(temp<res)
                {
                    res = temp;
                    ans = res[0];
                    ks = i + 1;
                }
            }
        }
        cout << res << endl;
        cout << ks << endl;
    }
}