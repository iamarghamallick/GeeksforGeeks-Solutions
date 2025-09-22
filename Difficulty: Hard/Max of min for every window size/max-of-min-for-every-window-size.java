class Solution {
    public ArrayList<Integer> maxOfMins(int[] arr) {
        int n = arr.length;
        Stack<Integer> st = new Stack<>();
        int[] left = new int[n];
        int[] right = new int[n];
        
        for(int i=0; i<n; i++) {
            left[i] = -1;
            right[i] = n;
        }
        
        for(int i=0; i<n; i++) {
            while(!st.isEmpty() && arr[st.peek()] >= arr[i])
                st.pop();
            
            if(!st.isEmpty()) left[i] = st.peek();
            st.push(i);
        }
        
        while(!st.isEmpty()) st.pop();
        
        for(int i=n-1; i>=0; i--) {
            while(!st.isEmpty() && arr[st.peek()] >= arr[i])
                st.pop();
            
            if(!st.isEmpty()) right[i] = st.peek();
            st.push(i);
        }
        
        int[] ans = new int[n+1];
        
        for(int i=0; i<n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len] = Math.max(ans[len], arr[i]);
        }
        
        for(int i=n-1; i>=1; i--)
            ans[i] = Math.max(ans[i], ans[i+1]);
        
        ArrayList<Integer> res = new ArrayList<>();
        for(int i=1; i<=n; i++)
            res.add(ans[i]);
            
        return res;
    }
}