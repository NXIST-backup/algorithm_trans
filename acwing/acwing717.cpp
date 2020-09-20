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

const int N = 50;
int n;

int main()
{
    cin >> n;
    ll a=0, b=1, c;

    if(n==1)
        cout << a << endl;
    else if(n==2)
        cout << a << " " << b << endl;
    else{
        cout << 0 << " " << 1 << " ";
        bool flag = 0;
        for (int i = 2; i < n;i++){
            c = b;
            b = a + b;
            a = c;
            cout << b << " ";
        }
        cout << endl;
    }
}