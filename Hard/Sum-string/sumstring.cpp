//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    // string getSum(string &a, string &b) {
    //     string ans = "";
        
    //     reverse(a.begin(), a.end());
    //     reverse(b.begin(), b.end());
        
    //     int carry = 0;
    //     int i = 0;
        
    //     while(i < a.size() && i < b.size()) {
    //         int sum = (a[i] - '0') + (b[i] - '0') + carry;
    //         carry = sum / 10;
    //         sum = sum % 10;
            
    //         ans += to_string(sum);
    //         ++i;
    //     }
        
    //     while(i < a.size()) {
    //         int sum = (a[i] - '0') + carry;
    //         carry = sum / 10;
    //         sum = sum % 10;
            
    //         ans += to_string(sum);
    //         ++i;
    //     }
        
    //     while(i < b.size()) {
    //         int sum = (b[i] - '0') + carry;
    //         carry = sum / 10;
    //         sum = sum % 10;
            
    //         ans += to_string(sum);
    //         ++i;
    //     }
        
    //     if(carry > 0) {
    //         ans += to_string(carry);
    //     }
        
    //     reverse(ans.begin(), ans.end());
        
    //     return ans;
    // }
    
    // bool helper(string &S, string &a, string &b, int n, int p, bool valid) {
    //     if(n == p)
    //         return valid;
            
    //     string need = getSum(a, b);
    //     string curr = "";
        
    //     for(int i=p; i<n; i++) {
    //         curr += S[i];
            
    //         if(curr == need)
    //             return helper(S, b, curr, n, i+1, 1);
    //     }
        
    //     return 0;
    // }
    
    // int isSumString(string S){
    //     // code here 
    //     int n = S.size();
        
    //     function<string(string&, string&)> getSum = [&](string &a, string &b) {
    //         string ans = "";
        
    //         reverse(a.begin(), a.end());
    //         reverse(b.begin(), b.end());
        
    //         int carry = 0;
    //         int i = 0;
        
    //         while(i < a.size() && i < b.size()) {
    //             int sum = (a[i] - '0') + (b[i] - '0') + carry;
    //             carry = sum / 10;
    //             sum = sum % 10;
            
    //             ans += to_string(sum);
    //             ++i;
    //         }
        
    //         while(i < a.size()) {
    //             int sum = (a[i] - '0') + carry;
    //             carry = sum / 10;
    //             sum = sum % 10;
            
    //             ans += to_string(sum);
    //             ++i;
    //         }
        
    //         while(i < b.size()) {
    //             int sum = (b[i] - '0') + carry;
    //             carry = sum / 10;
    //             sum = sum % 10;
            
    //             ans += to_string(sum);
    //             ++i;
    //         }
        
    //         if(carry > 0) {
    //             ans += to_string(carry);
    //         }
        
    //         reverse(ans.begin(), ans.end());
        
    //         return ans;
    //     };
        
    //     function<bool(string&, string&, int, bool)> helper = [&](string &a, string &b, int p, bool valid) {
    //         if(n == p)
    //         return valid;
            
    //         string need = getSum(a, b);
    //         string curr = "";
        
    //         for(int i=p; i<n; i++) {
    //             curr += S[i];
            
    //             if(curr == need)
    //                 return helper(b, curr, i+1, 1);
    //         }
        
    //         return false;
    //     };
        
    //     for(int i=1; i<n+1; i++) {
    //         for(int j=i+1; j<n+1; j++) {
    //             string a = S.substr(0, i);
    //             string b = S.substr(i, j - i);
                
    //             if(helper(a, b, j, 0))
    //                 return 1;
    //         }
    //     }
        
    //     return 0;
    // }
    
string sum(string s1,string s2) { 
    int i=s1.length()-1,j=s2.length()-1; 
    vector<char>ans; 
    
    int x,y,res,rem,carry; 
    char ch; 
    
    while(i>=0 and j>=0) { 
        x=s1[i]-'0'; 
        y=s2[j]-'0'; 
        res=x+y+carry; 
        rem=res%10; 
        carry=res/10; 
        ans.push_back(rem+'0'); 
        i--; 
        j--;
    } 
    
    while(i>=0) { 
        x=s1[i]-'0'; 
        res=x+carry; 
        rem=res%10; 
        carry=res/10; 
        ans.push_back(rem+'0'); 
        i--; 
    } 
    
    while(j>=0) { 
        y=s2[j]-'0'; 
        res=y+carry; 
        rem=res%10; 
        carry=res/10; 
        ans.push_back(rem+'0'); 
        j--; 
    }  
    
    while(carry) { 
       int rem=carry%10; 
       ans.push_back(rem+'0'); 
       carry/=10; 
    } 
    
    string t; 
    int p; 
    for(p=ans.size()-1; p>=0; p--) { 
       if(ans[i]!='0') 
       break; 
    } 
    
    while(p>=0) { 
       t+=ans[p]; 
       p--;; 
    } 
    
    return t; 
} 
 
bool solve(string s,int pos,int l1,int l2) { 
    string s1=s.substr(pos,l1); 
    string s2=s.substr(pos+l1,l2); 
    string s3=sum(s1,s2); 
    int n=s3.length(); 
    if(n>s.length()-pos-l1-l2) 
    return 0; 
    if(s.substr(pos+l1+l2,n)==s3) { 
        if(pos+l1+l2+n==s.length()) 
            return 1; 
        return solve(s,pos+l1,l2,n); 
    } 
    return 0; 
} 
 
int isSumString(string s) { 
    int n=s.length(); 
    for(int i=1;i<n;i++) { 
        for(int j=1;j+i<n;j++) { 
            if(solve(s,0,i,j)) 
            return 1; 
        } 
    } 
    return 0; 
}
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.isSumString(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends