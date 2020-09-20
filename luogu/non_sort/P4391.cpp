#include "iostream"
using namespace std;
const int N = 1111111;
char s[N];
int ne[N];
int n;

int main()
{
    cin >> n;
    cin >> (s + 1);
    for (int i = 2,j=0; i <= n;i++)
    {
        while(j&&s[i]!=s[j+1]){
            j = ne[j];
        }
        if(s[i]==s[j+1])
            j++;
        ne[i] = j;
    }
    cout << n - ne[n];
}