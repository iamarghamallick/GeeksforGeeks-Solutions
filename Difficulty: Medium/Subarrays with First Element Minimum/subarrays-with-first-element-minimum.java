class Solution {
    public int countSubarrays(int[] arr) {
        Stack<Integer> s = new Stack<>();
        int n = arr.length;
        if(n == 0 || n == 1) return n;
        
        int ans = 1;
        s.add(n-1);
        for(int i=n-2; i>=0; i--) {
            while(!s.isEmpty()&&arr[s.peek()]>=arr[i])
                s.pop();

            if(s.isEmpty()) ans += n-i;
            else ans += s.peek()-i;
            
            s.add(i);
        }
        
        return ans;
    }
}
