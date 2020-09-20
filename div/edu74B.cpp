#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
int q;
vector<int> x;
int main()
{
    cin >> q;
    while(q--){
        int n, r;
        cin >> n >> r;
        for (int i = 0; i < n;i++)
        {
            int temp;
            cin >> temp;
            x.push_back(temp);
        }
        sort(x.begin(),x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        n = x.size();
        int cnt = 0;
        int st = 0;
        for(auto item:x)
            cout << item << " ";
        cout << endl;
        while(st<=n)
        {
            x.pop_back();
            n--;
            cnt++;
            for (int i = st; i < x.size();i++)
            {
                x[i] -= r;
            }
            for (int i = 0; i < x.size();i++)
            {
                if(x[i]<=0)
                    st++;
            }
        }
        cout << cnt << endl;
    }
}