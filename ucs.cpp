#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100
#define INF 1e9

vector<pair<int, int>> adj[MAX];
int dist[MAX];


void ucs(int start, int target) {
    for (int i=0; i<MAX; i++) dist[i] = INF;
    

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start}); 

    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        int c = curr.first; int u = curr.second;

        if (u == target) {
            cout << "Target " << target << " found with minimum cost: " << c << endl;
            return;
        }
        if (c > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first; int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Target not reachable." << endl;
}

int main() {
    int n, e; cin>>n>>e;
    for (int i=0; i<e; i++) {
        int u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w}); 
    }
    int start=1;
     int target = 4;
    ucs(start, target);
    return 0;
}
// 4 5
// 1 2 2
// 1 3 5
// 2 4 6
// 2 3 2
// 3 4 1