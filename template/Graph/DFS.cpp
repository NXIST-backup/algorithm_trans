#include "iostream"

using namespace std;

const int N = 10;

int n;
int path[N];

bool st[N];
int cnt = 0;
void dfs(int u)
{
    if (u == 9) {
        cnt++;
    }
    for (int i = 1; i <= n; i++)
        if (!st[i]) {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false; //保存现场
        }
}
int main()
{
    cin >> n;
    dfs(0);
    cout << cnt << endl;
}