class Solution {
    public String largestSwap(String s) {
        char[] arr = s.toCharArray();
        char maxDigit = '0';
        int maxIndx = -1, l = -1, r = -1;

        for (int i = arr.length - 1; i >= 0; i--) {
            if (arr[i] > maxDigit) {
                maxDigit = arr[i];
                maxIndx = i;
            } else if (arr[i] < maxDigit) {
                l = i;
                r = maxIndx;
            }
        }

        if (l == -1) return s;

        char temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;

        return new String(arr);
    }
}