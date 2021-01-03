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

int t;

int main()
{
    cin >> t;

    while (t--) {

        ll n, k;
        cin >> n >> k;

        if(k*k>n)
            cout << "NO" << endl;
        else
        {
            int s = k * k;
            if(n%2==0)
            {
                
                if(k%2)
                    cout << "NO" << endl;
                else if((n-s)%2==0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else
            {
                if((n-s)%2==0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
}