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
	int n, x; cin >> n >> x;

	int price[n], pages[n];

	frange(n) cin >> price[i];
	frange(n) cin >> pages[i];

	vector< vector<int> > dp(n + 1, vector<int>(x + 1, 0));

	frange(n) {
		for (int j = 0; j <= x; j++) {
			//if we include that
			int current_price = j + price[i];
			int total_page = dp[i][j] + pages[i];

			if (current_price <= x)
				dp[i + 1][current_price] = total_page;

			//if we don't include
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
		}
	}

	// for (int i = 0; i < n + 1; i++) {
	// 	for (int j = 0; j < x + 1; j++)
	// 		cout << dp[i][j] << ' ';
	// 	cout << '\n';
	// }
	// cout << "==============\n";

	cout << dp[n][x] << '\n';

	return 0;
}



