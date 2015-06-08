#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <ctime>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL<<62);
const int inf = (1LL<<30);
const int maxn = (int) 1e9 + 5;
const int MOD = 1000000007;

vector<string> V;
bool isOn(int mask, int b){
    return (mask & (1<<b)) != 0;
}
bool func(set<char> const &clues){
    int sz = V.size();
    int f = 1;
    for(int i = 0; i < sz; ++i)
        for(int j = i + 1; j < sz; ++j){
            if(V[i] != V[j]){
                if(V[i][0] == V[j][0] && (clues.count(V[i][1]) == 0) && (clues.count(V[j][1]) == 0) ) 
                    f = 0;  
                else if(V[i][1] == V[j][1] && (clues.count(V[i][0]) == 0) && (clues.count(V[j][0]) == 0) ) 
                    f = 0;
                else{
                    if( (clues.count(V[i][1]) == 0) && (clues.count(V[j][1]) == 0) && (clues.count(V[i][0]) == 0) && (clues.count(V[j][0]) == 0)  )
                        f = 0;
                }
            }
        }
    return f;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        string S;
        cin >> S;
        V.push_back(S);
    }
    int mi = inf;
    for(int maskl = 0; maskl < (1<<5); ++maskl){
        for(int maskn = 0; maskn < (1<<5); ++maskn){
            set<char> clues;
            // R, G, B, Y, W
            if(isOn(maskl, 0)) clues.insert('R');
            if(isOn(maskl, 1)) clues.insert('G');
            if(isOn(maskl, 2)) clues.insert('B');
            if(isOn(maskl, 3)) clues.insert('Y');
            if(isOn(maskl, 4)) clues.insert('W');
            // 1, 2, 3, 4, 5
            if(isOn(maskn, 0)) clues.insert('1');
            if(isOn(maskn, 1)) clues.insert('2');
            if(isOn(maskn, 2)) clues.insert('3');
            if(isOn(maskn, 3)) clues.insert('4');
            if(isOn(maskn, 4)) clues.insert('5');
            if(func(clues)) mi = min(mi, __builtin_popcount(maskl) + __builtin_popcount(maskn));
        }
    }
    cout << mi << endl;
    return 0;
}
