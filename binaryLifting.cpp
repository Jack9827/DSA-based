// coded by Jai_Khatri

#include <bits/stdc++.h>

using namespace std;
//------------------------------

typedef long long ll;
typedef long double ld;
#define pii pair<ll , ll>
#define vi vector<ll>
#define pll pair<ll , ll>
#define vl vector<ll>
#define vb vector<bool>
#define vip(a,n)    for(ll i=0;i<n;i++) cin>>a[i];
#define p(v)         for(auto x:v) cout<<x<<' ';cout<<'\n';
#define n1 "\n"
#define pb push_back
#define ppb pop_back
#define F first
#define S second 
#define all(a) (a).begin() , (a).end()
#define sz(a) ((ll)((a).size()))

const ll INF = 4e18;
//---------------------------------
ll ans(ll node , ll k , vector<vi> &par)
{
    

    for(ll i=0; i<30; i++)
    {
        if(k&(1ll<<i))node = par[node][i];
    }

    return node;
}
// main code starts here


int32_t main(){

    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    ll n , q;
    cin >> n >> q;

    vector<vi> par(n+1 , vi(31 , -1));

    for(ll i=1; i<=n; i++)
    {
        //getting direct parent
        cin >> par[i][0];
    }

    for(ll d=1; d<30; d++)
    {
        for(ll i=1; i<n+1; i++)
        {
            //par[i][0] = parent[i][0]
            //par[i][1] = par[ par[i][0] ][1]
            //par[i][2] = par[ par[i][1] ][2]
            //......
            par[i][d] = par[par[i][d-1]][d-1];
        }
    }

   

    while(q--)
    {
        ll node , k;
        cin >> node >> k;
        cout << ans(node , k , par) << n1; 

    }


    return 0;

}   