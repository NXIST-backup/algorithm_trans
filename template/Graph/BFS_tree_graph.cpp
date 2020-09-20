#include "algorithm"
#include "cstring"
#include "iostream"
#include "queue"
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], e[N], ne[N], idx;
int st[N];
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs()
{
    queue<int> q;
    q.push(1);
    memset(st, -1, sizeof st);

    st[1] = 0;
    while (q.size()) {
        int t = q.front();
        q.pop();

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (st[j] == -1) {
                st[j] = st[t] + 1;
                q.push(j);
            }
        }
    }
    return st[n];
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
}
