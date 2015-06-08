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
const int INF = (int) 1e9;
map<string, int> idx;
map<int, string> idx2;
int arr[25][25];
int main()
{
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
    {
        string S;
        cin >> S;
        idx[S] = i;
        idx2[i] = S;
    }
    for (int i = 0; i < M; ++i)
    {
        string u, v;
        cin >> u >> v;
        int iu = idx[u];
        int iv = idx[v];
        arr[iu][iv] = 1;
        arr[iv][iu] = 1;
    }
    int ANS = 0;
    for(int i = 0; i < (1<<N); ++i)
    {
        bool valid = true;
        VI V;
        for(int j = 0; j < N; ++j){
            if(i & (1<<j))
                V.push_back(j);
        }
        for(int j = 0; j < V.size(); ++j)
            for(int k = 0; k < V.size(); ++k)
                if(arr[V[j]][V[k]])
                    valid = false;
        if(valid)
            if(__builtin_popcount(i) > __builtin_popcount(ANS))
                ANS = i;
    }
    vector<string> ANS2;
    for(int i = 0; i < N; ++i)
        if(ANS & (1<<i))
            ANS2.push_back(idx2[i]);
    sort(ANS2.begin(), ANS2.end());
    cout << ANS2.size() << endl;
    for(int i = 0; i < ANS2.size(); ++i)
        cout << ANS2[i] << endl;
}   
