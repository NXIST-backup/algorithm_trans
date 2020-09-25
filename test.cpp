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

int add(int x)
{
    int Bit = 0;
    while (x) {
        x >>= 1;
        Bit++;
    }
    return Bit;
}
int main()
{
    int a = 4;
    cout << add(a) << endl;
}