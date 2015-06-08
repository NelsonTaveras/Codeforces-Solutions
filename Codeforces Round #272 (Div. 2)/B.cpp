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
#include <bitset>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const llong inf = (1LL << 30);
const llong maxn = (llong) 1e6 + 10;
const llong MOD = 1000000007;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string S1, S2;
    cin >> S1 >> S2;
    int p1 = 0;
    int len = (int) S1.size();
    for (int i = 0; i < len; ++i) {
        if (S1[i] == '+')
            p1++;
        else
            p1--;
    }
    int unrec = 0;
    for (int i = 0; i < len; ++i) {
        if (S2[i] == '?')
            unrec++;
    }
    if (unrec == 0) {
        int p2 = 0;
        for (int i = 0; i < len; ++i) {
            if (S2[i] == '+')
                p2++;
            else
                p2--;
        }
        if (p1 == p2) {
            printf("%.10lf\n", 1.0 * 1);
        } else {
            printf("%.10lf\n", 1.0 * 0);
        }
    } else {
        int total = 0;
        int valid = 0;
        for (int mask = 0; mask < (1 << unrec); ++mask) {
            string tmp = S2;
            VI V;
            for (int bit = 0; bit < unrec; ++bit) {
                V.push_back((mask & (1 << bit)) == 0);
            }
            int idx = 0;
            for (int i = 0; i < len; ++i) {
                if (tmp[i] == '?') {
                    tmp[i] = (V[idx] ? '+' : '-');
                    idx++;
                }
            }
            int p2 = 0;
            for (int i = 0; i < len; ++i) {
                if (tmp[i] == '+')
                    p2++;
                else
                    p2--;
            }
            if(p2 == p1) valid++;
            total++;
        }
        printf("%.10lf\n", 1.0 * valid/total);
    }
    return 0;
}

