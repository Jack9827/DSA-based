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

    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    string s = "Jai Khatri";

    istringstream ss(s);

    string token;

    while(getline(ss , token  , ' '  ))
    {
        cout << token << n1;
    }


    return 0;

}   