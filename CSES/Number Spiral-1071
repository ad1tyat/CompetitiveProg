
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
	CASE(t) {
		ll row, col, ans;
		cin >> row >> col;
		if (row % 2 == 0) {
			if (col <= row) {
				ans = row * row - (col - 1);
			} else {
				if (col % 2 == 1) {
					ll adder = col * col;
					if (row <= col)
						ans = adder - row + 1;
				}
				else {
					ll adder = (col - 1) * (col - 1);
					if (row <= col)
						ans = adder + row;
				}
			}
		}
		else {
			ll adder = (row - 1) * (row - 1 ) + 1;
			if (col <= row) {
				ans = adder + col - 1;
			}
			else {
				if (col % 2 == 1) {
					ll adder = col * col;
					if (row <= col)
						ans = adder - row + 1;
				}
				else {
					ll adder = (col - 1) * (col - 1);
					if (row <= col)
						ans = adder + row;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
