class Solution {
    public static void generate(int st, int n, String current, ArrayList<Integer> ans) {
        if(current.length() == n) {
            ans.add(Integer.parseInt(current));
            return;
        }
        for(int i=st; i<=9; i++){
           generate(i+1, n, current+i, ans); 
        }
    }
    
    public static ArrayList<Integer> increasingNumbers(int n) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        if(n == 1) {
            for(int i=0; i<=9; i++){
                ans.add(i);
            }
            return ans;
        } 
        generate(1, n, "", ans);
        return ans;
    }
}
