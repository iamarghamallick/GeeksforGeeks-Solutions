#User function Template for python3

#Function to find a continuous sub-array which adds up to a given number.
class Solution:
    def subArraySum(self,arr, n, s): 
        #Write your code her
        # brute-force approch
        # for i in range(n):
        #     for j in range(i, n):
        #         subarr = arr[i:j+1]
        #         if sum(subarr) == s:
        #             return [i+1, j+1]
        # return [-1]
        
        # Sliding Window Approch
        currSum = arr[0]
        start = 0
        for end in range(1, n+1):
            while currSum>s and start<end-1:
                currSum -= arr[start]
                start += 1
                
            if  currSum == s:
                return [start+1, end]
            
            if end < n:
                currSum += arr[end]
                
        return [-1]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

def main():
        T=int(input())
        while(T>0):
            
            NS=input().strip().split()
            N=int(NS[0])
            S=int(NS[1])
            
            A=list(map(int,input().split()))
            ob=Solution()
            ans=ob.subArraySum(A, N, S)
            
            for i in ans:
                print(i, end=" ")
                
            print()
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends