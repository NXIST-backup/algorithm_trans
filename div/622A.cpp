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


int main()
{
    cin >> t;

    while (t--) {

        int a, b, c;

        cin >> a >> b >> c;

        if(a>=4&&b>=4&&c>=4)
            cout << 7 << endl;

        else
        {
            int sum = 0;
            if(a<b)
                swap(a, b);
            if(a<c)
                swap(a, c);
            if(a>0)
                sum += 1, a -= 1;
            if(b>0)
                sum += 1, b -= 1;
            if(c>0)
                sum += 1, c -= 1;
            if(a>0&&b>0)
                sum += 1, a -= 1, b -= 1;
            if(a>0&&c>0)
                sum += 1, a -= 1, c -= 1;
            if(b>0&&c>0)
                sum += 1, b -= 1, c -= 1;
            cout << sum << endl;
        }
    }
}