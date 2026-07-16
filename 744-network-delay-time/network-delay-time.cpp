class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1 , vector<pair<int,int>>());
        for(auto & edge : times){
            int u = edge[0] , v = edge[1] , wt = edge[2];
            adj[u].push_back({v,wt});
        }
        auto cmp = [](auto & a , auto & b){
            return a.second>b.second;
        };
        priority_queue<pair<int,int> , vector<pair<int,int>> , decltype(cmp)> q(cmp);
        vector<int> dist(n+1 , INT_MAX);
        q.push({k , 0});
        dist[k] = 0;
        while(!q.empty()){
            auto temp = q.top();
            q.pop();
            int node = temp.first;
            int wt = temp.second;
            for(auto it : adj[node]){
                int edW = it.second;
                int adjNode = it.first;
                if(wt + edW < dist[adjNode]){
                    dist[adjNode] = wt + edW ;
                    q.push({adjNode,wt+edW});
                }
            }
        }
        int ans = 0;
        for(int i =1 ; i<=n; i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans = max(ans , dist[i]);
        }
        return ans;
    }
};