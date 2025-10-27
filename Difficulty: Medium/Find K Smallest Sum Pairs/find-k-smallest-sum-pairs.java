class Solution {
    public ArrayList<ArrayList<Integer>> kSmallestPair(int[] arr1, int[] arr2, int k) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            new Comparator<int[]> () {
                public int compare(int[] a, int[] b) {
                    return a[0] - b[0];
                }
            }
        );
        HashSet<String> set = new HashSet<>();
        
        pq.offer(new int[]{arr1[0] + arr2[0], 0, 0});
        set.add("0,0");
        
        while(k > 0 && !pq.isEmpty()) {
            int[] temp = pq.poll();
            int sum = temp[0], i = temp[1], j = temp[2];
            
            ans.add(new ArrayList<>(Arrays.asList(arr1[i], arr2[j])));
            k--;
            
            if(i+1 < arr1.length) {
                String key = (i+1) + "," + j;
                if(!set.contains(key)) {
                    pq.offer(new int[]{arr1[i + 1] + arr2[j], i + 1, j});
                    set.add(key);
                }
            }
            
            if(j+1 < arr2.length) {
                String key = i + "," + (j+1);
                if(!set.contains(key)) {
                    pq.offer(new int[]{arr1[i] + arr2[j + 1], i, j + 1});
                    set.add(key);
                }
            }
        }
        
        return ans;
    }
}
