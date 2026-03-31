#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Maximize Spanning Tree Stability with Upgrades (Binary Search + Greedy/DSU):
    1. The problem asks for the maximum possible stability (minimum edge weight in the MST) given that we can upgrade up to `k` edges (doubling their weight).
    2. We use binary search on the answer (stability `target`).
    3. For a fixed `target`, we check if it's possible to form a spanning tree where every edge weight is at least `target`.
    4. First, process "must-have" edges (if any are specified). If a mandatory edge's weight is less than `target` even after potential upgrades, the target is impossible.
    5. For the remaining edges, we greedily pick those that already satisfy `s >= target`.
    6. If we still haven't formed a spanning tree, we use our `k` upgrades on edges where `s * 2 >= target`.
    7. If the graph becomes connected using these rules, the `target` is feasible.

Time Complexity: O(E log E + E log(max_weight)) where E is the number of edges.
Space Complexity: O(V + E) for DSU and edge storage.
*/

class DSU {
public:
    vector<int> p, r;
    DSU(int n) {
        p.resize(n);
        r.resize(n,0);
        for(int i=0;i<n;i++) p[i]=i;
    }
    
    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }
    
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

class Solution {
public:
    
    bool can(int n, vector<vector<int>>& edges, int k, int target){
        DSU dsu(n);
        int upgrades = 0;
        
        for(auto &e: edges){
            int u=e[0], v=e[1], s=e[2], must=e[3];
            
            if(must){
                if(s < target) return false;
                if(!dsu.unite(u,v)) return false;
            }
        }
        
        vector<tuple<int,int,int,int>> opt;
        for(auto &e: edges){
            if(e[3]==0){
                opt.push_back({e[2], e[0], e[1], 0});
            }
        }
        
        sort(opt.begin(), opt.end(), greater<>());
        
        for(auto &[s,u,v,_]: opt){
            if(dsu.find(u)==dsu.find(v)) continue;
            
            if(s >= target){
                dsu.unite(u,v);
            } else if(s*2 >= target && upgrades < k){
                upgrades++;
                dsu.unite(u,v);
            }
        }
        
        int root = dsu.find(0);
        for(int i=1;i<n;i++){
            if(dsu.find(i)!=root) return false;
        }
        
        return true;
    }
    
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int l=0, r=2e5, ans=-1;
        
        while(l<=r){
            int mid=(l+r)/2;
            if(can(n,edges,k,mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}