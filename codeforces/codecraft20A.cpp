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

const int N = 1e3 + 40;

int t;

int n, m;
int s[N];
int main()
{
    cin >> t;

    while (t--) {

        cin >> n >> m;
        int sum = 0;
        for (int i = 1; i <= n;i++)
        {
            int x;
            cin >> x;
            sum += x;
            s[i] = x;
        }

        if(m>sum)
        {
            cout << sum << endl;
        }
        else
        {
            cout << m << endl;
        }
    }
}