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
#define in cin
#define out cout
const int MAXN = 5005;

int arr[550];
int fen[550];
string ANS;
char last(){
    return ANS[ANS.size() - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt","r",stdin);
    int N;
    cin >> N;
    int tot = 0;
    int cur = 0;
    for(int i = 0; i < N; ++i){
        cin >> arr[i];
        tot += arr[i];
    }
    int aux = 0;
    while(tot > 0)
    {
        if(aux == 0)
        {
            // right
            if(arr[cur] > 0 && last() != 'P'){
                arr[cur]--;
                tot--;
                ANS += 'P';
            }
            if(cur + 1 < N) cur++, ANS += 'R';
            else aux = 1;
        }
        else
        {
            // left
            if(arr[cur] > 0 && last() != 'P'){
                arr[cur]--;
                tot--;
                ANS += 'P';
            }
            if(cur > 0) cur--, ANS += 'L';
            else aux = 0;
        }
    }
    cout << ANS << endl;
    return 0;
}