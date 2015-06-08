#include <cmath>
#include <ctime>
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
typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef pair<int, int> PI;
typedef pair<int, PI> PII;

VII adj;
int x[1000];
int y[1000];
int vis[1000];

void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        if(!vis[v])
        {
            vis[v] = 1;
            dfs(v);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    adj = VII(N);
    int cur = 0;
    while(N--)
    {
        int t, xx, yy;
        cin >> t >> xx >> yy;

        if( t == 1 )
        {
            // add xx,yy
            x[cur] = xx;
            y[cur] = yy;
            for(int i = 0; i < cur; ++i)
            {
                int a = xx;
                int b = yy;
                int c = x[i];
                int d = y[i];
                if( (c<a&&a<d) || (c<b&&b<d) )
                {
                    //cout << a<<","<<b << " -- > " << c<<","<<d << endl;
                    adj[cur].push_back(i);
                }

                swap(a, c);
                swap(b, d);
                if( (c<a&&a<d) || (c<b&&b<d) )
                {
                    //cout << a<<","<<b << " -- > " << c<<","<<d << endl;
                    adj[i].push_back(cur);
                }
            }
            cur++;
        }
        else
        {
            xx--, yy--;
            memset(vis, 0,sizeof(vis));
            dfs(xx);
            cout << (vis[yy] ? "YES" :"NO") << endl;

        }
    }
    return 0;
}
