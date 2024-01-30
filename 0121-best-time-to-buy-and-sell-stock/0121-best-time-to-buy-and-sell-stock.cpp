class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<int> low(n);
        vector<int> high(n);
        low[0] = p[0];
        for(int i=1;i<n;i++)
        {
            low[i] = min(p[i] , low[i-1]);
        }

        high[n-1] = p[n-1];
        for(int i=n-2; i>=0; i--)
        {
            high[i] = max(high[i+1], p[i]);
        }

        int profit = 0;
        for(int i=0; i<n;i++)
        {
            profit = max(profit, high[i]-low[i]);
        }
        return profit;

    }
};
