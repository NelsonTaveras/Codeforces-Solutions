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

bool func(int curh, int curm, int hh, int mm, int fh, int fm)
{
  while(hh > 0){
    curh++;
    hh--;
    if(curh > 23) curh = 0;
  }
  while(mm > 0){
    curm++;
    mm--;
    if(curm > 59){
      curm = 0;
      curh++;
      if(curh > 23) curh = 0;
    }
  }
  return (curh == fh && curm == fm);
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    int fh = ((s[0]-'0')*10)+(s[1]-'0');
    int fm = ((s[3]-'0')*10)+(s[4]-'0');
    int hh = ((t[0]-'0')*10)+(t[1]-'0');
    int mm = ((t[3]-'0')*10)+(t[4]-'0');
    int f = 1;
    for(int i = 0; i <= 23 && f; ++i)
      for(int j = 0; j <= 59 && f; ++j){
        if(func(i, j, hh, mm, fh, fm)){
          if(i < 10) cout << 0;
          cout << i;
          cout << ':';
          if(j < 10) cout << 0;
          cout << j;
          f = 0;
        }
      }
    return 0;
}