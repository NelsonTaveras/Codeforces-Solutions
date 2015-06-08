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
#include <cctype>
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
#define in cin
#define out cout
const int MAXN = 5005;

llong ans[1000005];

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt","r",stdin);
    int N;
    cin >> N;
    vector<pair<llong, int> > V;
    for(int i = 0; i < N; ++i){
        llong v;
        cin >> v;
        V.push_back(mp(v, i));
    }
    sort(V.begin(), V.end());
    llong cur = V[0].first;
    for(int i = 0; i < N; ++i){
        cur = max(cur, V[i].first);
        ans[V[i].second] = cur;
        cur++;
    }
    for(int i = 0; i < N; ++i)
        cout << ans[i] << ' ';
    return 0;
}