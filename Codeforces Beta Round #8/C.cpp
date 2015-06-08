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

using namespace std;

#define mp make_pair
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
const int INF = 1e9;
int x[25];
int y[25];
int d[25][25];
int hx, hy, N;
int memo[1<<24];
PII act[1<<24];
inline int dist(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int doitpls(int mask)
{
    if(mask == 0)
        return 0;
    if(memo[mask] != -1)
        return memo[mask];
    int ret = INF;
    for(int i = 0; i < N; ++i)
    {
        if( mask & (1<<i) )
        {
            int w = 2 * d[i + 1][0] + doitpls(mask ^ (1<<i));
            if( w < ret ){
                ret = w;
                act[mask] = PII(i, -1);
            }
            for(int j = 0; j < N; ++j)
                if( i != j && mask & (1<<j) ){
                    int w2 = d[i + 1][0] + d[i + 1][j + 1] + d[j + 1][0] + doitpls(mask ^ (1<<i) ^ (1<<j));
                    if(w2 < ret ){
                        ret = w2;
                        act[mask] = PII(i, j);
                    }
                }
            break;
        }
    }
    return memo[mask] = ret;
}
void go(int mask)
{
    int times = 0;
    while(mask)
    {
        if(times)
            cout << 0 << ' ';
        PII choice = act[mask];
        int i = choice.first;
        int j = choice.second;
        if( mask & (1<<i) )
            mask ^= (1<<i);
        if(j >= 0)
            if(mask & (1<<j))
                mask ^= (1<<j);
        cout << i + 1 << ' ';
        if(j >= 0)
            cout << j + 1 << ' ';
        times++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> hx >> hy >> N;
    for(int i = 0; i < N; ++i){
        cin >> x[i] >> y[i];
        d[i + 1][0] = dist(hx, hy, x[i], y[i]);
    }
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            d[i][j] = dist(x[i - 1], y[i - 1], x[j - 1], y[j - 1]);
    memset(memo, -1, sizeof(memo));
    cout << doitpls((1<<N) - 1) << endl;
    cout << 0 << ' '; go((1<<N) - 1); cout << 0;
    return 0;
}