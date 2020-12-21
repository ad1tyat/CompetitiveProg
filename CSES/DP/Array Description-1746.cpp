// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/********************************************************************/
#define M1 1000000007
#define M2 998244353
const double pi = 3.14159265;
 
#define ll long long
#define pll pair<ll, ll>
 
#define forr(i, n) for (ll i = 0; i < n; i++)
#define FOR(x) for (ll kk = 0; kk < (x); kk++)
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define MT make_tuple
#define V(a) vector<a>
#define vi vector<ll>
 
#define CASE(t) \
    ll t;       \
    cin >> t;   \
    while (t--)
 
#define endl '\n'
#define space ' '
#define enter cout << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
 
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define collect(v, n)            \
    for (ll i = 0; i < n; i++) { \
        cin >> v[i];             \
    }
 
#define deci(n) \
    fixed << setprecision(n)  // sets no of digits to show after decimal
#define setcount(n) __builtin_popcount(n)      // the number of ones in the int
#define setcountll(n) __builtin_popcountll(n)  // the number of ones in the ll
#define parity(n) \
    __builtin_parity(n)  // the parity (even or odd) of the number of ones
#define clz(n) \
    __builtin_clz(n)  // the number of zeros at the beginning of the number
#define clzll(n) \
    __builtin_clzll(n)  // the number of zeros at the beginning of the ll
#define ctz(n) __builtin_ctz(n)  // the number of zeros at the end of the number
 
void deb(ll x) { cout << x << endl; }
void deb(int x) { cout << x << endl; }
void deb(unsigned int x) { cout << x << endl; }
void deb(unsigned ll x) { cout << x << endl; }
void deb(float x) { cout << x << endl; }
void deb(double x) { cout << x << endl; }
void deb(long double x) { cout << x << endl; }
void deb(char x) { cout << '\'' << x << '\'' << endl; }
void deb(string s) { cout << '\"' << s << '\"' << endl; }
void deb(vector<ll> v) {
    for (auto x : v) cout << x << ' ';
    cout << endl;
}
void deb(bool bb) { cout << (bb ? "True" : "False") << endl; }
void deb(map<ll, ll> mpp) {
    for (auto x : mpp) cout << x.first << ' ' << x.second << endl;
}
void deb(pair<ll, ll> pp) {
    cout << "{" << pp.first << "," << pp.second << "}" << endl;
}
 
ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd((ll)y % x, (ll)x);
}
 
template <typename T>
#define o_set(T)                                   \
    tree<T, null_type, less_equal<T>, rb_tree_tag, \
         tree_order_statistics_node_update>
// member functions :
// 1. order_of_key(k) : number of elements strictly lesser than k
// 2. find_by_order(k) : k-th element in the set
// MULTISET ==> less_equal
// SET ==> less
 
ll powM(ll x, ll y, ll m) {
    ll ans = 1, r = 1;
    x %= m;
    while (r > 0 && r <= y) {
        if (r & y) {
            ans *= x;
            ans %= m;
        }
        r <<= 1;
        x *= x;
        x %= m;
    }
    return ans;
}
 
map<long long, long long> factorize(long long n) {
    map<long long, long long> ans;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ans[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        ans[n]++;
        n = 1;
    }
    return ans;
}
 
ll countBits(ll n) {
    ll count = 0;
    while (n) {
        count++;
        n >>= 1;
    }
    return count;
}
 
ll isP(ll n) {
    if (n == 0 || n == 1) return 0;
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
 
/*
 * Build Command:
 *
 */
/* **********END OF TEMPLATE*********** */
ll min(ll a, ll b) {
    if (a < b) return a;
    return b;
}
 
ll min(ll a, ll b, ll c) { return min(a, min(b, c)); }
ll min(ll a, ll b, ll c, ll d) { return min(min(a, d), min(b, c)); }
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vi v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll dp[n + 1][m + 1] = {};
    if (v[0] == 0) {
        for (ll mm = 1; mm <= m; mm++) {
            dp[0][mm] = 1;
        }
    } else {
        dp[0][v[0]] = 1;
    }
    for (ll i = 1; i < n; i++) {
        for (ll mm = 1; mm <= m; mm++) {
            if (v[i] == 0 || v[i] == mm) {
                dp[i][mm] = dp[i - 1][mm] % M1 + dp[i - 1][mm - 1] % M1 +
                            dp[i - 1][mm + 1] % M1;
                dp[i][mm] %= M1;
            } else {
                dp[i][mm] = 0;
            }
        }
    }
    ll ans = 0;
    for (ll mm = 1; mm <= m; mm++) {
        ans += dp[n - 1][mm] % M1;
        ans %= M1;
    }
    cout << ans << endl;
    return 0;
}
