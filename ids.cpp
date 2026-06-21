#include <iostream>
#include <vector>
using namespace std;
#define MAX 100

vector<int> adj[MAX];
bool visited[MAX];

bool dls(int node, int target, int limit) {
    if (node == target) return true;
    if (limit <= 0) return false;
    visited[node] = true;
    for (int v : adj[node]) {
        if (!visited[v]) {
            if (dls(v, target, limit - 1)) return true;
        }
    }
    visited[node] = false; 
    return false;
}

void ids(int start, int target, int max_depth_possible) {
    for (int limit = 0; limit <= max_depth_possible; limit++) {
        for (int i = 0; i < MAX; i++) visited[i] = false;
        cout<<"Searching at depth limit " << limit << "... " << endl;
        if (dls(start, target, limit)) {
            cout << "SUCCESS: Target " << target << " found at depth " << limit << "!" << endl;
            return;
        }
    }
    cout << "Target not found within maximum depth." << endl;
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
    int target = 4; int max_limit = 5; 
    ids(1, target, max_limit);
    return 0;
}
// 5 4
// 1 2
// 1 3
// 2 4
// 3 5