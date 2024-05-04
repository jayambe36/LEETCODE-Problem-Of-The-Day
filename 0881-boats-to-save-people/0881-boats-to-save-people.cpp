class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(),people.end());//Sort, so that it is from small to large
        int left = 0,right = people.size() - 1,result = 0;
        while(left < right) 
        {
            if(people[left] + people[right] <= limit)//If you can fight, use a boat
             {
                result++;
                left++;
                right--;
            }
            else //If not, let the heavy one use a single boat.
            {
                result++;
                right--;
            }
        }
        if(left == right) {//When there is only one person left, you must still use a separate one.
            result++;
        }
        return result;
    }
};