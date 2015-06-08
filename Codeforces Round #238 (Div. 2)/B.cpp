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
#include <bitset>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<llong, llong> PII;
typedef pair<llong, PII> PIP;
typedef vector<llong> VI;
typedef vector<VI> VVI;
const int INF = (llong) 1e9 + 50;
#define MOD (llong)  1000000007
const llong MAXN = 100050;

int L[3005];
int R[3005];
int F[3005];

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    string S;
    cin >> S;
    for(int i = 0; i < N; ++i){
        if(S[i] == '.') continue;
        if(S[i] == 'R'){
            int j = i + 1;
            while(j < N){
                if(S[j] == 'R') 
                    break;
                if(S[j] == 'L'){
                    int mid = j - i - 1;
                    if(mid & 1){
                        F[ (i + j) / 2] = 1;
                    }
                }
                j++;
            }
        }
    }
    for(int i = 0; i < N; ++i){
        if(S[i] == '.') continue;
        if(S[i] == 'L'){
            int j = i - 1;
            while(j >= 0 && S[j] == '.' && F[j] == 0){
                S[j] = 'L';
                j--;
            }
        }else{
            int j = i + 1;
            while(j < N && S[j] == '.' && F[j] == 0){
                S[j] = 'R';
                j++;
            }
        }
    }
    cout << count(S.begin(), S.end(), '.') << endl;
    return 0;
}