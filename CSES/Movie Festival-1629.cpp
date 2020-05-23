#include <bits/stdc++.h>
using namespace std;

#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPR(i,a,b) for(ll i=b-1;i>=a;i--)
#define forr(i,n) for(ll i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define DB pop_back
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
int main() {
	FAST();
	ll n, a, b;
	cin >> n;
	vector<pair<int, int>> v;

	while (n--) {
		cin >> a >> b;
		v.pb(mp(b, a));
	}
	sort(v.begin(), v.end());
	ll i = 0;
	ll curr_end = v[i].first;
	ll s = 0, ans = 0;
	for (auto x : v) {
		ll ex = x.first;
		ll entry = x.second;
		if (entry >= s) {
			s = ex;
			ans++;
		}
	}

	cout << ans << endl;
}
