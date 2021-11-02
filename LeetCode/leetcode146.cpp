/*
  Problem Name:
  algorithm tag:
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

class LRUCache
{
  public:
    struct Node
    {
        int key;
        int val;
        int last;
        int next;
    } node[3005];
    map<int, int> mp;
    int size, length, head, tail, idx;
    LRUCache(int capacity)
    {
        length = 0;
        size = capacity;
        tail = head = -1;
        idx = 0;
        memset(node, 0, sizeof node);
    }
    void update(int key)
    {
        int last = node[mp[key]].last;
        int next = node[mp[key]].next;
        //3,2,-1
        //2,-1,1
        if (last != -1)
            node[last].next = next;

        if (next != -1)
            node[next].last = last;
        else if (last != -1)
            tail = last;

        node[mp[key]].next = head;
        node[head].last = mp[key];
        node[mp[key]].last = -1;
        head = mp[key];
    }
    int get(int key)
    {
        if (!mp[key])
            return -1;
        update(key);
        return node[mp[key]].val;
    }

    void put(int key, int value)
    {
        if (mp[key]) {
            node[mp[key]].val = value;
            update(key);
        } else {
            if (length >= size) {
                int last = node[tail].last;
                if (last != -1)
                    node[last].next = -1;
                mp[node[tail].key] = 0;
                tail = last;
                length--;
            }
            node[++idx] = {key, value, -1, head};
            if (!length) {
                tail = head = idx;
                mp[key] = idx;
                length++;
                return;
            }
            mp[key] = idx;
            node[head].last = idx;
            head = idx;
            length++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache *obj = new LRUCache(2);
    obj->put(2, 1);
    obj->put(3, 2);
    cout << obj->get(3) << endl;
    cout << obj->get(2) << endl;
    obj->put(4, 3);
    cout << obj->get(2) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
    // obj->put(10, 5);
}