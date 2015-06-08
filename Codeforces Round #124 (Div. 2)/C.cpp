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

#define MOD 1000000009
#define mp make_pair
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef long long llong;
const int INF = 1e9;

using namespace std;
char mx[100009];
int main()
{
    ios_base::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string S;
    cin >> S;
    for(int i = 0; i <= (int) S.size(); ++i)
        mx[i] = 'A';
    for(int i = (int) S.size() - 1; i >= 0; --i)
        mx[i] = max(mx[i + 1], S[i]);
    string ANS;
    for(int i = 0; i < (int) S.size(); ++i)
        if(mx[i] == S[i])
            ANS += S[i];
    cout << ANS << endl;
    return 0;
}