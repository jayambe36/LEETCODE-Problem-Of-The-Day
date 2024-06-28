class Solution {
public:

    
    long long maximumImportance(int n, vector<vector<int>>& road) {
    long long ans=0,cnt=1;
     int in[n];
    for(int i=0;i<n;i++) in[i]=0;
    for(auto x:road)
    {
        in[x[0]]++;
        in[x[1]]++;
    }
    sort(in,in+n);
    for(auto x:in)
    {
        ans+=(long long)x*cnt;
        cnt++;
    }
 return ans;  
}

};