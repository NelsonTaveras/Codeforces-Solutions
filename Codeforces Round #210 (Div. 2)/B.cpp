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

int main()
{
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    VI V(N);
    for(int i = 0; i < N; ++i)
        V[i] = i + 1;
    int fix = N - 1 - K;
    int cur = 1;
    while(fix > 1 && cur < N)
    {
        bool fixed = false;
        if(cur + 1 < N){
            swap(V[cur], V[cur + 1]);
            fixed = true;
            fix -= 2;
            cur += 2;
        }
        if(!fixed) break;
    }
    if(fix) swap(V[0], V.back());
    int aux = 0;
    for(int i = 0; i < N; ++i)
        aux += ( __gcd(i + 1, V[i]) > 1 );
    if(aux != K){
        cout << -1;
    }
    else{
        for(int i = 0; i < N; ++i) cout << V[i] << ' ';
    }
    return 0;
}

/*

GOOD = 7;

8 3 2 5 4 7 6 1


FIX = 3

1 2 3 4 5 6 7

*/
