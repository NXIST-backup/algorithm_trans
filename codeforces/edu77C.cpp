//greedy
//

#include "iostream"
#include <algorithm>

using namespace std;
typedef long long ll;
int t;





int main()
{
    cin >> t;

    while (t--) {
        ll r, b, k;
        cin >> r >> b >> k;

        ll gcd = __gcd(r, b);
        if(r>b)
            swap(r, b);
        r /= gcd, b /= gcd;
        if(b<r*(k-1)+2)
            cout << "OBEY" << endl;
        else
            cout << "REBEl" << endl;
    }
}