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
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<llong> VI;
typedef vector<VI> VVI;
const int INF = (llong) 1e9 + 50;
#define MOD (llong)  1000000007
const llong MAXN = 100050;

map<int, int> used;

int main()
{
    // freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    if(n == 1 && k > 0){
        cout << -1;
        return 0;
    }
    int tot = n / 2;
    if(k < tot){
        cout << -1 << endl;
        return 0;
    }
    if(k == 0){
        cout << 1;
        return 0;
    }
    int wanted = k - tot + 1;
    VI V;
    int ans = 0;
    ans += __gcd(wanted, wanted * 2);
    cout << wanted << ' ' << wanted * 2 << ' ';
    used[wanted] = 1;
    used[wanted * 2] = 1;
    int cur = 1;
    int left = n - 2;
    while(left > 0){
        if(left == 1){
            while(used.count(cur) > 0)
                cur++;
            cout << cur;
            break;
        }
        if(used.count(cur) || used.count(cur + 1)){
            cur++;
        }else{
            ans += __gcd(cur, cur + 1);
            cout << cur << ' ' << cur + 1 << ' ';
            cur += 2;
            left -= 2;
        }
    }
    // cout << endl << ans << endl;
    return 0;
}