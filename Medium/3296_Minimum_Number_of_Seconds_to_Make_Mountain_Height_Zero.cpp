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
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        sort(workerTimes.begin(), workerTimes.end());
        
        long long lowTime = 0;
        long long highTime = 1e16;
        long long minRequiredTime = highTime;
        
        while (lowTime <= highTime) {
            
            long long midTime = lowTime + (highTime - lowTime) / 2;
            long long totalHeightReduced = 0;
            
            for (int baseTime : workerTimes) {
                
                long long lowHeight = 0;
                long long highHeight = mountainHeight;
                long long maxWorkerHeight = 0;
                
                while (lowHeight <= highHeight) {
                    
                    long long midHeight = lowHeight + (highHeight - lowHeight) / 2;
                    
                    long long timeNeeded = 
                        (long long)baseTime * midHeight * (midHeight + 1) / 2;
                    
                    if (timeNeeded <= midTime) {
                        maxWorkerHeight = midHeight;
                        lowHeight = midHeight + 1;
                    } 
                    else {
                        highHeight = midHeight - 1;
                    }
                }
                
                totalHeightReduced += maxWorkerHeight;
                
                if (totalHeightReduced >= mountainHeight)
                    break;
            }
            
            if (totalHeightReduced >= mountainHeight) {
                minRequiredTime = midTime;
                highTime = midTime - 1;
            } 
            else {
                lowTime = midTime + 1;
            }
        }
        
        return minRequiredTime;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> workerTimes1 = {2,1,1};
    cout << solution.minNumberOfSeconds(4, workerTimes1) << endl; // Output: 3

    vector<int> workerTimes2 = {3,2,2,4};
    cout << solution.minNumberOfSeconds(10, workerTimes2) << endl; // Output: 12

    vector<int> workerTimes3 = {1};
    cout << solution.minNumberOfSeconds(5, workerTimes3) << endl; // Output: 15

    return 0;
}