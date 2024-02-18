/*************** 
Assignment Submit korar por eta ami hackerrank e submit korchi
****************/

#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
using namespace std;
const ll N = 1e3 + 5;
char a[N][N];
bool visi[N][N];
ll n, m;
vector<pi> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
map<pi, pi> mp;
bool valid(ll i, ll j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '#')
    {
        return false;
    }
    return true;
}
void bfs(ll si, ll sj)
{
    queue<pi> q;
    q.push({si, sj});
    visi[si][sj] = true;
    while (!q.empty())
    {
        pi p = q.front();
        q.pop();
        int ci = p.first;
        int cj = p.second;
        if (a[ci][cj] == 'D')
        {
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            ll ni = ci + d[i].first;
            ll nj = cj + d[i].second;
            if (valid(ni, nj) && !visi[ni][nj])
            {
                q.push({ni, nj});
                visi[ni][nj] = true;
                mp[{ni, nj}] = {ci, cj};
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(visi, false, sizeof(visi));
    ll si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (a[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }
    bfs(si, sj);
    pi v = {di, dj};
    pi d = {si, sj};
    if (!visi[di][dj] || mp[v] == d)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        while (mp[v] != d)
        {
            if (a[v.first][v.second] != 'D')
            {
                a[v.first][v.second] = 'X';
            }
            v = mp[v];
        }
        a[v.first][v.second] = 'X';
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}