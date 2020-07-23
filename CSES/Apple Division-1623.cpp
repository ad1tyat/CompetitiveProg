#include <bits/stdc++.h>
using namespace std;
 
/********************************************************************/
#define M1 1000000007
#define M3 1000000009
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
const int mx = 50;
/********************************************************************/
//FAST IO//
void FAST() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 
ll ele, n;
ll allsum = 0, ans = INT_MAX, min_here = 0;
vi v, x;
void check() {
	ll sum1 = 0 ;
	for (auto xx : x) {
		sum1 += v[xx];
	}
	ll sum2 = allsum - sum1;
	ll min_here = abs(sum2 - sum1);
	ans = min(ans, min_here);
	return;
}
void solve(ll ind) {
	if (ind == n) {
		check();
		return;
	}
	solve(ind + 1);	//without taking element;
	x.pb(ind);
	solve(ind + 1);	//taking element v[ind]
	x.pop_back();
}
 
int main() {
	FAST();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ele;
		v.pb(ele);
		allsum += ele;
	}
	solve(0);
	cout << ans << endl;
	return 0;
}
