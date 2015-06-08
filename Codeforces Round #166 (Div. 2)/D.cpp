#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 1e9;

int A[100];
string S, good;
int K;
int ret = 0;
struct Trie{
    Trie *childs[26];
    Trie()
    {
        memset(childs, 0, sizeof(childs));
    }
    ~Trie()
    {
        for(int i = 0; i < 26; ++i)
            delete childs[i];
    }
    void insert(string word)
    {
        Trie *cur = this;
        for(int i = 0; i < (int) word.size(); ++i)
        {
            Trie *nxt = cur->childs[word[i]-'a'];
            if(!nxt)
                nxt = cur->childs[word[i]-'a'] = new Trie();
            cur = nxt;
        }
    }
    Trie* getroot()
    {
        Trie *root = this;
        return root;
    }
    void dfs(Trie *cur, int cnt)
    {
        if(cnt > K)
            return ;
        ret++;
        for(char c = 'a'; c <= 'z'; ++c)
        {
            Trie *nxt = cur->childs[c-'a'];
            if(nxt)
                dfs(nxt, cnt + (!A[c-'a']));
        }
    }
};

int main()
{
    cin >> S >> good >> K;
    for(int i = 0; i < (int) good.size(); ++i)
        A[i] = good[i] - '0';
    Trie t;
    for(int i = 0; i < (int) S.size(); ++i)
        t.insert(S.substr(i));
    t.dfs(t.getroot(), 0);
    cout << ret - 1 << endl;
    return 0;
}