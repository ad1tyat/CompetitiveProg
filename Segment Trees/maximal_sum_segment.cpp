#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/********************************************************************/
#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define forr(i, n) for(ll i=0;i<n;i++)
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define MT make_tuple
#define V(a) vector<a>
#define vi vector<ll>
#define endl '\n'
#define ce(ele) cout<<ele<<' '
#define cs(ele) cout<<ele<<'\n'
#define CASE(t) ll t; cin>>t; while(t--)
#define space ' '
#define enter cout<<endl
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define collect(v, n) for(ll i = 0; i < n;i++){cin>>v[i];}

ll gcd(ll x, ll y) {
	if (x == 0) return y;
	return gcd((ll) y % x, (ll) x);
}

template<typename T>
#define o_set(T) tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
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


const double pi = 3.14159265;

/* **********END OF TEMPLATE*********** */

const int mx = 1e5 + 69;

ll vals[mx] = {};
ll sums[4 * mx] = {};
ll pref[4 * mx] = {};
ll suff[4 * mx] = {};
ll maximal[4 * mx] = {};

void combine(ll x) {
	pref[x] = max(pref[2 * x], pref[2 * x + 1] + sums[2 * x]);
	suff[x] = max(suff[2 * x + 1], suff[2 * x] + sums[2 * x + 1]);
	sums[x] = sums[2 * x] + sums[2 * x + 1];
	maximal[x] = max(max(maximal[2 * x], maximal[2 * x + 1]), suff[2 * x] + pref[2 * x + 1]);
}

void build(ll x, ll lx, ll rx) {
	if (rx - lx == 0) {
		sums[x] = vals[lx];
		pref[x] = vals[lx];
		suff[x] = vals[lx];
		maximal[x] = vals[lx];
		return;
	}
	ll mid = (lx + rx) / 2;
	build(2 * x, lx, mid);
	build(2 * x  + 1, mid + 1, rx);
	combine(x);
}
void update(ll x, ll lx , ll rx, ll i, ll val) {
	if (rx - lx == 0) {
		sums[x] = val;
		pref[x] = val;
		suff[x] = val;
		maximal[x] = val;
	}
	else {
		ll mid = (lx + rx) / 2;
		if (i <= mid)
			update(2 * x , lx, mid, i, val);
		else
			update(2 * x + 1, mid + 1, rx, i, val);


		combine(x);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for (ll i = 0; i < n; i++)
		cin >> vals[i];
	build(1, 0, n - 1);
	cout << max(0ll, maximal[1]) << endl;
	while (m--) {
		ll ind, val;
		cin >> ind >> val;
		update(1, 0 , n - 1, ind, val);
		cout << max(0ll, maximal[1]) << endl;
	}
	return 0;
}
