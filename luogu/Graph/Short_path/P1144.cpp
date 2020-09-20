#include "iostream"
#include "algorithm"
#include "cstring"
#include "queue"
#include <queue>

using namespace std;

const int N = 1e6 + 50;

int n, m;
int h[N], e[N], ne[N], idx;
int st[N];
int cnt[N];

void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void bfs()
{
    queue<int> q;

    q.push(1);
    memset(st, -1, sizeof st);

    st[1] = 0;
    cnt[1] = 1;
    while (q.size()) {

        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1;i=ne[i])
        {
            int j = e[i];

            if(st[j]==-1)
            {
                cnt[j]++;
                st[j] = st[t] + 1;
                q.push(j);
            }
            else if(st[t]+1==st[j])
            {
                cnt[j]++;
            }
        }
    }
}




int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= m;i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    bfs();

    // for (int i = h[4]; i != -1;i=ne[i])
    // {
    //     cout << e[i] << endl;
    // }


    for (int i = 1; i <= n;i++)
        cout << cnt[i] << endl;
}