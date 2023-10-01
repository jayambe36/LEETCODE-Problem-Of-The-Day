//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n=s.size();
	    long long dp[n+1]={0};
	    dp[0]=1;
	    vector<int> prev(26,-1);
	    for(int i=1;i<=n;i++){
	        if(prev[s[i-1]-'a']!=-1){
	            dp[i]=2LL*dp[i-1]-dp[prev[s[i-1]-'a']];
	        }
	        else{
	            dp[i]=2LL*dp[i-1];
	        }
	        dp[i]=dp[i]%1000000007;
	        prev[s[i-1]-'a']=i-1;
	    }
	    if(dp[n]<0){
            dp[n]+=1000000007;
        }
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends