class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Getting the size of the input vector
        int n = nums.size();
        
        // Sorting the input vector in non-decreasing order
        sort(nums.begin(), nums.end());
        
        // Initializing a vector to store the output
        vector<vector<int>> output;
        
        // Looping through the input vector to find four elements whose sum equals the target
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                // Calculating the new target by subtracting the current elements from the target
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                
                // Setting up two pointers to find the remaining two elements
                int low = j + 1, high = n - 1;
                
                // Performing a two-pointer search to find the remaining two elements
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        // If four elements are found whose sum equals the target, adding them to the output vector
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        
                        // Incrementing the low pointer and decrementing the high pointer to find other combinations
                        int tempIndex1 = low, tempIndex2 = high;
                        while(low < high && nums[low] == nums[tempIndex1]) low++;
                        while(low < high && nums[high] == nums[tempIndex2]) high--;
                    }
                }
                
                // Skipping duplicate elements to avoid redundant calculations
                while(j + 1 < n && nums[j] == nums[j + 1]) j++;
            }
            
            // Skipping duplicate elements to avoid redundant calculations
            while(i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        
        // Returning the final output vector
        return output;
    }
};
//O(N^3)