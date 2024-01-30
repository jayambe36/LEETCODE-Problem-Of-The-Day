class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = INT_MAX;
        int p = 0;
        int mp = 0;
        for(int it: prices)
        {
            if(it < l) l = it;
            p = it-l;
            mp = max(mp,p);
        }
        return mp;
    }
};
