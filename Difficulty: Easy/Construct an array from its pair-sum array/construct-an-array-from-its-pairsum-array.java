class Solution {
    public ArrayList<Integer> constructArr(int[] arr) {
        int l=arr.length;
        ArrayList<Integer> al= new ArrayList<>();
        int n=1+(int)Math.floor(Math.sqrt(2*l));
        if( l==1)
        {
            al.add(1);
            al.add(arr[0]-1);
            return al;
        }
        int sum= arr[0];  //           a1+a2
        int diff=arr[1]-(arr[n-1]); // a1-a2
        int a1=( sum+diff)/2; 
        al.add(a1);
        for( int i=0;i<n-1;i++)
        {
            al.add(arr[i]-a1);
        }
        return al;
    }
}
