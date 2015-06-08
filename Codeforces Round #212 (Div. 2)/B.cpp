#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIIP;
typedef pair<PII, char> PIC;
typedef pair<int, char> PICD;
const int INF = (int) 2e9;
const int MAXN = 1000010;

int main()
{
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    VI V;
    for(int i = 0; i < M; ++i){
        int id;
        cin >> id;
        if(id == 1 || id == N){
            cout << "NO" << endl;
            return 0;
        }
        V.push_back(id);
    }
    sort(V.begin(), V.end());
    for(int i = 0; i < V.size(); ++i){
        int cur = V[i];
        int j = i + 1;
        int cons = 1;
        while(j < V.size() && V[j] == cur + 1){
            cur = V[j];
            cons++;
            j++;
        }
        if(cons >= 3){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
