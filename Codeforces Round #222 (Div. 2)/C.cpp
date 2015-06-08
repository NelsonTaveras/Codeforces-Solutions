#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <ctime>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <bitset>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef pair<int, int> PI;
typedef pair<int, PI> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (llong) 1e6 + 10;
const int MOD = 1000000007;

int n, m, k, cc, cur;
string maze[555];
int vis[555][555];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
void dfs(int i, int j) {
    if (vis[i][j] != -1)
        return;
    vis[i][j] = cur++;  
    for (int k = 0; k < 4; ++k) {
        int ni = i + dr[k];
        int nj = j + dc[k];
        if (ni >= 0 && nj >= 0 && ni < n && nj < m && maze[ni][nj] == '.')
            dfs(ni, nj);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> maze[i];
        cc += count(maze[i].begin(), maze[i].end(), '.');
    }
    memset(vis, -1, sizeof(vis));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(maze[i][j] == '.')
                dfs(i, j);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char c = maze[i][j];
            if(c == '#')
                cout << c;
            else{
                cout << (vis[i][j] < cc - k ? '.' : 'X');
            }
        }
        cout << endl;
    }
    return 0;
}
