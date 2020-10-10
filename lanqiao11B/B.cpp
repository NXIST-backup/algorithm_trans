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

int main()
{
    int run = 0;
    int nor = 0;
    for (int i = 1922; i <= 2021; i++) {
        if((i%4==0&&i%100!=0)||i%400==0)
            run++;
        else
            nor++;
    }

    cout << run * 366 + nor * 365 - 22 << endl;

    cout << 36868 * 24 * 60 << endl;
}
