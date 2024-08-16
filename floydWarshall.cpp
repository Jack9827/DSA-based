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
void floydWarshall(vector<vector<int>> &dist)
{
    int n = dist.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == -1)
            {
                dist[i][j] = 1e9;
            }
            if (i == j)
                dist[i][j] = 0;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j],
                                   dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == 1e9)
            {
                dist[i][j] = -1;
            }
        }
    }
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