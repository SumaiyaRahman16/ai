#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 1e9;

int minimaxAlphaBeta(int depth, int nodeIndex, bool isMax, int scores[], int h, int alpha, int beta) {
    if (depth == h) return scores[nodeIndex];

    if (isMax) {
        int best = -INF;
        for (int i=0;i<2; i++) { // 2 children per node
            int val = minimaxAlphaBeta(depth + 1, nodeIndex * 2 + i, false, scores, h, alpha, beta);
            best = max(best, val);
            alpha = max(alpha, best);
            
   
            if (beta <= alpha) break; 
        }
        return best;
    } else {
        int best=INF;
        for (int i=0;i<2; i++) {
            int val = minimaxAlphaBeta(depth + 1, nodeIndex * 2 + i, true, scores, h, alpha, beta);
            best = min(best, val);
            beta = min(beta, best);
            
      
            if (beta <= alpha) break;
        }
        return best;
    }
}

int main() {
    int scores[] = {3, 5, 2, 9, 12, 5, 23, 23};
    int n = sizeof(scores) / sizeof(scores[0]);
    int h = log2(n);

    int rootValue = minimaxAlphaBeta(0, 0, true, scores, h, -INF, INF);
    cout << "Optimal value with Alpha-Beta Pruning: " << rootValue << endl;
    return 0;
}