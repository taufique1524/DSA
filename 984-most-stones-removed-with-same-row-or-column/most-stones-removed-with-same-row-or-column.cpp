class Solution {
public:
    void dfs(int i , vector<int> & vis , vector<vector<int>> & stones){
        vis[i] = 1;
        for(int j=0;j<stones.size();j++){
            if(vis[j]==0){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    dfs(j,vis,stones);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int cnt = 0;
        int n = stones.size();
        vector<int> vis(n,0);
        int grp = 0;
        for(int i=0 ; i<n;i++){
            if(vis[i]==0){
                grp++;
                dfs(i,vis,stones);
            }
        }
        return n-grp;
    }
};