setprecision(n)  // sets no of digits to show after decimal
#define setcount(n) __builtin_popcount(n)      // the number of ones in the int
#define setcountll(n) __builtin_popcountll(n)  // the number of ones in the ll
#define parity(n) \
    __builtin_parity(n)  // the parity (even or odd) of the number of ones
#define clz(n) \
    __builtin_clz(n)  // the number of zeros at the beginning of the number
#define clzll(n) \
    __builtin_clzll(n)  // the number of zeros at the beginning of the ll
#define ctz(n) __builtin_ctz(n)  // the number of zeros at the end of the number

void deb(ll x) { cout << x << endl; }

void deb(int x) { cout << x << endl; }

void deb(unsigned int x) { cout << x << endl; }

void deb(unsigned ll x) { cout << x << endl; }

void deb(float x) { cout << x << endl; }

void deb(double x) { cout << x << endl; }

void deb(long double x) { cout << x << endl; }

void deb(char x) { cout << '\'' << x << '\'' << endl; }

void deb(string s) { cout << '\"' << s << '\"' << endl; }

void deb(vector<ll> v) {
    for (auto x : v) cout << x << ' ';
    cout << endl;
}

void deb(bool bb) { cout << (bb ? "True" : "False") << endl; }

void deb(map<ll, ll> mpp) {
    for (auto x : mpp) cout << x.first << ' ' << x.second << endl;
}

void deb(pair<ll, ll> pp) {
    cout << "{" << pp.first << "," << pp.second << "}" << endl;
}

void deb(vector<pair<ll, ll>> v) {
    for (auto x : v) deb(x);
}

// template <typename T>
// #define o_set(T)                                   \
//     tree<T, null_type, less_equal<T>, rb_tree_tag, \
//          tree_order_statistics_node_update>
// member functions :
// 1. order_of_key(k) : number of elements strictly lesser than k
// 2. find_by_order(k) : k-th element in the set
// MULTISET ==> less_equal
// SET ==> less

ll powM(ll x, ll y, ll m) {
    ll ans = 1, r = 1;
    x %= m;
    while (r > 0 && r <= y) {
        if (r & y) {
            ans *= x;
            ans %= m;
        }
        r <<= 1;
        x *= x;
        x %= m;
    }
    return ans;
}

int add(int a, int b) {
    a += b;
    if (a >= M2) a -= M2;
    return a;
}

int mul(int a, int b) { return a * 1ll * b % M2; }

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

map<long long, long long> factorize(long long n) {
    map<long long, long long> ans;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ans[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        ans[n]++;
        n = 1;
    }
    return ans;
}

ll countBits(ll n) {
    ll count = 0;
    while (n) {
        count++;
        n >>= 1;
    }
    return count;
}

ll isP(ll n) {
    if (n == 0 || n == 1) return 0;
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

ll min(ll a, ll b) {
    if (a < b) return a;
    return b;
}

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd((ll)y % x, (ll)x);
}

ll modI(ll a, ll m) {
    ll m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

ll min(ll a, ll b, ll c) { return min(a, min(b, c)); }

ll min(ll a, ll b, ll c, ll d) { return min(min(a, d), min(b, c)); }

/* **********END OF TEMPLATE*********** */

ll sgn(ll x) {
    if (x > 0) return 1;
    return -1;
}

void solve() {
    // cout<<"DO"<<endl;
    ll n;
    cin >> n;
    ll st, en, val;
    map<ll, ll> cmp;
    vi sts(n), ens(n), vals(n);
    for (ll i = 0; i < n; i++) {
        cin >> st >> en >> val;
        en++;
        cmp[st] = 1;
        cmp[en] = 1;
        sts[i] = st;
        ens[i] = en;
        vals[i] = val;
    }
    ll gg = 1;
    // Coordinate compression
    for (auto &x : cmp) {
        x.second = gg;
        gg++;
    }
    vector<vector<pair<ll, ll>>> pro(gg);
    for (ll i = 0; i < n; i++) {
        pro[cmp[ens[i]]].pb({cmp[sts[i]], vals[i]});
    }
    ll dp[gg] = {};
    for (ll i = 0; i < gg; i++) {
        if (i != 0) {
            dp[i] += dp[i - 1];
        }
        for (auto pp : pro[i]) {
            dp[i] = max(dp[i], dp[pp.first] + pp.second);
        }
    }
    cout << dp[gg - 1] << endl;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << gcd(288, 1234567890) << endl;
    cout << fixed << setprecision(12);
    // CASE(t)
    solve();
    return 0;
}