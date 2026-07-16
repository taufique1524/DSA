class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n , vector<pair<int,int>>());
        for(auto it : roads){
            int u = it[0] , v = it[1] , wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int cnt = 0;
         auto cmp = [](auto & a , auto & b){
            return a.second>b.second;
        };
        using ll = long long;
        const int MOD = (int)1e9+7;
        priority_queue<pair<int,ll> , vector<pair<int,ll>> , decltype(cmp)> q(cmp);
        vector<ll> dist(n , 1e18);
        vector<int> ways(n,0);
        q.push({0 , 0});  // node , dist
        dist[0] = 0;
        ways[0] = 1;
        while(!q.empty()){
            auto temp = q.top();
            int node = temp.first ;
            ll wt = temp.second;
            q.pop();
            for(auto it : adj[node]){
                long long edW = it.second;
                long long adjNode = it.first;
                if(edW + wt < dist[adjNode]){
                    dist[adjNode] = edW + wt;
                    q.push({adjNode , edW+wt});
                    ways[adjNode] = ways[node];
                }else if(edW + wt == dist[adjNode]){
                    ways[adjNode] = ((ways[node]+ways[adjNode])%MOD);
                }
            }
        }
        return ways[n-1];
    }
};