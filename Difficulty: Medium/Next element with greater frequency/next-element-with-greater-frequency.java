class Solution {
    public ArrayList<Integer> nextFreqGreater(int[] arr) {
        int max = Integer.MIN_VALUE;
        for(int i=0; i<arr.length; i++)
            if(max < arr[i])
                max = arr[i];
        
        int[] num = new int[max+1];
        for(int i=0; i<arr.length; i++)
            num[arr[i]]++;
        
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0; i<arr.length-1; i++) {
            boolean flag = true;
            for(int j=i+1; j<arr.length; j++) {
                if(num[arr[i]] < num[arr[j]]) {
                    list.add(arr[j]);
                    flag = false;
                    break;
                }
            }
            if(flag) list.add(-1);
        }
        
        list.add(-1);
        return list;
    }
}