#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def maxCombinations(self, N, K, A, B):
        # Code here
        from heapq import heappush, heappop
        A.sort(reverse=True)
        B.sort(reverse=True)
        q = [(-(A[0]+B[0]), 0, 0)]
        visited = set([(0, 0)])

        ans = []
        while len(ans) < K:
            v, i, j = heappop(q)
            ans.append(-v)
            if i+1 < len(A) and (i+1, j) not in visited:
                heappush(q, (-A[i+1]-B[j], i+1, j))
                visited.add((i+1, j))
            if j+1 < len(B) and (i, j+1) not in visited:
                heappush(q, (-A[i]-B[j+1], i, j+1))
                visited.add((i, j+1))
        return ans

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N, K = list(map(int, input().split()))
        A = list(map(int, input().split()))
        B = list(map(int, input().split()))
        ob = Solution()
        res = ob.maxCombinations(N, K, A, B)
        for val in res:
            print(val, end =' ')
        print()
# } Driver Code Ends