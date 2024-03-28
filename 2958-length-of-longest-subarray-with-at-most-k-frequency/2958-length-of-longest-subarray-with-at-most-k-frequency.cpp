class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int j = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;

            while (map[nums[i]] > k) {
                map[nums[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
