class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        //topo sort of the reversed graphj 
        
        //reverse the edges of the graph 
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        int n = graph.length;
        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
        }
        int [] indeg = new int[n];
        for(int i=0;i<n;i++){
            for(int j : graph[i]){
                adj.get(j).add(i);
                indeg[i]++;
            }
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.offer(i);
            }
        }
        //topo sort 
        ArrayList<Integer> ans = new ArrayList<>();
        while(!q.isEmpty()){
            int node = q.poll();
            ans.add(node);
            for(int a : adj.get(node)){
                indeg[a]--;
                if(indeg[a]==0) q.offer(a);
            }
        }
        Collections.sort(ans);
        return ans;
    }
}