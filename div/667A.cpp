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
int a, b;

int main()
{
    cin >> t;
    while (t--) {
        cin >> a >> b;

        if(a<b)
            swap(a, b);
        ll sum = 0;
        int t = a % 10;
        int t2 = b % 10;
        if(t!=t2)
            sum += 1;
        sum += (a - b) / 10;

        cout << sum << endl;
    }
}