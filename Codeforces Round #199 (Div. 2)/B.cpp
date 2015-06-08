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

using namespace std;

#define mp make_pair
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef long long llong;
const int INF = 1e9;

using namespace std;

map<int, PII> W;
bool watched(int id, int time){
    if(W.count(time) == 0)
        return false;
    int l = W[time].first;
    int r = W[time].second;
    return (id >= l && id <= r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int N, M, S, F;
    cin >> N >> M >> S >> F;
    for(int i = 0; i < M; ++i){
        int t, l, r;
        cin >> t >> l >> r;
        W[t] = mp(l, r);
    }
    int step = 1;
    string ANS;
    while(S != F)
    {
        int to = S;
        if(F > S)
            to++;
        else
            to--;
        if(watched(S, step) || watched(to, step))
            ANS += 'X';
        else{
            if(F > S)
                ANS += 'R';
            else
                ANS += 'L';
            S = to;
        }
        step++;
    }
    cout << ANS << endl;
    return 0;
}