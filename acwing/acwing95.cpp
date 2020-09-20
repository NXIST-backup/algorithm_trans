//!失败品

// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <queue>
// #include <map>
// #include <unordered_map>
// #include <cmath>
// #include <cstdio>
// #include <vector>

// using namespace std;

// typedef long long ll;
// typedef unsigned long long ull;
// const int INF = 1e9;
// typedef pair<int,int> pii;
// const int N = 7;
// int n;
// bool g[N][N];
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};
// int res = 0;
// int flag = 1;
// vector<int> ans;
// void baoli(){
//     for (int i = 1; i <= 5;i++){
//         for (int j = 1; j <= 5;j++){
//             if(g[i][j]==0){
//                 if(res>6)
//                     return;
//                 g[i][j] = 1;
//                 res++;
//                 for (int k = 0; k < 4;k++){
//                     if(g[i+dx[k]][j+dy[k]]==1)
//                         g[i + dx[k]][j + dy[k]] = 0;
//                     else
//                         g[i + dx[k]][j + dy[k]] = 1;
//                 }
//                 baoli();
//                 g[i][j] = 0;
//                 res--;
//                 for (int k = 0; k < 4;k++){
//                     if(g[i+dx[k]][j+dy[k]]==1)
//                         g[i + dx[k]][j + dy[k]] = 0;
//                     else
//                         g[i + dx[k]][j + dy[k]] = 1;
//                 }
//             }
//         }
//     }
//     for (int i = 1; i <= 5;i++)
//         for (int j = 1; j <= 5;j++){
//             if(g[i][j]==0)
//                 flag = 0;
//         }
//     if(flag)
//         ans.push_back(res);
//     flag = 1;
// }
// int main()
// {
//     cin >> n;

//     while (n--) {
//         string st[5];
//         for (int i = 0; i < 5;i++) {
//             cin >> st[i];
//         }

//         for (int i = 1; i <= 5;i++){
//             for (int j = 1; j <= 5;j++){
//                 int temp = st[i-1][j-1] - '0';
//                 g[i][j] = temp;
//             }
//         }
//         ans.clear();
//         res = 0;
//         baoli();
//         int srrr=1e9+50;
//         for(auto item:ans){
//             srrr = min(item, srrr);
//         }
//         if(srrr!=1e9+50)
//             cout << srrr << endl;
//         else
//             cout << -1 << endl;
//     }
// }


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

const int N = 6;

char g[N][N], backup[N][N];
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};

void turn(int x, int y)
{
    for (int i = 0; i < 5; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5) continue;   // 在边界外，直接忽略即可
        g[a][b] ^= 1;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        for (int i = 0; i < 5; i ++ ) cin >> g[i];

        int res = 10;
        for (int op = 0; op < 32; op ++ )
        {
            memcpy(backup, g, sizeof g);
            int step = 0;
            for (int i = 0; i < 5; i ++ )
                if (op >> i & 1)
                {
                    step ++ ;
                    turn(0, i);
                }

            for (int i = 0; i < 4; i ++ )
                for (int j = 0; j < 5; j ++ )
                    if (g[i][j] == '0')
                    {
                        step ++ ;
                        turn(i + 1, j);
                    }

            bool dark = false;
            for (int i = 0; i < 5; i ++ )
                if (g[4][i] == '0')
                {
                    dark = true;
                    break;
                }

            if (!dark) res = min(res, step);
            memcpy(g, backup, sizeof g);
        }

        if (res > 6) res = -1;

        cout << res << endl;
    }

    return 0;
}
