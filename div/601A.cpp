#include "iostream"
using namespace std;
int t;

int main()
{

    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int c = a - b;
        if(c<0)
            c = c * -1;
        if(c%5)
        {
            int x = c % 5;
            if(x==4||x==3)
                cout << c / 5 + 2 << endl;
            else
                cout << c / 5 + 1 << endl;
        }
        else
            cout << c / 5 << endl;
    }
}