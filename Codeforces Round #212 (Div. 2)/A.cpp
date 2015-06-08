#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIIP;
typedef pair<PII, char> PIC;
typedef pair<int, char> PICD;
const int INF = (int) 2e9;
const int MAXN = 1000010;
const int MAXSTEP = 10;
int dr[] = {2, 2, -2, -2};
int dc[] = {2, -2, 2, -2};
vector<string> GRID;
bool in(int x, int y)
{
    return (x >= 0 && y >= 0 && x < 8 && y < 8);
}
int memo[8][8][8][8][101];
int dp(int x1, int y1, int x2, int y2, int step)
{
    if(!in(x1, y1)) return 0;
    if(!in(x2, y2)) return 0;
    if(step > 100) return 0;
    if(x1 == x2 && y1 == y2 && GRID[x1][y1] == '.') return 1;
    if(memo[x1][y1][x2][y2][step] != -1) return memo[x1][y1][x2][y2][step];
    int aux = 0;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            aux = max(aux, dp(x1 + dr[i], y1 + dc[i], x2 + dr[j], y2 + dc[j], step + 1));
    return memo[x1][y1][x2][y2][step] = aux;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--)
    {
        GRID = vector<string>(8);
        for(int i = 0; i < 8; ++i)
            cin >> GRID[i];
        PII src, dst;
        int cur = 0;
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j){
                if(GRID[i][j] == 'K'){
                    if(cur == 0)
                        src = PII(i, j);
                    else
                        dst = PII(i, j);
                    GRID[i][j] = '.';
                    cur++;
                }
            }
        memset(memo, -1, sizeof(memo));
        int f = dp(src.first, src.second, dst.first, dst.second, 0);
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
