#include "iostream"
#include "vector"
using namespace std;

int n, t;
const int N = 100050;
int a[N], b[N];

int main()
{
    cin >> t;
    while (t -- ){
        cin >> n;
        for (int i = 1; i <= n; i ++ )
            cin >> a[i];
        for (int i = 1; i <= n; i ++ ){
            cin >> b[i];
            b[i] -= a[i];
        }
        vector<int> c;
        bool flag1 = true;
        int pos1 = 0, pos2 = 0;
        for (int i = 1; i <= n; i ++ ){
            if (b[i] < 0){
                flag1 = false;
                break;
            }
        }
        if (!flag1){
            cout << "NO\n";
            continue;
        }
        for (int i = 1; i <= n; i ++ ){
            if (b[i] != 0){
                pos1 = i;
                break;
            }
        }
        for (int i = n; i >= 1; i -- ){
            if (b[i] != 0){
                pos2 = i;
                break;
            }
        }
        for (int i = pos1; i <= pos2; i ++ )
            c.push_back(b[i]);
        bool flag2 = true;
        for (int i = 0; i < c.size() - 1; i ++ ){
            if (c[i] != c[i + 1]){
                flag2 = false;
                break;
            }
        }
        if (!flag2){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}