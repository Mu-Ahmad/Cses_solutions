#include <bits/stdc++.h>

using namespace std;

void stale_flippant() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

int n, e;
vector<int> arr, visited; 

template<class ADJLIST>
int bfs(ADJLIST neighbours){
  queue<int> q;
  q.push(1);

  int curr;
  while(!q.empty()){
    curr = q.front(); q.pop();

    for(auto& neighbour : neighbours[curr]){
      // cout << neighbour << " *** " << endl;

      if (visited[neighbour] != -1) continue;
      q.push(neighbour);
      visited[neighbour] = curr; 
      // cout << neighbour << " ---> " << curr << endl;

      if (neighbour == n){

        int temp = n;
        while(temp!=1){
          arr.push_back(temp);
          temp =  visited[temp];
        }
        arr.push_back(1);
        return arr.size();
      }
    }
  }

  return -1;
}

int main(){
  stale_flippant();
  cin >> n >> e;
  vector< vector<int> > neighbours(n+1, vector<int>());

  int a, b;
  while(e--){
    cin >> a >> b;
    neighbours[a].push_back(b);
    neighbours[b].push_back(a);
  }

  visited = vector<int>(n+1, -1);

  int ans = bfs(neighbours);

  if(ans==-1)
    cout << "IMPOSSIBLE\n";
  else{
    cout << ans << '\n';
    for (auto itr=arr.rbegin(); itr!=arr.rend(); itr++)
      cout << *itr << ' ';
    cout << '\n';
  }
  return 0;
}
