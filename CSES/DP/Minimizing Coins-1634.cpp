#include <bits/stdc++.h>
using namespace std;

/********************************************************************/
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
/********************************************************************/
const double pi = 3.1415926535;
/********************************************************************/
//FAST IO//
void FAST() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
/********************************************************************/
int main() {
	FAST();
	const int mxn = 1e6 + 5;
	ll dp[mxn] = {};
	ll nc, n;
	cin >> nc >> n;
	ll i, ele;
	ll coins[nc] = {};
	for (auto &c : coins) {
		cin >> c;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = INT_MAX;
		for (auto c : coins) {
			if (i >= c) {
				dp[i] = min(dp[i], 1 + dp[i - c]);
			}
		}
	}
	if (dp[n] == INT_MAX || dp[n] <= 0)
		dp[n] = -1;
	cout << dp[n];
	return 0;
}
