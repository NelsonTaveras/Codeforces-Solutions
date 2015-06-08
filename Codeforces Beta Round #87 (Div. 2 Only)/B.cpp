#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <string>
#include <set>

using namespace std;

int dr[] = {1, -1, 0, 0 };
int dc[] = {0, 0, -1, 1 };
int x[1000];
int y[1000];
int vis[100][100];
int match[100][100];
vector< vector<pair<int, int> > > adj;

bool find_match(int u)
{
    for(int i = 0; i < adj[u].size(); ++i)
    {
        int vx = adj[u][i].first;
        int vy = adj[u][i].second;

        if( match[vx][vy] == -1 )
        {
            match[vx][vy] = u;
            return true;
        }
        else
        {
            if(!vis[vx][vy])
            {
                vis[vx][vy] = 1;
                if( find_match(match[vx][vy]) )
                {
                    match[vx][vy] = u;
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int r, c;
    cin >> r >> c;

    vector<string> V(r);
    for(int i = 0; i < r; ++i)
        cin >> V[i];

    int cur = 0;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if( V[i][j] == 'W' )
            {
                x[cur] = i;
                y[cur] = j;
                cur++;
            }
        }
    }

    adj = vector< vector<pair<int, int> > > (cur);
    for(int i = 0; i < cur; ++i)
    {
        int curx = x[i];
        int cury = y[i];


        for(int j = 0; j < 4; ++j)
        {
            int _x = curx + dr[j];
            int _y = cury + dc[j];

            if( _x >= 0 && _y >= 0 && _x < r && _y < c )
                if( V[_x][_y] == 'P' )
                    adj[i].push_back(make_pair(_x, _y));
        }
    }

    memset(match, -1, sizeof(match));
    int res = 0;
    for(int i = 0; i < cur; ++i)
    {
        memset(vis, 0, sizeof(vis));
        res += find_match(i);
    }

    cout << res << endl;

    return 0;
}
