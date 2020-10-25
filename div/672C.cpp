#include <iostream>
#include <vector>

using namespace std;

inline int64_t calc(const vector<int> &a) {
	int n = a.size();
	vector<int64_t> d1(n+1), d2(n+1);
	d1[0] = -static_cast<int64_t>(1e18);
	d2[0] = 0;
	for (int i = 0; i < n; ++i) {
		d1[i+1] = max(d1[i], d2[i] + a[i]);
		d2[i+1] = max(d2[i], d1[i] - a[i]);
	}
	return max(d1.back(), d2.back());
}

int main() {
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		cout << calc(a) << "\n";
		for (int i = 0; i < q; ++i) {
			int l, r; cin >> l >> r; --l; --r;
			swap(a[l], a[r]);
			cout << calc(a) << "\n";
		}
	}
	return 0;
}