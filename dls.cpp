#include <iostream>
#include <vector>
using namespace std;
#define MAX 100

vector<int> adj[MAX];
bool visited[MAX];

bool dls(int node, int target, int limit) {
       if (node == target) { cout << node << " "; return true; }
    if (limit <= 0) return false;

    visited[node] = true;
    cout << node << " ";
     
          for (int v : adj[node]) {
        if (!visited[v]) {
            if (dls(v, target, limit - 1)) return true; 
        }
    }
    visited[node] = false; 
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int target = 4; int max_depth = 2; 
    cout<<"DLS Traversal path: ";
    if (dls(1, target, max_depth)) {
        cout<<"\nTarget "<<target<< " found within depth "<< max_depth<<endl;
    } else {
        cout<<"\nTarget not found within depth limit."<<endl;
    }
    return 0;
}

// 5 4
// 1 2
// 1 3
// 2 4
// 3 5