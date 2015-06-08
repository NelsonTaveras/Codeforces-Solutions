#include <cmath>
#include <ctime>
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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef pair<int, int> PII;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    VI V(N);
    VI pos(N + 1);
    for(int i = 0; i < N; ++i){
        int id;
        cin >> id;
        V[i] = id;
        pos[id] = i;
    }
    VI check(N);
    for(int i = 0; i < N; ++i) check[i] = i + 1;
    if(check == V){
        cout << 0 << ' ' << 0;
        return 0;
    }
    int op = 0;
    int l = -1;
    int r = -1;
    for(int i = 0; i < N; ++i){
        if(V[i] != i + 1){
            op++;
            VI temp;
            // This shouldn't be here, i + 1 should..
            int P = pos[ i + 1 ];
            int mi = min(P, i);
            int mx = max(P, i);
            l = mi + 1;
            r = mx + 1;
            for(int j = 0; j < mi; ++j) temp.push_back(V[j]);
            //for(int j = 0; j < temp.size(); ++j) cout << temp[j] << ' '; cout << endl;
            for(int j = mx; j >= mi; --j) temp.push_back(V[j]);
            //for(int j = 0; j < temp.size(); ++j) cout << temp[j] << ' '; cout << endl;
            for(int j = mx + 1; j < N; ++j) temp.push_back(V[j]);
            //for(int j = 0; j < temp.size(); ++j) cout << temp[j] << ' '; cout << endl;
            V = temp;
            break;
        }
    }
    if(op == 1 && V == check)
        cout << l << ' ' << r << endl;
    else
        cout << 0 << ' ' << 0 << endl;
    return 0;
}

