class Solution {
    public ArrayList<Integer> reducePairs(int[] arr) {
        ArrayList<Integer> ans = new ArrayList<>();
        for(int num : arr) {
            while(!ans.isEmpty() && ans.get(ans.size()-1) * num < 0) {
                int top = ans.get(ans.size()-1);
                if(Math.abs(top) > Math.abs(num)) {
                    num = top;
                    ans.remove(ans.size()-1);
                } else if(Math.abs(top) < Math.abs(num)) {
                    ans.remove(ans.size()-1);
                } else {
                    ans.remove(ans.size()-1);
                    num = 0;
                    break;
                }
            }
            if(num != 0) {
                ans.add(num);
            }
        }
        return ans;
    }
}