class Solution {
public:
    int specialArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(1001,0);  // initialize an array we know there can maximum 1000 elements
        for(int i = 0;i<n;i++){
            count[arr[i]]++;   // store which element comes how many times into count at its index like--> if 4 comes 3 times then at the index 4 we store 3 in count array
        }
        int total = n;   // total size of array
        for(int i = 0;i<1001;i++){  // traversing the array count which we have created uper (frequency of every number in original array)
            if(i == total) return i;  // if we found ok this numberFrequency is equal to total(initially size of original array) of original array else we decrease total by one  (because we have to check for smaller element)
            total -= count[i];
        }
        
        // if there are no such number such that number of element greater that is equal to that number then we return -1
        return -1;
    }
};
