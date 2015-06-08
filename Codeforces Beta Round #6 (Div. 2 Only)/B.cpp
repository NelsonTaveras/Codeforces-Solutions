#include <iostream>
#include <vector>
#include <set>

using namespace std;

int rows, cols;
char color;
set<char> saw;
vector<string> GRID(rows);
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int vis[1000][1000];
int ret = 0;
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dr[i];
        int ny = y + dc[i];
        if(nx >= 0 && ny >= 0 && nx < rows && ny < cols)
            if(GRID[nx][ny] != '.')
                if(!saw.count(GRID[nx][ny]))
                    if(GRID[nx][ny] != color)
                        if(!vis[nx][ny])
                        {
                            saw.insert(GRID[nx][ny]);
                            vis[nx][ny]++;
                            ret++;
                        }
    }
}

int main()
{
    cin >> rows >> cols;
    cin >> color;
    GRID = vector<string>(rows);
    for(int i = 0; i < rows; ++i)
        cin >> GRID[i];
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            if(GRID[i][j] == color && !vis[i][j])
                { dfs(i, j); };
    cout << ret;
    return 0;
}
