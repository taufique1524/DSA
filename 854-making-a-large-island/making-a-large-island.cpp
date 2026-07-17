class DSU{
private:
    vector<int> parent;
    vector<int> rank;
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

    void unionByRank(int u , int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
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
    bool isValid(int r , int c , int n){
        if(r>=0 && r<n && c>=0 && c<n) return true;
        return false;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dj(n*n);
        vector<vector<int>> vis(n, vector<int>(n,0));
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        queue<pair<int,int>> zeroes;
        unordered_map<int,int> mp;
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) zeroes.push({i,j});
                else{
                    if(vis[i][j]==0){
                        int area = 0;
                        queue<pair<int,int>> ones;
                        vis[i][j] = 1;
                        area++;
                        ones.push({i,j});
                        int p = n*i+j;
                        while(!ones.empty()){
                            auto temp = ones.front();
                            ones.pop();
                            int r = temp.first;
                            int c = temp.second;
                            int node = dj.findParent(r*n +c);
                            for(int i=0;i<4;i++){
                                int nrow = r + drow[i];
                                int ncol = c + dcol[i];
                                if(isValid(nrow,ncol,n) && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                                    int adjNode = dj.findParent(nrow*n + ncol);
                                    ones.push({nrow,ncol});
                                    vis[nrow][ncol]=1;
                                    area++;
                                    if(node!=adjNode){
                                        dj.unionByRank(node , adjNode);
                                    }
                                }
                            }
                        }
                        //bfs complete  
                        mp[dj.findParent(p)] = area;
                        maxi = max(area , maxi);
                    }
                }
            }
        }

        if(zeroes.empty()) return maxi;
        while(!zeroes.empty()){
            auto temp = zeroes.front();
            zeroes.pop();
            int r = temp.first;
            int c = temp.second;
            int area = 1;
            unordered_set<int> st;
            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c + dcol[i];
                if(isValid(nrow, ncol , n) && grid[nrow][ncol]==1){
                    st.insert(dj.findParent(nrow*n+ncol));
                }
            }

            for(int it : st){
                area+= mp[it];
            }
            maxi = max(area , maxi);
        }
        return maxi;
    }
};