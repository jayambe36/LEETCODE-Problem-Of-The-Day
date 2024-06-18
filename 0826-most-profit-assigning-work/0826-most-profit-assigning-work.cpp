class Solution {
public:
    
 
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    map<int, int> m{{0,0}};
    for (int i = 0; i < difficulty.size(); i++) // create the difficulty-maximum-profit BST
        m[difficulty[i]] = max(m[difficulty[i]], profit[i]);
    int mx = 0, res = 0;
    for (auto &p : m) // update the BST to reflect the maximum profit for a job
        mx = p.second = max(p.second, mx);
    for (int w : worker) // look up the BST to find the maximum profit for each worker
        res += prev(m.upper_bound(w))->second;
    return res;
}


};