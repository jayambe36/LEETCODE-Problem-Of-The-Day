class Solution:
    def duplicates(self, arr, n): 
    	# code here
    	set1 = set()
        arr = sorted(arr)
        for i in range(n-1):
            if arr[i] == arr[i+1]:
                set1.add(arr[i])
                
        if set1:  
            return sorted(list(set1))
        else:
            return [-1]
    	    


#{ 
 # Driver Code Starts
if(__name__=='__main__'):
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        res = Solution().duplicates(arr, n)
        for i in res:
            print(i,end=" ")
        print()



# } Driver Code Ends