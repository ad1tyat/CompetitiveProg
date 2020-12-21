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
const int mxn = 1e3 + 5;
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
	int mod = 1e9 + 7;
	int n;
	cin >> n;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < n; j++) {
			if (row[j] == '.') {
				if (i > 0) {
					(dp[i][j] += dp[i - 1][j]) %= mod;
				}
				if (j > 0) {
					(dp[i][j] += dp[i][j - 1]) %= mod;
				}
			} else {
				dp[i][j] = 0;
			}
		}
	}
	cout << dp[n - 1][n - 1] << endl;
	return 0;
}