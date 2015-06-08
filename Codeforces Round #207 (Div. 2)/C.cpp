#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <ctime>

using namespace std;

#define MAXN (int) 100005
#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;

int ans[1000009];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    set<int> left;
    for(int i = 1; i <= n; ++i) left.insert(i);
    for(int i = 0; i < m; ++i)
    {
        //4 6 7
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        set<int>::iterator low = left.lower_bound(l);
        VI del;
        for(set<int>::iterator it = low; it != left.end(); it++)
        {
            int val = *it;
            if(val > r) break;
            if(val == x) continue;
            del.push_back(val);
            ans[val] = x;
        }
        for(int i = 0; i < del.size(); ++i)
            left.erase(del[i]);
    }
    for(int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
}