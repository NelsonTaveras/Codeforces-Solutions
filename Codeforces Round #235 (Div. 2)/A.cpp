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
#include <bitset>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<llong, llong> PII;
typedef pair<llong, PII> PIP;
typedef vector<llong> VI;
typedef vector<VI> VVI;
const llong INF = (llong) 1e9;
#define MOD (llong)  1000000007
const llong MAXN = 100050;

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, x;
    cin >> n >> x;
    int sum = 0;
    for(int i = 0; i < n; ++i){
        int s;
        cin >> s;
        sum += s;
    }
    int dist = abs(sum);
    if(dist == 0)
        cout << 0 << endl;
    else{
        int l = 0;
        int aux = 0;
        while(l < dist){
            l += x;
            ++aux;
        }
        cout << aux << endl;
    }
    return 0;
}