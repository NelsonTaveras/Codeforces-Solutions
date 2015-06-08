#include <cmath>
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

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL<<62);

int arr[150];
int painted[150];

int main()
{
    // ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    string S;
    cin >> S;
    cout << "PRINT " << S[k - 1] << endl;
    int tot = 1;
    int init = k;
    if( n - k >= k - 1 ){
        k -= 2;
        while(k >= 0){
            cout << "LEFT" << endl;
            cout << "PRINT " << S[k] << endl;
            tot++;
            --k;
        }
        if(tot != n){
            for(int i = 0; i < init - 1; ++i){
                cout << "RIGHT" << endl;
            }
            k = init;
            while(k < n && tot != n){
                cout << "RIGHT" << endl;
                cout << "PRINT " << S[k] << endl;
                tot++;
                ++k;
            }
        }
        // go left
    }else{
        // go right
        while(k < n && tot != n){
            cout << "RIGHT" << endl;
            cout << "PRINT " << S[k] << endl;
            tot++;
            ++k;
        }
        if(tot != n){
            for(int i = 0; i < n - init; ++i){
                cout << "LEFT" << endl;
            }
            k = init - 2;
            while(k >= 0 && tot != n){
                cout << "LEFT" << endl;
                cout << "PRINT " << S[k] << endl;
                tot++;
                --k;
            }
        }
    }
    return 0;
}