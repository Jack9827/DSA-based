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
class SGTree
{
public:
    vector<int> seg, lazy;
    int n;

    SGTree(int n)
    {
        this->n = n;
        seg = vector<int>(4 * n + 1);
        lazy = vector<int>(4 * n + 1);
    }

    void build(int ind, int lo, int hi, vector<int> &a)
    {
        if (lo == hi)
        {
            seg[ind] = a[lo];
            return;
        }

        int mid = (lo + hi) / 2;
        build(2 * ind + 1, lo, mid, a);
        build(2 * ind + 2, mid + 1, hi, a);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void pointUpdate(int ind, int lo, int hi, int index, int val)
    {
        if (lo == ind && hi == lo)
        {
            seg[ind] = val;
            return;
        }

        int mid = (lo + hi) / 2;
        if (index > mid)
            pointUpdate(2 * ind + 2, mid + 1, hi, index, val);
        else
            pointUpdate(2 * ind + 1, lo, mid, index, val);

        seg[ind] = max(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }

    int query(int ind, int lo, int hi, int l, int r)
    {
        if (r < lo || l > hi)
            return INT_MIN;

        if (lo >= l && r >= hi)
            return seg[ind];

        int mid = (lo + hi) / 2;
        int left = query(2 * ind + 1, lo, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, hi, l, r);

        return max(left, right);
    }

    void rangeUpdate(int ind, int lo, int hi, int l, int r, int val)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] += (hi - lo + 1) * lazy[ind];

            if (lo != hi)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
        }
        lazy[ind] = 0;

        if (r < lo || l > hi || lo > hi)
            return;

        if (lo >= l && hi <= r)
        {
            seg[ind] = (hi - lo + 1) * val;
            if (lo != hi)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            return;
        }

        int mid = (lo+hi)/2;
        rangeUpdate(2*ind+1 , lo , mid , l , r , val);
        rangeUpdate(2*ind+2 , mid+1 , hi , l , r , val);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
};
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