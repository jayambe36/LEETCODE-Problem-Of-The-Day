class Solution {
public:
       bool containsDuplicate(vector<int>& nums) {
        if (nums.empty() || nums.size() <= 1)
            return false;

        unordered_set<int> set;

        for (int num : nums) {
            if (set.find(num) != set.end())
                return true;
            set.insert(num);
        }

        return false;
    }

};
    