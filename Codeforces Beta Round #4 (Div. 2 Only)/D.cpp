#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007
typedef long long llong;

struct Box{
    int W;
    int H;
    int id;
    bool operator <(Box B)const{
        if(W != B.W)
            return W < B.W;
        return H < B.H;
    }
}E[5001];
int L[5001];
int LIS(int N){
    for(int i = 0; i < N; ++i) L[i] = 1;
    for(int i = 0; i < N; ++i)
        for(int j = i + 1; j < N; ++j)
            if(E[j].W > E[i].W && E[j].H > E[i].H)
                L[j] = max(L[j], L[i] + 1);
    int aux = 0;
    for(int i = 0; i < N; ++i) aux = max(aux, L[i]);
    return aux;
}
vector<int> constructLIS(int N, int mx){
    vector<int> ANS;
    int idx = 0;
    for(int i = 0; i < N; ++i) 
        if(L[i] == mx)
            idx = i;
    while(mx){
        mx--;
        ANS.push_back(E[idx].id);
        for(int j = idx - 1; j >= 0; --j)
            if(E[j].W < E[idx].W && E[j].H < E[idx].H && L[j] == mx){
                idx = j;
                break;
            }
    }
    reverse(ANS.begin(), ANS.end());
    return ANS;
}
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int N, W, H;
    cin >> N >> W >> H;
    bool ans = false;
    int cur = 0;            //cur++;
    int curr = 0;
    for(int i = 0; i < N; ++i){
        int w, h;
        cin >> w >> h;
        if(w > W && h > H){
            ans = true;
            E[curr].W = w;
            E[curr].H = h;
            E[curr].id = i;
            curr++;
        }
    }
    N = curr;
    if(!ans){
        cout << 0;
        return 0;
    }
    sort(E, E+N);
    int ret = LIS(N);
    vector<int> ANS = constructLIS(N, ret);
    cout << ret << endl;
    for(int i = 0; i < ANS.size(); ++i)
        cout << ANS[i] + 1 << ' ';
    return 0;
}