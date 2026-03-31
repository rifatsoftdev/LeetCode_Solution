#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Equal Sum Grid Partition II (Prefix Sums / Frequency Map):
    1. The problem asks if we can partition a grid into two non-empty parts (top/bottom or left/right) such that their sums are equal, possibly after moving one cell from one part to the other.
    2. We use a helper function `solve` to check for horizontal partitions (top and bottom). To check for vertical partitions, we transpose the grid and call `solve` again.
    3. For each possible horizontal split line:
        - Maintain the `topSum` and `bottomSum`, along with frequency maps (or arrays) of the values in each part.
        - If `topSum == bottomSum`, a valid partition exists.
        - If `topSum > bottomSum`, we check if moving a value `diff = (topSum - bottomSum) / 2` from top to bottom makes them equal. However, the problem specifically allows moving a cell to the *other* part's boundary or simply moving it if it maintains connectivity.
        - The logic checks if the difference `diff` exists in the current part's frequency map, considering specific constraints on grid dimensions (h, w) to ensure the move is valid according to problem rules.
    4. If any such condition is met for any split line in either orientation, return true.

Time Complexity: O(N * M) where N and M are grid dimensions.
Space Complexity: O(max(N*M, max_val)) for the frequency arrays and transposed grid.
*/

class Solution {
private:
    typedef long long ll;

    bool solve(vector<vector<int>>&grid){
        int n=grid.size(),m=grid[0].size();
        ll bottomSum=0,topSum=0;
        vector<int>bottomFreq(100001,0),topFreq(100001,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bottomSum+=grid[i][j];
                bottomFreq[grid[i][j]]++;
            }
        }

        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                bottomSum-=grid[i][j];
                bottomFreq[grid[i][j]]--;
                topSum+=grid[i][j];
                topFreq[grid[i][j]]++;
            }

            if(topSum==bottomSum)return true;
            ll diffTop=topSum-bottomSum;

            if(diffTop>0 && diffTop<=100000){
                int h=i+1,w=m;

                if(h>1 && w>1){
                    if(topFreq[diffTop])return true;
                }
                else if(h>1 && w==1){
                    if(grid[0][0]==diffTop || grid[i][0]==diffTop)return true;
                }else if(h==1 && w>1){
                    if(grid[0][0]==diffTop || grid[0][w-1]==diffTop)return true;
                }
            }

            ll diffBot=bottomSum-topSum;

            if(diffBot>0 && diffBot<=100000){
                int h=(n-i-1),w=m;

                if(h>1 && w>1){
                    if(bottomFreq[diffBot])return true;
                }else if(h>1 && w==1){
                    if(grid[i+1][0]==diffBot || grid[n-1][0]==diffBot)return true;
                }else if(h==1 && w>1){
                    if(grid[n-1][0]==diffBot || grid[n-1][w-1]==diffBot)return true;
                }
            }
        }

        return false;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if(solve(grid))return true;

        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>mat(m,vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[j][i]=grid[i][j];
            }
        }

        return solve(mat);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> grid1 = {{1,4},{2,3}};
    cout << solution.canPartitionGrid(grid1) << endl;

    vector<vector<int>> grid2 = {{1,2},{3,4}};
    cout << solution.canPartitionGrid(grid2) << endl;

    vector<vector<int>> grid3 = {{1,2,4},{2,3,5}};
    cout << solution.canPartitionGrid(grid3) << endl;

    vector<vector<int>> grid4 = {{4,1,8}, {3,2,6}};
    cout << solution.canPartitionGrid(grid4) << endl;

    return 0;
}