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


ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

int n = 8;
int ans = 0;
int col[8] = {0}, diag1[20] = {0}, diag2[20] = {0};
char grid[8][8];

void search(int y) {
	if (y == n) {
		ans++;
		return;
	}
	frange(n) {
		if (col[i] or diag1[i + y] or diag2[i - y + n - 1]) continue;
		if (grid[y][i] == '*') continue;
		col[i] = diag1[i + y] = diag2[i - y + n - 1] = 1;
		search(y + 1);
		col[i] = diag1[i + y] = diag2[i - y + n - 1] = 0;

	}
}
//=================================
int main() {
	frange(n) {
		for (int j = 0; j < 8; j++) {
			cin >> grid[i][j];
		}
	}
	search(0);
	cout << ans;
	return 0;
}



