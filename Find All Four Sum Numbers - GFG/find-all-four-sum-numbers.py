#User function Template for python3

# arr[] : int input array of integers
# k : the quadruple sum required
class Solution:
    def fourSum(self, arr, k):
        quadruples = []
        arr.sort()  # Sort the array to handle duplicates and maintain the order

        for i in range(len(arr) - 3):
            # Skip duplicates for the first element
            if i > 0 and arr[i] == arr[i - 1]:
                continue
            
            for j in range(i + 1, len(arr) - 2):
                # Skip duplicates for the second element
                if j > i + 1 and arr[j] == arr[j - 1]:
                    continue
                
                left = j + 1
                right = len(arr) - 1
                
                while left < right:
                    current_sum = arr[i] + arr[j] + arr[left] + arr[right]
                    
                    if current_sum == k:
                        quadruples.append([arr[i], arr[j], arr[left], arr[right]])
                        
                        # Skip duplicates for the third element
                        while left < right and arr[left] == arr[left + 1]:
                            left += 1
                        # Skip duplicates for the fourth element
                        while left < right and arr[right] == arr[right - 1]:
                            right -= 1
                    
                        left += 1
                        right -= 1
                    elif current_sum < k:
                        left += 1
                    else:
                        right -= 1
        
        return quadruples


#{ 
 # Driver Code Starts
#Initial Template for Python 3


#Main
if __name__=='__main__':
    t = int(input())
    while t:
        t-=1
        n, k=map(int,input().split())
        # print(n, k)
        a=list(map(int,input().strip().split()))[:n]
        # print(a)
        ob=Solution()
        ans=ob.fourSum(a, k)
        # print(ans)
        for v in ans:
            for u in v:
                print(u, end=" ")
            print("$", end="")
        if(len(ans)==0):
            print(-1, end="")
        print()
        
        

# } Driver Code Ends