class Solution {
public:
    bool isValid(int r , int c , vector<vector<int>> & grid){
        int n = grid.size();
        if(r>=0 && r<n && c>=0 && c<n && grid[r][c] == 0){
            return true;
        }
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n = grid.size() , m = grid[0].size();

        auto cmp = [](auto & a , auto & b){
            return a[2]>b[2];
        };
        priority_queue<vector<int> , vector<vector<int>> , decltype(cmp)> q(cmp);
        int drow[] = {-1 ,0, 1, 0 ,1,1,-1,-1};
        int dcol[] = {0 , 1, 0 ,-1,-1,1,1,-1};
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        q.push({0,0,1});
        dist[0][0] = 1;
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int r = it[0] , c = it[1] , wt = it[2];
            if(r==n-1 && c==n-1) return wt;
            for(int i=0;i<8;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(i<=3 && isValid(nrow,ncol,grid) && wt + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = wt+1;
                    q.push({nrow,ncol,1+wt});
                }else if(i>=4 && isValid(nrow,ncol,grid) && wt+1<dist[nrow][ncol]){
                    dist[nrow][ncol] = wt+1;
                    q.push({nrow,ncol ,wt+1});
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};