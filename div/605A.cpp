#include "iostream"
#include "cmath"
using namespace std;

int q;


int main()
{
    cin >> q;

    while (q--) {
        int a, b, c;

        cin >> a >> b >> c;

        if(b>a)
            swap(b, a);
        if(c>a)
            swap(c, a);
        if(c>b)
            swap(c, b);
        int mid = (a + c) / 2;
        if(b>mid)
            b--;
        if(b<mid)
            b++;
        if(a>b)
        {
            a--;
        }
        if(c<b)
            c++;
        cout << a << b << c << endl;
        int ans = abs(a - b) + abs(a - c) + abs(b - c);

        cout << ans << endl;
    }
}