class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> um;
        int count=0;
        for(auto val:s){
            um[val]++;
        }

        // for(auto val:um){
        //     cout<<"("<<val.first<<","<<val.second<<")"<<" ";
        // }
        // cout<<"\n";

        for(auto val:t){
            if(um.find(val)==um.end()){
                count++;
            }
            else{
                um[val]--;
                if(um[val]==0){um.erase(val);}
            }
        }

        // for(auto val:um){
        //     cout<<"("<<val.first<<","<<val.second<<")"<<" ";
        // }
        // cout<<"\n";

        return count;
    }
};
