#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi              	first
#define se              	second
#define ll             		long long
#define pb              	push_back
#define mp              	make_pair
#define pqb             	priority_queue<int>
#define pqs             	priority_queue<int,vi,greater<int> >
#define setbits(x)      	__builtin_popcountll(x)
#define zrobits(x)      	__builtin_ctzll(x)
#define mod             	1000000007
#define inf             	1e18
#define deb(x)				cout<< #x << ' ' << x << endl
#define deb2(x, y)          cout<< #x << ' ' << x <<' '<< #y << ' ' << y << endl
#define deb3(x, y, z)       cout<< #x << ' ' << x << ' '<<#y << ' ' << y << ' ' << #z << ' ' << z << endl
#define ps(x,y)         	cout<< fixed << setprecision(y) << x
#define reset(a, b)     	memset(a, b, sizeof(a))
#define w(x)            	int x; cin>>x; while(x--)
#define finc(s, e, k)		for(int i=s; i<e; i+=k)
#define f(s, e)				finc(s, e, 1)
#define frange(x)			finc(0, x, 1)
#define repeat(x)			frange(x)
#define all(cont)       	cont.begin(), cont.end()
#define rall(cont)      	cont.end(), cont.begin()
#define mk(arr,n,type)  				type *arr=new type[n];
#define copyArray(src, des, n, type)	type des[n]; frange(n){des[i] = src[i];}
//================================
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//=================================
mt19937                 				rng(chrono::steady_clock::now().time_since_epoch().count());
//=================================
void stale_flippant() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

template<class Container>
void split(const string& str, Container& cont, char delim = ' ') {
	stringstream ss(str);
	string token;
	while (getline(ss, token, delim))
		cont.push_back(token);
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

//=================================
int main() {
	stale_flippant();

	vector< vector<ll> > dp(1000001, vector<ll>(2, 0));

	//Base case
	dp[1][0] = dp[1][1] = 1;


	//Fill the dp
	for (ll i = 2; i <= 1000000; i++) {
		//we put a 2x1 block or 2 1x1 block
		ll op1 = (dp[i - 1][0] + dp[i - 1][1]) % mod;
		// we extend 2 1X1 blocks
		ll op2 = dp[i - 1][0];
		// we extend 1 and put 1 1x1
		ll op3 = (2 * dp[i - 1][0]) % mod;
		// we extend 1 2X2 block
		ll op4 = dp[i - 1][1];

		dp[i][0] = (op1  + op2  + op3 ) % mod;
		dp[i][1] = (op1  + op4 ) % mod;

	}

	// Answer the queries
	w(t) {
		int n; cin >> n;
		cout << (dp[n][0] + dp[n][1]) % mod << "\n";
	}

	return 0;
}

/*
Input:
4
2
6
1337
1000000
Output:
8
2864
640403945
211059306
*/



