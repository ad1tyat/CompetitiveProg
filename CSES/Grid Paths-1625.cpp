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
 
ll a = 0;
bool occu[7][7];
bool legal(int x, int y) {
	return x >= 0 && x < 7 && y >= 0 && y < 7 && !occu[x][y];
}
string s;
void fun(ll x, ll y, ll pos) {
	// cout << x << ' ' << y << ' ' << pos << endl;
	if (x == 6 && y == 0) {
		if (pos == 48)
			a++;
		return;
	}
	occu[x][y] = true;
	ll ans = 0;
	ll i = x, j = y;
	if (s[pos] == '?' || s[pos] == 'U')
		if (x && !occu[x - 1][y])
			if (!(!legal(i - 2, j) && legal(i - 1, j + 1) && legal(i - 1 , j - 1)))
				fun(x - 1, y, pos + 1);
	if (s[pos] == '?' || s[pos] == 'D')
		if (x < 6 && !occu[x + 1][y])
			if (!(!legal(i + 2, j) && legal(i + 1, j + 1) && legal(i + 1 , j - 1)))
				fun(x + 1, y,  pos + 1);
	if (s[pos] == '?' || s[pos] == 'L')
		if (y && !occu[x][y - 1])
			if (!(!legal(i, j - 2) && legal(i + 1, j - 1) && legal(i - 1, j - 1)))
				fun(x, y - 1, pos + 1);
	if (s[pos] == '?' || s[pos] == 'R')
		if (y < 6 && !occu[x][y + 1])
			if (!(!legal(i, j + 2) && legal(i + 1, j + 1) && legal(i - 1 , j + 1)))
				fun(x, y + 1, pos + 1);
	occu[x][y] = false;
 
	return;
}
 
const double pi = 3.14159265;
int main() {
	FAST();
	// string s;
	cin >> s;
	for (int i  = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			occu[i][j] = false;
		}
	}
	fun(0, 0, 0);
	cout << a << endl;
	return 0;
 
}
