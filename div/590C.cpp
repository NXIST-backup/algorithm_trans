#include "iostream"

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		string s[2];
		cin >> n >> s[0] >> s[1];
		int row = 0;
		int pos = 0;
		for (pos = 0; pos < n; ++pos) {
			if (s[row][pos] >= '3') {
				if (s[row ^ 1][pos] < '3') {
					break;
				} else {
					row ^= 1;
				}
			}
		}
		if (pos == n && row == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}