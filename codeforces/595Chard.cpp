#include "iostream"
#include "cmath"
using namespace std;

int q;
long long n;

int main()
{

    cin >> q;

    while(q--){
        
        cin >> n;
        long long  t = n;
        long long sum = 0;
        for (int i = 18; i >= 0;i--)
        {
            if(t<=pow(3,i)/2&&t>pow(3,i-1))
            while(t<0){
                int h = 1;
                t -= pow(3, i - h);

            }
            else if(t>pow(3,i)/2&&t<pow(3,i+1))
                cout << pow(3, i);
        }
    }

}