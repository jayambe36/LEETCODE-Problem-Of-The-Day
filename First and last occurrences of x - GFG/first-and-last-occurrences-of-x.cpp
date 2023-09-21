//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
    int i = 0 ,j = n-1;
        int index1 = -1;
        //Find the leftmost
        while(i<=j){
            int mid = (i+j)/2;
            if(arr[mid] == x){
                index1 = mid;
                j = mid-1;
            }
            else if(arr[mid] < x){
                i = mid+1;
            }
            else j = mid-1;
        }
        //If the element does not exist then directly return -1
        if(index1 == -1) return {-1,-1};
        // Find the rightmost 
       int index2 = -1;
        i = 0, j = n-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(arr[mid] == x){
                index2 = mid;
                i = mid+1;
            }
            else if(arr[mid] < x){
                i = mid+1;
            }
            else j = mid-1;
        }
        return {index1,index2};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends