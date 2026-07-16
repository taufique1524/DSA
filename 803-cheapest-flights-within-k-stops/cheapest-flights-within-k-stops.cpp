class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(auto & it : flights){
            int u = it[0] , v = it[1] , wt = it[2];
            adj[u].push_back({v,wt});
        }

        auto cmp = [](auto & a , auto & b){
            return a[2]>b[2];
        };
        priority_queue<vector<int> , vector<vector<int>> , decltype(cmp)> q(cmp);
        vector<int> dist( n , INT_MAX);
        dist[src] = 0;
        q.push({src,0,0}); //node,dist,k
        int ans = INT_MAX;
        while(!q.empty()){
            auto temp = q.top();
            q.pop();
            int node = temp[0] , wt = temp[1] , stops = temp[2];
            if(stops>k) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if(wt + edW < dist[adjNode]){
                    dist[adjNode] = wt + edW;
                    q.push({adjNode, dist[adjNode] , stops+1});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};