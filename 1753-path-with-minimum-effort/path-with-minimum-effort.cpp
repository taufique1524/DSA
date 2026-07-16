class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size() , m = h[0].size();

        auto cmp = [](auto & a , auto & b){
            return a[2]>b[2]; // min-heap
        };
        priority_queue<vector<int>,vector<vector<int>>, decltype(cmp)> q(cmp);
        vector<vector<int>> dist(n , vector<int>(m,INT_MAX));

        int drow[]= {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        q.push({0,0,0});
        dist[0][0] = 0;
        while(!q.empty()){
            auto temp = q.top();
            q.pop();

            int r = temp[0] , c = temp[1] , wt = temp[2];
            if(r==n-1 && c==m-1) return wt; 
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m){
                    int diff = max(wt,abs(h[nrow][ncol]-h[r][c]));
                    if(diff<dist[nrow][ncol]){
                        dist[nrow][ncol] = diff;
                        q.push({nrow,ncol,diff});
                    }
                }
            }
        }
        return 0;
    }
};