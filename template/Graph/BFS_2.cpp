//这题求最少步数
//可以把网格状态抽象成图中的一个点
//这样就是求图中一点到另一点的最短路
//!难点:
//!一、状态表示复杂：
//!    1.怎么把状态存到队列里面
//!    2.如何来记录每一个状态的距离 dist数组
//!    1.用字符串来表示状态——>queue<string>
//!    2.用哈希表来存dist——>unorder_map<string,int>
//!二、怎么做状态转移:
//!    1.恢复状态
//!    2.移动
//!    3.再变回字符串

#include "algorithm"
#include "iostream"
#include "queue"
#include "unordered_map"


using namespace std;

int bfs(string start)
{
    string end = "12345678x";

    queue<string> q;
    unordered_map<string, int> d;

    q.push(start);
    d[start] = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (q.size()) {
        auto t = q.front();
        q.pop();
        int distance = d[t];
        if (t == end)
            return distance;
        //状态转移

        int k = t.find('x');
        int x = k / 3, y = k % 3;

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                swap(t[k], t[a * 3 + b]);
                if (!d.count(t)) {
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[k], t[a * 3 + b]); //!存完或没存继续恢复原来状态迎接下一个队列元素
            }
        }
    }
}

int main()
{
    string start;

    for (int i = 0; i < 9; i++) {
        char c;
        cin >> c;
        start += c;
    }
    cout << bfs(start) << endl;
}