#include <bits/stdc++.h>

using namespace std;


/********************************************************************/
#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define REP(i, a, b) for(ll i=a;i<b;i++)
#define REPR(i, a, b) for(ll i=b-1;i>=a;i--)
#define forr(i, n) for(ll i=0;i<n;i++)
#define F first
#define S second
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

void FAST() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll gcd(ll x, ll y) {
	if (x == 0) return y;
	return gcd(y % x, x);
}

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

void count_sort(vector<int> &p, vector<int> &c) {
	int n = p.size();
	vector<int> cnt(n);
	for (auto x : c)
		cnt[x]++;
	vector<int> p_new(n);
	vector<int> pos(n);
	pos[0] = 0;
	for (int i = 1; i < n; i++) {
		pos[i] = pos[i - 1] + cnt[i - 1];
	}
	for (auto x : p) {
		int i = c[x];
		p_new[pos[i]] = x;
		pos[i]++;
	}
	p = p_new;

}

int main() {
	FAST();
	string s;
	cin >> s;
	s += "$";
	int n = s.size();
	vector<int> p(n), c(n);
	vector<pair<char, int>> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = {s[i], i};
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		p[i] = a[i].second;
	}
	//recoding
	c[p[0]] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i].first == a[i - 1].first)
			c[p[i]] = c[p[i - 1]];
		else
			c[p[i]] = c[p[i - 1]] + 1;
	}
	int k = 0;
	while ((1 << k) < n) {
		for (int i = 0; i < n; i++) {
			p[i] = (p[i] - (1 << k) + n) % n;
		}
		count_sort(p, c);

		vector<int> c_new(n);
		c_new[p[0]] = 0;
		for (int i = 1; i < n; i++) {
			pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
			pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
			if (now == prev) {
				c_new[p[i]] = c_new[p[i - 1]];
			} else {
				c_new[p[i]] = c_new[p[i - 1]] + 1;
			}
		}
		c = c_new;
		k++;
	}
	for (int i = 0; i < n; i++)
		cout << p[i] << ' ';
	return 0;

}
