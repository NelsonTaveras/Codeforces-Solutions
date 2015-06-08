#include <cmath>
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
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL<<62);

string arr[100010];

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> arr[i];
    }
    int cur = 0;
    int len = arr[0].size();
    string ANS;
    for(int i = 0; i < len; ++i){
        set<char> S;
        int q = 0;
        for(int j = 0; j < N; ++j){
            if(arr[j][i] == '?')
                q++;
            else
                S.insert(arr[j][i]);
        }
        if(q == N)
            ANS += 'a';
        else{
            if(S.size() == 1){
                ANS += *S.begin();
            }
            else if(S.size() > 1){
                ANS += '?';
            }
        }
    }
    cout << ANS << endl;
    return 0;
}