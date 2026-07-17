class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n , vector<int>(n,1e8));
        auto cmp = [](auto& a , auto &b){
            return a[2]>b[2];
        };
        priority_queue<vector<int> , vector<vector<int>> , decltype(cmp)> q(cmp);
        //r,c,t
        q.push({0,0,grid[0][0]});
        dist[0][0] = grid[0][0];
        int time = grid[0][0];
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        while(!q.empty()){
            auto temp = q.top();
            q.pop();
            int r = temp[0] , c = temp[1] , t = temp[2];
            time = max(t , time);
            if(r==n-1 && c==n-1) return time;
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){
                    int t_adj = max(grid[nrow][ncol],t);
                    if(dist[nrow][ncol]>t_adj){
                        dist[nrow][ncol] = t_adj;
                        q.push({nrow,ncol,t_adj});
                    }
                }
            }
        }
        return  -1;
    }
};