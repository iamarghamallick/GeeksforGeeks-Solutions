class Solution {
  public:
    string findSum(vector<int> &arr1, vector<int> &arr2) {
        string ans = "";
        int carry = 0;
        int i = arr1.size() - 1, j = arr2.size() - 1;
        
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += arr1[i--];
            if(j >= 0) sum += arr2[j--];
            ans = to_string(sum % 10) + ans;
            carry = sum / 10;
        }
        
        return ans;
    }
    
    string minSum(vector<int> &arr) {
        // int n = arr.size();
        
        // vector<int> freq(10, 0);
        // for(int num : arr)  freq[num]++;
        
        // vector<int> num1, num2;
        // bool flag = true;
        // for(int i=0; i<10; i++) {
        //     while(freq[i] > 0) {
        //         if(flag && i > 0) num1.push_back(i);
        //         else if(i > 0) num2.push_back(i);
        //         freq[i]--;
        //         flag = !flag;
        //     }
        // }
        
        // return findSum(num1, num2);
        
        string ans;
        int carry = 0;
        sort(arr.begin(), arr.end());
        for (int i = arr.size() - 1; i >= 0; i -= 2) {
            int sum = (arr[i] + (i - 1 >= 0 ? arr[i - 1] : 0) + carry);
            ans.push_back('0' + (sum % 10));
            carry = (sum / 10);
        }
        if (carry) ans.push_back('0' + carry);
        while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};