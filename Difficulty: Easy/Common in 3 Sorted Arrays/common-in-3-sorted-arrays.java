class Solution {
    public ArrayList<Integer> commonElements(int[] a, int[] b, int[] c) {
        ArrayList<Integer> ans = new ArrayList<>();
        
        int lenA = a.length;
        int lenB = b.length;
        int lenC = c.length;
        
        int i = 0;
        int j = 0;
        int k = 0;
        
        while(i < lenA && j < lenB && k < lenC) {
            if(a[i] == b[j] && b[j] == c[k]) {
                if(ans.size() > 0 && ans.get(ans.size()-1) != a[i])
                    ans.add(a[i]);
                if(ans.size() == 0) {
                    ans.add(a[i]);
                }
                i++; j++; k++;
            } else if(a[i] < b[j]) {
                i++;
            } else if(b[j] < c[k]) {
                j++;
            } else {
                k++;
            }
        }
        
        return ans;
    }
}