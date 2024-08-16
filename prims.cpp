// coded by Jai_Khatri

#include <bits/stdc++.h>

using namespace std;
//------------------------------

typedef long long ll;
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define pll pair<ll, ll>
#define vl vector<ll>
#define vb vector<bool>
#define vip(a, n)              \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define p(v)              \
    for (auto x : v)      \
        cout << x << ' '; \
    cout << '\n';
#define n1 "\n"
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)((a).size()))

const ll INF = 4e18;
//---------------------------------
int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>, greater<pair<int, int>>>
        pq;

    vector<int> vis(V, 0);
    // {wt, node}
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1)
            continue;
        // add it to the mst
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edW = it[1];
            if (!vis[adjNode])
            {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}
// main code starts here

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
    }

    return 0;
}