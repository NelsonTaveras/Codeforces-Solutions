#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007
typedef long long llong;

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int N;
    cin >> N;
    string S;
    getline(cin, S);
    while(N--){
        getline(cin, S);
        string preffix, suffix;
        if(S.size() < 5){
            cout << "OMG>.< I don't know!" << endl;
            continue;
        }
        for(int i = 0; i < 5; ++i)
            preffix += S[i];
        for(int i = 4; i >= 0; --i)
            suffix += (S[S.size() - 1 - i]);
        string total = preffix + suffix;
        if(total == "miao.lala.")
            cout << "OMG>.< I don't know!" << endl;
        else if(preffix == "miao.")
            cout << "Rainbow's" << endl;
        else if(suffix == "lala.")
            cout << "Freda's" << endl;
        else
            cout << "OMG>.< I don't know!" << endl;
    }
    return 0;
}