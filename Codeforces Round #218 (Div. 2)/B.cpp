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
const int MAXN = 5005;

map<PII, int> memo;
int dp(int a, int b)
{
    if(a == b) return 0;
    if(memo.count(mp(a, b))) return memo[mp(a,b)];
    int aux = INF;
    if(a % 2 == 0) aux = min(aux, 1 + dp(a / 2, b));
    if(b % 2 == 0) aux = min(aux, 1 + dp(a, b / 2));
    if(a % 3 == 0) aux = min(aux, 1 + dp(a / 3, b));
    if(b % 3 == 0) aux = min(aux, 1 + dp(a, b / 3));
    if(a % 5 == 0) aux = min(aux, 1 + dp(a / 5, b));
    if(b % 5 == 0) aux = min(aux, 1 + dp(a, b / 5));
    return memo[mp(a, b)] = aux;
}

int main()
{
    // freopen("input.txt", "r", stdin);    
    int a, b;
    cin >> a >> b;
    int aux = dp(a, b);
    cout << (aux == INF? -1 : aux) << endl;
    return 0;
}