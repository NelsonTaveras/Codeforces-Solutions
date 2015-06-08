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
const int INF = (int) 1e9;
set<int> arr[100005];
int color[100005];
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
        cin >> color[i];
    for(int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(color[u] == color[v])
            continue;
        arr[color[u]].insert(color[v]);
        arr[color[v]].insert(color[u]);
    }
    int best = -1;
    int ANS = 10000000;
    for(int i = 0; i < N; ++i)
        if((int) arr[color[i]].size() > best || ((int) arr[color[i]].size() == best && color[i] < ANS)){
            best = arr[color[i]].size();
            ANS = color[i];
        }
    cout << ANS;
    return 0;
}   
