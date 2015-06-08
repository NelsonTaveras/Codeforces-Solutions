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

int main()
{
    // freopen("input.txt", "r", stdin);    
    string S;
    cin >> S;
    int nb, ns, nc;
    cin >> nb >> ns >> nc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    llong money;
    cin >> money;
    int bn = 0, sn = 0, cn = 0;
    for(int i = 0; i < S.size(); ++i){
        bn += (S[i] == 'B');
        sn += (S[i] == 'S');
        cn += (S[i] == 'C');
    }
    llong lo = 0, hi = 10000000000000;
    while(lo < hi)
    {
        llong mid = lo + (hi - lo + 1) / 2;
        llong bread = max(0LL, (bn * mid) - nb);
        llong sausage = max(0LL,(sn * mid) - ns);
        llong cheese = max(0LL,(cn * mid) - nc);
        llong tot = bread*pb + sausage*ps + cheese*pc;
        if(!(tot <= money))
            hi = mid - 1;
        else
            lo = mid;
    }
    cout << lo << endl;
    return 0;
}