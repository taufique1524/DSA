class Solution {
private:
    int timer = 0;
public:
    void dfs(int node , int parent , vector<int>& low , vector<int> & tin , vector<int> & vis, vector<vector<int>> & adj , vector<vector<int>> & bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it : adj[node]){
            if(it==parent){
                continue;
            }
            else if(vis[it]==0){
                dfs(it , node , low , tin , vis , adj , bridges);
                low[node] = min(low[node] , low[it]);
                if(low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
            }else{
                low[node] = min(low[node] , tin[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n , vector<int>());
        for(auto it : edges){
            int u = it[0] , v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> low(n,-1);
        vector<int> tin(n,-1);
        vector<int> vis(n,0);
        vector<vector<int>> bridges;
        dfs(0,-1,low,tin,vis,adj,bridges);
        return bridges;
    }
};