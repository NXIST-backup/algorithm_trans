#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

int t;
int n;
char g[250][250];

int main()
{
    cin >> t;

    while (t--){
        cin >> n;
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                cin >> g[i][j];
            }
        }

        vector<pii> a, b;
        a.push_back({n - 2, n});
        a.push_back({n, n - 2});
        a.push_back({n - 1, n - 1});
        b.push_back({n - 1, n});
        b.push_back({n, n - 1});

        int sum10 = 0, sum11 = 0, sum01 = 0, sum00 = 0;

        for(auto item:a){
            if(g[item.first][item.second]=='0')
                sum00++;
            else
                sum10++;
        }
        for(auto item:b){
            if(g[item.first][item.second]=='0')
                sum01++;
            else
                sum11++;
        }

        if(sum00+sum01>=5||sum10+sum11>=5){
            cout << 2 << endl;
            cout << n - 1 << " " << n << endl;
            cout << n << " " << n - 1 << endl;
            continue;
        }
        if(sum00+sum01>=4||sum10+sum11>=4){
            if(sum00>=3||sum10>=3){
                cout << 1 << endl;
                if(sum00>=3){
                    for(auto item:b){
                        if(g[item.first][item.second]=='0'){
                            cout << item.first << " " << item.second << endl;
                            break;
                        }
                    }
                }
                else{
                    for(auto item:b){
                        if(g[item.first][item.second]=='1'){
                            cout << item.first << " " << item.second << endl;
                            break;
                        }
                    }
                }
            }
            else{
                cout << 2 << endl;
                if(sum01>=2){
                    for(auto item:a){
                        if(g[item.first][item.second]=='0')
                            cout << item.first << " " << item.second << endl;
                    }
                }
                else{
                    for(auto item:a){
                        if(g[item.first][item.second]=='1')
                            cout << item.first << " " << item.second << endl;
                    }
                }
            }
            continue;
        }

        if(sum00+sum01>=3||sum11+sum10>=3){
            if(sum00==3||sum10==3){
                cout << 0 << endl;
            }
            else{
                
                if(sum00==2||sum10==2){
                    cout << 1 << endl;


                    for(auto item:a)
                        if(g[item.first][item.second]==)
                }
            }
        }
    }
}