//f(s)=(number of all sub-string)-(number of sub-strings that doesn't have any symbol equals to '1')



#include "iostream"

using namespace std;

int t;
typedef unsigned long long ull;
ull n, m;

int main()
{
    cin >> t;

    while (t--) {

        cin >> n >> m;

        ull sum = (n * (n + 1)) / 2;
        ull n0 = (n - m) / (m + 1);
        ull n1 = (n - m) % (m + 1);

        ull ans = sum - n1 * (n0 + 1) * (n0 + 2) / 2 - (m + 1 - n1) * (n0) * (n0 + 1) / 2;
        cout << ans << endl;
    }
}