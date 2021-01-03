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

        int a, b;

        cin >> a >> b;

        if(a>b)
        {
            if((a-b)%2==0)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
        else if(a<b)
        {
            if((a-b)%2)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
        else
            cout << 0 << endl;
    }
}