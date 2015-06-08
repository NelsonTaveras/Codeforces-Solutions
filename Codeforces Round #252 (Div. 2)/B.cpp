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

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL<<62);
const int inf = (1LL<<30);
const int maxn = (int) 1e9 + 5;
const int MOD = 1000000007;

int mat[3005][3005];
int used[3005];
int arr[3005];

struct S{
    int day;
    int id;
    int fruits;
    S(int _id, int _day, int _fruits){
        id = _id;
        day = _day;
        fruits = _fruits;
    }
    bool operator < (S s)const{
        if(day != s.day) return day < s.day;
        return fruits > s.fruits;
    }
};

int main()
{
    // freopen("input.txt", "r", stdin);
    int n, v;
    cin >> n >> v;
    int ma = 0;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        ma = max(ma, a + 1);
        mat[i][a] = mat[i][a + 1] = b;
        arr[i] = a;
    }
    int ans = 0;
    for(int day = 1; day <= ma; ++day){
        vector<S> V;
        for(int id = 0; id < n; ++id){
            if(mat[id][day] - used[id] <= 0) continue;
            V.push_back(S(id, arr[id], mat[id][day] - used[id]));
        }
        sort(V.begin(), V.end());
        int got = 0;
        for(int j = 0; j < V.size() && got != v; ++j){
            int id = V[j].id;
            int day = V[j].day;
            int fruits = V[j].fruits;
            int mi = min(fruits, v - got);
            got += mi;
            used[id] += mi;
        }
        ans += got;
    }
    cout << ans << endl;
    return 0;
}