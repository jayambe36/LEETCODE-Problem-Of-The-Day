class Solution {
public:
    int solve(int i, string& corri, int flag, vector<vector<int>>&dp){
        if(i==corri.size()){
            if(flag==2)
                return 1;
            return 0;
        }
        if(dp[i][flag]!=-1)
            return dp[i][flag];
        int a = 0, b = 0;
        if(corri[i]=='P')
        {
            if(flag==2){
                a = solve(i+1, corri, 0, dp);
                b = solve(i+1, corri, 2, dp);
            }
            else{
                a = solve(i+1, corri, flag, dp);
            }
        }
        else{
            if(flag==2){
                return 0;
            }
            else if(flag==1){
                a = solve(i+1, corri, 0, dp);
                b = solve(i+1, corri, 2, dp);
            }
            else{
                b = solve(i+1, corri, 1, dp);
            }
        }
        return dp[i][flag]=(a+b)%1000000007;
    }
    int numberOfWays(string corridor) {
        int n = corridor.length();
        vector<vector<int>>dp(n, vector<int>(3, -1));
        return solve(0, corridor, false, dp);
    }
};