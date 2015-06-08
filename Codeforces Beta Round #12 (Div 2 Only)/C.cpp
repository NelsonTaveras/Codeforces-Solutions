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
int arr[200];
int fre[200];
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
        cin >> arr[i];
    for(int i = 0; i < M; ++i)
    {
        string S;
        cin >> S;
        if(!idx.count(S))
            idx[S] = i;
        int id = idx[S];
        fre[id]++;
    }
    sort(arr, arr+N);
    sort(fre, fre+M);
    reverse(fre, fre+M);
    int mi = 0;
    int mx = 0;
    int idx = 0;
    for(int i = 0; i < M; ++i)
        mi += (fre[i] * arr[idx]), idx++;
    idx = N - 1;
    for(int i = 0; i < M; ++i)
        mx += (fre[i] * arr[idx]), idx--;
    cout << mi << ' ' << mx;
    return 0;
}   
