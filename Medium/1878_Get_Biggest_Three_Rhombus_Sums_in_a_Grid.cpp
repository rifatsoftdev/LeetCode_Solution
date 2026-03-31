#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:


*/

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int, greater<int>> s;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                s.insert(grid[i][j]); // size 0

                for(int k=1;;k++){
                    if(i-k<0 || i+k>=m || j-k<0 || j+k>=n) break;

                    int sum=0;

                    int x=i-k,y=j;

                    for(int t=0;t<k;t++) sum+=grid[x+t][y+t];
                    for(int t=0;t<k;t++) sum+=grid[x+k+t][y+k-t];
                    for(int t=0;t<k;t++) sum+=grid[x+2*k-t][y-t];
                    for(int t=0;t<k;t++) sum+=grid[x+k-t][y-k+t];

                    s.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(int x: s){
            ans.push_back(x);
            if(ans.size()==3) break;
        }
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> grid1 = {{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
    vector<int> result = solution.getBiggestThree(grid1);
    printVec(result); // Expected: [228, 216, 211]

    vector<vector<int>> grid2 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result2 = solution.getBiggestThree(grid2);
    printVec(result2); // Expected: [20, 9, 8]

    vector<vector<int>> grid3 = {{7,7,7}};
    vector<int> result3 = solution.getBiggestThree(grid3);
    printVec(result3); // Expected: [7]

    return 0;
}