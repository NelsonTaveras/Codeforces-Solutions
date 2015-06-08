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
const int MAXN = (int) 1e5;

string S;
int fx[(int) MAXN + 50];
int fy[(int) MAXN + 50];
int fz[(int) MAXN + 50];
int getx(int l, int r)
{
    return fx[r] - (l == 0 ? 0 : fx[l - 1]);
}
int gety(int l, int r)
{
    return fy[r] - (l == 0 ? 0 : fy[l - 1]);
}
int getz(int l, int r)
{
    return fz[r] - (l == 0 ? 0 : fz[l - 1]);
}
bool func(int l, int r)
{
    VI V;
    V.push_back(getx(l, r));
    V.push_back(gety(l, r));
    V.push_back(getz(l, r));
    sort(V.begin(), V.end());
    if(V[2] - V[0] > 1) return false;
    if(V[2] - V[1] > 1) return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cin >> S;
    int sz = (int) S.size();
    fx[0] = fy[0] = fz[0] = 0;
    for(int i = 1; i <= sz; ++i){
        fx[i] = fx[i - 1] + (S[i - 1] == 'x');
        fy[i] = fy[i - 1] + (S[i - 1] == 'y');
        fz[i] = fz[i - 1] + (S[i - 1] == 'z');
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; ++i){
        int l, r;
        cin >> l >> r;
        if(r - l + 1 < 3)
            cout << "YES" << endl;
        else
            cout << (func(l, r) ? "YES" : "NO") << endl;
    }
    return 0;
}