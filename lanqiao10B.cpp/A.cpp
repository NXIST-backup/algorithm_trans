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
    for (int i = 2020;;i++){
        int t = (i * i - 2019 * 2019);
        int y = sqrt(i*i + t);
        if(y*y-i*i!=t)
            continue;
        else{
            cout << i + y << endl;
            break;
        }
    }
}