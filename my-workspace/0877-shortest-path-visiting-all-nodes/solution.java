class Solution {
    private int setbit(int mask, int i){
        return mask | (1<<i);
    }
    public int shortestPathLength(int[][] graph) {
        HashMap<Integer, ArrayList<Integer>> hm = new HashMap<>();
        int n = graph.length;
        for(int i=0; i<n; i++){
            if(!hm.containsKey(i)){
                hm.put(i, new ArrayList<Integer>());
            }
            int m = graph[i].length;
            for(int j=0; j<m; j++){
                hm.get(i).add(graph[i][j]);
            }
        }
        int r = (int)Math.pow(2, n);
        int c = n;
        int dist[][] = new int[r][c];
        for(int i=0; i<r; i++){
            Arrays.fill(dist[i], -1);
        }
        LinkedList<int[]> q = new LinkedList<>();
        for(int i=0; i<n; i++){
            int lead = i;
            int mask = setbit(0, i);
            q.add(new int[]{lead, mask});
            dist[mask][lead] = 0;
        }
        while(q.size() > 0){
            int size = q.size();
            for(int i=0; i<size; i++){
                int[] path = q.remove();
                int lead = path[0];
                int mask = path[1];
                if(mask == r-1){
                    return dist[mask][lead];
                }
                if(hm.containsKey(lead)){
                    for(int child : hm.get(lead)){
                        int newlead = child;
                        int newmask = setbit(mask, newlead);
                        if(dist[newmask][newlead] != -1){
                            continue;
                        }
                        dist[newmask][newlead] = dist[mask][lead] + 1;
                        q.add(new int[]{newlead, newmask});
                    }
                }
            }
        }
        return -1;
    }
}
