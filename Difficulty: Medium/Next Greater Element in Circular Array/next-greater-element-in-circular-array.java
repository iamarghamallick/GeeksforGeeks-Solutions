class Solution {
    public ArrayList<Integer> nextGreater(int[] arr) {
        int n = arr.length;
        Stack<Integer> st = new Stack<>();
        ArrayList<Integer> ans = new ArrayList<>(Collections.nCopies(n, -1));
        
        for(int i=2*n-1; i>=0; i--) {
            int index = i % n;
            while(!st.isEmpty() && st.peek() <= arr[index]) st.pop();
            if(!st.isEmpty()) ans.set(index, st.peek());
            st.push(arr[index]);
        }
        
        return ans;
    }
}