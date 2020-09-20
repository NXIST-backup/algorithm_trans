#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

int main() {

	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (int j = 0; j < n; ++j) {
			cin >> p[j];
			--p[j];
		}
		vector<int> used(n);
		vector<int> ans(n);
		for (int j = 0; j < n; ++j) {
			if (!used[j]) {
				vector<int> cur;//cycle长度
				while (!used[j]) {
					cur.push_back(j);
					used[j] = true;
					j = p[j];
				}
				for (auto el : cur) ans[el] = cur.size();
			}
		}
		for (int j = 0; j < n; ++j) cout << ans[j] << " ";
		cout << endl;
	}
	
	return 0;
}