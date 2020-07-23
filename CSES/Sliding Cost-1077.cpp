#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

/********************************************************************/
#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define REP(i, a, b) for(ll i=a;i<b;i++)
#define REPR(i, a, b) for(ll i=b-1;i>=a;i--)
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



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vi v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	o_set(ll) s;
	for (int i = 0; i < k; i++)
		s.insert(v[i]);
	ll mid = (k + 1) / 2 - 1;
	ll cost = 0;
	ll prev = *s.find_by_order(mid);
	for (int i = 0; i < k; i++) {
		cost += abs(prev - v[i]);
	}
	cout << cost << ' ';
	for (int i = 0; i + k < n; i++) {
		s.erase(s.find_by_order((s.order_of_key(v[i]))));
		s.insert(v[i + k]);
		ll added = v[i + k];
		ll subt = v[i];
		ll curr = *s.find_by_order(mid);
		cost -= abs(subt - prev);
		cost += abs(added - curr);
		cost -= curr * (k % 2 == 0);
		cost += prev * (k % 2 == 0);
		prev = curr;
		cout << cost << ' ';
	}


}
