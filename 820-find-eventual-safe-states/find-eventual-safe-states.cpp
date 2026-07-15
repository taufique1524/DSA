class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n , vector<int>());
        vector<int> indeg(n,0);
        for(int i=0;i<n;i++){
            int u = i;
            for(int a: graph[i]){
                int v = a;
                adj[v].push_back(u);
                indeg[u]++;
            }
        }
        //perform topo sort 
        queue<int> q;
        for(int i=0 ; i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                cout<<i<<" ";
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int a : adj[node]){
                indeg[a]--;
                if(indeg[a]==0){
                    q.push(a);
                }
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};