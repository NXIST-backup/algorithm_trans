#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<pair<ll, ll>> v;
    ll mine = INT_MAX, sum = 0, x;
    for (int i = 0; i < n1; i++) {
        cin >> x;
        mine = min(x, mine);
        sum += x;
    }
    v.pb({mine, sum - mine});

    mine = INT_MAX, sum = 0;
    for (int i = 0; i < n2; i++) {
        cin >> x;
        mine = min(x, mine);
        sum += x;
    }
    v.pb({mine, sum - mine});

    mine = INT_MAX, sum = 0;
    for (int i = 0; i < n3; i++) {
        cin >> x;
        mine = min(x, mine);
        sum += x;
    }
    v.pb({mine, sum - mine});

    sort(v.begin(), v.end());

    vector<ll> v1;
    v1.pb(v[0].first - v[1].second - v[2].second);
    v1.pb(v[1].first - v[0].second);
    v1.pb(v[2].first);

    // sort(v1.begin(), v1.end());

    ll ans = abs(v1[0]) + abs(v1[1]) + v1[2];
    if (v1[0] > 0 && v1[1] > 0)
        ans -= (2 * v1[0]);

    cout << ans << endl;

    return 0;
}
