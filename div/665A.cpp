#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stdlib.h>
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
int n, k;

int main()
{
    cin >> t;

    while (t--) {
        cin >> n >> k;

        if(n>=k){
            if((n-k)%2==0)
                cout << 0 << endl;
            else {
                cout << 1 << endl;
            }
        }
        else {
            cout << abs(k - n) << endl;
        }
    }
}