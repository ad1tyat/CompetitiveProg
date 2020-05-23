
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll M1 = 1e9 + 7;
	ll n;
	cin >> n;
	ll m = 5, ans = 0;
	while (n >= m) {
		ans += (n / m);
 
		m *= 5;
 
	}
	cout << ans << endl;
}
