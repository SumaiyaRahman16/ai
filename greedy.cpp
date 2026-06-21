#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100

vector<pair<int, int>> adj[MAX];
bool visited[MAX];
int h[MAX]; 

void greedy(int start, int target) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({h[start], start});
    visited[start]=true;

    while(!pq.empty()){
        auto curr = pq.top(); pq.pop();
        int u=curr.second;
        cout<<u<<" ";

        if(u==target){
            cout<<"\nTarget "<<target<<" found!"<<endl;
            return;
        }

        for(auto edge:adj[u]){
            int v=edge.first;
            if(!visited[v]){
                visited[v]=true;
                pq.push({h[v],v});
            }
        }
    }
    cout<<"\nTarget not reachable."<<endl;
}

int main() {
    int n, e; 
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
    cout<<"Greedy Search Path: ";
    greedy(start,target);
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