class Solution {
    public int [] findOrder(int n, int[][] edges) {
        //make the adj list 
        ArrayList<ArrayList<Integer>> adj= new ArrayList<>();
        for(int i=0;i<n;i++){
          adj.add(new ArrayList<>());
        }
        int[] indeg= new int[n];
        for(int[] edge: edges){
            int u = edge[0];
            int v= edge[1];
            adj.get(v).add(u);
            indeg[u]++;
        }
        // topo sort 
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<n;i++){
            if(indeg[i] == 0){
                q.offer(i);
            }
        }
        int cnt = 0;
        int [] ans = new int[n];
        while(!q.isEmpty()){
            int node = q.poll();
            ans[cnt] = node;
            cnt++;
            for(int a : adj.get(node)){
                indeg[a]--;
                if(indeg[a]==0) q.offer(a);
            }
        }
        if(cnt==n) return ans;
        return new int[]{};
        
        
    }
}