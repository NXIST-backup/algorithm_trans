#include "iostream"
using namespace std;

typedef long long ll;

int t;


int main()
{
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        if(x-y!=1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}