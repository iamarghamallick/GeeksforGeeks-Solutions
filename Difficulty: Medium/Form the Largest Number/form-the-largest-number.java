class Solution {
    public String findLargest(int[] arr) {
        String[] nums=new String[arr.length];
        StringBuilder largestNumber=new StringBuilder();
        int i=0;
        for(int x:arr){
            nums[i++]=String.valueOf(x);
        }
        Arrays.sort(nums,(a,b)->(b+a).compareTo(a+b));
        if(nums[0].charAt(0)=='0'){
            return "0";
        }
        for(String x:nums){
            largestNumber.append(x);
        }
        return largestNumber.toString();
    }
}