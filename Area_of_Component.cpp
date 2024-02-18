#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char a[N][N];
bool vis[N][N];
int minArea;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= n || cj < 0 || cj >= m || a[ci][cj] != '.')
        return false;
    else
        return true;
}
int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int total = 1;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && a[ci][cj] == '.')
        {
            total += dfs(ci, cj);
        }
    }
    return total;
}
int main()
{
    cin >> n >> m;
    minArea = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.' && !vis[i][j])
            {
                int val = dfs(i, j);
                minArea = min(val, minArea);
            }
        }
    }

    if (minArea == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << minArea << endl;
    }
    return 0;
}