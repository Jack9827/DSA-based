// coded by Jai_Khatri
// queries  add l to r k and reverse l to r substract k

#include <bits/stdc++.h>

using namespace std;
//------------------------------

typedef long long ll;
typedef long double ld;
#define pii pair<ll , ll>
#define vi vector<int>
#define pll pair<ll , ll>
#define vl vector<ll>
#define vb vector<bool>
#define vip(a,n)    for(ll i=0;i<n;i++) cin>>a[i];
#define b(v)         for(auto x:v) cout<<x<<' ';cout<<'\n';
#define n1 "\n"
#define pb push_back
#define ppb pop_back
#define F first
#define S second 
#define all(a) (a).begin() , (a).end()
#define sz(a) ((ll)((a).size()))

const ll INF = 4e18;

//---------------------------------
// coded by Jai_Khatri


void sol(vector<int> arr, vector<vector<int>> q, vector<vector<int>> p) {
    int n = arr.size();
    vector<int> pref(n + 1, 0);

    // Apply forward operations
    for (auto &i : q) {
        int l = i[0] - 1, r = i[1], k = i[2];
        pref[l] += k;
        if (r < n) pref[r] -= k;
    }

    // Apply the prefix sum to the array
    for (int i = 0; i < n; i++) {
        if (i > 0) pref[i] += pref[i - 1];
        arr[i] += pref[i];
    }

    // Reverse the array
    reverse(arr.begin(), arr.end());

    // Reset the prefix sum array for backward operations
    fill(pref.begin(), pref.end(), 0);

    // Apply backward operations
    for (auto &i : p) {
        int l = i[0] - 1, r = i[1], k = i[2];
        pref[l] -= k;
        if (r < n) pref[r] += k;
    }

    // Apply the prefix sum to the reversed array
    for (int i = 0; i < n; i++) {
        if (i > 0) pref[i] += pref[i - 1];
        arr[i] += pref[i];
    }

    // Find the lengths of non-decreasing segments
    vector<int> len;
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && arr[j] >= arr[j - 1]) j++;
        len.push_back(j - i);
        i = j;
    }

    // Merge segments as per the problem statement
    multiset<int> st(len.begin(), len.end());
    vector<int> res;

    while (st.size() > 1) {
        auto it1 = st.begin();
        auto it2 = next(it1);
        
        if (*it1 == *it2) {
            st.insert(*it1 + *it2);
            st.erase(it1);
            st.erase(it2);
        } else {
            res.push_back(*it1);
            st.erase(it1);
        }
    }

    if (!st.empty()) res.push_back(*st.begin());

    // Print the result
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
}
 

// main code starts here


int32_t main(){

    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    int n;
    cin >> n;

    vi a(n);
    vip(a , n);
    int m;
    cin >> m;
    vector<vi> q(m , vi(3)) , p(m , vi(3));
    
    for(int i=0; i<m; i++)
    {
      for(int j=0; j<3; j++)
      {
        cin >> q[i][j];
      }
    }

    for(int i=0; i<m; i++)
    {
      for(int j=0; j<3; j++)
      {
        cin >> p[i][j];
      }
    }
    


    sol(a , q , p);


    return 0;

}   