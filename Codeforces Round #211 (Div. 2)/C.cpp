#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIIP;
typedef pair<PII, char> PIC;
typedef pair<int, char> PICD;
const int INF = (int) 2e9;

int memo[200001][27][3][2];
short int act[200001][27][3][2];
string S;
int dp(int id, int last, int cons, int f)
{
    if(cons >= 3) return INF;
    if(cons >= 2 && f) return INF;
    if(id >= (int) S.size()) return 0;
    if(memo[id][last][cons][f] != -1) return memo[id][last][cons][f];
    int ret = INF;
    int w = INF;
    if(S[id]-'a' == last)
    {
        w = min(w, dp(id + 1, last, cons + 1, f));
    }
    else
    {
        if(cons >= 2)
            w = min(w, dp(id + 1, S[id] - 'a', 1, 1));
        else
            w = min(w, dp(id + 1, S[id] - 'a', 1, 0));
    }
    if(w < ret){
        ret = w;
        act[id][last][cons][f] = 1;
    }
    w = 1 + dp(id + 1, last, cons, f);
    if(w < ret){
        ret = w;
        act[id][last][cons][f] = 2;
    }
    return memo[id][last][cons][f] = ret;
}
string doit(int id, int last, int cons, int f)
{
    string aux;
    while(1)
    {
        if(id >= (int) S.size()) break;
        int choice = act[id][last][cons][f];
        if(choice == 1)
        {
            aux += S[id];
            if(S[id] - 'a' == last)
            {
                id++;
                cons++;
            }
            else
            {
                if(cons >= 2){
                    last = S[id] - 'a';
                    cons = 1;
                    f = 1;
                    id++;
                }
                else{
                    last = S[id] - 'a';
                    cons = 1;
                    f = 0;
                    id++;
                }
            }
        }
        else if(choice == 2)
        {
            id++;
        }
        else
            break;
    }
    return aux;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> S;
    memset(memo, -1, sizeof(memo));
    dp(0, 27, 0, 0);
    cout << doit(0, 27, 0, 0) << endl;
    return 0;
}
