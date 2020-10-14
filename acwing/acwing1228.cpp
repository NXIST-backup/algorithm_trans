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

const int N = 10010;

int n;
struct Segment
{
    int x,y1,y2;
    int k;
    bool operator< (const Segment &t)const{
        return x < t.x;
    }
} seg[N * 2];
struct Node
{
    int l,r;
    int cnt, len;
} tr[N * 4];

int main()
{
    cin>>n;

    int m = 0;

}
