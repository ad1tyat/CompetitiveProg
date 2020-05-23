
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
ll fun(ll a, ll b) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a % M1;
	ll a1 = fun(a, b / 2);
	a1 %= M1;
	if (b % 2 == 0) {
		return (a1 * a1) % M1;
	}
	ll ans = (((a1 * a1) % M1) * a) % M1;
	return ans;
 
}
int main() {
	FAST();
	CASE(t) {
		ll a, b;
		cin >> a >> b;
		cout << fun(a, b) << endl;
	}
}
