#include "iostream"


#include "iostream"
#include "cstring"

using namespace std;


int n;
int a[150];


int main()
{
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n;i++)
        cin >> a[i], sum += a[i];
    int cnt = 0;
    int mid = sum / n;

    for (int i = 0; i < n;i++)
    {
        if(a[i]<mid)
        {
            a[i + 1] -= mid - a[i];
            a[i] = mid;
            cnt++;
        }
        else if(a[i]>mid)
        {
            a[i + 1] += a[i] - mid;
            a[i] = mid;
            cnt++;
        }
    }

    cout << cnt << endl;
}
