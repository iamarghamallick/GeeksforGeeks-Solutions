class Solution {
    ArrayList<Integer> findTwoElement(int arr[]) {
        int n = arr.length;
        ArrayList<Integer> ans = new ArrayList<>();
        
        for(int i=0; i<n; i++) {
            if(arr[Math.abs(arr[i])-1] > 0)
                arr[Math.abs(arr[i])-1] = -arr[Math.abs(arr[i])-1];
            else ans.add(Math.abs(arr[i]));
        }
        
        for(int i=0; i<n; i++) {
            if(arr[i] > 0) {
                ans.add(i+1);
                break;
            }
        }
        
        return ans;
    }
}
