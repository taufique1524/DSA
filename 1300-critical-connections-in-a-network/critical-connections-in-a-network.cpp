class Solution {
private:
    int timer = 0;
public:
    void dfs(int node , int parent , vector<int> & vis , vector<vector<int>>& adj  , vector<int>& low , vector<int> &inTime ,
                      vector<vector<int>> & bridges){
        vis[node] = 1;
        low[node] = inTime[node] = timer;
        timer++;

        for(int it : adj[node]){
            if(it==parent) continue;
            else if(vis[it]==0){
                dfs(it , node , vis , adj , low , inTime , bridges);
                low[node] = min(low[node] , low[it]);
                if(inTime[node]<low[it]){
                    bridges.push_back({it,node});
                }
            }else{
                low[node] = min(low[node] , low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n,vector<int>());
        for(vector<int> & edge : edges){
            int u = edge[0] , v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> low(n);
        vector<int> inTime(n);
        vector<int> vis(n);
        vector<vector<int>> bridges;
        dfs(0,-1,vis,adj,low , inTime , bridges);
        return bridges;
    }
};