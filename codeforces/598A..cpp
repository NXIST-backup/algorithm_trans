#include "iostream"
using namespace std;

int q;
int a, b, n, s;


int main()
{
    cin >> q;
    while(q--){

        cin >> a >> b >> n >> s;
        
        if(s/n<=a)
            s %= n;
        else
        {
            s -= a * n;
        }
        if(s>b)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}