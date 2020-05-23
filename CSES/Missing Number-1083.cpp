#include <bits/stdc++.h>
using namespace std;

/********************************************************************/
/*
Codeforces : @a.trivedi
Codechef   : @adityat25
HackerRank : @adityatrivedi
 
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
	ll n;
	cin >> n;
	ll i, ele;
	set<ll> ss;
	forr(i, n - 1) {
		cin >> ele;
		ss.insert(ele);
	}
	ll cnt = 1, f = 1;
	for (auto s : ss) {
		if (s != cnt) {
			f = 0;
			cout << cnt << endl;
			break;
		}
		cnt++;
	}
	if (cnt == n)
		cout << n << endl;
 
 
	return 0;
}
