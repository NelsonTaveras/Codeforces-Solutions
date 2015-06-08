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

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;
#define MOD (llong)  100999

int dr[] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};
bool in(int x, int y)
{
    return (x >= 0 && y >= 0 && x < 8 && y < 8);
}
int bfs(PII src, PII dst)
{
    queue<PII> Q;
    Q.push(src);
    map<PII, int> dist;
    dist[src] = 0;
    while(!Q.empty())
    {
        PII cur = Q.front();
        Q.pop();
        if(cur == dst) break;
        for(int i = 0; i < 8; ++i){
            PII np = cur;
            np.first += dr[i];
            np.second += dc[i];
            if(in(np.first, np.second) && dist.count(np) == 0){
                Q.push(np);
                dist[np] = dist[cur] + 1;
            }
        }
    }
   return dist.count(dst) ? dist[dst] : INF;
}
int bfs2(PII src, PII dst)
{
    queue<PII> Q;
    Q.push(src);
    map<PII, int> dist;
    dist[src] = 0;
    while(!Q.empty())
    {
        PII cur = Q.front();
        Q.pop();
        if(cur == dst) break;
        for(int k = 1; k <= 8; ++k)
        {
            for(int i = 4; i < 8; ++i){
                PII np = cur;
                np.first += k*dr[i];
                np.second += k*dc[i];
                if(in(np.first, np.second) && dist.count(np) == 0){
                    Q.push(np);
                    dist[np] = dist[cur] + 1;
                }
            }
        }
    }
   return dist.count(dst) ? dist[dst] : INF;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    int rook = 0, bishop = 0, king = 0;
    // rook
    if(r1 == r2 || c1 == c2) rook = 1;
    else rook = 2;
    PII src(r1, c1);
    PII dst(r2, c2);
    king = bfs(src, dst);
    bishop = bfs2(src, dst);
    if(king == INF) king = 0;
    if(bishop == INF) bishop = 0;
    cout << rook << ' ' << bishop << ' ' << king << endl;
    return 0;
}
