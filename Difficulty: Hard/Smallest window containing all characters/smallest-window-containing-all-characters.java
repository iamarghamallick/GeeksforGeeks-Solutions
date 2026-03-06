class Solution {
    public static String minWindow(String s, String p) {
        int[]cnt=new int[128];
        int req=p.length(),left=-1,min=s.length()+1;
        for(char c:p.toCharArray()){
            ++cnt[c];
        }
        for(int l=0,r=0;r<s.length();r++){
            if(--cnt[s.charAt(r)]>=0)
            --req;
            while(req==0){
                if(r-l+1<min){
                    left=l;
                    min=r-l+1;
                }
                if(++cnt[s.charAt(l++)]>0)
                ++req;
            }
        }
        return left==-1?"":s.substring(left,left+min);
    }
}