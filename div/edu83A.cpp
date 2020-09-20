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

int n, m;

int main()
{
    cin >> t;

    while (t--) {

        cin >> n >> m;

        if(n%m==0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
