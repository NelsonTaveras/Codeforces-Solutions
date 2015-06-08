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
const int INF = (int) 2e9;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int res = 0;
    for(int i = 0; i < n; ++i){
        string S;
        cin >> S;
        VI F(25);
        for(int i = 0; i < S.size(); ++i)
            F[S[i] - '0']++;
        bool f = true;
        for(int i = 0; i <= k; ++i)
            if(F[i] == 0) f = false;
        res += f;
    }
    cout << res << endl;
    return 0;
}
