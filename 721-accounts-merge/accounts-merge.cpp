class DSU{
private:
    vector<int> parent , rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void un(int u , int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu] = pv;
        }else if(rank[pv]<rank[pu]){
            parent[pv] = pu;
        }else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        //make a map < string , int>
        int n = acc.size();
        DSU dj(n);
        unordered_map<string,int> mp;
        for(int i = 0;i<n;i++){
            for(int j=1;j<acc[i].size();j++){
                if(mp.find(acc[i][j]) == mp.end()){
                    mp[acc[i][j]] = i;
                }else{
                    dj.un(i , mp[acc[i][j]]);
                }
            }
        }
        //making a merged vector 

        vector<vector<string>> merge(n , vector<string>());

        for(auto & it : mp){
            int index = dj.findParent(it.second);
            merge[index].push_back(it.first);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merge[i].size()==0) continue;
            vector<string> temp;
            temp.push_back(acc[i][0]);
            sort(merge[i].begin() , merge[i].end());
            for(auto it : merge[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};