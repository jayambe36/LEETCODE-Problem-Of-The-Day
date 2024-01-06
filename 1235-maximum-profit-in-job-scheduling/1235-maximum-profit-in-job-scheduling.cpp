class Solution {
public:
    int numJobs;
    int memo[50001];


    int getNextIndex(vector<vector<int>>&jobs , int l , int end){
        int r = numJobs - 1;
        int res = numJobs;
        while(l <= r){
            int mid = l + ((r-l) >> 1);

            if(jobs[mid][0] >= end){
                res = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return res;
    }
    int solve(vector<vector<int>>&jobs ,vector<int>&startTime , int i){

        if(i >= numJobs){
            return 0;
        }


        //if we have already calculated the max profit of that job
        if(memo[i] != -1){
            return memo[i];
        }

        //include
        int next = getNextIndex(jobs , i+1 , jobs[i][1]);
        //we are using binary search here to get the next index
        //it helps us to find the lower bound of the next safe job to take
        //so passing jobs , start , end

        //instead we can also use lower_bound function directly but it is always better to write your own function

        // int next = lower_bound(startTime.begin() , startTime.end() , jobs[i][1]) - startTime.begin();

        int inc = jobs[i][2] + solve(jobs , startTime , next);


        //not include
        int not_inc = solve(jobs , startTime, i + 1);

        return memo[i] = max(inc , not_inc);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        numJobs = startTime.size();
        memset(memo , -1 , sizeof(memo));
        
        vector<vector<int>>jobs(numJobs , vector<int>(3,0));
        for(int i = 0 ; i < numJobs ; i++){
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        //we can also create jobs in a diff way
        // vector<tuple<int,int,int>>jobs(numJobs);

        // for(int i = 0 ; i < numJobs ;i++){
        //     jobs[i] = {startTime[i] , endTime[i] , profit[i]};
        // }

        //by default -> sorted on the basis of first value but still writing comp for better undertsanding
        auto comp = [&](auto& vec1 , auto& vec2){
            return vec1[0] <= vec2[0];
        };

        //sort it on the basis of start time
        sort(jobs.begin() , jobs.end() , comp);

        return solve(jobs , startTime ,0);
    }
};
