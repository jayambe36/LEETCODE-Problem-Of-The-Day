#User function Template for python3
class Solution:
    def knapSack(self, N, W, val, wt):
        max_wt = [0]*(W+1)
        for j in range(1, W+1):
            left = max_wt[j-1]
            curr_max = 0
            for i, num in enumerate(wt):
                if j-num < 0:
                    temp = 0
                else:
                    temp = max_wt[j-num] + val[i]
                if curr_max < temp:
                    curr_max = temp
            max_wt[j] = max(left, curr_max)
        return max_wt[W]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N, W = [int(x) for x in input().split()]
        val = input().split()
        for itr in range(N):
            val[itr] = int(val[itr])
        wt = input().split()
        for it in range(N):
            wt[it] = int(wt[it])
        
        ob = Solution()
        print(ob.knapSack(N, W, val, wt))
# } Driver Code Ends