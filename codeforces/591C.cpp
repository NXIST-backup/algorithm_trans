#include "iostream"
#include "algorithm"
using namespace std;
int cmp( const int &a, const int &b ){
    if( a > b )
        return 1;
    else
        return 0;
}
int q;
int n;
int x, y;
int a, b;
int k;
int tik[200050];

int main()
{
    cin >> q;
    while(q--){
        cin >> n;
        for (int i = 0; i < n;i++)
            {
                cin >> tik[i];
                tik[i] /= 100;
            }
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;
        int sum = 0;
        int i = 0;
        int t[100];
        sort(tik,tik+n,cmp);
        while(a<=n||b<=n){
            if(a>b)
            {
                t[i++] = b;
                b *= 2;
            }
            else
            {
                t[i++] = a;
                a *= 2;
            }
        }
        for (int j = 0; j < i;j++)
            cout << t[j] << " ";
    }
}