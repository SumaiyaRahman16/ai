#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100
#define INF 1e9

vector<pair<int, int>> adj[MAX];
int g[MAX]; 
int h[MAX]; 

void a_star(int start, int target) {
    for(int i=0;i<MAX;i++)g[i]=INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    g[start]=0;
    pq.push({g[start]+h[start],start});

    while(!pq.empty()){
        auto curr=pq.top();pq.pop();
        int f=curr.first;int u=curr.second;

        if(u==target){
            cout<<"Target "<<target<<" found with total cost: "<<g[u]<<endl;
            return;
        }

        for(auto edge:adj[u]){
            int v=edge.first;int weight=edge.second;
            if(g[u]+weight<g[v]){
                g[v]=g[u]+weight;
                int f_v=g[v]+h[v];
                pq.push({f_v,v});
            }
        }
    }
    cout<<"Target not reachable."<<endl;
}

int main() {
    int n,e; 
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v,w; 
        cin>>u>>v>>w;
        adj[u].push_back({v,w}); 
    }
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    int start=1;int target=4;
    a_star(start,target);
    return 0;
}
// 4 5
// 1 2 2
// 1 3 5
// 2 4 6
// 2 3 2
// 3 4 1
// 5
// 4
// 2
// 0