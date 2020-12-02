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
//bf
const int N = 20;
int a[N][N];
int n, m;
vector<int> lis1,lis2;
int ans;
int res;
void dfs(int depth,int sum)
{
    if(depth==n){
        res += a[depth][m - sum];
        lis2.push_back(m-sum);
        if(res>ans){
            ans = res;
            lis1 = lis2;
        }
        lis2.pop_back();
        res -= a[depth][m - sum];
        return;
    }
    for (int i = 0; i <= m-sum;i++){
        res += a[depth][i];
        sum += i;
        lis2.push_back(i);
        dfs(depth + 1, sum);
        res -= a[depth][i];
        sum -= i;
        lis2.pop_back();
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++)
            cin >> a[i][j];
    }

    dfs(1, 0);

    cout << ans << endl;

    for (int i = 0; i < lis1.size();i++){
        cout << i + 1 << " " << lis1[i] << endl;
    }
}