#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int minimax(int depth, int nodeIndex, bool isMax, int scores[], int h) {
    // Base Case: If we reached a leaf node, return its score
    if (depth == h) {
        return scores[nodeIndex];
    }

    if (isMax) {
        return max(minimax(depth + 1, nodeIndex * 2, false, scores, h),
                   minimax(depth + 1, nodeIndex * 2 + 1, false, scores, h));
    } 
    else {
        return min(minimax(depth + 1, nodeIndex * 2, true, scores, h),
                   minimax(depth + 1, nodeIndex * 2 + 1, true, scores, h));
    }
}

int main() {

    int scores[] = {3, 5, 2, 9, 12, 5, 23, 23};
    int n = sizeof(scores) / sizeof(scores[0]);
    int h = log2(n); 

    int rootValue = minimax(0, 0, true, scores, h);
    
    cout << "The optimal value at the root is: " << rootValue << endl;
    return 0;
}