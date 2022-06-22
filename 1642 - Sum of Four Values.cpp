#include<bits/stdc++.h>
using namespace std;

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
#define ps(x,y)         	fixed<<setprecision(y)<<x
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

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

//=================================
int main() {
	stale_flippant();
	int n, t; cin >> n >> t;

	if (n < 4) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	int temp[n];

	frange(n) cin >> temp[i];

	vector<tuple<int, int, int>> arr;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			arr.emplace_back(temp[i] + temp[j], i + 1, j + 1);

	sort(all(arr));
	int a, b, c, x, y, z;
	for (unsigned int i = 0; i < arr.size() - 1; i++) {
		tie(a, b, c) = arr[i];
		if (a * 2 > t) break;

		auto it = lower_bound(arr.begin() + i + 1, arr.end(), make_tuple(t - a, 0, 0));

		tie(x, y, z) = *it;
		while (a + x == t) {
			if (y == b or y == c or z == b or z == c) {
				it++;
				tie(x, y, z) = *it;
				continue;
			}
			cout << b << ' ' << c << ' ' << y << ' ' << z << '\n';
			return 0;
		}
	}

	cout << "IMPOSSIBLE\n";
	return 0;
}



