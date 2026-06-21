#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 200005; // Increased to prevent out-of-bounds crashes
vector<int> adj[MAX];
bool visited[MAX];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    int start;
    cin >> start;
    bfs(start);

    return 0;
}

// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 0