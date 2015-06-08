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
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;

llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (llong) 1e6 + 10;
const int MOD = 1000000007;

int homeyellow[150];
int awayyellow[150];
int homered[150];
int awayred[150];

int main() {
    string home, away;
    cin >> home >> away;
    int n;
    cin >> n;
    vector<PIP> ans;
    for (int i = 0; i < n; ++i) {
        int time;
        cin >> time;
        string S;
        cin >> S;
        if (S[0] == 'h') {
            int number;
            cin >> number;
            string C;
            cin >> C;
            if (homered[number] || homeyellow[number] >= 2)
                continue;
            if (C[0] == 'y') {
                homeyellow[number]++;
            } else {
                homered[number]++;
            }
            if ((homeyellow[number] >= 2) || homered[number]) {
                ans.push_back(mp(0, mp(number, time)));
            }
        } else {
            int number;
            cin >> number;
            string C;
            cin >> C;
            if (awayred[number] || awayyellow[number] >= 2)
                continue;
            if (C[0] == 'y') {
                awayyellow[number]++;
            } else {
                awayred[number]++;
            }
            if ((awayyellow[number] >= 2) || awayred[number]) {
                ans.push_back(mp(1, mp(number, time)));
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        PIP p = ans[i];
        cout << (p.first == 0 ? home : away) << ' ';
        cout << p.second.first << ' ' << p.second.second << endl;
    }
    return 0;
}
