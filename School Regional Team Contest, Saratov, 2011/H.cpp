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
string words[201];
vector<vector<string> > adj;
map<string, int> match;
map<string, int> vis;
bool find_match(int u)
{
    for(int i = 0; i < adj[u].size(); ++i)
    {
        string v = adj[u][i];
        if(match.count(v) == 0)
        {
            match[v] = u;
            return true;
        }
        else
        {
            if(!vis[v])
            {
                vis[v] = 1;
                if(find_match(match[v]))
                {
                    match[v] = u;
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> words[i];
    adj = vector<vector<string> > (N);
    for(int i = 0; i < N; ++i)
    {
        int sz = (int) words[i].size();
        for(int j = 1; j < (1<<sz); ++j){
            string W;
            if(__builtin_popcount(j) <= 4){
                string W;
                for(int k = 0; k < sz; ++k)
                    if(j & (1<<k))
                        W += words[i][k];
                adj[i].push_back(W);
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < N; ++i)
    {
        vis.clear();
        if(find_match(i))
            ret++;
    }
    if(ret < N)
        cout << -1;
    else
    {
        vector<string> ANS(N);
        for(map<string, int>::iterator it = match.begin(); it != match.end(); ++it)
            ANS[it->second] = it->first;
        for(int i = 0; i < ANS.size(); ++i)
            cout << ANS[i] << endl;
    }
}   
