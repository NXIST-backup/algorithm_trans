#include "iostream"
#include "vector"
using namespace std;


long long  q, n, k;

string b;

int main()
{
    cin >> q;
    while(q--){
        cin >> n >> k;
        vector<int> mem;
        cin >> b;
        for (int i = 0; i < n;i++)
        {
            if(b[i]=='0')
            {
                mem.push_back(i);
            }
        }
        int idx = 0;
        int idx0 = 0;
        // for(auto item:mem)
        // {
        //     cout << item << " ";
        // }
        // cout << endl;
        while(k>0&&idx<mem.size()){

            if(k>=mem[idx]-idx)
            {
                k -= mem[idx]-idx;
                //cout << idx0 << " " << mem[idx] << " "<< k << endl;
                swap(b[idx0++], b[mem[idx++]]);
            }
            else
            {
                //cout << mem[idx] - k+idx << "*" << mem[idx]<<endl;
                swap(b[mem[idx] - k], b[mem[idx]]);
                k = 0;
            }
        }
        for (int i = 0; i < n;i++)
            cout << b[i];
        cout << endl;
    }
}