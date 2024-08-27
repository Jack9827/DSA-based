// coded by Jai_Khatri

#include <bits/stdc++.h>

using namespace std;
//------------------------------

//---------------------------------
int n;
vector<vector<int>> parent, adj;
vector<int> lvl;

void dfs(int node, int par, int l)
{
    //cout << node << " " << par << n1;
    lvl[node] = l;
    parent[node][0] = par;
    for (auto child : adj[node])
    {
        if (par != child)
            dfs(child, node, l + 1);
    }
}

int lca(int p, int q)
{
    if (lvl[p] < lvl[q])
        swap(p, q);

    int diff = lvl[p] - lvl[q];

    for (int i = 20; i >= 0; i--)
        if (diff & (1 << i))
            p = parent[p][i];

    if (p == q)
        return p;

    for (int i = 20; i >= 0; i--)
    {
        if (parent[p][i] != parent[q][i])
        {
            p = parent[p][i];
            q = parent[q][i];
        }
    }
    return parent[p][0];
}
// main code starts here

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> n >> q;
    lvl = vector<int>(n + 1);
    adj = vector<vector<int>>(n + 1);

    parent = vector<vector<int>>(n + 1, vector<int>(31, 0));

    for (int i = 0; i < n-1; i++)
    {
       int u , v;
       cin >> u >> v;
       adj[u].push_back(v);
    }

    
    dfs(1, 0, 0);

    for (int d = 1; (1 << d) <= n; d++)
    {
        for (int i = 0; i < n + 1; i++)
        {
            // cout << i << " " << d << n1;
            parent[i][d] = parent[parent[i][d - 1]][d - 1];
        }
    }

    
    while (q--)
    {
        int u , v;
        cin >> u >> v;
        cout <<  lca(u , v) << endl;
    }

    return 0;
}