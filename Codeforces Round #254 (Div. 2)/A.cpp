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

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<llong> VL;
typedef vector<VL> VVL;
llong INF = (1LL<<62);
const int inf = (1LL<<30);
const int maxn = (int) 1e5 + 10;
const int MOD = 1000000007;

vector<string> mat;
vector<string> tmp;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int vis[101][101];
int tmpvis[101][101];
int n, m;
bool valid;
void dfs(int x, int y, char c){
    vis[x][y] = 1;
    mat[x][y] = c;
    for(int i = 0; i < 4; ++i){
        int nx = x + dr[i];
        int ny = y + dc[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m){
            if(mat[nx][ny] == c){
                valid = false;
                return ;
            }
            if(mat[nx][ny] != '.' || vis[nx][ny]) continue;
            dfs(nx, ny, (c == 'W' ? 'B' : 'W'));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        string S;
        cin >> S;
        mat.push_back(S);
    }
    tmp = mat;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(mat[i][j] != '.' || vis[i][j]) continue;
            // before
            tmp = mat;
            for(int k = 0; k < n; ++k)
                for(int l = 0; l < m; ++l)
                    tmpvis[k][l] = vis[k][l];
            valid = true;
            dfs(i, j, 'B');
            if(!valid){
                mat = tmp;
                valid = true;
                for(int k = 0; k < n; ++k)
                    for(int l = 0; l < m; ++l)
                        vis[k][l] = tmpvis[k][l];
                dfs(i, j, 'W');
            }
        }
    }
    for(int i = 0; i < n; ++i)
        cout << mat[i] << endl;
    return 0;
}
