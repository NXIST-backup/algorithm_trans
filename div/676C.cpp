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
// abcdefghidjklkjd
string s;

int main()
{
    cin >> s;
    int len = s.size();
    cout << 3 << endl;
    cout << "R " << len - 1 << endl;
    len += 1;
    cout << "L " << len - 1 << endl;
    cout << "L " << 2 << endl;
}