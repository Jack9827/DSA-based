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
// to get strongly connected components
// main code starts here
void dfs1(int node , vector<vi> &adj , vi &vis , stack<int> &st)
{
    vis[node] = 1;
    
    for(auto child : adj[node])
    {
        if(!vis[child])
        {
            dfs1(child , adj , vis , st);
        }
    }

    st.push(node);
}

void dfs2(int node , vector<vi> &adj , vi &vis , queue<int> &q)
{
    vis[node] = 1;
    q.push(node);

    for(auto child : adj[node])
    {
        if(!vis[child])dfs2(child , adj , vis , q);
    }
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vi> adj1(n) , adj2(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj2[v].pb(u);
        adj1[u].pb(v);
    }

    
    vi vis1(n) , vis2(n) , ans(n);
    stack<int> st;
    queue<int> q;

    for(int i=0; i<n; i++)
    {
        if(!vis1[i])dfs1(i , adj1 , vis1 , st);
    }
    int cnt = 1;
    while(!st.empty())
    {
        if(vis2[st.top()])
        {
            st.pop();
            continue;
        }

        else
        {
            dfs2(st.top() , adj2 , vis2 , q);
            while(!q.empty())
            {
                ans[q.front()] = cnt;
                q.pop();
            }
            cnt++;
        }
    }

    cout << cnt-1 << n1;
    p(ans);
    
   

    return 0;
}
