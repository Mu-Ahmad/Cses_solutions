#include<bits/stdc++.h>
using namespace std;

#define fi              	first
#define si              	second
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

int main() {

	int n; cin >> n;
	mk(x, n, int);
	frange(n) cin >> x[i];
	ll ans = 0;
	f(1, n) {
		ll temp = x[i - 1] - x[i];
		if (temp > 0) {
			x[i] += temp;
			ans += temp;
		}
	}
	//frange(n) cout << x[i] << ' ' << endl;
	cout << ans;
	return 0;
}



