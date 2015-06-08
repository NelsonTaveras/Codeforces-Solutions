#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long llong;

int arr[(int) 1e5 + 10];
int sum[(int) 1e5 + 10];
int func(int l, int r)
{
    if(l == 0)
        return sum[r];
    return sum[r] - sum[l - 1];
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> arr[i];
    for(int i = 1; i <= N; ++i)
        sum[i] = sum[i - 1] + arr[i - 1];
    string S;
    cin >> S;
    int mi = (int) 0;
    int p = 0;
    for(int i = S.size() - 1; i >= 0; --i)
    {
        if(S[i] == '1')
        {
            mi = max(mi, p + arr[i]);
            mi = max(mi, p + func(0, i));
            p += arr[i];
        }
    }
    cout << mi << endl; 
    return 0;
}