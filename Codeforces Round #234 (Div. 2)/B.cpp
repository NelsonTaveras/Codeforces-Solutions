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
typedef vector<llong> VI;
typedef vector<VI> VVI;
const llong INF = (llong) 2e9;
#define MOD (llong)  1000000007
const llong MAXN = 100010;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> V;
    for(int i = 0; i < n; ++i){
        string S;
        cin >> S;
        V.push_back(S);
    }
    vector<int> arr;
    for(int i = 0; i < n; ++i){
        int c = 0;
        for(int j = 0; j < m; ++j)
            if(V[i][j] == 'S') 
                c++;
        if(c == 0) continue;
        int saw = 0;
        for(int j = 0; j < m; ++j){
            if(V[i][j] == 'G') 
                saw++;
            else if(V[i][j] == 'S'){
                if(saw != 1){
                    cout << -1;
                    return 0;
                }
                --saw;
            }
        }
        int d = 0;
        set<int> dist;
        for(int j = 0; j < m; ++j){
            if(V[i][j] == 'G'){
                d = 0;
                while(j + 1 < m && V[i][j] != 'S')
                    j++, d++;
                if(j < m && V[i][j] == 'S'){
                    dist.insert(d);
                }
            }
        }
        for(set<int>::iterator it = dist.begin(); it != dist.end(); ++it)
            arr.push_back(*it);
    }
    if(arr.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    int steps = 0;
    while(1){
        ++steps;
        int mi = INF;
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i] > 0) mi = min(mi, arr[i]);
        }
        for(int i = 0; i < arr.size(); ++i)
            arr[i] -= mi;
        int f = 0;
        for(int i = 0; i < arr.size(); ++i)
            if(arr[i] > 0) f++;
        if(f == 0) break;
    }
    cout << steps << endl;
    return 0;
}
