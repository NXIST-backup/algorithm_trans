/*
  Problem Name: String Equality
  algorithm tag:
*/

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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

int main()
{
    int t;
    cin >> t;
    int jishu = 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a == b) {
            cout << "YES" << endl;
            continue;
        }
        bool flag = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                flag = 0;
                break;
            } else if (a[i] == b[i])
                continue;
            else {
                int j;
                for (j = i + 1; j < i + k; j++) {
                    if(a[j]!=a[j-1]||b[j]!=b[j-1]){
                        flag = 0;
                        break;
                    }
                    if(a[j]>=b[j]){
                        flag = 0;
                        break;
                    }
                }
                if(!flag)
                    break;
                i = j - 1;
            }
        }

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}