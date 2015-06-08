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
#include <ctime>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;
#define MOD (llong)  100999
const int MAXN = 5005;

int l[5050];
int r[5050];
int c[5050];
int ansl[5050];
int ansr[5050];
int main()
{
    // freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i){
        scanf("%d", &c[i]);
        ansl[i] = c[i];
        ansr[i] = c[i];
    }
    for(int i = 0; i < n; ++i){
        if(ansl[i] != ansr[i]) continue;
        for(int j = 0; j < n; ++j){
            if(ansl[i] != ansl[j] && ansl[i] != ansr[j]){
                swap(ansl[i], ansl[j]);
                break;
            }
            if(ansr[i] != ansr[j] && ansr[i] != ansl[j]){
                swap(ansr[i], ansr[j]);
                break;
            }
        }
    }
    int aux = 0;
    for(int i = 0; i < n; ++i)
        if(ansl[i] != ansr[i]) aux++;
    cout << aux << endl;
    for(int i = 0; i < n; ++i)
        cout << ansl[i] << ' ' << ansr[i] << endl;
    return 0;
}