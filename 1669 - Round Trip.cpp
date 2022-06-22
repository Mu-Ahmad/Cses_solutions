#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi                first
#define se                second
#define ll                 long long
#define pb                push_back
#define mp                make_pair
#define pqb               priority_queue<int>
#define pqs               priority_queue<int,vi,greater<int> >
#define setbits(x)        __builtin_popcountll(x)
#define zrobits(x)        __builtin_ctzll(x)
#define mod               1000000007
#define inf               1e18
#define deb(x)        cout<< #x << ' ' << x << endl
#define deb2(x, y)          cout<< #x << ' ' << x <<' '<< #y << ' ' << y << endl
#define deb3(x, y, z)       cout<< #x << ' ' << x << ' '<<#y << ' ' << y << ' ' << #z << ' ' << z << endl
#define ps(x,y)           cout<< fixed << setprecision(y) << x
#define reset(a, b)       memset(a, b, sizeof(a))
#define w(x)              int x; cin>>x; while(x--)
#define finc(s, e, k)    for(int i=s; i<e; i+=k)
#define f(s, e)        finc(s, e, 1)
#define frange(x)      finc(0, x, 1)
#define repeat(x)      frange(x)
#define all(cont)         cont.begin(), cont.end()
#define rall(cont)        cont.end(), cont.begin()
#define mk(arr,n,type)          type *arr=new type[n];
#define copyArray(src, des, n, type)  type des[n]; frange(n){des[i] = src[i];}
//================================
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>    vi;
typedef vector<ll>    vl;
typedef vector<pii>    vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//=================================
mt19937                         rng(chrono::steady_clock::now().time_since_epoch().count());
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

ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}

const int N = 1e5+5;
vector<int> neigbors[N];
bool visited[N] = {0};
int pre[N];
  int n, m;

void dfs(int curr, int previous){
  // cout << previous << ' ' << curr << endl;
  // Mark the current node visited and trace the path
  visited[curr] = 1;
  pre[curr] = previous;

  for(auto neigbor : neigbors[curr])
    if (!visited[neigbor]) dfs(neigbor, curr);
    else if (neigbor != previous){
      vector<int> ans;
      int x = curr;
      ans.push_back(x);
      while(pre[x] != neigbor){
        x = pre[x];
        ans.push_back(x);
      }
      ans.push_back(neigbor);
      ans.push_back(curr);

      cout << ans.size() << '\n';
      for (int num : ans) cout << num << ' ';
        cout << '\n';
      // for (int i=1; i<=n; i++) cout << pre[i] << ' ';

      exit(0);
    }
  
}

//=================================
int main() {
  stale_flippant();

  cin >> n >> m;

  int from, to;

  while(m--){
    cin >> from >> to;
    neigbors[from].push_back(to);
    neigbors[to].push_back(from);
  }

  for(int i=1; i<=n; i++)
    if(!visited[i]) dfs(i, -1);

  cout << "IMPOSSIBLE\n";

  return 0;
}



