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

int main() {
	string temp;
	cin >> temp;
	int p_count(0), count(0);
	char p = temp[0];
	for (char x : temp) {
		if (x == p)
			count++;
		else {
			p = x;
			count = 1;
		}
		p_count = max(p_count, count);
	}
	cout << p_count ;


	return 0;
}



