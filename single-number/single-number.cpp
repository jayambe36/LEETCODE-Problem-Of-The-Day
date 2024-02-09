class Solution {
public:
    int singleNumber(vector<int>& nums) {
   
        int res = nums[0]; // Initialize the result with the first element of the vector

        // Iterate through the vector starting from the second element
        for (int i = 1; i < nums.size(); i++)
            res = res ^ nums[i]; // Using bitwise XOR to find the single number

        return res; // Return the single number
    

    }
};