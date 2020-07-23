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
void FAST() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 
/* **********END OF TEMPLATE*********** */
 
const double pi = 3.14159265;
int main() {
	FAST();
	ll n;
	cin >> n;
	ll total = n * (n + 1) / 2;
	if (total % 2 == 1) {
		cout << "NO";
	}
	else {
		cout << "YES" << endl;
		vi a1, a2;
		total /= 2;
		while (n) {
			if (total >= n) {
				total -= n;
				a1.pb(n);
			}
			else {
				a2.pb(n);
			}
			n--;
		}
		cout << a1.size() << endl;
		for (auto x : a1)
			cout << x << ' ';
		cout << endl;
		cout << a2.size() << endl;
		for (auto x : a2)
			cout << x << ' ';
		cout << endl;
	}
	return 0;
 
}
