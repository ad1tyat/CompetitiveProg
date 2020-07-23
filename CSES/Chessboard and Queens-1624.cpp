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
ll ans = 0;
bool col[16], diag1[16], diag2[16], used[8][8];
 
 
void fun(ll row) {
	if (row == 8) {
		ans++;
		return;
	}
	for (int c = 0; c < 8; c++) {
		if (col[c] || diag1[row + c] || diag2[row - c + 7] || used[row][c])
			continue;
		col[c] = diag1[row + c] = diag2[row - c + 7] = true;
		fun(row + 1);
		col[c] = diag1[row + c] = diag2[row - c + 7] = false;
	}
}
 
const double pi = 3.14159265;
int main() {
	FAST();
	for (int i  = 0; i < 16; i++) {
		col[i] = diag1[i] = diag2[i] = false;
	}
	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			if (s[j] == '.')
				used[i][j] = 0;
			else
				used[i][j] = 1;
 
		}
	}
	fun(0);
	cout << ans << endl;
	return 0;
 
}
