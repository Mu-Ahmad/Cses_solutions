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

#define MONSTER 0
#define PLAYER 1

char grid[1001][1001];
int path[1001][1001];
int steps[2][10001][10001];
int n, m, s_x, s_y;
queue< pair<int, int> > q;
int d_y[] = {1, -1, 0, 0};
int d_x[] = {0, 0, 1, -1};
char symbol[] = {'D', 'U', 'R', 'L', 'X'};
vector<char> ans;

void bfs(int index){
  int y, x, a , b;
  while(!q.empty()){
    tie(y, x) = q.front(); q.pop();

    // trace the path
    if(index==PLAYER){
      int dy, dx;
      if(y == 0 or x == 0 or y+1 == n or x+1 == m){
        cout << "YES\n";
        while(grid[y][x] != 'A'){
          ans.push_back(symbol[path[y][x]]);
          dy =  d_y[path[y][x]];
          dx =  d_x[path[y][x]];
          y -= dy;
          x -= dx;
        }
        cout << ans.size() << '\n';
        for(auto it = ans.rbegin(); it != ans.rend(); it++)
          cout << *it;
        exit(0);

      }
    }

    for(int i=0; i<4; i++){
      a = y + d_y[i];
      b = x + d_x[i];
      if (a < 0 or a >= n or
          b < 0 or b >= m or
          grid[a][b] == '#' or
          steps[index][a][b] != INT_MAX) continue;
      // deb2(a, b);
      steps[index][a][b] = steps[index][y][x] + 1;
      if(index == PLAYER and steps[index][a][b]>=steps[MONSTER][a][b]) continue;
      path[a][b] = i;
      q.push({a, b});
    }
  }
}

//=================================
int main() {
  stale_flippant();
  cin >> n >> m;
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++){
      cin >> grid[i][j];
      steps[MONSTER][i][j] = steps[PLAYER][i][j] = INT_MAX;
      // path[i][j] = 4;
      if(grid[i][j] == 'M'){
        steps[MONSTER][i][j] = 0;
        q.push({i, j});
      } else if (grid[i][j] == 'A') s_y = i, s_x = j;
    }

    // calculate distances for the monsters
    bfs(MONSTER);

    // check if the player can reach the corner hithout enocuntring any monsters in the path
    q.push({s_y, s_x});
    steps[PLAYER][s_y][s_x] = 0;
    bfs(PLAYER);

    cout << "NO\n"; 

  return 0;
}



