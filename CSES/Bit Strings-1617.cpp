
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll M1 = 1e9 + 7;
	ll n;
	cin >> n;
	ll ans = 2, cnt = 1;
	while (cnt < n) {
		cnt++;
		ans *= 2;
		ans %= M1;
	}
	cout << ans << endl;
}
