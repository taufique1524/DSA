class DSU{
private:
    vector<int> parent , rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void un(int u , int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu] = pv;
        }else if(rank[pv]<rank[pu]){
            parent[pv] = pu;
        }else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int mr = -1 , mc = -1;
        int n = stones.size();
        for(int i=0;i<n;i++){
            mr = max(mr , stones[i][0]);
            mc = max(mc , stones[i][1]);
        }
        DSU dj(mr+mc+2);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int r = stones[i][0];
            int c = stones[i][1]+mr+1;
            dj.un(r,c);
            mp[r] = 1;
            mp[c] = 1;
        }
        int cnt =0;
        for(auto & it : mp){
            if(it.first==dj.findParent(it.first)){
                cnt++;
            }
        }
        return n-cnt;
    }
};