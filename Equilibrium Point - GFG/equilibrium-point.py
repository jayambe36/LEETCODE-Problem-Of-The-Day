# User function Template for python3

class Solution:
    # Complete this function
    
    #Function to find equilibrium point in the array.
    def equilibriumPoint(self,A, N):
        # Your code here
        if N == 0:
            return -1
        if N == 1:
            return 1
    
        for i in range(1, N):
            A[i] = A[i] + A[i - 1]
        # print(A)
        tsum, lsum, rsum = A[N - 1], 0, 0
        ans = -1
        for i in range(1, N - 1):
            lsum = A[i - 1]
            rsum = tsum - A[i]
    
            if lsum == rsum:
                ans = i + 1
                break
    
        return ans




#{ 
 # Driver Code Starts
# Initial Template for Python 3

import math


def main():

    T = int(input())

    while(T > 0):

        N = int(input())

        A = [int(x) for x in input().strip().split()]
        ob=Solution()

        print(ob.equilibriumPoint(A, N))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends