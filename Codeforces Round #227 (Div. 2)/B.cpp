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
typedef pair<llong, llong> PII;
typedef pair<llong, PII> PIP;
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
    int n, m;
    cin >> n >> m;
    VI need, have;
    for(int i = 0; i < n; ++i){
      int c;
      cin >> c;
      need.push_back(c);
    }
    for(int i = 0; i < m; ++i){
      int c;
      cin >> c;
      have.push_back(c);
    }
    sort(need.begin(), need.end());
    sort(have.begin(), have.end());
    int l = 0, r = 0;
    while(r < m){
      if(have[r] >= need[l]) 
        l++, r++;
      else
        r++;
      if(l >= n) break;
    }
    cout << n - l << endl;
    return 0;
}