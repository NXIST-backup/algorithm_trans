#include "iostream"
using namespace std;
int q;
int main()
{
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        if(x==2)
            cout << 2 << endl;
        else if (x%2) {
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
    }
}