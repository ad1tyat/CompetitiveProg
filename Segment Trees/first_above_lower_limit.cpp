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
bool cust(const pair<ll, ll> &a, const pair<ll, ll> &b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}
const int mx = 55;
ll adj[mx][mx];
ll ddistance[mx][mx] = {};


struct segtree {
	int size;
	vector<ll> values;
	void init(int n) {
		size = 1;
		while (size < n)
			size *= 2;
		values.assign(2 * size, INT_MIN);
	}



	void build(vector<ll> &a, ll x, ll lx, ll rx) {
		if (rx - lx == 1) {
			//check whether a[lx] is in range(n) or one of those added to make perfect power of 2  n<lx<2^k
			if (lx < (ll)a.size()) {
				values[x] = a[lx];
			}
			return;
		}
		//else recursively build left and right part
		int mid = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, mid);
		build(a, 2 * x + 2, mid, rx);
		values[x] = max(values[2 * x + 1], values[2 * x + 2]);
	}

	void build(vector<ll> &a) {
		build(a, 0, 0 , size);
	}

	void set(int i, int val, int x, int lx, int rx) {

		if (rx - lx == 1) {
			values[x] = val;
			return;
		}
		int mid = (lx + rx) / 2;
		if (i < mid) {
			//Go to left subtree
			set(i, val, 2 * x + 1, lx, mid);
		}
		else {
			//Go to right subtree
			set(i,  val, 2 * x + 2, mid, rx);
		}
		values[x] = max(values[2 * x + 1], values[2 * x + 2]);
	}
	void set(int i, int val) {
		set(i, val, 0, 0 , size);
	}
	ll first_above(ll val, ll l, ll x, ll lx, ll rx) {

		if (values[x] < val)
			return -1;
		if (rx <= l)
			return -1;
		if (rx - lx == 1)
			return lx;
		ll mid = (lx + rx) / 2;
		ll res = first_above(val, l, 2 * x + 1, lx , mid);
		if (res == -1)
			res = first_above(val, l, 2 * x + 2, mid, rx);
		return res;
	}

	ll first_above(ll val, ll l) {
		return first_above(val, l, 0, 0 , size);
	}

};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// ll tc = 0;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ll n, m;
	cin >> n >> m;
	// cout << n << endl;
	segtree st;
	st.init(n);
	vector<ll> eles;
	for (ll i  = 0; i < n; i++) {
		ll ele;
		cin >> ele;
		eles.pb(ele);
		// st.set(i, ele);
	}
	st.build(eles);
	while (m--) {
		ll op;
		cin >> op;
		if (op == 1) {
			ll id, val;
			cin >> id >> val;
			st.set(id, val);
		}
		else {
			ll x, l;
			cin >> x >> l;
			cout << st.first_above(x, l) << endl;
		}

	}
	return 0;
}
