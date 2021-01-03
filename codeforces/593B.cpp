#include "iostream"
#include "cmath"
using namespace std;
const int N = 1e9 + 7;
int n, m;

int query_zu(int m)
{
    if(m==1)
        return 1;
    else if(m==2)
        return 2;
    int ans = 0;
    ans = query_zu(m - 1) * query_zu(m - 2) + query_zu(m - 1) + query_zu(m - 2);
    return ans%N;
}

int main()
{
    cin >> n >> m;

    cout << query_zu(m);
}