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

int markers[1001][1001];
int caps[1001][1001];
int summarkers[1001];
int sumcaps[1001];
int main()
{
    ios_base::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
    {
        int c, d;
        cin >> c >> d;
        markers[c][d]++;
    }
    for(int i = 0; i < M; ++i)
    {
        int c, d;
        cin >> c >> d;
        caps[c][d]++;
    }
    int closed = 0;
    int beautiful = 0;
    for(int i = 1; i <= 1000; ++i)
    {
        for(int j = 1; j <= 1000; ++j)
        {
            int m = markers[i][j];
            int c = caps[i][j];
            if(c >= m)
            {
                caps[i][j] -= m;
                markers[i][j] = 0;
                beautiful += m;
                closed += m;
            }
            else
            {
                caps[i][j] = 0;
                markers[i][j] -= c;
                beautiful += c;
                closed += c;
            }
        }
    }
    for(int i = 1; i <= 1000; ++i)
        for(int j = 1; j <= 1000; ++j)
            summarkers[j] += (markers[i][j]);
     for(int i = 1; i <= 1000; ++i)
        for(int j = 1; j <= 1000; ++j)
            sumcaps[j] += (caps[i][j]);
    for(int i = 1; i <= 1000; ++i)
        closed += min(sumcaps[i], summarkers[i]);
    cout << closed << ' ' << beautiful << endl;
    return 0;
}