#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Find Center of Star Graph:
    1. You are given an array edges where edges[i] = [ui, vi] indicates that there is an edge between ui and vi in the graph.
    2. The graph is a star graph, meaning there is exactly one center node and exactly n - 1 edges that connect the center node with every other node.
    3. Return the center of the given star graph.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> edges1 = {{1, 2}, {2, 3}, {4, 2}};
    cout << solution.findCenter(edges1) << endl;

    vector<vector<int>> edges2 = {{1, 2}, {5, 1}, {1, 3}, {1, 4}};
    cout << solution.findCenter(edges2) << endl;
    
    return 0;
}