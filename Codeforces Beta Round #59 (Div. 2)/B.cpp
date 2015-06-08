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
#define MAXN (int) 1e5 + 5
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 1e9;

vector<int> V;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    VI V;
    for(int i = 0; i < N; ++i){
        int id;
        cin >> id;
        if(id < K) V.push_back(id);
    }
    int step = 0;
    while(V.size() > 0){
        step++;
        VI NV;
        for(int i = 1; i <= 100; ++i){
            int cnt = count(V.begin(), V.end(), i);
            for(int j = 0; j < cnt; ++j)
                NV.push_back(i);
            if(cnt) NV.back()++;
        }
        V = NV;
        while(V.size() > 0 && V.back() >= K) V.pop_back();
    }
    cout << step << endl;
    return 0;
}