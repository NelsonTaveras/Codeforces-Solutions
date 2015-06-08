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

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt","r",stdin);
    llong N, K;
    while(cin >> N >> K)
    {
        llong res = 0;
        llong pending = 0;
        while(N > 0){
            res += N;
            pending += (N%K);
            N /= K;
            if(pending >= K){
                N += (pending/K);
                pending %= K;
            }
        }
        cout << res << endl;
    }
    return 0;
}