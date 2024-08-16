// coded by Jai_Khatri

#include <bits/stdc++.h>

using namespace std;
//------------------------------

typedef long long ll;
typedef long double ld;
#define pii pair<int , int>
#define vi vector<int>
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
#define sz(a) ((int)((a).size()))

const ll INF = 4e18;
//---------------------------------
class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
// main code starts here


int32_t main(){

    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        
        


        
    }


    return 0;

}   