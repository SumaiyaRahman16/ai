

#include <iostream>
#include <vector>
using namespace std;

#define MAX 100

using namespace std;
vector<int>adj[MAX];
bool visited[MAX];
//vcdfs
void dfs(int node){
  visited[node]=true;
  cout<<node<<" ";
  for(int v:adj[node]){
    if(!visited[v]){
      dfs(v);
    }
  }

}

int main(){
  int n,e;
  cin>>n>>e;
  for(int i=0;i<MAX;i++){
    visited[i]=false;

  }
  for (int i=0;i<e;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);// starting with first node
}
// 6 7
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 4 6
// 5 6