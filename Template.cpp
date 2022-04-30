#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops")

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define PI 3.1415926535897932384626
#define setbits(n) __builtin_popcountll(n)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define readv(vec) for(auto &x:vec){cin>>x;}
#define printv(vec) for(auto x: vec){cout<<x<<" ";}cout<<"\n";
#define sortasc(vec) sort(all(vec));
#define sortdes(vec) sort(vec.rbegin(),vec.rend());
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define revloop(i,a,b) for(int i=a;i>=b;i--)
#define forSTL(it,a) for(auto it = a.begin(); it != a.end(); it++)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
// typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds;

const int N = 2e5 + 1;

/*---------------------------------------------DEBUGGING------------------------------------------------------------------------*/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*----------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

ll bin_expo(ll a, ll b, ll mod = MOD) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

ll fermatinv(ll a, ll b) {return bin_expo(a, b - 2, b);} //for prime b

ll mod_add(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (mod_mul(a, fermatinv(b, m), m) + m) % m;}  //only for prime m

ll phi(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i * i <= n; i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

ll nCr(ll n, ll r, ll p) {if (n < r)return 0; if (r == 0)return 1; ull fac[n + 1]; fac[0] = 1; for (ll i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % p; return (fac[n] * fermatinv(fac[r], p) % p * fermatinv(fac[n - r], p) % p) % p;}

vl sieve(ll N) {vl pr; vl lp(N + 1); for (ll i = 2; i <= N; ++i) {if (lp[i] == 0) {lp[i] = i; pr.pb(i);} for (ll j = 0; j < (ll)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)lp[i * pr[j]] = pr[j];} return pr;}

/*-------------------------------------------------MAIN------------------------------------------------------------------------*/

void solve(int Case) {
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << setprecision(12) << fixed;
	int t = 1, c = 1;
	cin >> t;
	while (t--) {
		solve(c++);
	}
}