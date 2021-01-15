#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x, y;
map<ll, int> mp;

void bfs(ll y)
{
    queue<ll> q;
    q.push(y);

    while (q.size()) {
        ll t = q.front();
        q.pop();
        if (t % 2) {
            if (mp[t + 1])
                mp[t + 1] = min(mp[t] + 1, mp[t + 1]);
            else {
                mp[t + 1] = mp[t] + 1;
                q.push(t + 1);
            }
            if (mp[t - 1])
                mp[t - 1] = min(mp[t] + 1, mp[t - 1]);
            else {
                mp[t - 1] = mp[t] + 1;
                q.push(t - 1);
            }
        } else {
            if (mp[t >> 1])
                mp[t >> 1] = min(mp[t] + 1, mp[t >> 1]);
            else {
                mp[t >> 1] = mp[t] + 1;
                q.push(t >> 1);
            }
        }
    }
}
int main()
{
    cin >> x >> y;

    bfs(y);

    cout << mp[x] << endl;
}