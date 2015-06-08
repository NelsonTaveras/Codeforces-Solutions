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
#include <cctype>
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

int main()
{
    // freopen("input.txt", "r", stdin);    
    int N, K;
    cin >> N >> K;
    VVI V(N/K);
    int cur = 0;
    int id = 0;
    for(int i = 0; i < N; ++i){
        int v;
        cin >> v;
        V[cur].push_back(v);
        id++;
        if(id >= K){
            id = 0;
            cur++;
        }
    }
    int aux = 0;
    for(int i = 0; i < K; ++i){
        int ones = 0, twos = 0;
        for(int j = 0; j < V.size(); ++j){
            ones += V[j][i] == 1;
            twos += V[j][i] == 2;
        }
        aux += min(ones, twos);
    }
    cout << aux << endl;
    return 0;
}