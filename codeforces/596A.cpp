#include "iostream"
using namespace std;

int d1, d2;

int main()
{
    cin >> d1 >> d2;
    if(d1==d2)
    {
        cout << d1 << "1"
             << " " << d2 << "2";
        return 0;
    }
    if(d2-d1==1)
    {
        cout << d1 << " " << d2;
        return 0;
    }
    if(d1==9&&d2==1)
    {
        cout << d1 << " " << d2 << "0";
        return 0;
    }
    else
        cout << -1 << endl;
}
