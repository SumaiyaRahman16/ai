#include <iostream>
#include <vector>
using namespace std;
#define MAX 100

vector<int> adj[MAX];
int color[MAX]; 

bool isSafe(int node, int c) {
    for(int neighbor:adj[node]){
        if(color[neighbor]==c) return false;
    }
    return true;
}

bool colorMap(int node, int total_nodes, int m) {
    if(node>total_nodes) return true;
    for(int c=1;c<=m;c++){
        if(isSafe(node,c)){
            color[node]=c; 
            if(colorMap(node+1,total_nodes,m)) return true;
            color[node]=0;
        }
    }
    return false;
}

int main() {
    int n,e,m;
    cout<<"Enter number of regions (nodes) and borders (edges): ";
    cin>>n>>e;
    cout<<"Enter the borders (u and v): \n";
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"Enter the number of available colors (m): ";
    cin>>m;
    for(int i=1;i<=n;i++) color[i]=0;

    if(colorMap(1,n,m)){
        cout<<"\nSolution Found! Assigned colors are:\n";
        for(int i=1;i<=n;i++){
            cout<<"Region "<<i<<" -> Color "<<color[i]<<endl;
        }
    }else{
        cout<<"\nNo solution exists with "<<m<<" colors."<<endl;
    }
    return 0;
}
// 4 5
// 1 2
// 1 3
// 2 3
// 2 4
// 3 4
// 3