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

// main code starts here


int32_t main(){

    
    int n;
    cin >> n;
    vector<vector<int>> arr(n+1 , vector<int>(n+1 , 0));

    vector<vector<int>> pf(n+1 , vector<int>(n+1 , 0));


    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];

        }
    }


    int a , b , c , d;
    cin >> a >> b >> c >> d;
    cout << pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1] << n1;;
    
    /* for(auto i : pf){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    } */


    return 0;

}   