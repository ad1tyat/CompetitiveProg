
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
 
	string s ;
	cin >> s;
	sort(s.begin(), s.end());
	vector<string> vv;
	do {
		vv.pb(s);
	} while (next_permutation(s.begin(), s.end()));
	cout << vv.size() << endl;
	for (auto x : vv) {
		cout << x << endl;
	}
	return 0;
}
