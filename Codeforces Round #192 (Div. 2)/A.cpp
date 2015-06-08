#include <cmath>
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
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<int, PI> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

int mat[15][15];

int main()
{
    ios_base::sync_with_stdio(false);
    int R, C;
    cin >> R >> C;
    vector<string> V(R);
    for(int i = 0; i < R; ++i)
        cin >> V[i];
    int cnt = 0;
    for(int i = 0; i < R; ++i)
    {
        if(V[i].find('S') == string::npos)
        {
            for(int j = 0; j < C; ++j)
                mat[i][j] = 1;
        }
    }
    for(int i = 0; i < C; ++i)
    {
        bool saw = true;
        for(int j = 0; j < R && saw; ++j)
            if(V[j][i] == 'S')
                saw = false;
        if(saw)
            for(int j = 0; j < R; ++j)
                mat[j][i] = 1;
    }
    for(int i = 0; i < R; ++i)
    {
        for(int j = 0; j < C; ++j)
            cnt += mat[i][j];
    }
    cout << cnt;
    return 0;
}
